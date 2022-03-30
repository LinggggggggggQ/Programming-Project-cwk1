#include "User.h"
#include "book_management.h"


user *init_userbook(FILE *file)
{
	file = fopen("user_book.txt","r");
	user *head = (user*)malloc(sizeof(user));
	fscanf(file, "%s %s %s %s", head->account, head->book1, head->book2, head->book3);
	head->next = NULL;
	user *node = NULL;
	user *end = NULL;
	end = head;
	int a;
	while(1)
	{
		node = (user*)malloc(sizeof(user));
		a = fscanf(file, "%s %s %s %s", node->account, node->book1, node->book2, node->book3);
		if(a != EOF)
		{
			end->next = node;
			end = node;
		}
		else
		{
			free(node);
			break;
		}
	}
	end->next = NULL;
	return head;
}

int store_books_user(FILE *file, user *book)
{
	file = fopen("user_book.txt", "w");
	user *temp = book;
	while(temp != NULL)
	{
		if(temp->account != NULL)
		{
			fprintf(file, "%s %s %s %s\n", temp->account, temp->book1, temp->book2, temp->book3);
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	fclose(file);
	return 0;
}
void free_user(user *book)
{
	user *temp = book;
	user *p;
	while(temp != NULL)
	{
		p = temp;
		temp = temp->next;
		free(p);
	}
}
int return_book(user *book, char *string)
{
	if(!strcmp(book->book1, "empty"))
	{
		printf("\nSorry, you did not borrow this book!\n\n");
		return 0;
	}
	else
	{
		if(!strcmp(book->book1, string))
		{
			strcpy(book->book1, book->book2);
			strcpy(book->book2, book->book3);
			strcpy(book->book3, "empty");
			printf("\nCongratulations! Returned successfully!\n\n");
			return 1;
		}
	}
	/////////
	if(!strcmp(book->book2, "empty"))
	{
		printf("\nSorry, you did not borrow this book!\n\n");
		return 0;
	}
	else
	{
		if(!strcmp(book->book2, string))
		{
			strcpy(book->book2, book->book3);
			strcpy(book->book3, "empty");
			printf("\nCongratulations! Returned successfully!\n\n");
			return 1;
		}
	}
	///////
	if(!strcmp(book->book3, "empty"))
	{
		printf("\nSorry, you did not borrow this book!\n\n");
		return 0;
	}
	else
	{
		if(!strcmp(book->book1, string))
		{
			strcpy(book->book1, book->book2);
			strcpy(book->book2, book->book3);
			strcpy(book->book3, "empty");
			printf("\nCongratulations! Returned successfully!\n\n");
			return 1;
		}
		else
		{
			printf("\nSorry, you did not borrow this book!\n\n");
			return 0;
		}
	}
}
int borrow_book(user *book, char *string)
{
	if(!strcmp(book->book1, "empty"))
	{
		strcpy(book->book1, string);
		printf("\nCongratulations! Borrowed successfully!\n\n");
		return 1;
	}
	else
	{
		if(!strcmp(book->book1, string))
		{
			printf("\nSorry, you have borrowed this book!\n\n");
			return 0;
		}
	}
	/////
	if(!strcmp(book->book2, "empty"))
	{
		strcpy(book->book2, string);
		printf("\nCongratulations! Borrowed successfully!\n\n");
		return 1;
	}
	else
	{
		if(!strcmp(book->book2, string))
		{
			printf("\nSorry, you have borrowed this book!\n\n");
			return 0;
		}
	}
	////////
	if(!strcmp(book->book3, "empty"))
	{
		strcpy(book->book3, string);
		printf("\nCongratulations! Borrowed successfully!\n\n");
		return 1;
	}
	else
	{
		if(!strcmp(book->book3, string))
		{
			printf("\nSorry, you have borrowed this book!\n\n");
			return 0;
		}
		else
		{
			printf("\nSorry, you have borrowed three books!\n");
			printf("Everyone only borrows three books at most!\n\n");
			return 0;
		}
	}
}