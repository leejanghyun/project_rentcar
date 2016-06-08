#include "Common.h"

void Cookie(int* login ,char* ip,char* id){
	MYSQL* conn_ptr=NULL; // mysql 과의 연결 담당
    MYSQL_RES* res=NULL; // 쿼리 결과 받는 변수
    MYSQL_ROW row; //쿼리에 대한 실제 데이터 값이 들어있는 변수

	initMYSQL(&conn_ptr);
	mysql_query(conn_ptr, Query1);
	res = mysql_store_result(conn_ptr); 

	while ((row=mysql_fetch_row(res))!=NULL)
		{
			if(!strcmp(ip,row[0]) && (atoi(row[3])==1)){      /////////////id pw 가 일치하는지 검산 row[1]:id row[2]:pw
			  *login=1;
			  strcpy(id,row[1]); 
				break;                    //=>이유:로그인 한사람만 다음페이지로
			}
		}	
}