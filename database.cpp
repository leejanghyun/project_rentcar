#include "Common.h"

MYSQL* conn_ptr=NULL;
MYSQL_RES* res=NULL; // ���� ��� �޴� ����
MYSQL_ROW row; //������ ���� ���� ������ ���� ����ִ� ����


static char Query1[QUERY_LEN]="select * from client ";  //////Ȯ�� ����
static char Query2[QUERY_LEN]="update client set login='";  ////��������

void initMYSQL(){
	// Mysql �� ����	
	conn_ptr = mysql_init(NULL);

	conn_ptr = mysql_real_connect(conn_ptr, HOST, USER, PASS, NAME, 3306, (char*)NULL, 0);
	mysql_query(conn_ptr,"set session character_set_connection=euckr;");
	mysql_query(conn_ptr,"set session character_set_results=euckr;");
	mysql_query(conn_ptr,"set session character_set_client=euckr;");
}
