
int Parsing_Image(char* header){///filename+image
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

void Parsing_for_login(SOCKET Clntsock,char* ct,char* message,char* IP){
	char identify[MIN_SIZE];
	char id[MIN_SIZE];
	char pw[MIN_SIZE];
	char login[200]="";//////id pw ��ġ�ϸ� �����ͺ��̽� login=1�κ����ϱ� ����
	char IP_Field[200]="";///IP�ʵ� �������� ����

	int len=0;
	MYSQL* conn_ptr=NULL; // mysql ���� ���� ���
    MYSQL_RES* res=NULL; // ���� ��� �޴� ����
    MYSQL_ROW row; //������ ���� ���� ������ ���� ����ִ� ����
	
	strcpy(identify,strstr(message,"login_id"));
	strtok(identify,"=");
	strcpy(id,strtok(NULL,"&"));////(id)&pw=(pw)
	strtok(NULL,"=");//(id)����
	strcpy(pw,strtok(NULL,"="));//(pw)����

	initMYSQL(&conn_ptr);
	mysql_query(conn_ptr, Query1);
	res = mysql_store_result(conn_ptr); 

	while ((row=mysql_fetch_row(res))!=NULL)
		{
			if(!strcmp(id,row[1]) && !strcmp(pw,row[2])){      /////////////id pw �� ��ġ�ϴ��� �˻� row[1]:id row[2]:pw
				strcat(login,Query2);
				strcat(IP_Field,Query3);
				strcat(login,"1' where ID='"); /////login ��� 1���� ����
				strcat(IP_Field,IP);
				strcat(IP_Field,"' where ID='"); /////login ��� 1���� ����
				strcat(login,id);
				strcat(IP_Field,id);
				strcat(login,"'");
				strcat(IP_Field,"'");

	            len = mysql_query(conn_ptr, login);
				len = mysql_query(conn_ptr, IP_Field);
				main_html(Clntsock,ct,id);
				return;                    //=>����:�α��� �ѻ���� ������������
			}
		}	
	char err_message[MAX_SIZE]="<html><head><script type=\"text/javascript\">alert('login error')</script></head></html>";
	send(Clntsock,err_message,strlen(err_message),0);
	SendData(Clntsock,ct,"main.html");	//////������������ �̵�

}