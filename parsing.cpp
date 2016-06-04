#include "Common.h"

int Parsing_Image(char* header){
	char* Last_HTML_File=NULL;////
	strcpy(method, strtok(header," /"));////전체 패킷문입니다.
	
	while(1){/////////////////ex) .html/.html/...있을때 마지막 .html뽑기위한과정 입니다.
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