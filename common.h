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
#define CONTENT_SIZE 5000
#define MAX_SIZE 2048
#define HTML 10000
#define MIN_SIZE 300
#define SIZE 1000

extern char method[MAX_SIZE];
extern char ct[MIN_SIZE];
extern char fileName[MIN_SIZE];
extern char First_Header[MAX_SIZE];/////ù���� ��� �ڸ��� (ù��)
extern char Image[MIN_SIZE];
extern void SendData(SOCKET sock,char* reply,char* fileName);
//extern char* IP;

#define HOST "localhost"
#define USER "root"
#define PASS "apmsetup"
#define NAME "rentcar"  //////������ ���̽� �̸�
#define QUERY_LEN 100


static char Query1[QUERY_LEN]="select * from customer ";  //////Ȯ�� ����
static char Query2[QUERY_LEN]="update customer set login='";  ////��������
static char Query3[QUERY_LEN]="update customer set IP='";  ////��������


