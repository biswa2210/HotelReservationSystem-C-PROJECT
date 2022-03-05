 /****Hotel Management System*****/
/*HEADER FILES*/
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
/*
CREATED BY BISWARUP BHATTACHARJEE
EMAIL    : bbiswa471@gmail.com
PHONE NO : 6290272740
*/
/*Global Variable Declaration*/
int main_exit;
struct CustomerDetails   //STRUCTURE DECLARATION
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;
/*Functions (Declaration)*/
void greetings();
void holding();
void signin();
void menu();
void credits();
void add();
void list();
void find();
void deletee();
void add_cus_menu();
void close();
/*Functions (Definition)*/
void close()
{
    system("cls");
    printf("\n\n\n\t\tCurrent Time :: ");
    system("echo %time%");
      printf("\n\n\n\t\tCurrent Date :: ");
      system("echo %date%");
    printf("\n\n\n\n\t\tHave nice day Sir....\n\n\n\n");
    Sleep(2000);
    exit(0);
}
void add_cus_menu()
{
    char b;
        system("color f");
    system("cls");
printf("\n\t\t\t%c\t\t%c\n\t\t\t%c\t\t%c\n\t\t\t%c\t\t%c\n\t\t\t%c\t\t%c\n\t\t\t%c\t\t%c\n\t\t\t%c\t\t%c\n\t\t\t%c\t\t%c\n\t\t",178,178,178,178,178,178,178,178,178,178,178,178,178,178);

printf("|--------------------------------\n\t\t||\t\t\t\t|");
printf("\n\t\t||\t\t\t\t|\n\t\t||\t\t\t\t|\n\t\t|");

printf("-----> 1.");

printf("BOOK A ROOM");

printf("\t\t|");

printf("\n\t\t||\t\t\t\t%c\n\t\t||\t\t\t\t%c\n\t\t|",31,30);

printf("-----> 2.");

printf("SEARCH RECORD\t");
printf("\t|");

printf("\n\t\t||\t\t\t\t%c\n\t\t||\t\t\t\t%c\n\t\t|",31,30);

printf("-----> 3.");
printf("MENU            ");
printf("\t|");
printf("\n\t\t||\t\t\t\t|\n\t\t||\t\t\t\t|\n\t\t|--------------------------------\n\n\n");
printf("\t\t\t>><<ENTER CHOICE>><<");
while(1)
{
    b=getche();
		b=toupper(b);
switch(b)
{
    case '1': add();
                    break;
    case '2': find();
                    break;
    case '3': menu();
                    break;
}
}
}
void add()
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}


		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");

		printf("\n \n\nEnter Room number : ");

		scanf("\n%s",s.roomnumber);
		fflush(stdin);

		printf("\n\nEnter Name : ");

		scanf("%s",s.name);

		printf("\n\nEnter Address :");
		scanf("%s",s.address);

		printf("\n\nEnter Phone Number : ");

		scanf("%s",s.phonenumber);
		printf("\n\nEnter Nationality : ");
		scanf("%s",s.nationality);
		printf("\n\nEnter Email : ");
		scanf(" %s",s.email);
		printf("\n\nEnter Period(\'x\'days) :  ");
		scanf("%s",&s.period);
		printf("\n\nEnter Arrival date(dd\mm\yyyy): ");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);

		printf("\n\n\n   ---> 1 Room is successfully booked!!\a\a\n\n");
fclose(f);
                       add_invalid2:
    printf("\n\n\n\t\tEnter 1 to  again book a room ,2 to back and 0 to main menu : ");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       add();
    else if(main_exit==0)
            menu();
                else if(main_exit==2)
            add_cus_menu();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid2;
        }



}
void list()
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ROOM    ");
	printf("NAME\t\t ");
	printf("ADDRESS ");
	printf("\t\tPHONENUMBER ");
	printf("\t\tNATIONALITY \n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		/*printf("ROOMNUMBER :\t%s\n",s.roomnumber);
		printf("NAME:\t%s\n",,s.name);
		printf("ADDRESS:\t%s\n",s.address);
		printf("PHONENUMBER:\t%s\n",s.phonenumber);
		printf("NATIONALITY \n");*/
		printf("\n\n%s \t%s \t\t%s \t\t%s \t\t%s  \t\n",s.roomnumber, s.name , s.address , s.phonenumber ,s.nationality ,s.email,s.period,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);

        system("color a");
        Sleep(1000);
        system("color b");
        Sleep(1000);
        system("color c");
        Sleep(1000);
        system("color d");
        Sleep(1000);
        system("color e");
        Sleep(1000);
        system("color f");
        Sleep(1000);

						                       add_invalid5:

    printf("\n\n\n\t\tEnter 1 to  exit and 0 to main menu : ");

    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
    close();
    else if(main_exit==0)
            menu();
    else
        {
            printf("\n\n\n\t\t\tInvalid!\a");
            goto add_invalid5;
        }

	getch();
}
void deletee()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");

	printf("\n\tEnter the Room Number of the hotel to be deleted from the database  ::   ");
	fflush(stdin);

	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{

		printf("\n\n\n\tRecords of Customer in this  Room number is not found!!");
		//remove("E:/file.txt");
	   //rename("E:/temp.txt","E:/file.txt");
		getch();
		fclose(f);
		fclose(t);
					                       add_invalid6:

    printf("\n\n\n\t\tEnter 1 to  try again and 0 to main menu : ");

    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
    deletee();
    else if(main_exit==0)
            menu();
    else
        {
            printf("\n\n\n\t\t\tInvalid!\a");
            goto add_invalid6;
        }

	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\n\n\tThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
				                       add_invalid4:

    printf("\n\n\n\t\tEnter 1 to  delete again and 0 to main menu : ");

    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       deletee();
    else if(main_exit==0)
            menu();
    else
        {
            printf("\n\n\n\t\t\tInvalid!\a");
            goto add_invalid4;
        }

	getch();
}

void find()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);

	printf("\n\n   Enter Room number of the customer to search its details ::  ");

	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;

			printf("\n\t   Record Found %c !!!! %c \n\n\n ",1,1);

			printf("\n\n   Room Number:");
			printf("\t\t%s",s.roomnumber);

			printf("\n\n   Name:\t\t");

			printf("%s",s.name);

			printf("\n\n   Address:");

			printf("\t\t%s",s.address);

			printf("\n\n   Phone number:");

			printf("\t%s",s.phonenumber);

			printf("\n\n   Nationality:");

			printf("\t\t%s",s.nationality);

			printf("\n\n   Email:\t");

			printf("\t%s",s.email);

			printf("\n\n   Period:\t");

			printf("\t%s",s.period);

			printf("\n\n   Arrival date:");

			printf("\t%s",s.arrivaldate);
			flag=0;
			                       add_invalid3:

    printf("\n\n\n\t\tEnter 1 to  again search ,2 to back and 0 to main menu : ");

    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       find();
    else if(main_exit==0)
            menu();
                else if(main_exit==2)
            add_cus_menu();
    else
        {
            printf("\n\n\n\t\t\tInvalid!\a");
            goto add_invalid3;
        }

		}
	}
	if(flag==1){

		printf("\n\tRequested Customer could not be found!");
		                       add_invalid2:

    printf("\n\n\n\t\tEnter 1 to  again search,2 to back and 0 to main menu : ");

    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       find();
    else if(main_exit==0)
            menu();
                else if(main_exit==2)
            add_cus_menu();
    else
        {
            printf("\n\n\n\t\t\tInvalid!\a");
            goto add_invalid2;
        }

	}
	getch();
	fclose(f);
}
void greetings()
{
    system("mode 1000");
	system("cls");   // FOR CLEARING SCREEN

	printf("\n\n\n\n\n\n\n \t|----------------------------------------------------------------------------------*\n");
	printf("\t|                                                                         |\n");
	printf("\t|                                                                         |\n");

	printf("\t|  $$$$$$   $$$$$$ $$$$$$ $$$$$$ $$$$$$ $$$$$$ $      $ $$$$$$$  $$$$$$   |\n");
	printf("\t|  $        $    $ $      $        $      $    $ $    $ $        $        |\n");
	printf("\t|  $  $$$$$ $$$$$$ $$$$$  $$$$$    $      $    $  $   $ $  $$$$$ $$$$$$   |\n");
	printf("\t|  $    $   $  $   $      $        $      $    $   $  $ $    $        $   |\n");
	printf("\t|  $$$$$$   $   $  $$$$$$ $$$$$$   $    $$$$$$ $    $ $ $$$$$$   $$$$$$   |\n");
	printf("\t|                                                                         |\n");

	printf("\t|----------------------------------------------------------------------------------*\n\n\n\n\t\t\t\t");
	//Sleep(5000);

	system("pause");
}
void holding()
{
    system("cls");
    	printf("\n\n\n\n\n\n\n\n\n");

 	printf("\t\t*************************************************\n");
	printf("\t\t*                                               *\n");

	printf("\t\t*       -----------------------------           *\n");

	printf("\t\t*        WELCOME TO HOTEL");

	printf(" ROYAL ORBIT");

	printf("           *\n");

	printf("\t\t*       -----------------------------           *\n");

	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n\n\n\t\t\t");
	system("pause");
}
void signin()
{

	int a=1,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="MACK";
    char pass[10]="UEMK";
    do
{
	system("cls");

    printf("\n\t**************************  LOGIN FORM  **************************  ");

    printf("\n\n\n\tYOU HAVE ONLY TWO CHANCE TO LOGIN , SO BE CAREFUL TO LOGIN...\n\n\n");

    printf("\n                    ENTER USERNAME:-  ");

	scanf("%s", &uname);

	printf(" \n\n                    ENTER PASSWORD:- ");
	while(1)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13)
            break;
	    else
	     printf("|*|");
	    i++;
	}
	pword[i]='\0';

	i=0;
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{

	printf("  \n\n\n     \t \t    WELCOME \n\n     \t \t    !!!!LOGIN IS SUCCESSFUL!!!!! ");
    Sleep(3000);
	break;
	}
	else
	{

		printf("\n\n\n     \t \tSORRY  !!!!   LOGIN IS UNSUCESSFUL !!!\a\a\a");
		Sleep(2000);
		a++;
		continue;
	}
}
	while(a<=2);
	if (a>2)
	{

		printf("\n\n\n\n     \t \tSorry you have entered the wrong username and \n\n   \t\t   password for three times!!!");
        Sleep(5000);
        exit(0);
		getch();

		}
		system("cls");
}
void menu()
{

    int choice;
    printf("\n\nMenu\n***********\n\n1 ---------> ADD NEW CUSTOMER\n\n2 ---------> ALL CUSTOMERS LIST \n\n3 ---------> DELETE RECORD\n\n4 ---------> Exit\n\n");
  printf("Enter your choice ::  ");

  scanf("%d",&choice);
  switch(choice)
  {
       case 1: add_cus_menu();
          break;
        case 2: list();
          break;
        case 3: deletee();
          break;
        case 4: close;
          break;
          default: printf("\n\nInvalid Input !!! \a\a\a");
          break;
  }
}
void credits()
{
    system("cls");
             system("color b");
             printf("\n\n\n\n\t\t\t\tLoading\n\n");
Sleep(1000);
    printf("\t\t\t|||||");
    Sleep(1000);
    printf("||||||||||");
    Sleep(1000);
    printf("||||||||||");
    Sleep(2000);
    system("cls");
    system("color e");
    printf("\t|    Group Members    |");

    printf("\n*--------------------------------------------*\n");

    printf("|\n|\tROLL       STUDENT NAME\n|\n|\n|\t17  ----> HARSHITA SHARMA\n|\n|\t18  ----> BISWARUP BHATTACHARJEE \n|\n|\t19  ----> SANDIP MAHATO \n|\n|\t20  ----> PRITILIMA KUMAR\n|\n|");

    printf("\n*--------------------------------------------*\n");

                         add_invalid:

    printf("\n\n\n\tEnter 1 to main menu : ");

    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
       menu();
    else
        {
            printf("\n\n\tInvalid!\a");
            goto add_invalid;
        }
}
/*Main Function*/
int main()
{
    printf("\n\n\n\n\n\n\n\t\t\tHOTEL RESERVATION SYSTEM");
        Sleep(3000);
    system("cls");
    printf("\n\n\n\n\n\t\t\t\tDON'T USE SPACE  FOR GAPPING IN RUNTIME INPUT\n\n\t\t\t\tYOU CAN USE '-' OR '_' FOR GAPPING...");
    Sleep(5000);
    greetings();
    holding();
    signin();
    menu();
}
