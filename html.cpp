#include "Common.h"
void main_html(SOCKET Clntsock,char* ct,char *id){////id ,pw에 맞게
	char html[MIN_SIZE]="<!DOCTYPE html> <html lang=\"ko\">"; 
	char head[MIN_SIZE]=" <head><meta charset=\"utf-8\" /><title>Game_1</title><style type=\"text/css\">body{background-image: url(\"mainmain4.jpg\");background-size:1970px 1000px}</style></head>";
	char body1[MIN_SIZE]="  <body bgcolor = \"grey\">";
	char form[MAX_SIZE]="<br> <div align=\"right\" width=\"300\" height=\"30\">";//////////////////로그인 성공시 각장의 id에 맞게 오른쪽 상단에 적어준다.
	
	strcat(form," <form name=\"logout\" method=\"post\"><input type=\"hidden\" name=\"logout\" ><font size=\"5\" color=\"grey\">");
	strcat(form,id);
	strcat(form,"</font>&nbsp;&nbsp;<input type=\"submit\" style=\"background-color:black; height: 25px; width: 70px; font-size:25; font-family:Times New Roman; color:white;\" value=\"logout\">&nbsp;&nbsp;&nbsp;</form></div>");
	char body2[MAX_SIZE]=" <br><center>"
    "<table width = \"1960\" height =\"50\" align=\"center\" border = \"0\">"
         "   <tr height =\"13\"></tr>"
          "  <tr>"
           "     <td><a href=\"join.html\"><img src=\"bar2.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td>"
            "    <td><a href=\"rent.html\"><img src=\"bar1.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td>"
             "    <td width=\"190\" height=\"70\"></td>"
              "  <td><a href=\"reserve.html\"><img src=\"bar3.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td>"
               " <td><a href=\"question.html\"><img src=\"bar4.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td>"
            "</tr>"
        "</table>"

       " </center>"
 "   </body>"
"</html>	";

char content[CONTENT_SIZE]="";
	strcat(content,html);
	strcat(content,head);
	strcat(content,body1);
	strcat(content,body2);
	strcat(content,form);
	send(Clntsock,content,strlen(content),0);
    closesocket(Clntsock); 
}

void rent_html(SOCKET Clntsock,char* ct,char *id){
	char html[MIN_SIZE]="<!DOCTYPE html> <html lang=\"ko\">"; 
	char head[MIN_SIZE]=" <head> <meta charset=\"utf-8\" /> <style type=\"text/css\">  #icon{position: absolute;left: 600;top: 0;}</style> </head>";
	char body1[MIN_SIZE]="<body background=\"rentbg.jpg\"> <img align=\"center\"border=\"0\"> ";
	char form[MAX_SIZE]="<div align=\"right\" width=\"300\" height=\"30\">";//////////////////로그인 성공시 각장의 id에 맞게 오른쪽 상단에 적어준다.
	strcat(form," <form name=\"logout\" method=\"post\"><input type=\"hidden\" name=\"logout\" ><font size=\"5\" color=\"grey\">");
	strcat(form,id);
	strcat(form,"</font>&nbsp;&nbsp;<input type=\"submit\" style=\"background-color:black; height: 25px; width: 70px; font-size:25; font-family:Times New Roman; color:white;\" value=\"logout\">&nbsp;&nbsp;&nbsp;</form></div>");
	
	char body2[HTML]="<center>"
  "<table width = \"1960\" height =\"50\" align=\"center\" border = \"0\">"
         "   <tr height =\"13\"></tr>"
          "  <tr>"
           "     <td><a href=\"join.html\"><img src=\"bar2.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td>"
            "    <td><a href=\"rent.html\"><img src=\"bar1.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td>"
             "    <td width=\"190\" height=\"70\"></td>"
              "  <td><a href=\"reserve.html\"><img src=\"bar3.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td>"
               " <td><a href=\"question.html\"><img src=\"bar4.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td>"
            "</tr>"
        "</table>";

    char body3[HTML]=""
   " <table align =\"center\" border=\"0\" width=\"1000\" height=\"700\">"
       " <tr>"
          "  <td colspan=\"5\"><br><br><br></td></tr>"
       " <tr>"
        "    <td><a href=\"rent1.html\"><img width = \"380\" height =\"250\" src =\"rentcar1.jpg\" margin =\"0\"></a></td>"
         "   <td >&nbsp;</td>"
          "  <td><a href=\"rent2.html\"><img width = \"380\" height =\"250\" src =\"rentcar2.jpg\"></a></td>"
           "  <td>&nbsp;</td>"
           " <td><a href=\"rent3.html\"><img width = \"380\" height =\"250\" img src =\"rentcar3.jpg\"></a></td>"
       " </tr>"
        
        "<tr>"
         "   <td align=\"center\" width=\"160\" height=\"50\" bgcolor=\"#AAAAAA\"><strong><font face=\"arial\" size=\"6\">Elantra MD</font></strong></td>"
          "  <td width=\"80\">&nbsp;</td>"
           " <td align=\"center\" width=\"160\" height=\"50\" bgcolor=\"#AAAAAA\"><strong><font face=\"arial\" size=\"6\">K3</font></strong></td>"
            "<td width=\"80\">&nbsp;</td>"
            "<td align=\"center\" width=\"160\" height=\"50\" bgcolor=\"#AAAAAA\"><strong><font face=\"arial\" size=\"6\">K5</font></strong></td>"
        "</tr>"
        "<tr>"
         "   <td><a href=\"rent4.html\"><img width = \"380\" height =\"250\" src =\"rentcar4.jpg\"></a></td>"
          "   <td width=\"80\">&nbsp;</td>"
           " <td><a href=\"rent5.html\"><img width = \"380\" height =\"250\" src =\"rentcar5.jpg\"></a></td>"
            " <td width=\"80\">&nbsp;</td>"
            "<td><a href=\"rent6.html\"><img width = \"380\" height =\"250\"  src =\"rentcar6.jpg\"></a></td>"
       " </tr>"
       " <tr>"
        "    <td align=\"center\" width=\"160\" height=\"50\" bgcolor=\"#AAAAAA\"><strong><font face=\"arial\" size=\"6\">new K5</font></strong></td>"
         "    <td width=\"80\">&nbsp;</td>"
          "  <td align=\"center\" width=\"160\" height=\"50\" bgcolor=\"#AAAAAA\"><strong><font face=\"arial\" size=\"6\">YF Sonata</font></strong></td>"
           " <td width=\"80\">&nbsp;</td>"
            "<td align=\"center\" width=\"160\" height=\"50\" bgcolor=\"#AAAAAA\"><strong><font face=\"arial\" size=\"6\">LF Sonata</font></strong></td>"
       " </tr>"
    "</table>"
    
"</center>"
"</body>"
"</html>"; 

	char content[CONTENT_SIZE]="";
	strcat(content,html);
	strcat(content,head);
	strcat(content,body1);
		strcat(content,body2);
	strcat(content,form);
	strcat(content,body3);
	send(Clntsock,content,strlen(content),0);
    closesocket(Clntsock); 
};
  
void join_html(SOCKET Clntsock,char* ct,char *id){
	char html[MIN_SIZE]="<!DOCTYPE html> <html lang=\"ko\">"; 
	char head[MIN_SIZE]=" <head> <meta charset=\"utf-8\" /> <style type=\"text/css\">  #icon{position: absolute;left: 600;top: 0;}</style> </head>";
	char body1[MIN_SIZE]="<body background=\"signupback3.jpg\">";
	char form[MAX_SIZE]="<br> <div align=\"right\" width=\"300\" height=\"30\">";//////////////////로그인 성공시 각장의 id에 맞게 오른쪽 상단에 적어준다.
	strcat(form," <form name=\"logout\" method=\"post\"><input type=\"hidden\" name=\"logout\" ><font size=\"5\" color=\"grey\">");
	strcat(form,id);
	strcat(form,"</font>&nbsp;&nbsp;<input type=\"submit\" style=\"background-color:black; height: 25px; width: 70px; font-size:25; font-family:Times New Roman; color:white;\" value=\"logout\">&nbsp;&nbsp;&nbsp;</form></div>");
	char body2[HTML]="<center>"
   " <form method=\"post\" action=\"main.html\">"
   
    "    <br>"
      "<table width = \"1960\" height =\"50\" align=\"center\" border = \"0\">"
         "   <tr height =\"13\"></tr>"
          "  <tr>"
           "     <td><a href=\"join.html\"><img src=\"bar2.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td>"
            "    <td><a href=\"rent.html\"><img src=\"bar1.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td>"
             "    <td width=\"190\" height=\"70\"></td>"
              "  <td><a href=\"reserve.html\"><img src=\"bar3.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td>"
               " <td><a href=\"question.html\"><img src=\"bar4.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td>"
            "</tr>"
        "</table>";
     char body3[HTML]=""      
     "   <table border=\"0\" width=\"640\" height=\"720\" >"
       "     <tr height=\"20\">"
        "    </tr>"
         "   <tr>"
          "      <td align=\"center\" width=\"80\" height=\"40\"></td>"
           "     <td align=\"center\" width=\"60\" height=\"40\" bgcolor=\"#AAAAAA\">User Name</td>"
            "    <td align=\"center\" width=\"20\" height=\"40\"></td>"
             "   <td  align=\"left\" width=\"20\"><input type=\"text\" size=\"20\"/></td>"
            "</tr>"

            "<tr height=\"20\" ></tr>"
           " <tr>"
            "    <td align=\"center\" width=\"40\" height=\"40\"></td>"
             "   <td align=\"center\" width=\"60\" height=\"40\" bgcolor=\"#AAAAAA\">ID</td>"
              "  <td align=\"center\" width=\"20\" height=\"40\"></td>"
        "        <td  align=\"left\" width=\"20\"><input type=\"text\" name=\"identify\" />"
         "       </td>"
          "  </tr>"
            
           " <tr height=\"20\" ></tr>"
            "<tr>"
             "   <td align=\"center\" width=\"40\" height=\"40\"></td>"
              "  <td align=\"center\" width=\"60\" height=\"40\" bgcolor=\"#AAAAAA\">Password</td>"
               " <td align=\"center\" width=\"20\" height=\"40\"></td>"
                "<td  align=\"left\" width=\"20\"><input type=\"password\" name=\"pw\" /></td>"
            "</tr>"
            
            "<tr height=\"20\" ></tr>"
           " <tr>"
            "    <td align=\"center\" width=\"40\" height=\"40\"></td>"
             "   <td align=\"center\" width=\"60\" height=\"40\" bgcolor=\"#AAAAAA\">Reenter Password</td>"
              "  <td align=\"center\" width=\"20\" height=\"40\"></td>"
               " <td align=\"left\" width=\"20\"><input type=\"password\" /></td>"
            "</tr>"

         "   <tr height=\"20\" ></tr>"
          "  <tr>"
           "     <td align=\"center\" width=\"40\" height=\"40\"></td>"
            "    <td align=\"center\" width=\"60\" height=\"40\" bgcolor=\"#AAAAAA\">Personal Number</td>"
             "   <td align=\"center\" width=\"20\" height=\"40\"></td>"
              "  <td  align=\"left\" width=\"20\">"
              "      <input type=\"text\" maxlength=\"6\" size=\"6\" />"
                    "-"
             "       <input type=\"text\" maxlength=\"7\" size=\"7\" />"
            "    </td>"
           " </tr>"

           " <tr height=\"20\" ></tr>"
           " <tr>"
             "   <td align=\"center\" width=\"40\" height=\"40\"></td>"
              "  <td align=\"center\" width=\"60\" height=\"40\" bgcolor=\"#AAAAAA\">Phone Number</td>"
               " <td align=\"center\" width=\"20\" height=\"40\"></td>"
                "<td  align=\"left\" width=\"20\">"
                 "   <select>"
                  "      <option value=\"t010\">010</option>"
                   "     <option value=\"t011\">011</option>"
                    "    <option value=\"t016\">016</option>"
                     "   <option value=\"t017\">017</option>"
                      "  <option value=\"t019\">019</option>"
                    "</select>"
                   " -<input type=\"text\" maxlength=\"4\" size=\"4\" />"
                   " -<input type=\"text\" maxlength=\"4\" size=\"4\" />"
                "</td>"
           " </tr>"
            
            "<tr height=\"20\" ></tr>"
            "<tr>"
             "   <td align=\"center\" width=\"40\" height=\"20\"></td>"
              "  <td align=\"center\" width=\"60\" height=\"40\" bgcolor=\"#AAAAAA\">Agreement</td>"
               " <td align=\"center\" width=\"20\" height=\"40\"></td>"
                "<td align=\"left\">"
                 "   <input type=\"checkbox\" id=\"agree\" checked=\"checked\" />"
                  "  <label for=\"agree\" color=\"white\">I accept<br> Privacy statement <br> and Conditions.</label>"
           "     </td>"
           " </tr>"

        "</table> "
       " <br/>"
        "<input type=\"submit\" value=\"Create an Account\" color=\"#blue\";/>"
        "<input type=\"reset\" value=\"Reset\" bgcolor=\"#990000\" />"
    "</form>"
"</center>"
"</body>"
"</html> ";
	
	char content[CONTENT_SIZE]="";
	strcat(content,html);
	strcat(content,head);
	strcat(content,body1);
	strcat(content,body2);
	strcat(content,form);
	strcat(content,body3);
	send(Clntsock,content,strlen(content),0);
    closesocket(Clntsock); 
}

void pay1_html(SOCKET Clntsock,char* ct,char *id,int page ,int zero){
	char html[MIN_SIZE]="<!DOCTYPE html> <html lang=\"ko\">"; 
	char head[MIN_SIZE]=" <head> <meta charset=\"utf-8\" /> <style type=\"text/css\">  #icon{position: absolute;left: 600;top: 0;}</style> <script type=\"text/javascript\">function SetValue(){var fm = document.MyForm;fm.getTxt.value = fm.getVal.options[fm.getVal.selectedIndex].text;}";
	char script[MIN_SIZE]="alert('sorry we have no car')";
	char script1[MIN_SIZE]="</script></head>";
	char num=page;
	char car[MIN_SIZE]="";
	switch(num){
	case '1':strcat(car,"Elentra MD");
		break;
	case '2':strcat(car,"K3");
		break;
	case '3':strcat(car,"K5");
		break;
	case '4':strcat(car,"New K5");
		break;
	case '5':strcat(car,"YF SONATA");
		break;
	case '6':strcat(car,"LF SONATA");
		break;
	}
	int len=0;
	if(zero){
		strcat(head,script);
		strcat(head,script1);
	}
	else{
		strcat(head,script1);
	}
	char body1[MIN_SIZE]="<body background=\"rentbg.jpg\"> <img align=\"center\"border=\"0\"> <br>";
	char body2[HTML]="<center>"
       "<table width = \"1960\" height =\"50\" align=\"center\" border = \"0\">"
         "   <tr height =\"13\"></tr>"
          "  <tr>"
           "     <td><a href=\"join.html\"><img src=\"bar2.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td>"
            "    <td><a href=\"rent.html\"><img src=\"bar1.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td>"
             "    <td width=\"190\" height=\"70\"></td>"
              "  <td><a href=\"reserve.html\"><img src=\"bar3.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td>"
               " <td><a href=\"question.html\"><img src=\"bar4.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td>"
            "</tr>"
        "</table>"
            "<br><br><br><br>"
                  "   <form name=\"MyForm\" method=\"post\">"
            "<table border=\"0\" width=1200 height=500>"
                
             "   <tr>"
              "      <td width= 500 rowspan =\"3\" bgcolor=\"white\"><img align = \"center\" src=\"rentcar";
			  len=strlen(body2);
	         body2[len]=num;
			 char body3[MAX_SIZE]=""
			  ".jpg\" width=\"550\" height=\"350\" border=\"0\"></td>" 
              "      <td align = \"center\" bgcolor=\"#AAAAAA\" ><strong><font size=6 color=\"white\">model</font></strong></td>"
               "     <td bgcolor=\"white\" align = \"center\"><strong><font size=6 color=\"black\">";
			 char body4[HTML]=" </font></strong></td>"
               " </tr>"    
               " <tr>"
                "    <td align = \"center\" width= 250 bgcolor=\"#AAAAAA\"><strong><font size=6 color=\"white\">lending period</font></strong>"
                 "   <td  rowspan = 2 width= 450 bgcolor=\"white\">"
                   "         <strong><font face=\"arial\" size=6 color=\"black\">day : </font></strong>"
                    "        <select name =\"month\" id=\"month\">"
                     "           <option>- MONTH -</option>"
                      "          <option value=1>1</option><option value=2>2</option><option value=3>3</option><option value=4>4</option>"
                       "         <option value=5>5</option><option value=6>6</option><option value=7>7</option><option value=8>8</option>"
                        "        <option value=9>9</option><option value=10>10</option><option value=11>11</option><option value=12>12</option>"
                         "   </select>"
                          "  <select name =\"date\" id=\"date\">"
                           "     <option>- DATE -</option>"
                            "    <option value=1>1</option><option value=2>2</option><option value=3>3</option><option value=4>4</option><option value=5>5</option>"
                             "   <option value=6>6</option><option value=7>7</option><option value=8>8</option><option value=9>9</option><option value=10>10</option>"
                              "  <option value=11>11</option><option value=12>12</option><option value=13>13</option><option value=14>14</option>"
                               " <option value=15>15</option><option value=16>16</option><option value=17>17</option><option value=18>18</option><option value=19>19</option>"
                                "<option value=20>20</option><option value=21>21</option><option value=22>22</option><option value=23>23</option><option value=24>24</option>"
                                "<option value=27>27</option><option value=28>28</option><option value=29>29</option><option value=30>30</option><option value=31>31</option>"
                          "  </select>"
                         "   <br><br><br>"
                         "   <strong><font face=\"arial\" size=6 color=\"black\">time : </font></strong>"
                          "  <select name =\"time\" id=\"time\">"
                           "     <option>- Time -</option>"
                            "    <option value=1>1hour</option><option value=3>3hour</option><option value=6>6hour</option><option value=9>9hour</option><option value=12>12hour</option>"
                             "   <option value=18>18hour</option><option value=24>24hour</option><option value=36>36hour</option><option value=48>48hour</option>"
                        "    </select>"
                        "    <br><br><br><br><br><br>"
                        "    <input type = 'button' value='show estimates' onclick='javascript:SetValue();'>"

                 "   </td>"
              "  </tr>"
              "  <tr>"
               "     <td bgcolor=\"#AAAAAA\" align = \"center\"><strong><font size=6 color=\"white\">estimates</font></strong></td>"
                
             "   </tr>"
		   "    </form>"
          "  <br><br><br><br>"
		     "</table>"
		  "<div align=\"center\">"
            "<input type=\"submit\"  src=\"loginimg.jpg\" style=\"background-color:black; height: 55px; width: 100px; font-size:150; color:white;\" value=\"Pay\" value = \"message\" onclick = \"alert('Thank you')\";>&nbsp;&nbsp;&nbsp;  </div>"
    
          "      </form>  "
        "</center>"
    "</body>"
"</html>";

	char content[CONTENT_SIZE]="";
	strcat(content,html);
	strcat(content,head);
	strcat(content,body1);
	strcat(content,body2);
	strcat(content,body3);
	strcat(content,car);
	strcat(content,body4);
	send(Clntsock,content,strlen(content),0);
    closesocket(Clntsock); 
}

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


void reserve_html(SOCKET Clntsock,char* ct,char *id,char* info){
	char html[MIN_SIZE]="<!DOCTYPE html> <html lang=\"ko\">"; 
	char head[MIN_SIZE]=" <head><meta charset=\"utf-8\" /><title>Game_1</title><style type=\"text/css\">body{background-size:1970px 1000px}</style></head>";
	char body1[MIN_SIZE]="  <body background=\"reservebg.jpg\">";
	char body2[MAX_SIZE]="  <br>"
        "<center> "
        " <table width = \"1960\" height =\"50\" align=\"center\" border = \"0\"> "
          "   <tr height =\"13\"></tr> "
            " <tr> "
              "    <td><a href=\"join.html\"><img src=\"bar2.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td> "
                " <td><a href=\"rent.html\"><img src=\"bar1.jpg\" width=\"280\" height=\"77\" border=\"0\"></a></td> "
                  "<td width=\"190\" height=\"70\"></td> "
                 "<td><a href=\"reserve.html\"><img src=\"bar3.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td> "
                 "<td><a href=\"question.html\"><img src=\"bar4.jpg\" width=\"300\" height=\"77\" border=\"0\"></a></td> "
            " </tr> "
        " </table> "
    " <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> "
      " <table align=\"center\"> "
        " <tr> "
          "   <td><img src=\"r_ID.jpg\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color=\"black\"  face=\"arial\" size=\"10\">";
	char body3[MIN_SIZE]="";
	strcat(body3,id);
	char body4[MAX_SIZE]="</font></tr> "
         "<tr> "
           "  <td colspan =\"3\"><br><br><br></td> "
        " </tr> "
         "<tr> "
		 "  <td><img src=\"r_INFO.jpg\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<font color=\"black\"  face=\"arial\" size=\"5\">";
	char body5[MAX_SIZE]="";
	strcat(body5,info);
	strcat(body5,"</font></td></tr>");
	char body6[MAX_SIZE]="<tr align=\"center\"><td><br><br>"
       "   <form method=\"post\">"
	   "      <input type=\"hidden\" name=\"cancel\">"
	   "     <input type=\"submit\"  src=\"loginimg.jpg\" style=\"background-color:grey; height: 50px; width: 300px; font-size:10; font-family:Times New Roman; color:black;\" value=\"cancel rent\">&nbsp;&nbsp;&nbsp;</form></td>"
		 " </tr>"
		"</table></center></body></html>";
	char content[CONTENT_SIZE]="";
	strcat(content,html);
	strcat(content,head);
	strcat(content,body1);
	strcat(content,body2);
	strcat(content,body3);
	strcat(content,body4);
	strcat(content,body5);
	strcat(content,body6);
	send(Clntsock,content,strlen(content),0);
    closesocket(Clntsock); 
}


