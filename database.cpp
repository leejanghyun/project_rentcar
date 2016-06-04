#include "Common.h"

MYSQL* conn_ptr=NULL;
MYSQL_RES* res=NULL; // 쿼리 결과 받는 변수
MYSQL_ROW row; //쿼리에 대한 실제 데이터 값이 들어있는 변수


static char Query1[QUERY_LEN]="select * from client ";  //////확인 쿼리
static char Query2[QUERY_LEN]="update client set login='";  ////변경쿼리

void initMYSQL(){
	// Mysql 에 연결	
	conn_ptr = mysql_init(NULL);

	conn_ptr = mysql_real_connect(conn_ptr, HOST, USER, PASS, NAME, 3306, (char*)NULL, 0);
	mysql_query(conn_ptr,"set session character_set_connection=euckr;");
	mysql_query(conn_ptr,"set session character_set_results=euckr;");
	mysql_query(conn_ptr,"set session character_set_client=euckr;");
}
