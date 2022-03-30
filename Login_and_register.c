#include "Login_and_register.h"


char *Register(char *name)
{
	bookuser a,b;//a用来储存现有的账号密码,b用来储存以前的账号密码
	FILE *fp;
	fp = fopen("Userinfo.txt","r");
	fscanf(fp, "%s %s", b.username, b.password);//读一个结构体字符块到b
	printf("Please enter a username: ");
	scanf("%s", a.username);//输入Id
	getchar();
	while(1)
	{
		if(strcmp(a.username, b.username))//用户名不相等
		{
			if(!feof(fp))
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
			//返回主菜单
			//meun();
			return name;
		}
	}
	fclose(fp);
	printf("Please enter a password: ");
	scanf("%s", a.password);
	getchar();
	printf("Please confirm your password: ");
	scanf("%s", temp);
	getchar();
	while(1)
	{
		if(strcmp(a.password, temp) == 0)//密码相等
		{
			fp = fopen("Userinfo.txt", "a");
			fprintf(fp, "%s %s\n", a.username, a.password);
			printf("\nregistration success!\n\n");
			fclose(fp);
			//进入借阅界面
			strcpy(name, a.username);
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
char *Login(char *name)
{
	bookuser a,b;//a用来储存已有的用户名，b用来储存输入的
	FILE *fp = NULL;
	fp = fopen("Userinfo.txt", "r");
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
			if(!feof(fp))//文件后还有内容
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
			return name;
		}
		else
		{
			printf("Wrong password!\nPlease enter your password again: ");
			strcpy(b.password, "");
			scanf("%s", b.password);
			getchar();
			getchar();
		}
	}
}