#include "book_management.h"
#include "configure.h"

int count;//Array length

int load_books(FILE *file, BookArray *p)
{
    file = fopen(PATH_BOOK_MANAGEMENT, "r");
    count = 0;
    if(!file)
    {
        p->length = count;
        return -1;
    }
    p->array = (Book*)malloc(sizeof(Book));
    p->array->next = NULL;
    Book *temp = p->array;
    int a;
    while(1)
    {
        Book *node = (Book*)malloc(sizeof(Book));
        node->title = (char*) malloc(sizeof (char)*Max);
        node->authors = (char *) malloc(sizeof (char )*Max);
        a = fscanf(file, "%d %s %s %d %d", &(node->id), node->title, node->authors, &(node->year), &(node->copies));
        if(a != EOF)
        {
            node->next = NULL;
            temp->next = node;
            temp = temp->next;
            count++;
        }
        else
        {
            free(node);
            break;
        }
    }
    fclose(file);
    p->length = count;
    return 0;
}
int store_books(FILE *file, BookArray *p)
{
    file = fopen(PATH_BOOK_MANAGEMENT, "w");
    if(file == NULL)
        return -1;
    Book *temp = p->array;
    while(temp)
    {
        if(temp->year)
        {
            fprintf(file, "%d %s %s %d %d\n", temp->id, temp->title, temp->authors, temp->year, temp->copies);
            temp = temp->next;
        }
        else
            temp = temp->next;
    }
    fclose(file);
    return 0;
}
int add_book(Book *book)
{
    while(book->next)
        book = book->next;
    Book *temp = (Book*)malloc(sizeof(Book));
    temp->title = (char*) malloc(sizeof (char)*Max);
    temp->authors = (char *) malloc(sizeof (char )*Max);
    printf("ID:%d\n", book->id + 1);
    temp->id = book->id + 1;
    printf("Title:");
    scanf("%s", temp->title);
    getchar();
    printf("Authors:");
    scanf("%s", temp->authors);
    getchar();
    printf("Year:");
    scanf("%d", &(temp->year));
    getchar();
    printf("Copies:");
    scanf("%d", &(temp->copies));
    getchar();
    temp->next = NULL;
    book->next = temp;
    return 0;
}
int remove_book(Book *book)
{
    printf("\nPlease enetr you want to delete the book ID: ");
    int a;
    scanf("%d", &a);
    getchar();
    if(a > 1)
    {
        book = book->next;
        while(book->id != a-1)
        {
            book = book->next;
        }
        Book *del1 = book->next;
        book->next = book->next->next;
        free(del1);
    }
    if(a == 1)
    {
        Book *del2 = book->next;
        book->next = book->next->next;
        free(del2);
    }
    if(a < 1)
        return -1;
    book = book->next;
    while(book != NULL)
    {
        (book->id)--;
        book = book->next;
    }
    return 0;
}
BookArray *find_book_by_title (const char *title, BookArray *p)
{
    Book *temp = p->array->next;
    int n = 0;
    while(temp != NULL)
    {
        if(!strcmp(title, temp->title))
        {
            printf("ID:%d\n", temp->id);
            printf("Title:%s\n", temp->title);
            printf("Authors:%s\n", temp->authors);
            printf("Year:%d\n", temp->year);
            printf("Copies:%d\n\n", temp->copies);
            n = 1;
        }
        temp = temp->next;
    }
    if(n == 0)
        printf("\nSorry, there is no book you want to search!\n\n");
    return p;
}
BookArray *find_book_by_author (const char *author, BookArray *p)
{
    Book *temp = p->array->next;
    int n = 0;
    while(temp != NULL)
    {
        if(!strcmp(author, temp->authors))
        {
            printf("ID:%d\n", temp->id);
            printf("Title:%s\n", temp->title);
            printf("Authors:%s\n", temp->authors);
            printf("Year:%d\n", temp->year);
            printf("Copies:%d\n\n", temp->copies);
            n = 1;
        }
        temp = temp->next;
    }
    if(n == 0)
        printf("\nSorry, there is no book about author you want to search!\n\n");
    return p;
}
BookArray *find_book_by_year (unsigned int year, BookArray *p)
{
    Book *temp = p->array->next;
    int n = 0;
    while(temp != NULL)
    {
        if(year == temp->year)
        {
            printf("ID:%d\n", temp->id);
            printf("Title:%s\n", temp->title);
            printf("Authors:%s\n", temp->authors);
            printf("Year:%d\n", temp->year);
            printf("Copies:%d\n\n", temp->copies);
            n = 1;
        }
        temp = temp->next;
    }
    if(n == 0)
        printf("\nSorry, there is no book about year you want to search!\n\n");
    return p;
}
void display_book(BookArray *head)
{
    printf("ID\t");
    printf("Title\t");
    printf("Authors\t");
    printf("Year\t");
    printf("Copies\n");
    Book *temp = head->array->next;
    while(temp)
    {
        if(temp->year)
        {
            printf("%d\t", temp->id);
            printf("%s\t", temp->title);
            printf("%s\t", temp->authors);
            printf("%d\t", temp->year);
            printf("%d\n", temp->copies);
        }
        temp = temp->next;
    }
    return;
}
void free_book(BookArray *head)
{
    Book *temp;
    while(head->array)
    {
        temp = head->array;
        head->array = head->array->next;
        free(temp);
    }
    free(head);
    return;
}
//查找书籍函数
void search_for_book()
{
    while(1)
    {
        BookArray *temp = (BookArray*)malloc(sizeof(BookArray));
        FILE *file;
        load_books(file, temp);
        char string[Max];
        int year;
        printf("Please choose an option:\n");
        printf("1. Find books by title\n");
        printf("2. Find books by author\n");
        printf("3. Find books by year\n");
        printf("4. Return to previous menu\n");
        printf("Option:");
        char enter;
        //输入查找书的依据
        scanf("%c", &enter);
        getchar();
        switch(enter)
        {
            case '1':
            {
                printf("\nPlease enter book title:");
                scanf("%s", string);
                getchar();
                find_book_by_title(string, temp);
                break;
            }
            case '2':
            {
                printf("\nPlease enter author name:");
                scanf("%s", string);
                getchar();
                find_book_by_author(string, temp);
                break;
            }
            case '3':
            {
                printf("\nPlease enter book year:");
                scanf("%d", &year);
                getchar();
                find_book_by_year(year, temp);
                break;
            }
            case '4':
            {
                return;
            }
            default:
            {
                printf("\nInvalid input!\n\n");
                break;
            }
        }
        free_book(temp);
    }
}
//展示所有书籍
void display_all_books()
{
    FILE *file;
    BookArray *temp = (BookArray*)malloc(sizeof(BookArray));
    load_books(file, temp);
    display_book(temp);
    free_book(temp);
    return;
}
//书籍管理界面
void book_manager()
{
    while(1)
    {
        printf("(Logged in as: library)\n");
        printf("1. Add a book\n");
        printf("2. Remove a book\n");
        printf("3. Search for books\n");
        printf("4. Display all books\n");
        printf("5. Log out\n");
        printf("Option:");
        char enter;
        scanf("%c", &enter);
        getchar();
        switch(enter)
        {
            case '1':
            {
                FILE *file;
                BookArray *temp = (BookArray*)malloc(sizeof(BookArray));
                load_books(file, temp);
                printf("\nPlease enter the book content you want to add!\n");
                add_book(temp->array);
                store_books(file, temp);
                free_book(temp);
                break;
            }
            case '2':
            {
                FILE *file;
                BookArray *temp = (BookArray*)malloc(sizeof(BookArray));
                load_books(file, temp);
                printf("\nPlease enter the book content you want to delete!\n");
                remove_book(temp->array);
                store_books(file, temp);
                free_book(temp);
                break;
            }
            case '3':
            {
                search_for_book();
                break;
            }
            case '4':
            {
                display_all_books();
                break;
            }
            case '5':
            {
                return;
            }
            default:
            {
                printf("\nInvalid input!\n\n");
                break;
            }
        }
    }
}
