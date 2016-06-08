#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;
#include <Windows.h>
#include <mysql.h>
#include <process.h>
#include "service2.h"
#include "Parsing.h"
#include "DataBase.h"
#include "Cookie.h"
#include "html.h"
#define CONTENT_SIZE 10000
#define MAX_SIZE 2048
#define HTML 5000
#define MIN_SIZE 300
#define SIZE 1000

extern char method[MAX_SIZE];
extern char ct[MIN_SIZE];
extern char fileName[MIN_SIZE];
extern char First_Header[MAX_SIZE];/////첫번쨰 헤더 자를떄 (첫줄)
extern char Image[MIN_SIZE];
extern void SendData(SOCKET sock,char* reply,char* fileName);
//extern char* IP;

#define HOST "localhost"
#define USER "root"
#define PASS "apmsetup"
#define NAME "rentcar"  //////데이터 베이스 이름
#define QUERY_LEN 100


static char Query1[QUERY_LEN]="select * from customer ";  //////확인 쿼리
static char Query2[QUERY_LEN]="update customer set login='";  ////변경쿼리
static char Query3[QUERY_LEN]="update customer set IP='";  ////변경쿼리
static char Query4[QUERY_LEN]="select * from rent ";
static char Query5[QUERY_LEN]="select * from question";
static char Query6[QUERY_LEN]="alter question auto_increment=0";



