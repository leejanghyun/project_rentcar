#include "Common.h"

void Cookie(int* login ,char* ip,char* id){
	MYSQL* conn_ptr=NULL; // mysql ���� ���� ���
    MYSQL_RES* res=NULL; // ���� ��� �޴� ����
    MYSQL_ROW row; //������ ���� ���� ������ ���� ����ִ� ����

	initMYSQL(&conn_ptr);
	mysql_query(conn_ptr, Query1);
	res = mysql_store_result(conn_ptr); 

	while ((row=mysql_fetch_row(res))!=NULL)
		{
			if(!strcmp(ip,row[0]) && (atoi(row[3])==1)){      /////////////id pw �� ��ġ�ϴ��� �˻� row[1]:id row[2]:pw
			  *login=1;
			  strcpy(id,row[1]); 
				break;                    //=>����:�α��� �ѻ���� ������������
			}
		}	
}