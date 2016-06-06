
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
