#include "interface.h"

#include "book_management.h"
#include "Login_and_register.h"
#include "User.h"
#include "configure.h"
int st;
char name[Max];
//借阅函数
void user_interface(char *name)
{
    while(1)
    {
        printf("(Logged in as:%s)\n", name);
        printf("1. Borrow a book\n");
        printf("2. Return a book\n");
        printf("3. Search for books\n");
        printf("4. Display all books\n");
        printf("5. Log out\n");
        printf("Option:");
        char enter;
        //用户进行选择
        scanf("%c", &enter);
        getchar();
        switch(enter)
        {
            //用户选择为1，进入借书功能
            case '1':
            {
                FILE *file;
                file = fopen(PATH_USER_BOOK, "a");
                fprintf(file, "%s %s %s %s\n", name, "empty", "empty", "empty");
                fclose(file);
                //初始化用户所借书籍
                user *temp = init_userbook(file);
                while(strcmp(temp->account, name))
                    temp = temp->next;
                printf("\nPlease enter the book name:");
                char string[Max];
                //输入所借书的书名
                scanf("%s", string);
                getchar();
                borrow_book(temp, string);
                store_books_user(file, temp);
                free_user(temp);
                break;
            }
            //用户选择为2，进入还书功能
            case '2':
            {
                FILE *file;
                user *temp = init_userbook(file);
                while(strcmp(temp->account, name))
                    temp = temp->next;
                printf("\nPlease enter the book name:");
                char string[Max];
                scanf("%s", string);
                getchar();
                return_book(temp, string);
                store_books_user(file, temp);
                free_user(temp);
                break;
            }
            //用户选择3，进入查找书籍界面
            case '3':
            {
                search_for_book();
                break;
            }
            //用户选择4，展示所有书籍
            case '4':
            {
                display_all_books();
                break;
            }
            case '5':return;
            default:
            {
                printf("Invalid input!");
                break;
            }
        }
    }
}

void run_interface()
{
    st = 0;
    while(st == 0)
    {
        printf("Please choose an option:\n");
        printf("1. Register an account\n");
        printf("2. Login\n");
        printf("3. Search for books\n");
        printf("4. Display all books\n");
        printf("5. Quit\n");
        printf("Option:");
        char enter;
        scanf("%c", &enter);//用户输入选项（字符型）
        getchar();//清空缓存区
        strcpy(name, "");
        switch(enter)
        {
            //用户选择1，进入注册界面
            case '1':
            {
                Register(name);
                if(strcmp(name, ""))
                    //进入借阅界面
                    user_interface(name);
                break;
            }
            //用户选择2，进入登录界面
            case '2':
            {
                Login(name);
                if(strcmp(name, ""))
                {
                    if(!strcmp(name, "library"))
                        book_manager();
                    else
                        user_interface(name);
                }
                break;
            }
            //用户选择3，进入查找书界面
            case '3':
            {
                search_for_book();
                break;
            }
            //用户选择4，展示库中所有书籍
            case '4':
            {
                display_all_books();
                break;
            }
            //用户选择5，退出系统
            case '5':return;
            //用户选择错误，显示错误语句，并结束程序
            default:
            {
                printf("\nInvalid input!\n");
                break;
            }
        }
    }
}