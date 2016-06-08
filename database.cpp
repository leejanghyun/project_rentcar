#include "Common.h"


void initMYSQL(MYSQL** conn_ptr){
	// Mysql ¿¡ ¿¬°á	
	*conn_ptr = mysql_init(NULL);

	*conn_ptr = mysql_real_connect(*conn_ptr, HOST, USER, PASS, NAME, 3306, (char*)NULL, 0);
	mysql_query(*conn_ptr,"set session character_set_connection=euckr;");
	mysql_query(*conn_ptr,"set session character_set_results=euckr;");
	mysql_query(*conn_ptr,"set session character_set_client=euckr;");

}
