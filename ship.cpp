//---------------------------Cruise Ship reservation project by using c++ programming language--------------------------
//---------------------------------------header file start-----------------------------------------
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>
//---------------------------------------header file close-------------------------------------------
//---------------------------------------user define function start----------------------------------
void viewinfo();
void bookticket();
void cancelticket();
void admin();
void password();
void viewpassenger();
void addship();
void dltship();
void bsearch();
void awrite();
void aread();
void bookticket_write();
void viewpassengers_read();
//-----------------------------------------user define function close-----------------------------------
//-----------------------------------------structure start----------------------------------------------
struct adddata
{
	char si[10];
	char ship_number[10];
	char ship_name[20];
	char start[10];
	char destination[10];
	char price[10];
	int seat;
	char time[10];
} add[1000];

struct bookticket
{
	char ship_number[20];
	char name[20];
	char phone[10];
	char date[20];
	int seat;
}book[1000];
//---------------------------------------structure close----------------------------------------------
//---------------------------------------global variable----------------------------------------------
int k=0,u=0;
char trn_nmbr[100],name[100],phn[100];
//---------------------------------------main function start------------------------------------------
int main()
{
	aread();
	viewpassengers_read();
	system("COLOR 0f");
	int ch;
	time_t currentTime;
	time(&currentTime);
	printf("\n\t\t\t     %s\n",ctime(&currentTime));

	printf("\n\t\t\t*********************************\n");
	printf("\t\t\t*******Cruise Ship RESERVATION SYSTEM*******\n");
	printf("\t\t\t*********************************\n");
	printf("\n\t\t\t<<<<<<<<<<WELCOME USERS>>>>>>>>>>\n");
	printf("\n\n\t\t\t\t      MENU\n");
	printf("\t\t\t             ******");
	printf("\n\t\t\t[1] VIEW INFORMATION\n");
	printf("\n\t\t\t[2] BOOK TICKET\n");
	printf("\n\t\t\t[3] CANCEL TICKET\n");
	printf("\n\t\t\t[4] ADMIN");
	printf("\n\n\t\t\t[5] EXIT\n");
	printf("\n\t\t\t********************************");
	printf("\n\t\t\t********************************");
	printf("\n\t\t\tENTER YOUR CHOICE: ");

	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			viewinfo();
			break;
			case 2:
				bookticket();
				break;
				case 3:
					cancelticket();
					break;
					case 4:
						password();
						break;
						case 5:
							system("cls");
							printf("\n\t\t\t=========================================\n");
							printf("\t\t\t *******Cruise Ship RESERVATION SYSTEM*******\n");
							printf("\t\t\t===============================================\n");
							printf("\n\n\t\t\tBROUGHT TO YOU BY\n\n");
							printf("\t\t\t\t***REETIK AND RAVI***\n");
							getch();
							exit(0);
							break;
							default:
								system("cls");
								printf("\n\t\t\t==============================================\n");
								printf("\t\t\t   *******Cruise Ship RESERVATION SYSTEM*******\n");
								printf("\t\t\t==============================================\n");
								printf("\n\n\t\t\t<<<<<<<<YOU ENTERED WRONG CHOICE>>>>>>>>\n");
								printf("\t\t\t<<<<<<<<PLEASE ENTER RIGHT THING>>>>>>>>\n");
								getch();
								system("cls");
								main();
	}
	return 0;
}
//---------------------------------------main function close--------------------------------------------------
//---------------------------------------search function-----------------------------------------------------






//---------------------------------------book ticket function-----------------------------------------------
void bookticket()
{
	int c,j,n,i,found=-1;
	char v,ship_number[10];
	system ("cls");
	aread();
	printf("\n\n\t\t\t============================================");
	printf("\n\t\t\t**********Cruise Ship RESERVATION SYSTEM**********\n");
	printf("\t\t\t==================================================");
	printf("\n\n\t\t\thow many ticket do you want to buy: ");
	scanf("%d",&n);
	for(j=u;j<u+n;j++)
	{
	printf("\n\n\t\t\tEnter ship number: ");
	scanf("%s", book[j].ship_number);
	for(i=0;i<k;i++)
	{
	if(strcmp(book[j].ship_number,add[i].ship_number)==0)
	{
	if(add[i].seat==0)
	{
		printf("\n\n\t\t\tnot available seat");

		getch();
		system("cls");
		main();
	}
	else
	{
	    found=1;
		printf("\n\t\t\tenter book %d no ticket: ",n);
		printf("\n\t\t\tenter date: ");
		scanf("%s",book[j].date);
		printf("\n\t\t\tenter your name: ");
		scanf("%s",book[j].name);
		printf("\n\t\t\tenter your phone number: ");
		scanf("%s",book[j].phone);
		printf("\n\t\t\tseat number : %d",add[i].seat );
		book[j].seat=add[i].seat;
		bookticket_write();
		add[i].seat--;
		awrite();
		}
	}
}
	if(found==-1)
	{
		printf("\n\n\t\t\tship not found!!!");
		getch();
		system("cls");
		main();
	}

	}
		u=j;
		bookticket_write();
		printf("\n\n\t\t\tenter '1' for main menu & press any key to exit: ");
		scanf("%d",&c);
			if(c==1)
			{
				system("cls");
				main();
			}
			if(c!=1)
			{
				exit;
			}
}
//---------------------------------------cancel ticket function---------------------------------------------
void cancelticket()
{
	viewpassengers_read();
    char pnnmbr[100];
    int location = -1,e;
    printf ("\n\n\t\t\tenter phone number: ");
    scanf ("%s",pnnmbr);
    for (e=0;e<u;e++)
    {
        if (strcmp(pnnmbr,book[e].phone)==0)
        {
            location=e;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t\t\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        main();
    }
    else
    {
        for (e=location;e<u;e++)
        {
            strcpy(book[e].date,book[e+1].date);
            strcpy(book[e].ship_number,book[e+1].ship_number);
            strcpy(book[e].name,book[e+1].name);
            strcpy(book[e].phone,book[e+1].phone);
            bookticket_write();
        }
        u--;
        bookticket_write();
        printf("\n\n\t\t\t<<<<<<<<<<<<<<<ticket cancelled successfully>>>>>>>>>>>>");
        getch();
        system("cls");
        main();
    }
}
//-------------------------------------admin portal function----------------------------------------
void admin()
{
	int chhh;
	system("cls");
	printf("\n     ==================================================================");
	printf("\n     ********************Cruise Ship RESERVATION SYSTEM*******************");
	printf("\n     ====================================================================");
	printf("\n\n");
	printf("           <<<<<<<<<<<<<<<WELCOME_ADMIN>>>>>>>>>>>>>>>\n");
	printf("\n\n");
	printf("              ************************************\n");
	printf("              ||      CHOOSE YOUR OPERATION     ||\n");
	printf("              ||--------------------------------||\n");
	printf("              ||      [1] VIEW PASSENGERS       ||\n");
	printf("              ||      [2] ADD ship             ||\n");
	printf("              ||      [3] DELETE ship          ||\n");
	printf("              ||      [4] BACK                  ||\n");
	printf("              ||                                ||\n");
	printf("              ************************************\n\n");
	printf("     **********************************************************\n");
	printf("\n\t\tENTER YOUR CHOICE: ");
	scanf("%d",&chhh);

	switch(chhh)
	{
		case 1:
			viewpassenger();
			break;
			case 2:
				addship();
				break;
				case 3:
					dltship();
					break;
					case 4:
						system("cls");
						//getch();
						main();
						break;
						default:
							getch();
							printf("\n\t\t\tyou entered wrong KEY!!!!");
							getch();
							system("cls");
							main();
	}
	getch();
}
//-----------------------------password function----------------------------------
void password()
{
	int number=1234567;
	int pass;
	printf("\n\t\t\tenter password: ");
	scanf("%d",&pass);
	if(pass==number)
	{
		printf("\n\n\t\t\t<<<<<login successfully>>>>>");
		getch();
		system("cls");
		admin();
	}
	else
	{
		printf("\n\n\t\t\t\t   ERROR!!!!!");
		printf("\n\n\t\t\t<<<<<<<<wrong password>>>>>>>>");
		getch();
		system("cls");
		main();
	}
}
//------------------------------------delete ship function----------------------------------------------
void dltship()
{
	aread();
    char ship[100];
    int location = -1,f;
    printf ("\n\n\tenter ship number: ");
    scanf ("%s",ship);
    for (f=0;f<k;f++)
    {
        if (strcmp(ship,add[f].ship_number)==0)
        {
            location=f;
            break;
        }
    }
    if (location==-1)
    {
        printf ("\n\n\t<<<<<<<<<<<<<<Data Not Found>>>>>>>>>>>>>>>>> \n");
        getch();
        system("cls");
        admin();
    }
    else
    {
        for (f=location;f<k;f++)
        {
            strcpy(add[f].si,add[f+1].si);
            strcpy(add[f].ship_number,add[f+1].ship_number);
            strcpy(add[f].ship_name,add[f+1].ship_name);
            strcpy(add[f].start,add[f+1].start);
            strcpy(add[f].destination,add[f+1].destination);
            strcpy(add[f].price,add[f+1].price);

            strcpy(add[f].time,add[f+1].time);
            awrite();
        }
        k--;
        awrite();
		printf("\n\n\t<<<<<<<<<<<<<ship deleted successfully>>>>>>>>>>>>>");
		getch();
		system("cls");
		admin();
    }
}
//--------------------------------------view passengers function----------------------------------------
void viewpassenger()
{
	int a,j;
	system("cls");
	viewpassengers_read();
	printf("\n\t\t\t       **********************************************************");
	printf("\n\t\t\t       ********************Cruise Ship RESERVATION SYSTEM********************");
	printf("\n\t\t\t       **********************************************************");
	printf("\n\n\t\t\tship number\t\tname\t\tphone number\t\tdate\t\tseat\n");
	printf("\n\t\t\t**********************************************************************************\n");
	for(j=0;j<u;j++)
	{
		printf("\n\t\t\t%s\t\t\t%s\t\t%s\t\t%s\t%d",book[j].ship_number,book[j].name,book[j].phone,book[j].date,book[j].seat);
		book[j].seat++;
	}
	printf("\n\t\t\t**********************************************************************************\n");
	printf("\n\n\t\t\tenter '1' for main menu & enter '0' for back: ");
	scanf("%d",&a);
	if(a==1)
	{
		system("cls");
		main();
	}
	if(a==0)
	{
		system("cls");
		admin();
	}
}
//--------------------------------------add ship function--------------------------------------------
void addship()
{
	system("cls");
	int ch;
	aread();
	int i,a;
	printf("\n\t\t     **********************************************************");
	printf("\n\t\t     ********************Cruise Ship RESERVATION SYSTEM********************");
	printf("\n\t\t     **********************************************************");
	printf("\n\n\t\t\thow many ships do you want to add: ");
	scanf("%d",&a);
	for(i=k;i<k+a;i++)
	{
		//printf("\n\t\t\tenter %d ship details: ",i+1);
		printf("\n\t\t\tenter serial number: ");
		scanf("%s",add[i].si);
		printf("\n\t\t\tenter ship number: ");
		scanf("%s",add[i].ship_number);
		printf("\n\t\t\tenter ship name: ");
		scanf("%s",add[i].ship_name);
		printf("\n\t\t\tenter start place: ");
		scanf("%s",add[i].start);
		printf("\n\t\t\tenter destination place: ");
		scanf("%s",add[i].destination);
		printf("\n\t\t\t enter price: ");
		scanf("%s",add[i].price);
		printf("\n\t\t\t enter seat: ");
		scanf("%d", & add[i].seat);
		printf("\n\t\t\t enter time: ");
		scanf("%s",add[i].time);
	}

		printf("\n\n\t\t\tconfirm ship: (y=1/n=0):- ");
		scanf("%d",&ch);
		if(ch==1)
		{
			awrite();
			k=i;
			awrite();
			system("cls");
			printf("\n\n\t\t\t**********************************************************");
			printf("\n\t\t\t********************Cruise Ship RESERVATION SYSTEM********************");
			printf("\n\t\t\t**********************************************************");
			printf("\n\n");
			printf("\n\t\t\t\t   **********************************");
			printf("\n\t\t\t\t   *<<<<<ship add successfully>>>>>*");
			printf("\n\t\t\t\t   **********************************");
			getch();
			system("cls");
			main();
		}
			if(ch==0)
			{
				system("cls");
				admin();
			}
			if((ch!=1)&&(ch!=0))
			{
				system("cls");
				main();
			}
}
//-----------------------------------view information function--------------------------------------
void viewinfo()
{
	int ch,i;
	system("cls");
	aread();
	printf("\n\t\t     **********************************************************");
	printf("\n\t\t     ********************Cruise Ship RESERVATION SYSTEM********************");
	printf("\n\t\t     **********************************************************");
	printf("\n\n\n    SI\tship number\tship name\tstart place\tdestination place\tprice\tseat\ttime\n\n");
	for(i=0;i<k;i++)
	{
		printf("    %s\t%s\t\t%s\t\t%s\t\t%s\t\t\t%s\t%d\t%s\n",add[i].si,add[i].ship_number,add[i].ship_name,add[i].start,add[i].destination,add[i].price,add[i].seat,add[i].time);
	}
	printf("    ***********************************************************************************************\n");
	printf("\n\t\t\tpress '1' for main menu & press any key for exit:  ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			system("cls");
			main();
			break;
				default:
					exit(0);
	}
}
//------------------------------------------book ticket file start-----------------------------------------
void bookticket_write()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","w");
	fwrite(&book,sizeof(book),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","w");
	fwrite(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}
void viewpassengers_read()
{
	FILE *booklist;
	booklist=fopen("booklist.txt","r");
	fread(&book,sizeof(book),1,booklist);
	fclose(booklist);

	FILE *booklistreport;
	booklistreport=fopen("booklistreport.txt","r");
	fread(&u,sizeof(u),1,booklistreport);
	fclose(booklistreport);
}
//-----------------------------------------add ship file start---------------------------------------------------
void awrite()
{
	FILE *ship_details;
	ship_details = fopen("ship_details.txt","w");
	fwrite(&add,sizeof(add),1,ship_details);
	fclose(ship_details);

	FILE *ship_report;
	ship_report = fopen("ship_report.txt","w");
	fwrite(&k,sizeof(k),1,ship_report);
	fclose(ship_report);
}
void aread()
{
	FILE *ship_details;
	ship_details = fopen("ship_details.txt","r");
	fread(&add,sizeof(add),1,ship_details);
	fclose(ship_details);

	FILE *ship_report;
	ship_report = fopen("ship_report.txt","r");
	fread(&k,sizeof(k),1,ship_report);
	fclose(ship_report);
}
//----------------------------------------------------file close----------------------------------------------
//----------------------------------------------------program close----------------------------------------

