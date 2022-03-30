#ifndef LOGIN_AND_REGISTER_GUARD__H 
#define LOGIN_AND_REGISTER_GUARD__H 

#define Max 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct bookUser
{
    char username[Max];
    char password[Max];
}bookuser;
char temp[Max];//临时的字符数组
char *Register(char *name);//用户注册
char *Login(char *name);//用户登录
#endif