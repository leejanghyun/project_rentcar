
int Parsing_Image(char* header){///filename+image
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

void Parsing_for_login(SOCKET Clntsock,char* ct,char* message,char* IP){
	char identify[MIN_SIZE];
	char id[MIN_SIZE];
	char pw[MIN_SIZE];
	char login[200]="";//////id pw 일치하면 데이터베이스 login=1로변경하기 위함
	char IP_Field[200]="";///IP필드 저장위한 쿼리

	int len=0;
	MYSQL* conn_ptr=NULL; // mysql 과의 연결 담당
    MYSQL_RES* res=NULL; // 쿼리 결과 받는 변수
    MYSQL_ROW row; //쿼리에 대한 실제 데이터 값이 들어있는 변수
	
	strcpy(identify,strstr(message,"login_id"));
	strtok(identify,"=");
	strcpy(id,strtok(NULL,"&"));////(id)&pw=(pw)
	strtok(NULL,"=");//(id)저장
	strcpy(pw,strtok(NULL,"="));//(pw)저장

	initMYSQL(&conn_ptr);
	mysql_query(conn_ptr, Query1);
	res = mysql_store_result(conn_ptr); 

	while ((row=mysql_fetch_row(res))!=NULL)
		{
			if(!strcmp(id,row[1]) && !strcmp(pw,row[2])){      /////////////id pw 가 일치하는지 검산 row[1]:id row[2]:pw
				strcat(login,Query2);
				strcat(IP_Field,Query3);
				strcat(login,"1' where ID='"); /////login 대면 1으로 변경
				strcat(IP_Field,IP);
				strcat(IP_Field,"' where ID='"); /////login 대면 1으로 변경
				strcat(login,id);
				strcat(IP_Field,id);
				strcat(login,"'");
				strcat(IP_Field,"'");

	            len = mysql_query(conn_ptr, login);
				len = mysql_query(conn_ptr, IP_Field);
				main_html(Clntsock,ct,id);
				return;                    //=>이유:로그인 한사람만 다음페이지로
			}
		}	
	char err_message[MAX_SIZE]="<html><head><script type=\"text/javascript\">alert('login error')</script></head></html>";
	send(Clntsock,err_message,strlen(err_message),0);
	SendData(Clntsock,ct,"main.html");	//////메인페이지로 이동

}