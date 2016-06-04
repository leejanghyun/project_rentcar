#include "Common.h"

WSADATA wsaData;
SOCKET Servsock,Clntsock;
SOCKADDR_IN servAdr,clntAdr;
HANDLE ThreadID;
int clntSZ;
char method[MAX_SIZE];
char ct[MIN_SIZE];
char fileName[MIN_SIZE];
char First_Header[MAX_SIZE];/////첫번쨰 헤더 자를떄 (첫줄)
string Image;

void SendData(SOCKET sock,char* reply,char* fileName){
	
	char sendData[MAX_SIZE];
	FILE* sendFile=NULL;

	int len=0;
	
	if(!strstr(fileName,".jpg")){////일반 .html 문서
		if((sendFile=fopen(fileName,"r"))==NULL){///////html파일들
			ERRORMESSAGE(sock);
			return;
		}
	
		while(fgets(sendData,MAX_SIZE,sendFile)!=NULL){  //////////요구하는 파일 보내줌
			len=send(sock,sendData,strlen(sendData),0);
		}
	}
	else{///////이미지파일들
		char buf[20];
		int readCnt=0;
		sendFile=fopen(fileName,"rb");
		while(1){
			readCnt=fread((void*)buf,1,sizeof(buf),sendFile);
			if(readCnt<sizeof(buf)){
				if(feof(sendFile)!=0){
					send(sock,buf,sizeof(buf),0);
				}
				break;
			}
			send(sock,buf,sizeof(buf),0);
		}
	}
	//closesocket(sock);
}

unsigned WINAPI RequestThread(void* arg){
	SOCKET Clntsock=(SOCKET)arg;
	char recvData[MAX_SIZE];

	recv(Clntsock,recvData,MAX_SIZE,0);

	printf("%s",recvData);
	

	if(strstr(recvData,"HTTP/")==NULL || strstr(recvData,"main.html")==NULL)  ///먼저 클라이언트 메시지가 HTTP프로토콜인지 확인+main을 통하지 않으면 error뜨게
	{ERRORMESSAGE(Clntsock);
	closesocket(Clntsock);
	return -1;
	}

	strcpy(First_Header,strtok(recvData,"\r\n"));/////1번째 헤더문을 잘랐습니다.
	
	Parsing_Image(First_Header);
		
	if(!strcmp(method,"GET")){////GET
		
		SendData(Clntsock,ct,fileName);

	}
	else{////POST

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
  servAdr.sin_addr.s_addr=inet_addr("127.0.0.1");  /////localhost로 테스트 
  servAdr.sin_port=htons(atoi("9190"));////8080포트

  if(bind(Servsock,(SOCKADDR*)&servAdr,sizeof(servAdr))==SOCKET_ERROR)
	  printf("bind() error");
  if(listen(Servsock,5)==SOCKET_ERROR)
	  printf("listen() error");

  while(1){
	  clntSZ=sizeof(clntAdr);
	  Clntsock=accept(Servsock,(SOCKADDR*)&clntAdr,&clntSZ);
	  printf("client enter......:%s:%d\n",inet_ntoa(clntAdr.sin_addr),ntohs(clntAdr.sin_port)); ///클라이언트 주소+포트
	  (HANDLE)_beginthreadex(NULL,0,RequestThread,(void*)Clntsock,0,(unsigned*)&ThreadID);
  }
  closesocket(Servsock);
  WSACleanup();
  return 0;
}