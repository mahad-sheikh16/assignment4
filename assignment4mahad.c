#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <conio.h>

FILE *fptr;
FILE *fptr2;

void menu(void);
void add(void);
void update(void);
/////////////

typedef struct patient_record
{

	char id[5];
	char name[20];
	char cnic[15];
	char number[15];
	char disease[20];
	unsigned isAdmitted;

} pr;

pr p;
unsigned id = 0;
int count = 0;

int main()
{
	fptr = fopen("file1.txt","r");
	if(fptr == NULL){
		
		fptr = fopen("file1.txt", "w+");
		fprintf(fptr, "ID        Name                     CNIC           Phone Number   Disease                  Status\n-----------------------------------------------------------------------------------------\n\n");
		fclose(fptr);

	}
	else{
		
		fptr = fopen("file1.txt", "a+");
		fclose(fptr);

	}
	fclose(fptr);
	menu();
	return 0;
}

void menu(void)
{   
   system("COLOR 75");
	int choice;
	printf("\n***************  PATIENT MANAGEMENT SYSTEM  *****************\n");
	printf("\t\t\t _    _   __  _    \n");
	printf("\t\t\t| \\  / | |__ | \\ | |  |\n");
	printf("\t\t\t|  \\/  | |__ |  \\| |__|\n");

	do
	{

		printf("\n\n\t1 ->  ADD       Patient Record.\n");
		printf("\t2 ->  UPDATE    Patient Record.\n");
		/////////
		printf("\t0 ->  EXIT.\n");
		printf("\n   Enter Choice (0-5) : ");
		scanf("%d", &choice);
		switch (choice)
		{

		case 0:

			exit(1);
			break;

		case 1:
			system("cls");
            
   system("COLOR 72");
			add();
			break;
		case 2:
			system("cls");
   system("COLOR 70");
			update();
            
			break;

		/////
		default:
           
			printf("Invalid input,Enter again");
			_sleep(700);
			system("cls");
		}

	} while (choice > 5 || choice < 0);
}

void add(void)
{
	printf("\t\t--------ADD PAITIENT--------\n\n");
	printf("Note: Enter -1 in ID to return to menu without adding patient\n");

	fptr = fopen("file1.txt", "a+");
	fseek(fptr, 0, SEEK_END);
	char sid[5];
	do
	{
		printf("\nEnter ID  :  ");
		fflush(stdin);
		gets(p.id);
	} while (strlen(p.id) < 1);
	if (strcmp(p.id, "-1") == 0)
	{
		_sleep(700);
		system("cls");
		menu();
	}

	while (ftell(fptr) > 96 && count > 0)
	{
		fseek(fptr, -97, SEEK_CUR);
		fscanf(fptr, "%s", sid);
		fseek(fptr, -strlen(sid), SEEK_CUR);

		if (strcmp(p.id, sid) == 0)
		{
			printf("Sorry, Repeated Entry. Try Again.....\n");
			_sleep(700);
			system("cls");
			add();
		}
	}

	fseek(fptr, 0, SEEK_END);
	fprintf(fptr, "\n%-10s", p.id);
	count++;

	fflush(stdin);

	do
	{
		printf("Enter Name  : ");
		gets(p.name);
	} while (strlen(p.name) < 1);

	do
	{
		printf("Enter  CNIC no (13 digits) ");
		gets(p.cnic);
	} while (strlen(p.cnic) < 1 || strlen(p.cnic)!=13);

	do
	{
		printf("Enter Phone no (11 digits) ");
		gets(p.number);
	} while (strlen(p.number) < 1 || strlen(p.number)!=11);

	do
	{
		printf("Enter Disease : ");
		gets(p.disease);
	} while (strlen(p.disease) < 1);

	do
	{
		printf("Enter Admitted or not (0 for no 1 for yes): ");
		scanf("%u", &p.isAdmitted);
		if (p.isAdmitted == 0 || p.isAdmitted == 1)
		{
			break;
		}
	} while (1);

	fflush(stdin);

	fprintf(fptr, "%-25s%-15s%-15s%-25s%-5u", p.name, p.cnic, p.number, p.disease, p.isAdmitted);
	printf("\nRecord Added Successfully!\n");
	fclose(fptr);
	_sleep(700);
	system("cls");
	menu();
}

void update(void)
{

	printf("\t\t-------UPDATE PAITIENT-------\n\n");
	printf("Note: Enter -1 in ID to return to menu without updating patient\n");

	fptr = fopen("file1.txt", "r+");
	fseek(fptr, 0, SEEK_END);
	char sid[5];
	fflush(stdin);
	printf("\nEnter    ID   : ");
	gets(p.id);
	if (strcmp(p.id, "-1") == 0)
	{
		_sleep(700);
		system("cls");
		menu();
	}

	int flag = 0;
	while (ftell(fptr) > 96)
	{
		fseek(fptr, -97, SEEK_CUR);
		fscanf(fptr, "%s", sid);
		fseek(fptr, -strlen(sid) - 1, SEEK_CUR);

		if (strcmp(p.id, sid) == 0)
		{
			printf("Repeated Entry Found  !! \n\n");
			_sleep(700);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("No Such Record Found !!\n");
		_sleep(700);
		system("cls");
		fclose(fptr);
		menu();
	}
	else
	{

		fprintf(fptr, "%-10s", p.id);
		fflush(stdin);

		do
	{
		printf("Enter Name  : ");
		gets(p.name);
	} while (strlen(p.name) < 1);

	do
	{
		printf("Enter  CNIC no (13 digits) ");
		gets(p.cnic);
	} while (strlen(p.cnic) < 1 || strlen(p.cnic)!=13);

	do
	{
		printf("Enter Phone no (11 digits) ");
		gets(p.number);
	} while (strlen(p.number) < 1 || strlen(p.number)!=11);

	do
	{
		printf("Enter Disease : ");
		gets(p.disease);
	} while (strlen(p.disease) < 1);

	do
	{
		printf("Enter Admitted or not (0 for no 1 for yes): ");
		scanf("%u", &p.isAdmitted);
		if (p.isAdmitted == 0 || p.isAdmitted == 1)
		{
			break;
		}
	} while (1);

		printf("%-10s", p.id);

		fprintf(fptr, "%-25s%-15s%-15s%-25s%-5u", p.name, p.cnic, p.number, p.disease, p.isAdmitted);
		printf("\nRecord Updated Successfully!\n");
		fclose(fptr);
		_sleep(900);
		system("cls");
		//system("COLOR 07");
		
		menu();
	}
}

///////