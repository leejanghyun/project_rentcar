#include "Common.h"

int Parsing_Image(char* header){
	char* Last_HTML_File=NULL;////
	strcpy(method, strtok(header," /"));////��ü ��Ŷ���Դϴ�.
	
	while(1){/////////////////ex) .html/.html/...������ ������ .html�̱����Ѱ��� �Դϴ�.
	char * Image_File=strtok(NULL," /");
	    if(strstr(Image_File,".html")==NULL){
			strcpy(fileName,Last_HTML_File);
			strcpy(Image,Image_File);
			break;
	    }
		Last_HTML_File=Image_File;
	}

	
	strcpy(ct,ContentType(fileName));///Content-Type Ȯ��

	return 1;
}