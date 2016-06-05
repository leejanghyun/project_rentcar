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
