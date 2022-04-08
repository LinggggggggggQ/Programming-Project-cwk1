#include "Login_and_register.h"
#include "configure.h"
char temp[Max];//临时的字符数组
#ifdef PARAM_SUP
extern char* _USER_INFO_PATH;
#endif

//注册函数
char *Register(char *name)
{
    bookuser a,b;//a用来储存现有的账号密码,b用来储存以前的账号密码
    FILE *fp;
#ifdef PARAM_SUP
    fp = fopen(_USER_INFO_PATH,"r");
#elif
    fp = fopen(PATH_USERINFO,"r");
#endif
    fscanf(fp, "%s %s", b.username, b.password);//读一个结构体字符块到b
    printf("Please enter a username: ");
    scanf("%s", a.username);//输入用户名
    getchar();//清空缓存区
    while(1)//判断现存用户与新注册用户是否重复
    {
        if(strcmp(a.username, b.username))//用户名不相等
        {
            if(!feof(fp))//测试文件是否读取完毕
            {
                strcpy(b.username, "");
                strcpy(b.password, "");
                fscanf(fp, "%s %s", b.username, b.password);
            }
            else
                break;
        }
        else//用户名相等
        {
            printf("\nSorry, registration unsuccessful, the username you entered already exists\n\n");
            return name;
        }
    }
    fclose(fp);
    printf("Please enter a password: ");
    scanf("%s", a.password);
    getchar();//清空缓存区
    printf("Please confirm your password: ");
    scanf("%s", temp);
    getchar();
    while(1)
    {
        if(strcmp(a.password, temp) == 0)//密码相等
        {
#ifdef PARAM_SUP
            fp = fopen(_USER_INFO_PATH,"a");
#elif
            fp = fopen(PATH_USERINFO,"a");
#endif
            fprintf(fp, "%s %s\n", a.username, a.password);
            printf("\nregistration success!\n\n");
            fclose(fp);
            strcpy(name, a.username);
            //登录成功，返回上一级菜单
            return name;
        }
        else//密码不相等
        {
            printf("\nSorry, the two passwords do not match! please enter again!\n\n");
            strcpy(a.password, "");
            printf("Please enter a password: ");
            scanf("%s", a.password);
            getchar();
            printf("Please confirm your password: ");
            strcpy(temp, "");
            scanf("%s", temp);
            getchar();
        }
    }
}
//登录函数
char *Login(char *name)
{
    bookuser a,b;//a用来储存已有的用户名，b用来储存输入的
    FILE *fp = NULL;
#ifdef PARAM_SUP
    fp = fopen(_USER_INFO_PATH,"r");
#elif
    fp = fopen(PATH_USERINFO,"r");
#endif
    fscanf(fp, "%s %s", a.username, a.password);
    printf("Please enter your username: ");
    scanf("%s", b.username);
    getchar();
    while(1)
    {
        if(!strcmp(a.username, b.username))//输入的用户名存在就退出
            break;
        else//不存在就继续找
        {
            if(!feof(fp))//判断文件是否读取完毕
            {
                strcpy(a.username, "");
                strcpy(a.password, "");
                fscanf(fp, "%s %s", a.username, a.password);
            }
            else
            {
                printf("User dose not exist.\n");
                fclose(fp);
                return name;
            }
        }
    }
    printf("Please enter your password: ");
    scanf("%s", b.password);
    getchar();
    while(1)
    {
        if(!strcmp(a.password, b.password))//密码相等
        {
            fclose(fp);
            printf("\nLogin successfully\n\n");
            strcpy(name, b.username);
            //登录成功，返回上一级菜单
            return name;
        }
        else
        {
            printf("Wrong password!\nPlease enter your password again: ");
            strcpy(b.password, "");//清空之前输入的字符
            scanf("%s", b.password);
            getchar();
            getchar();
        }
    }
}
