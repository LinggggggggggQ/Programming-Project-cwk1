#ifndef USER_GUARD_H
#define USER_GUARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 1000
typedef struct User
{
    char account[Max];
    char book1[Max];
    char book2[Max];
    char book3[Max];
    struct User *next;
}user;
int return_book(user *book, char *string);//还书 string表示书名,book表示用户节点
int borrow_book(user *book, char *string);//借书 string表示书名，book表示用户节点
int store_books_user(FILE *file, user *book);//储存
user *init_userbook(FILE *file);//初始化链表
void free_user(user *book);//释放内存
void user_interface(char *name);//用户界面
#endif
