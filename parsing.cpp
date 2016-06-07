
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
