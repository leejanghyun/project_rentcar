#include "Common.h"
#include "DataBase.h"
WSADATA wsaData;
SOCKET Servsock,Clntsock;
SOCKADDR_IN servAdr,clntAdr;
HANDLE ThreadID;
int clntSZ;
char method[MAX_SIZE];///GET 
char ct[MIN_SIZE];
char fileName[MIN_SIZE];//////
char First_Header[MAX_SIZE];/////ù���� ��� �ڸ��� (ù��)
char Image[MIN_SIZE];
char Data[MAX_SIZE];
char* IP;

struct package{
	SOCKET socket;
	char Data[MAX_SIZE];
}PACKAGE; /////�����忡 �����ַ���...

void SendData(SOCKET sock,char* reply,char* fileName){
	
	char sendData[MAX_SIZE];
	FILE* sendFile=NULL;

	int len=0;
	
	if(!strstr(fileName,".jpg")){////�Ϲ� .html ����
		if((sendFile=fopen(fileName,"r"))==NULL){///////html���ϵ�
			ERRORMESSAGE(sock);
			return;
		}
	
		while(fgets(sendData,MAX_SIZE,sendFile)!=NULL){  //////////�䱸�ϴ� ���� ������
			len=send(sock,sendData,strlen(sendData),0);
		}
	}
	else{///////�̹������ϵ�
		char buf[200];
		int readCnt=0;
		sendFile=fopen(fileName,"rb");
		while(1){
			readCnt=fread((void*)buf,1,sizeof(buf),sendFile);
			if(readCnt<sizeof(buf)){
				if(feof(sendFile)!=0){
					send(sock,buf,sizeof(buf),0);
					break;
				}
		    break;
			}
			send(sock,buf,sizeof(buf),0);
		}
	}
	closesocket(sock);
}

unsigned WINAPI RequestThread(void* arg){
	SOCKET Clntsock=(SOCKET)arg;
	char recvData[MAX_SIZE];
	int login=0;
	int len=0; 
	char id[MIN_SIZE];
    /*
	client IP�� login 1����Ȯ���ϰ� //��Ű��Ȱ login����1�� ���� login==0�̸� SendData else �� switch()
	*/
	

	len=recv(Clntsock,recvData,MAX_SIZE,0);
	recvData[len]=0;
	
	printf("%s",recvData);
	strcpy(Data,recvData);

	if(strstr(recvData,"HTTP/")==NULL )  ///���� Ŭ���̾�Ʈ �޽����� HTTP������������ Ȯ��+main�� ������ ������ error�߰�
	{ERRORMESSAGE(Clntsock);
	closesocket(Clntsock);
	return -1;
	}

	strcpy(First_Header,strtok(recvData,"\r\n"));/////1��° ������� �߶����ϴ�.

	Parsing_Image(First_Header);
		
	if(!strcmp(method,"GET")){////GET
		if(strstr(Image,".jpg")!=NULL|| strstr(Image,".png")!=NULL){
			SendData(Clntsock,ct,Image);
		}
		else{/////if(login) else {header}
		    Cookie(&login,IP,id);
			if(!login)SendData(Clntsock,ct,fileName);
			else{
				if(!strcmp(fileName,"main.html")){
					main_html(Clntsock,ct,id);
				}
				else if(!strcmp(fileName,"rent.html")){
					rent_html(Clntsock,ct,id);
				}
				else if(!strncmp(fileName,"rent1.html",4)){/////1,2,3,4,5,6 �� ���� �����ϱ�
					pay1_html(Clntsock,ct,id,fileName[4],0);
				}
				else if(!strcmp(fileName,"join.html")){
					join_html(Clntsock,ct,id);
				}
				else if(!strcmp(fileName,"reserve.html")){
					Parsing_for_reserve(Clntsock,ct,Data,id);///////��� Parsing �Լ����ο��� reserve_html.html ���� �ٰ��̴�.
				}
				else if(!strcmp(fileName,"question.html")){
					question_html(Clntsock,ct,id,1);
				}
				else{
					char pagenumber[MIN_SIZE]="";
					strcpy(pagenumber,strtok(fileName,".html"));///////[1],[2]...=1.html 2.html
					question_html(Clntsock,ct,id,atoi(pagenumber));

				}
			}
		}
	}
	else{////POST
		 Cookie(&login,IP,id);
		if(strstr(Data,"login_id")){
		 Parsing_for_login(Clntsock,ct,Data,IP);}
	    else if(strstr(Data,"logout")){
		 Parsing_for_logout(Clntsock,ct,Data,IP);
		}
		else if(strstr(Data,"month")){
			Parsing_for_rent(Clntsock,ct,Data,IP,id);////����â
		}
		else if(strstr(Data,"cancel")){
			Parsing_for_cancel(Clntsock,ct,Data,IP,id);////����â
		}
		else if(strstr(Data,"chat")){
			if(login)
			Parsing_for_chat(Clntsock,ct,Data,IP,id);////����â
		}
		else
		{
		 Parsing_for_join(Clntsock,ct,Data,IP);		 
		 SendData(Clntsock,ct,fileName);
     	}
	}
	return 0;
}

int main(){

  if(WSAStartup(MAKEWORD(2,2),&wsaData)!=0){
	  printf("WSAStartup error");
  }
  Servsock=socket(PF_INET,SOCK_STREAM,0);
  memset(&servAdr,0,sizeof(servAdr));
  servAdr.sin_family=AF_INET;
  servAdr.sin_addr.s_addr=inet_addr("127.0.0.1");  /////localhost�� �׽�Ʈ 
  servAdr.sin_port=htons(atoi("9190"));////8080��Ʈ

  if(bind(Servsock,(SOCKADDR*)&servAdr,sizeof(servAdr))==SOCKET_ERROR)
	  printf("bind() error");
  if(listen(Servsock,5)==SOCKET_ERROR)
	  printf("listen() error");

  while(1){
	  clntSZ=sizeof(clntAdr);
	  Clntsock=accept(Servsock,(SOCKADDR*)&clntAdr,&clntSZ);
	  printf("client enter......:%s:%d\n",inet_ntoa(clntAdr.sin_addr),ntohs(clntAdr.sin_port)); ///Ŭ���̾�Ʈ �ּ�+��Ʈ
	  IP=new char[100];
	  strcpy(IP,inet_ntoa(clntAdr.sin_addr));////Ŭ���̾�Ʈ IP����
	  (HANDLE)_beginthreadex(NULL,0,RequestThread,(void*)Clntsock,0,(unsigned*)&ThreadID);
  }
  closesocket(Servsock);
  WSACleanup();
  return 0;
}