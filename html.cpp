
void question_html(SOCKET Clntsock,char* ct,char *id,int page){
	//////////DB에 모든 메시지 찾아서 거기 맞게 출력
	MYSQL* conn_ptr=NULL; // mysql 과의 연결 담당
    MYSQL_RES* res=NULL; // 쿼리 결과 받는 변수
    MYSQL_ROW row; //쿼리에 대한 실제 데이터 값이 들어있는 변수
	
	

	char table[HTML]= "<table width=\"900\"><tr><td> <font color=\"grey\" size=\"10\">ID</font></td><td><font color=\"grey\" size=\"10\">QUESTION</font></td><td><font color=\"grey\" size=\"10\">ANSWER</font></td></tr>";
    char Query[MAX_SIZE]="select * from question where no>='";
	char pg_s[MIN_SIZE]={0,};
	char pg_f[MIN_SIZE]={0,};
	sprintf(pg_s,"%d",(page-1)*10+1);
	sprintf(pg_f,"%d",(page-1)*10+10);

	strcat(Query,pg_s);
	strcat(Query,"' && no<='");
    strcat(Query,pg_f);
	strcat(Query,"'");
	int num=0;
	initMYSQL(&conn_ptr);

	mysql_query(conn_ptr, Query);

	res = mysql_store_result(conn_ptr); 
	int col=mysql_num_rows(res);
	while ((row=mysql_fetch_row(res))!=NULL)
	{
		
		if(num++==10)
			break;
		strcat(table,"<tr><td>");
		strcat(table,row[0]);
		strcat(table,"</td><td>");
		strcat(table,row[1]);
		strcat(table,"</td><td>");
		if(row[2]!=NULL)
		strcat(table,row[2]);
		strcat(table,"</td></tr><br>");		
	}
	strcat(table,"</table>");

	
	char html[MIN_SIZE]="<!DOCTYPE html> <html>"; 
	char head[MIN_SIZE]=" <head><meta charset=\"UTF-8\" /><title>Game_1</title><style type=\"text/css\">body{background-size:1970px 1000px}.item1{ position: absolute; left: 500px; top: 600px; width: 200px;}</style></head>";
	char body1[MIN_SIZE]="  <body background=\"questionbg.jpg\">";
	char body2[MAX_SIZE]=" <center><br>"
		"<table width = \"1960\" height =\"50\" align=\"center\" border = \"0\">"
         "              <tr height =\"13\"></tr>"
          "<tr>"
           "     <td><a href=\"join.html\"><img src=\"bar2.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td>"
            "    <td><a href=\"rent.html\"><img src=\"bar1.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td>"
             "    <td width=\"190\" height=\"70\"></td>"
              "  <td><a href=\"rent.html\"><img src=\"bar3.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td>"
               " <td><a href=\"question.html\"><img src=\"bar4.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td>"
         "   </tr>"
   " </table><br><br><br><br><br>";

 
  char body3[MAX_SIZE]=   "<br><br><br><br><br><br>"
    "<form method=\"post\">"
	"<textarea name=\"chat\" rows=\"1\" cols=\"100\"></textarea>"
	"<input type=\"submit\" value=\"send\">"
    "</form>";
	char link[MAX_SIZE]="";
	for(int i=1;i<(col)/10+2;i++){
		char* pg_num=new char[10];
		strcat(link,"<a href=\"");
		sprintf(pg_num,"%d",i);
		strcat(link,pg_num);
		strcat(link,".html\">[");
		strcat(link,pg_num);
		strcat(link,"]</a>");
	}
	strcat(link, " </center></body></html>");

	char content[CONTENT_SIZE]="";
	strcat(content,html);
	strcat(content,head);
	strcat(content,body1);
	strcat(content,body2);
	strcat(content,table);
	strcat(content,body3);
	strcat(content,link);
	send(Clntsock,content,strlen(content),0);
    closesocket(Clntsock); 
}

