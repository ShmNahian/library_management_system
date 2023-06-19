#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void password();
void hadline();
void mainMenu();
void addbook();
void booklist();
void searchbook();
void editbook();
void deletebook();
void help();

struct Book_info
{
    int id;
    char name[30];
    char author[30];
    int quantity;
    int rack;
};

struct Book_info a;
FILE *file,*file2;
int main()
{
    password();
}
void hadline()
{

    printf("\n \n\t\t ___library management project___\n\n\t \t");


}
void password()
{
    hadline();

    char pass1[30]= {"admin"};
    char pass2[30];
    printf("\n\t enter password:");
    scanf("%s",pass2);
    while(1)
    {
        if(strcmp(pass1,pass2)==0)
        {
            printf("\n \n\t match password\n");
            printf("\t press any key.....");
            break;
        }
        else
        {
            printf("\n\n\t try again password\n");
            scanf("\n\n \t%s",pass2);

        }
    }
    mainMenu();
}
void mainMenu()
{
    int n;
    printf("\n \n\t ____ mainMenu____\n");
    printf("\n\n\t 1. add book\n");
    printf("\n\n\t 2.Book list\n");
    printf("\n\n\t 3. search book\n");
    printf("\n\n\t 4.edit book\n");
    printf("\n\n\t 5. delete book\n");
    printf("\n\n\t 6. Help\n");
    printf("\n\n\t 7. exit\n");
    printf("\t\t---------------\n");
    printf("\n\n\t enter your choice: ");


    scanf("%d",&n);

    if(n==1)
    {
        printf("\n\n\t you want to add book\n");
        addbook();

    }


    else if(n==2)
    {
        printf("\n\n\t you want to book list\n");
        booklist();

    }

    else if(n==3)
    {
        printf("\n\n\t you want to search book\n");
        searchbook();

    }
    else if(n==4)
    {
        printf("\n\n\t you want to edit book\n");
        editbook();

    }
    else if(n==5)
    {
        printf("\n\n\t you want to delete book\n");
        deletebook();

    }
    else if(n==6)
    {
        printf("\n\n\t you want to Help\n");
        help();
    }
    else if(n==7)
    {
        printf("\n\n\t you want to exit\n");
        exit(0);
    }
    else
    {
        printf("your choice is wrong");
    }


}
void addbook()
{
    int d,count=0;
    printf("\n\n\t ____Add book____\n\n");
    file = fopen("books.dat","ab+");
    printf("\t\t enter ID:");
    scanf("%d",&d);
    rewind(file);
    while(fread(&a,sizeof(a),1,file)==1)
    {
        if(d==a.id)
        {
            printf("\n\n\t This book is already in lbirary....");
            count=1;

        }
    }
    if(count==1)
    {
        fflush(stdin);
        getchar();
        mainMenu();
    }
    a.id=d;
    printf("\n\t\t enter Name :");
    scanf("%s",a.name);
    printf("\n\t\t enter Author :");
    scanf("%s",a.author);
    printf("\n\t\t enter quantity :");
    scanf("%d",&a.quantity);
    printf("\n\t\t enter Rack :");
    scanf("%d",&a.rack);

    fseek(file,0,SEEK_END);
    fwrite(&a,sizeof(a),1,file);
    fclose(file);
    printf("\n\n\t\t add book sucessful");
    fflush(stdin);
    getchar();
    mainMenu();
}
void booklist()
{
    int count=0;
    printf("\n\n\t\t ******** Book list*****\n\n");
    printf("\tID\tName\tAuthor\tQunt\tRack\n\n");

    file = fopen("books.dat","rb");
    while(fread(&a,sizeof(a),1,file)==1)
    {
        printf("\t%d",a.id);
        printf("\t%s",a.name);
        printf("\t%s",a.author);
        printf("\t%d",a.quantity);
        printf("\t%d\n",a.rack);
        count = count +a.quantity;
    }
    fclose(file);
    printf("\n\t\t Total Books: %d",count);
    printf("\n\n\t\t press any key...");
    fflush(stdin);
    getchar();
    mainMenu();

}
void searchbook()
{
    int d,count=0;
    printf("\n\n\t\t****** search book*****\n");
    printf("\n\t\t seaeching___\n\n");
    file=fopen("books.dat","rb");
    printf("\n\t\t enter ID:");
    scanf("%d",&d);
    while(fread(&a,sizeof(a),1,file)==1)
    {
        if(a.id=d)
        {
            printf("\n\n\t\t Book is found\n");
            printf("\t\t ID:%d",a.id);
            printf("\n\t\t Name:%s",a.name);
            printf("\n\t\t Author:%s",a.author);
            printf("\n\t\t quantity:%d",a.quantity);
            printf("\n\t\t Rack:%d\n",a.rack);
            count = 1;
        }
    }
    if(count==0)
    {
        printf("\n\n Book is not found");
    }
    printf("\n\n\t\t press any key");
    fflush(stdin);
    getchar();
    mainMenu();

}
void editbook()
{
    int d,count=0;
    printf("\n\n\t\t****** edit book*****\n");

    file=fopen("books.dat","rb+");
    printf("\n\t\t enter ID:");
    scanf("%d",&d);
    while(fread(&a,sizeof(a),1,file)==1)
    {
        if(a.id=d)
        {
            printf("\n\n\t\t Book is availble\n");
            printf("\t\t ID:%d",a.id);
            printf("\n\t\t enter new name:");
            scanf("%s",a.name);
            printf("\n\t\t enter new Author:");
            scanf("%s",a.author);
            printf("\n\t\t enter new quantity:");
            scanf("%d",&a.quantity);
            printf("\n\t\t enter new Rack:");
            scanf("%d",&a.rack);

            fseek(file,ftell(file)-sizeof(a),0);
            fwrite(&a,sizeof(a),1,file);
            fclose(file);
            count = 1;

        }

    }
    if(count==0)
    {
        printf("\n\n Book is not found");
    }
    printf("\n\n\t\t press any key");
    fflush(stdin);
    getchar();
    mainMenu();



}

void deletebook()
{
    int d,count=0;
    printf("\n\n\t\t****** delete book*****\n");
    printf("\n\n\t\t enter ID for delete book :");


    scanf("%d",&d);
    file = fopen("books.dat","rb+");
    rewind(file);
    while(fread(&a,sizeof(a),1,file)==1)
    {
        if(a.id=d)
        {
            printf("\n\n\t\t Book is Availble");

            printf("\n\t\t book Name is:%s",a.name);

            printf("\n\t\t Rack no:%d\n",a.rack);
            count = 1;
        }
    }
    if(count==0)
    {
        printf("\n\n Book is not availble");
    }
    else
    {
        file2=fopen("text.dat","wb+");
        rewind(file);
        while(fread(&a,sizeof(a),1,file)==1);
        {
            if(d!= a.id)
            {
                fseek(file2,ftell(file2)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,file2);
            }
        }
        fclose(file);
        fclose(file2);
        remove("books.dat");
        rename("text.dat","books.dat");
        file=fopen("books.dat","rb+");
        fclose(file);

    }
    printf("\n\n\t\t press any key");
    fflush(stdin);
    getchar();
    mainMenu();

}

void help()
{
    printf("\n\n\t\t ****** help section*****\n\n");
    printf("\n\t\t 1.This is a simple library project\n\n");
    printf("\n\t\t 2.Password is: admin\n\n");
    printf("\n\t\t 3.you can add book in library\n\n");
    printf("\n\t\t 4.see all feature under main menu\n\n");
    printf("\n\t\t 5.you can use all of them\n\n");
    printf("\n\t\t  Thank you\n\n");

    printf("\n\n\t\t press any key");
    fflush(stdin);
    getchar();
    mainMenu();
}

