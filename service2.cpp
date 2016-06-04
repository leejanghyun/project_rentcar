#include "Common.h"


void ERRORMESSAGE(SOCKET sock){
	char protocol[]="HTTP/1.0 400 Bad Request\r\n";
	char cntLen[]="Contenet-length:2048\r\n";
	char content[]="<html><head><title>HTTP 프로토콜로 작성 해주시기 바랍니다.</title></head>";
	send(sock,protocol,strlen(protocol),0);
	send(sock,servName,strlen(servName),0);
	send(sock,cntLen,strlen(cntLen),0);
	send(sock,cntType,strlen(cntType),0);
	send(sock,content,strlen(content),0);
	closesocket(sock);
}


char* ContentType(char* file){
	char extension[MIN_SIZE];
	char fileName[MIN_SIZE];
	strcpy(fileName,file);
	strtok(fileName,".");
	strcpy(extension,strtok(NULL,"."));
	if(!strcmp(extension,"html")||!strcmp(extension,"htm"))
		return "text/html";
	else
		return "text/plain";

}
