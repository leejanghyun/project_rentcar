
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

