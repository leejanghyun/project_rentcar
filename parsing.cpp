#include "Common.h"


int Parsing_Image(char* header){
	char* Last_HTML_File=NULL;////
	strcpy(method, strtok(header," /"));////��ü ��Ŷ���Դϴ�.
	
	while(1){/////////////////ex) .html/.html/...������ ������ .html�̱����Ѱ��� �Դϴ�.///Image_FILE���� �̹������� ����.
	char * Image_File=strtok(NULL," /");
	    if(strstr(Image_File,".html")==NULL){
			strcpy(fileName,Last_HTML_File);
			strcpy(Image,Image_File);
			break;
	    }
		Last_HTML_File=Image_File;
	}

	strcpy(ct,ContentType(fileName));///Content-Type Ȯ��

	return 1;
}

void Parsing_for_join(SOCKET Clntsock,char* ct,char* message){
	char identify[MIN_SIZE];
	char id[MIN_SIZE];
	char pw[MIN_SIZE];
	char Query[MIN_SIZE]="";
	int ok=0;
    MYSQL* conn_ptr=NULL; // mysql ���� ���� ���
    MYSQL_RES* res=NULL; // ���� ��� �޴� ����
    MYSQL_ROW row; //������ ���� ���� ������ ���� ����ִ� ����

	initMYSQL(&conn_ptr);

	strcpy(identify,strstr(message,"identify"));
	strtok(identify,"=");
	strcpy(id,strtok(NULL,"&"));////(id)&pw=(pw)
	strtok(NULL,"=");//(id)����
	strcpy(pw,strtok(NULL,"="));//(pw)����
	
	mysql_query(conn_ptr, Query1);
	res = mysql_store_result(conn_ptr); 

	while ((row=mysql_fetch_row(res))!=NULL)
	{///�����Ѱ� ������ ok
			if(!strcmp(id,row[1])){
				ok=1;
				break;
			}
	}

	if(!ok){
		////������ ���̽�������
		strcat(Query,"INSERT INTO `rentcar`.`customer` (`IP` ,`ID` ,`PW` ,`login` ) VALUES ( '");
		strcat(Query,IP);
		strcat(Query,"', '");
		strcat(Query,id);
		strcat(Query,"', '");
		strcat(Query,pw);
		strcat(Query,"', '0' )");
		mysql_query(conn_ptr, Query);
		SendData(Clntsock,ct,"main.html");	//////������������ �̵�
	}
	else{
		SendData(Clntsock,ct,"index2.html");	//////�ٽ� ȸ�������������� �̵�
	}

}