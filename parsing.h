int Parsing_Image(char* header);
void Parsing_for_login(SOCKET Clntsock,char* ct,char* message,char*IP);
void Parsing_for_join(SOCKET Clntsock,char* ct,char* message ,char* IP);
void Parsing_for_logout(SOCKET Clntsock,char* ct,char* Data,char* IP);
void Parsing_for_rent(SOCKET Clntsock,char* ct,char* Data,char* IP,char* id);
void Parsing_for_reserve(SOCKET Clntsock,char* ct,char* Data,char* id);
void Parsing_for_cancel(SOCKET Clntsock,char* ct,char* Data,char* IP,char* id);
void Parsing_for_chat(SOCKET Clntsock,char* ct,char* Data,char* IP,char* id);