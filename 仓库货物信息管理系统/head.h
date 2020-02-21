/***********************************
    @名称：仓库货物信息管理系统设计
    @author：super-so,。。。。,骚白
    @create：2019.12.30~2019.12.31
************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define N 100

int  users();
void menu();
int  dataout();
void datain(int i);
void read(int i);
void query(int i);
void change(int i);
void sort(int i);
int  in(int i);
void out(int i);
int  clear(int i);

int sign = 1;                    //警示作用，返回0，打开文件失败
int hang = 0;

struct goods                    //
{
    int num;					//编号
    char name[100];				//名称
    char category[100];			//类别
    char specifications[100];	//规格
    char manufactor[100];		//厂家
    char area[100];				//产地
    int  inventory;				//库存量
};

struct users
{
    char zh[20];                //管理员账号
    char password[50];          //管理员密码
};

struct goods goods[N];
struct users Users[N];
