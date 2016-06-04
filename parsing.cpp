#include "Common.h"


int Parsing_Image(char* header){
	char* Last_HTML_File=NULL;////
	strcpy(method, strtok(header," /"));////전체 패킷문입니다.
	
	while(1){/////////////////ex) .html/.html/...있을때 마지막 .html뽑기위한과정 입니다.///Image_FILE에는 이미지들이 담긴다.
	char * Image_File=strtok(NULL," /");
	    if(strstr(Image_File,".html")==NULL){
			strcpy(fileName,Last_HTML_File);
			strcpy(Image,Image_File);
			break;
	    }
		Last_HTML_File=Image_File;
	}

	strcpy(ct,ContentType(fileName));///Content-Type 확인

	return 1;
}

void Parsing_for_join(SOCKET Clntsock,char* ct,char* message){
	char identify[MIN_SIZE];
	char id[MIN_SIZE];
	char pw[MIN_SIZE];
	char Query[MIN_SIZE]="";
	int ok=0;
    MYSQL* conn_ptr=NULL; // mysql 과의 연결 담당
    MYSQL_RES* res=NULL; // 쿼리 결과 받는 변수
    MYSQL_ROW row; //쿼리에 대한 실제 데이터 값이 들어있는 변수

	initMYSQL(&conn_ptr);

	strcpy(identify,strstr(message,"identify"));
	strtok(identify,"=");
	strcpy(id,strtok(NULL,"&"));////(id)&pw=(pw)
	strtok(NULL,"=");//(id)저장
	strcpy(pw,strtok(NULL,"="));//(pw)저장
	
	mysql_query(conn_ptr, Query1);
	res = mysql_store_result(conn_ptr); 

	while ((row=mysql_fetch_row(res))!=NULL)
	{///동일한게 없으면 ok
			if(!strcmp(id,row[1])){
				ok=1;
				break;
			}
	}

	if(!ok){
		////데이터 베이스에저장
		strcat(Query,"INSERT INTO `rentcar`.`customer` (`IP` ,`ID` ,`PW` ,`login` ) VALUES ( '");
		strcat(Query,IP);
		strcat(Query,"', '");
		strcat(Query,id);
		strcat(Query,"', '");
		strcat(Query,pw);
		strcat(Query,"', '0' )");
		mysql_query(conn_ptr, Query);
		SendData(Clntsock,ct,"main.html");	//////메인페이지로 이동
	}
	else{
		SendData(Clntsock,ct,"index2.html");	//////다시 회원가입페이지로 이동
	}

}