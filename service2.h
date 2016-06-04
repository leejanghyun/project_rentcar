/////////////에러 메시지 함수+파일 건네주는 함수
static char protocol[]="HTTP/1.0 200 OK\r\n";
static char servName[]="Server:simple web server\r\n";
static char cntType[]="Content-type:text/html\r\n\r\n";

void ERRORMESSAGE(SOCKET sock);
char* ContentType(char* file);