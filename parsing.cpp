#include "Common.h"


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

void Parsing_for_join(SOCKET Clntsock,char* ct,char* message, char* IP){
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

void Parsing_for_chat(SOCKET Clntsock,char* ct,char* Data,char* IP,char* id){
	MYSQL* conn_ptr=NULL; // mysql 과의 연결 담당
    MYSQL_RES* res=NULL; // 쿼리 결과 받는 변수
    MYSQL_ROW row; //쿼리에 대한 실제 데이터 값이 들어있는 변수
	char Query[MAX_SIZE]="INSERT INTO `rentcar`.`question` (`ID` ,`Q`) VALUES ('";
	char Question[MIN_SIZE]="";
	char message[MIN_SIZE]="";
	strcpy(message,strstr(Data,"chat"));
	strcpy(Question,message+5);

	initMYSQL(&conn_ptr);
	strcat(Query,id);
	strcat(Query,"','");
	strcat(Query,Question);
	strcat(Query,"' )");
	mysql_query(conn_ptr, Query);//////////////////DV에 send로 보낸 메시지 ID와 Question 저장

	question_html(Clntsock,ct,id,1);
}
void Parsing_for_cancel(SOCKET Clntsock, char* ct, char* Data, char* IP, char* id) {
   MYSQL* conn_ptr = NULL;
   MYSQL_RES* res = NULL;
   MYSQL_ROW row;
   initMYSQL(&conn_ptr);
   mysql_query(conn_ptr, Query1);
   res = mysql_store_result(conn_ptr);
   char identify[MIN_SIZE];
   char temp[MIN_SIZE];
   char num[200] = "";
   char num1[200] = "";
   char num2[200] = "";
   char* Query_NUM = "update rent set NUM='";
   char* Query_CAR = "update customer set CAR='";
   char* Query_INFO = "update customer set INFO='";

   if (strstr(Data, "cancel")) {
      while ((row = mysql_fetch_row(res)) != NULL)
      {
         if (!strcmp(id, row[1])) {      /////////////id pw 가 일치하는지 검산 row[1]:id row[2]:pw
            strcpy(temp, row[5]);
            if (!strcmp(temp, row[5])) {
               strcpy(num1, Query_CAR);
               strcat(num1, "NULL");
               strcat(num1, "'");
               strcat(num1, " where ID='");
               strcat(num1, id);
               strcat(num1, "'");
               strcpy(num2, Query_INFO);
               strcat(num2, "NULL");
               strcat(num2, "'");
               strcat(num2, " where ID='");
               strcat(num2, id);
               strcat(num2, "'");
               mysql_query(conn_ptr, num1);
               mysql_query(conn_ptr, num2);
               break;
            }
         }
      }
            MYSQL* conn_ptr = NULL;
            MYSQL_RES* res = NULL;
            MYSQL_ROW row;
            initMYSQL(&conn_ptr);
            mysql_query(conn_ptr, Query4);
            res = mysql_store_result(conn_ptr);
            while ((row = mysql_fetch_row(res)) != NULL)
            {
               if (!strcmp(temp, row[0]))
               {
                  int temp1;
                  temp1 = atoi(row[1]);
                  temp1++;
                  itoa(temp1, row[1], 10);
                  strcpy(num, Query_NUM);
                  strcat(num, row[1]);
                  strcat(num, "'");
                  strcat(num, " where CAR='");
                  strcat(num, temp);
                  strcat(num, "'");
                  mysql_query(conn_ptr, num);
                  }
                  break;
               }
               
               
            }
   	Parsing_for_reserve(Clntsock,ct,Data,id);///////비록 Parsing 함수내부에서 reserve_html.html 던져 줄것이다.
                          //=>이유:로그인 한사람만 다음페이지
}
void Parsing_for_logout(SOCKET Clntsock,char* ct,char* Data,char* IP){
	MYSQL* conn_ptr=NULL; // mysql 과의 연결 담당
    MYSQL_RES* res=NULL; // 쿼리 결과 받는 변수
    MYSQL_ROW row; //쿼리에 대한 실제 데이터 값이 들어있는 변수
	char login[200]="";//////id pw 일치하면 데이터베이스 login=1로변경하기 위한 쿼리문 저장 변수
	char IP_Field[200]="";////ip필드 변경 위한 쿼리 저장 변수
	initMYSQL(&conn_ptr);
	mysql_query(conn_ptr, Query1);
	res = mysql_store_result(conn_ptr); 

	while ((row=mysql_fetch_row(res))!=NULL)
		{
			if(!strcmp(IP,row[0])){      /////////////id pw 가 일치하는지 검산 row[1]:id row[2]:pw
				strcat(login,Query2);
				strcat(IP_Field,Query3);
				strcat(login,"0' where IP='"); /////login 대면 1으로 변경
				strcat(IP_Field,"NULL' where IP='"); 
				strcat(login,IP);
				strcat(IP_Field,IP);
				strcat(login,"'");
				strcat(IP_Field,"'");
	            mysql_query(conn_ptr, login);
				mysql_query(conn_ptr, IP_Field);

				SendData(Clntsock,ct,"main.html");	//////메인페이지로 이동
				break;                    //=>이유:로그인 한사람만 다음페이지로
			}
		}	
}


void Parsing_for_reserve(SOCKET Clntsock,char* ct,char* Data,char* id){
	MYSQL* conn_ptr=NULL; // mysql 과의 연결 담당
    MYSQL_RES* res=NULL; // 쿼리 결과 받는 변수
    MYSQL_ROW row; //쿼리에 대한 실제 데이터 값이 들어있는 변수
	char resrvation_info[MIN_SIZE]="CAR  ";////최대 1명당 6명 예약가능
	initMYSQL(&conn_ptr);
	mysql_query(conn_ptr, Query1);
	res = mysql_store_result(conn_ptr); 

	while ((row=mysql_fetch_row(res))!=NULL)
		{
			if(!strcmp(id,row[1])){
				strcat(resrvation_info,row[5]);
				strcat(resrvation_info,"     DATE:");
				strcat(resrvation_info,row[4]);
			}
		}	
	reserve_html(Clntsock,ct,id,resrvation_info);
}

void Parsing_for_rent(SOCKET Clntsock,char* ct,char* Data,char* IP,char* id){
	char identify[MIN_SIZE];
	char month[MIN_SIZE];
	char date[MIN_SIZE];
	char time[MIN_SIZE];
	char car[MIN_SIZE];
	char info[200]="";
	char carinfo[200]="";
	char num[200]="";
	char* Query_CAR="update customer set CAR='";
	char* Query_INFO="update customer set INFO='";
	char* Query_NUM="update rent set NUM='";
	id;
	int number;
	MYSQL* conn_ptr=NULL;
	MYSQL_RES* res = NULL;
	MYSQL_ROW row;
	initMYSQL(&conn_ptr);
	mysql_query(conn_ptr, Query1);
	res = mysql_store_result(conn_ptr);

	if(!strcmp(fileName,"rent1.html")){
		strcpy(car,"Elantra");
	}
	else if(!strcmp(fileName,"rent2.html")){
		strcpy(car,"K3");
	}
	else if(!strcmp(fileName,"rent3.html")){
		strcpy(car,"K5");
	}
	else if(!strcmp(fileName,"rent4.html")){
		strcpy(car,"NK5");
	}
	else if(!strcmp(fileName,"rent5.html")){
		strcpy(car,"YF");
	}
	else if(!strcmp(fileName,"rent6.html")){
		strcpy(car,"LF");
	}

	strcpy(identify,strstr(Data,"month"));
	strtok(identify,"=");
	strcpy(month,strtok(NULL,"&"));		//month
	strtok(NULL,"=");	
	strcpy(date, strtok(NULL,"&"));		//date
	strtok(NULL,"=");
	strcpy(time, strtok(NULL,"\0"));	//time
	
	strcpy(carinfo,Query_CAR);
	strcat(carinfo,car);
	strcat(carinfo,"'");		//Car
	strcat(carinfo," where ID='");
	strcat(carinfo,id);
	strcat(carinfo,"'");
	
	strcpy(info,Query_INFO);
	strcat(info,month);
	strcat(info,"/");
	strcat(info,date);
	strcat(info,"/");
	strcat(info,time);
	strcat(info,"'");
	strcat(info," where ID='");
	strcat(info,id);
	strcat(info,"'");

	initMYSQL(&conn_ptr);
	mysql_query(conn_ptr, Query4);
	res = mysql_store_result(conn_ptr);

	while ((row=mysql_fetch_row(res))!=NULL)
		{
			if(!strcmp(car,row[0])){      /////////////id pw 가 일치하는지 검산 row[1]:id row[2]:pw
				number = atoi(row[1]);
				if(number==0){
					pay1_html(Clntsock,ct,id,fileName[4],1);
						break;
				}
				number--;
				strcpy(num,Query_NUM);
				itoa(number,row[1],10);
				strcat(num,row[1]);
				strcat(num,"'");
				strcat(num," where CAR='");
				strcat(num,car);
				strcat(num,"'");

				mysql_query(conn_ptr,num);
				break;                    //=>이유:로그인 한사람만 다음페이지로
			}
		}	
	
	mysql_query(conn_ptr, carinfo);
	mysql_query(conn_ptr, info);
}

