
void Parsing_for_chat(SOCKET Clntsock,char* ct,char* Data,char* IP,char* id){
	MYSQL* conn_ptr=NULL; // mysql ���� ���� ���
    MYSQL_RES* res=NULL; // ���� ��� �޴� ����
    MYSQL_ROW row; //������ ���� ���� ������ ���� ����ִ� ����
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
	mysql_query(conn_ptr, Query);//////////////////DV�� send�� ���� �޽��� ID�� Question ����

	question_html(Clntsock,ct,id,1);
}
