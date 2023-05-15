#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <math.h>

void viewHomePage();
void viewCustomerMainmenu();
void createAccount();
char validateData(char[], int);
int validateAlreadyTakenData(char *name, int id);
void viewCustomerDetails();
void viewRegisteredCustomerMenu();
void login();
void viewSecondMenu(char[],char[]);
void viewServices();
void viewProfile(char nic1[],char password1[]);
void updateProfile(char nic1[]);
void deleteProfile(char nic1[]);
void orderProduct();
void bookHalls();
void viewBookingDetails();
void makeAppointments();
void viewAppointmentsDetails();
void managerLogin();
void viewManagerMainmenu();
void viewHeaderFoodMenu();
void createFoodMenu();
int validateCode(int code);
void viewFoodMenu();
void updateMenu();
void removeProduct();
void removeBreakfast();
void removeLunch();
void removeDinner();
void removeDrinks();
void removeAllFoods(int code);
void viewReports();
void loadingProgressBar();
void exitSystem();

struct data
    {
    char name[100];
	char nic[100];
	char phone[100];
	char address[100];
	char password[10];
    char district[100];
    }d;

struct product
{
	int productCode;
	char productName[20];
	float unitPrice;
};

struct sales
{
    int productCode;
    int quantity;
}s;

int count = 0;

int main()
{
    remove("sales.dat");
    viewHomePage();
	return 0;
}

void viewHomePage()
{
	system("cls");
	system("COLOR 0E");

    printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**      WELCOME TO CHILLOUT RESTAURANT         **");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t*************************************************");
    printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t|     [1] - Customer                            |");
    printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t|     [2] - Manager                             |");
    printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t=================================================");

    int option = 0;

    printf("\n\n\t  Enter Your Option : ");
    scanf("%d",&option);

    if(option == 1)
    {
        viewCustomerMainmenu();
    }
    else if(option == 2)
    {
        managerLogin();
    }
    else
    {
        printf("\t\tInvalid Input\n\t\tEnter Again");
        viewHomePage(option);
    }
}

void viewCustomerMainmenu()
{
	system("cls");
	system("COLOR 09");

    printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t**      WELCOME TO CHILLOUT RESTAURANT         **");
    printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [1] - Create an Account                   |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [2] - Login                               |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [3] - Menu                                |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [4] - About Us                            |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [5] - Exit                                |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t=================================================");

    int option = 0;
    int option2 = 0;

    printf("\n\n\t  Enter Your Option : ");
    scanf("%d",&option);

    if(option == 1)
    {
        createAccount();
    }
    else if(option == 2)
    {
        login();
    }
    else if(option == 3)
    {
    	system("cls");
    	system("COLOR 0F");

        viewFoodMenu();

        printf("\n\n\t\t  1. Back to MainMenu");
        printf("\n\n\t\t  2. Exit");

        do
        {
        	printf("\n\n\t\tEnter Your Option : ");
            scanf("%d",&option2);

            if(option2 == 1)
           {
                viewCustomerMainmenu();
           }
           else if(option2 == 2)
           {
                exitSystem();
           }
           else
           {
           	    printf("\tInvalid Input");
           	    sleep(2);
		   }

		}while(option2 != 1 || option2 != 2);
    }
    else if(option == 4)
    {
        system("cls");
        system("COLOR 0A");

        printf("\n\n\t****************************************************************************************************************************");
        printf("\n\t**\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  **");
		printf("\n\t**                                             WELCOME TO CHILL OUT RESTAURANT                                            **");
		printf("\n\t**\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  **");
        printf("\n\t****************************************************************************************************************************");

        printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   |");
		printf("\n\t|  we are warmly welcome you to our restaurant a local favourite for years. Full pub menu and sandwich selection.          |");
        printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   |");
		printf("\n\t|  Homemade, delicious Italian dishes, featuring seafood, and pasta. Our special full menu offered all day and late night. |");
        printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   |");
        printf("\n\t============================================================================================================================");

        printf("\n\n\t\t  1. Back to MainMenu");
        printf("\n\n\t\t  2. Exit");
        printf("\n\n\t============================================================================================================================");

        int option3 = 0;
        printf("\n\n\t\tEnter Your Option : ");
        scanf("%d",&option3);

        if(option3 == 1)
        {
            viewCustomerMainmenu();
        }
        else if(option3 == 2)
        {
            exitSystem();
        }
    }
    else if(option == 5)
    {
    	exitSystem();
	}
	else
	{
	    printf("\t\tInvalid Input\n\t\tEnter Again");
	    sleep(2);
	    viewCustomerMainmenu();
	}
}

void createAccount()
{
	system("cls");
	system("COLOR 0B");

    printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t**      WELCOME TO CHILLOUT RESTAURANT         **");
    printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");

    FILE *file1;

	file1 = fopen("customer.dat","a");

	struct data d;

	int i, j, found, found1;
	char option, confirmPW[20];

	do
	{
       found = 1;

	   printf("\n\n\t\tEnter Your Name            : ");
	   scanf("%s",d.name);

 	   i = 1;
	   found = validateData(d.name,i);

	   if(found == 0)
	   {
	   	  found = 0;
	      printf("\n\n\tInvalid Input try Again");
	   }

	}while(found == 0);

	do
	{
       found = 1;

	   printf("\n\n\t\tEnter Your Phone Number    : ");
	   scanf("%s",d.phone);

	   i = 2;
	   found = validateData(d.phone,i);

	   if(found == 0 || strlen(d.phone) != 10 || d.phone[0] != '0' || d.phone[1] != '7')
	   {
	 	   found = 0;
    	   printf("\n\n\tInvalid Input try Again");
	   }

	}while(found == 0);

	do
    {
       found = 1;
       found1 = 0;

       printf("\n\n\t\tEnter NIC                  : ");
	   scanf("%s",d.nic);

	   j = 1;
	   found1 = validateAlreadyTakenData(d.nic,j);

	   if(strlen(d.nic) == 10 && (d.nic[9] == 'v' || d.nic[9] == 'V'))
       {
           found = 1;
       }
       else
       {
           found = 0;
           printf("\nInvalid Input.. Try Again...");
       }
       if(found1 != 0)
       {
           found = 0;
           printf("\nAlready Taken... Try Again...");
       }


    }while(found == 0);

	printf("\n\n\t\tEnter Home Address         : ");
	scanf("%s",d.address);

	printf("\n\n\t\tEnter District             : ");
	scanf("%s",d.district);

	do
    {
       found = 1;
       found1 = 1;

       printf("\n\n\t\tEnter password             : ");
	   scanf("%s",&d.password);
	   printf("\n\n\t\tRe Enter Password          : ");
	   scanf("%s",&confirmPW);

	   j = 2;
	   found1 = validateAlreadyTakenData(d.password,j);

	   if(strcmp(d.password,confirmPW) != 0)
       {
           found = 0;
           printf("\nPassword is not matching.. Re Enter..");
       }
       if(found1 != 0)
       {
           found = 0;
           printf("\nAlready Taken... Try Again...");
       }

    }while(found == 0);

	printf("\n\n");
    printf("\n\n\t=================================================");

    printf("\n\n\t\tDo You Want to Save it(Y or N) : ");
    scanf(" %c",&option);

    if(option == 'Y' || option == 'y')
    {
        fprintf(file1,"%s  %s  %s  %s  %s  %s\n",d.name,d.nic,d.phone,d.address,d.district,d.password );
        fclose(file1);

    	viewRegisteredCustomerMenu(option);
	}
	else if(option == 'N' || option == 'n')
	{
		createAccount();
	}
	else
	{
		printf("\n\n\tError");
		sleep(2);
		createAccount();
	}
}

char validateData(char *name, int id)
{
	int i;

	switch(id)
	{
		case 1:
		for(i=0; i < strlen(name); i++)
		{
		   if(!isalpha(name[i]))
		   return 0;
		}
		return 1;
		break;

		case 2:
		for(i=0; i<strlen(name); i++)
		{
			if(isdigit(name[i]))
			return 1;
		}
		return 0;
		break;

	}

}

int validateAlreadyTakenData(char *name, int id)
{
     FILE *file1;
	 file1 = fopen("customer.dat","r");

	 struct data d;

	 fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);

	 while(!feof(file1))
     {

        switch(id)
        {
            case 1:
   		    if(strcmp(name,d.nic) == 0)
            {
                return 1;
                break;
   		    }

   		   case 2:
   		   if(strcmp(name,d.password) == 0)
           {
               return 1;
               break;
   		   }
        }
     fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);
     }
	fclose(file1);
}

void viewCustomerDetails()
{
	system("cls");
	system("COLOR 0C");

	printf("\n\n\t***********************************************************************************************************");
    printf("\n\t**\t\t\t\t\t\t\t\t\t\t\t\t\t **");
	printf("\n\t**                                            CUSTOMER REPORT                                            **");
	printf("\n\t**\t\t\t\t\t\t\t\t\t\t\t\t\t **");
    printf("\n\t***********************************************************************************************************");
    printf("\n\t|\t\t|\t\t|\t\t|\t\t        |\t\t|\t\t  |");
    printf("\n\t|    NAME       |    NIC        |     PHONE     |       ADDRESS         |    DISTRICT   |    PASSWORD     |");
    printf("\n\t|\t\t|\t\t|\t\t|\t\t        |\t\t|\t\t  |");
    printf("\n\t===========================================================================================================");
    printf("\n\t|\t\t|\t\t|\t\t|\t\t        |\t\t|\t\t  |");

    struct data d;

     FILE *file1;
     file1 = fopen("customer.dat","r");

     fscanf(file1,"%s  %s  %s  %s  %s  %s",d.name,d.nic,d.phone,d.address,d.district,d.password);

     while(!feof(file1))
     {
        printf("\n\t|  %s\t| %s\t|  %s\t|  %s\t|  %s\t|    %s\t  |",d.name,d.nic,d.phone,d.address,d.district,d.password);
        printf("\n\t|\t\t|\t\t|\t\t|\t\t        |\t\t|\t\t  |");
        fscanf(file1,"%s   %s   %s  %s   %s   %s",d.name,d.nic,d.phone,d.address,d.district,d.password);
     }
     printf("\n\t===========================================================================================================");
     printf("\n\n\n");

  fclose(file1);
}

void viewRegisteredCustomerMenu()
{
    system("cls");
    system("COLOR 01");

	printf("\n\n\t`````````````````````````````````````````````````");
	printf("\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**                     WELCOME !               **");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**              SUCCESSFULLY REGISTERED..      **");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t*************************************************");
    printf("\n\t`````````````````````````````````````````````````");

    printf("\n\n\t     [1] - Back to Main Menu");
    printf("\n\n\t     [2] - Exit");
    printf("\n\n\t=================================================");

    int option = 0;

    printf("\n\n\t\tEnter Your Option : ");
    scanf("%d",&option);

    if(option == 1)
    {
    	viewCustomerMainmenu();
	}

	else if(option == 2)
	{
		exitSystem();
	}

	else
	{
		printf("\n\n\tError");
		sleep(2);
		viewRegisteredCustomerMenu();
	}
}

void login()
{
    char nic1[20];
    char password1[10];

    FILE *file1;
	file1 = fopen("customer.dat","r");

	struct data d;

	system("cls");
	system("COLOR 0D");

	printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t**      WELCOME TO CHILLOUT RESTAURANT         **");
    printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");

    printf("\n\n\t\tEnter Your NIC Number : ");
    scanf(" %s",nic1);

    printf("\n\n\t\tEnter Your Password   : ");
    scanf(" %s",password1);

    fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password );

   	while(!feof(file1))
   	{
   		if((strcmp(nic1,d.nic) == 0) && (strcmp(password1,d.password) == 0) )
   		{
		   viewSecondMenu(nic1,password1);
   		}
    fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password );
    }

    if((strcmp(nic1,d.nic) != 0) || (strcmp(password1,d.password) != 0))
    {
        printf("\n\n\tIncorrect Password\nTry Again..");
        sleep(2);
        login();
    }

	fclose(file1);
	printf("\n");

}

void viewProfile(char nic1[20],char password1[20])
{
    system("cls");
    system("COLOR 0C");

    printf("\n\n\t**************************************************");
    printf("\n\t**\t\t\t\t\t\t**");
    printf("\n\t**       WELCOME TO CHILL OUT RESTAURANT        **");
    printf("\n\t**\t\t\t\t\t\t**");
    printf("\n\t**************************************************");
    printf("\n\t**\t\t\t\t\t\t**");
    printf("\n\t**                  MY PROFILE                  **");
    printf("\n\t**\t\t\t\t\t\t**");
    printf("\n\t==================================================");
    printf("\n\t|\t\t\t\t\t\t |");

	struct data d;
	FILE *file1;

   	file1 = fopen("customer.dat","r");

    fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);

   	while(!feof(file1))
   	{
   			if((strcmp(nic1,d.nic) == 0) && (strcmp(password1,d.password) == 0) )
   			{
		   	    printf("\n\t|\tName         :    %s\t       |",d.name);
		     	printf("\n\t|\t\t\t\t\t\t |");
                printf("\n\t|\tNIC          :    %s\t       |",d.nic);
   		    	printf("\n\t|\t\t\t\t\t\t |");
   		    	printf("\n\t|\tPhone Number :    %s\t       |",d.phone);
   			    printf("\n\t|\t\t\t\t\t\t |");
   			    printf("\n\t|\tDistrict     :    %s\t       |",d.district);
   		    	printf("\n\t|\t\t\t\t\t\t |");
   		    	printf("\n\t|\tAddress      :    %s\t       |",d.address);
   		    	printf("\n\t|\t\t\t\t\t\t |");
   		     	printf("\n\t|\tPassword     :    %s\t       |",d.password);
   		    	printf("\n\t|\t\t\t\t\t\t |");
                printf("\n\t==================================================");
   			}

    fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);
    }

    int option = 0;

    printf("\n\n\t\t 1.Back");
    printf("\n\n\t\t 2.Exit");
    printf("\n\n\t==================================================");

    printf("\n\n\t\tEnter Your Option : ");
    scanf("%d",&option);

    if(option == 1)
    {
        viewSecondMenu(nic1,password1);
    }

    else if(option == 2)
    {
        exitSystem();
    }

    else
    {
    	printf("\nInvalid Input.. Try Again...");
    	sleep(2);
    	viewProfile(nic1[20],password1[20]);
	}

	fclose(file1);
}

void updateProfile(char nic1[20])
{
    FILE *file1;
    FILE *file2;

    struct data d;

    file1 = fopen("customer.dat","r");
    file2 = fopen("copy.dat","w");

    fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);

    while(!feof(file1))
    {
        if(strcmp(nic1,d.nic) != 0 )
        {
            fprintf(file2,"%s  %s  %s  %s  %s  %s\n",d.name,d.nic,d.phone,d.address,d.district,d.password );
        }
       fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);
    }

    fclose(file1);
    fclose(file2);

    file1 = fopen("customer.dat","w");
    file2 = fopen("copy.dat","r");

    fscanf(file2,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);

    while(!feof(file2))
    {
       fprintf(file1,"%s  %s  %s  %s  %s  %s\n",d.name,d.nic,d.phone,d.address,d.district,d.password );
       fscanf(file2,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);
    }

    fclose(file1);
    fclose(file2);

    createAccount();

}

void deleteProfile(char nic1[20])
{
    struct data d;

    FILE *file1;
    FILE *file2;

    file1 = fopen("customer.dat","r");
    file2 = fopen("copyy.dat","w");

    fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);

    while(!feof(file1))
    {
        if(strcmp(nic1,d.nic) != 0 )
        {
            fprintf(file2,"%s  %s  %s  %s  %s  %s\n",d.name,d.nic,d.phone,d.address,d.district,d.password );
        }
       fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);
    }

    fclose(file1);
    fclose(file2);

    file1 = fopen("customer.dat","w");
    file2 = fopen("copyy.dat","r");

    fscanf(file2,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);

    while(!feof(file2))
    {
       fprintf(file1,"%s  %s  %s  %s  %s  %s\n",d.name,d.nic,d.phone,d.address,d.district,d.password );
       fscanf(file2,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);
    }

    fclose(file1);
    fclose(file2);

    remove("copyy.dat");

    system("cls");

    printf("\n\n\t\t\t``````````````````````````````````````````````````");
    printf("\n\t\t\t**************************************************");
    printf("\n\t\t\t**\t\t\t\t\t        **");
    printf("\n\t\t\t**     Your profile deleted successfully..!     **");
    printf("\n\t\t\t**\t\t\t\t\t        **");
    printf("\n\t\t\t``````````````````````````````````````````````````");
    printf("\n\t\t\t**************************************************");

    printf("\n\n");
    printf("\n\t\t\t=================================================");
    printf("\n\t\t\t|     [1] - Register Again                      |");
    printf("\n\t\t\t|\t\t\t\t\t\t|");
    printf("\n\t\t\t|     [2] - Back to Main Menu                   |");
    printf("\n\t\t\t|\t\t\t\t\t\t|");
    printf("\n\t\t\t|     [3] - Exit                                |");
    printf("\n\t\t\t|\t\t\t\t\t\t|");
    printf("\n\t\t\t=================================================");

    int option = 0;

    do
    {
        printf("\n\n\t\tEnter Your Option : ");
        scanf("%d",&option);

        if(option == 1)
        {
            createAccount();
        }
        else if(option == 2)
        {
            viewCustomerMainmenu();
        }
        else if(option == 3)
        {
            exitSystem();
        }
        else
	    {
	        printf("\n\tInvalid Input...Enter Again...");
	    }
    }while(option != 1 && option != 2 && option != 3);

}

void viewSecondMenu(char nic1[20], char password1[20])
{
	system("cls");
	system("COLOR 0A");

    printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**      WELCOME TO CHILLOUT RESTAURANT         **");
	printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");
    printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t|     [1] - Services                            |");
	printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [2] - Your Profile                        |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [3] - Edit Profile                        |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [4] - Delete Profile                      |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [5] - Back to Main Menu                   |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [6] - Exit                                |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t=================================================");

    int option = 0;

    printf("\n\n\t  Enter Your Option : ");
    scanf("%d",&option);

    if(option == 1)
    {
        viewServices();
    }
    else if(option == 2)
    {
        viewProfile(nic1,password1);
    }
    else if(option == 3)
    {
        updateProfile(nic1);
    }
    else if(option == 4)
    {
        deleteProfile(nic1);
    }
    else if(option == 5)
    {
        viewCustomerMainmenu();
    }
    else if(option == 6)
    {
    	exitSystem();
	}
	else
	{
		viewSecondMenu(nic1,password1);
	}

}

void viewServices()
{
	system("cls");
	system("COLOR 06");

    printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**      WELCOME TO CHILLOUT RESTAURANT         **");
	printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");
    printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t|     [1] - Order Products                      |");
	printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [2] - Book Halls                          |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [3] - Make Appointments                   |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [4] - Back to Main Menu                   |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|     [5] - Exit                                |");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t=================================================");

    int option = 0;

    printf("\n\n\t  Enter Your Option : ");
    scanf("%d",&option);

    if(option == 1)
    {
        orderProduct();
    }
    else if(option == 2)
    {
        bookHalls();
    }
    else if(option == 3)
    {
        makeAppointments();
    }
    else if(option == 4)
    {
        viewCustomerMainmenu();
    }
    else if(option == 5)
    {
    	exitSystem();
	}
	else
	{
	    printf("\t\tInvalid Input\n\t\tEnter Again");
	    sleep(2);
		viewServices();
	}
}

void orderProduct()
{
	system("cls");
	system("COLOR 0B");

    viewFoodMenu();
    printf("\n\n");

    int option = 0;
    float totalPrice, unitPrice, price;
    float deliverCharges = 0;
    float netAmount = 0;

    struct product p;
    struct sales s;

    FILE *file1;
    FILE *file2;
    FILE *file3;

    do
    {
        int i = 0,found = 0;

        file1 = fopen("sales.dat","a");
        file2 = fopen("allSales.dat","a");

        do
        {
            i = 0;

            printf("\n\t  Enter Product Code : ");
            scanf("%d",&s.productCode);

            FILE *file5;
            file5 = fopen("foodMenu.dat","r");

            while(fread(&p,sizeof(struct product),1,file5))
            {
                if(p.productCode == s.productCode)
                {
                    found = 1;
                    unitPrice = p.unitPrice;
                }
            }

            if(found != 1)
            {
                printf("\nInvalid Input...");
                i = 1;
            }

        }while(i == 1);

        int input, temp, status;

        do
        {
            printf("\n\t  Enter Quantity     : ");
            status = scanf("%d",&s.quantity);

            while(status != 1)
            {

                while((temp = getchar()) != EOF && temp != '\n');

                printf("Invalid input... \n\t  Enter Quantity     : ");
                status = scanf("%d",&s.quantity);
            }
            if(s.quantity > 1000)
            {
                printf("\nYou can't order more than 1000 products..");
            }

        }while(s.quantity > 1000);

        printf("\n\tDo you want to order another(1 - Yes or 2 - No): ");
        scanf("%d",&option);

        if(option == 2)
        {
            option = 2;
        }

        totalPrice += unitPrice * s.quantity;

        price = unitPrice * s.quantity;

        fprintf(file1,"%.4d\t %d\t %.2f\t %.2f\n",s.productCode,s.quantity,unitPrice,price);
        fprintf(file2,"%.4d\t %d\t %.2f\t %.2f\n",s.productCode,s.quantity,unitPrice,price);

        fclose(file1);
        fclose(file2);

    }while(option == 1);

    char district[20];

    printf("\n\n\tEnter Your District : ");
    scanf("%s",district);

    if(strcmp(district,"colombo") == 0)
	{
		deliverCharges = 100.00;
	}
	else
	{
		deliverCharges = 200.00;
	}

    netAmount = totalPrice + deliverCharges;

    loadingProgressBar();

    system("cls");
    system("COLOR 0C");

    struct tm *myTime;
    time_t currentTime;

    currentTime = time(NULL);
    myTime = localtime(&currentTime);
    time(&currentTime);

    int month, day, year, hour, min, sec;

    month = myTime->tm_mon + 1;
    day   = myTime->tm_mday;
    year  = myTime->tm_year + 1900;
    hour  = myTime->tm_hour;
    min   = myTime->tm_min;
    sec   = myTime->tm_sec;

        printf("\n\n\t==============================================================");
        printf("\n\t|                          BILL                              |");
        printf("\n\t==============================================================");
        printf("\n\t| DATE : %.2d/%.2d/%d                                          |",month,day,year);
        printf("\n\t| TIME : %.2d:%.2d:%.2d                                            |",hour,min,sec);
        printf("\n\t==============================================================");
        printf("\n\t|  PACKAGE CODE       QUANTITY     UNIT PRICE      TOTAL     |");
        printf("\n\t==============================================================");
        printf("\n\t|\t\t\t\t\t\t\t     |");

	    file1 = fopen("sales.dat","r");
	    file3 = fopen("s.dat","w");

        fscanf(file1,"%d %d %f %f",&s.productCode,&s.quantity,&unitPrice,&price);

        while(!feof(file1))
        {
            fprintf(file3,"% d  %d  %f  %f",s.productCode,s.quantity,unitPrice,price);
            printf("\n\t| %.4d\t\t  %.4d\t\t  %.2f\t\t  %.2f",s.productCode,s.quantity,unitPrice,price);
            fscanf(file1,"%d %d %f %f",&s.productCode,&s.quantity,&unitPrice,&price);
        }

        fclose(file1);
        fclose(file3);

        printf("\n\t|\t\t\t\t\t\t\t     |");

	    printf("\n\t==============================================================");
	    printf("\n\t|\t\t\t\t\t\t\t     |");
	    printf("\n\t| Deliver Charges\t = \t\t\t  %.2f\t |",deliverCharges);
	    printf("\n\t|\t\t\t\t\t\t\t     |");
	    printf("\n\t==============================================================");
	    printf("\n\t|\t\t\t\t\t\t\t     |");
        printf("\n\t| Total Price    \t = \t\t\t  %.2f\t |",netAmount);
        printf("\n\t|\t\t\t\t\t\t\t     |");
        printf("\n\t==============================================================");

        getch();
        exit(1);
}

void viewSales(char nic1[20])
{
    loadingProgressBar();

	system("cls");
	system("COLOR 0C");

	struct sales s;
	struct data d;

	float unitPrice, price;

	FILE *file1;
    FILE *file2;
    FILE *file3;

    file1 = fopen("customer.dat","r");
    file2 = fopen("s.dat","w");
    file3 = fopen("sales.dat","r");

    fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);
    fscanf(file3,"%d %d %f %f",&s.productCode,&s.quantity,&unitPrice,&price);

    while(!feof(file1))
    {
        if(strcmp(nic1,d.nic) != 0 )
        {
            fprintf(file2,"%s  %s  %s  %s  %d  %d  %f  %f\n",d.name,d.phone,d.address,d.district,s.productCode,s.quantity,unitPrice,price);
        }
       fscanf(file1,"%s %s %s %s %s %s",d.name,d.nic,d.phone,d.address,d.district,d.password);
       fscanf(file3,"%d %d %f %f",&s.productCode,&s.quantity,&unitPrice,&price);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);


}

void bookHalls()
{
   system("cls");
   system("COLOR 0B");

   printf("\n\n\t**************************************************************************************************");
   printf("\n\t**\t\t\t\t\t\t\t\t\t\t\t\t**");
   printf("\n\t**                               WELCOME TO CHILLOUT RESTAURANT                                 **");
   printf("\n\t**\t\t\t\t\t\t\t\t\t\t\t\t**");
   printf("\n\t**************************************************************************************************");
   printf("\n\t**\t\t\t\t\t\t\t\t\t\t\t\t**");
   printf("\n\t**                                      Hall BOOKING                                            **");
   printf("\n\t**\t\t\t\t\t\t\t\t\t\t\t\t**");
   printf("\n\t**************************************************************************************************");
   printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t\t |");
   printf("\n\t|  Package Code   |\t  Seating     |\t  Price for head   |\t   Menu     |\t  Facilities     |");
   printf("\n\t|------------------------------------------------------------------------------------------------|");
   printf("\n\t|     pk1          \t  50 - 150     \t     3000/=         \t   buffet    \t    non A/C      |");
   printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t\t |");
   printf("\n\t|     pk2          \t  50 - 150     \t     3500/=         \t   dinner    \t      A/C        |");
   printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t\t |");
   printf("\n\t|     pk3          \t 200 - 300     \t     3700/=         \t   dinner    \t    non A/C      |");
   printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t\t |");
   printf("\n\t|     pk4          \t 200 - 300     \t     4000/=         \t   dinner    \t      A/C        |");
   printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t\t |");
   printf("\n\t|     pk5          \t 300 - 500     \t     4500/=         \t   buffet    \t    non A/C      |");
   printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t\t |");
   printf("\n\t|     pk6          \t 300 - 500     \t     4700/=         \t   buffet    \t      A/C        |");
   printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t\t |");
   printf("\n\t**************************************************************************************************");

    char packageCode[10];
    char function[20];
    int day, month, noOfMembers;
    float priceForHead, total;

    FILE *file3;
	file3 = fopen("bookingDetails.dat","a");

   do
   {
   	    printf("\n\n\t\tEnter day              : ");
        scanf("%d",&day);

        if(day < 1 || day > 31)
        {
        	printf("\tInvalid Input");
		}

   }while(day < 1 || day > 31);

   do
   {
   	    printf("\n\n\t\tEnter month            : ");
        scanf("%d",&month);

        if(month < 1 || month > 12)
        {
        	printf("\tInvalid Input");
		}

   }while(month < 1 || month > 12);

   do
   {
   	    printf("\n\n\t\tEnter no of members    : ");
        scanf("%d",&noOfMembers);

        if(noOfMembers < 50 || noOfMembers > 500)
        {
        	printf("\tInvalid Input or No halls for more than 500 members..");
		}

   }while(noOfMembers < 50 || noOfMembers > 500);

   int option = 0;

   printf("\n\t\t 1. A/C\n\t\t 2. Non A/C");
   printf("\n\n\t\tEnter Your Option : ");
   scanf("%d",&option);

   if(option == 1)
   {
       if(noOfMembers >= 50 && noOfMembers <= 150)
       {
           priceForHead = 3500.00;
           strcpy(packageCode,"PK2");
       }
       else if(noOfMembers >= 200 && noOfMembers <= 300)
       {
           priceForHead = 4000.00;
           strcpy(packageCode,"PK4");
       }
       else if(noOfMembers > 300 && noOfMembers <= 500)
       {
           priceForHead = 4700.00;
           strcpy(packageCode,"PK6");
       }
   }
   else if(option == 2)
   {
       if(noOfMembers >= 50 && noOfMembers <= 150)
       {
           priceForHead = 3000.00;
           strcpy(packageCode,"PK1");
       }
       else if(noOfMembers >= 200 && noOfMembers <= 300)
       {
           priceForHead = 3700.00;
           strcpy(packageCode,"PK3");
       }
       else if(noOfMembers > 300 && noOfMembers <= 500)
       {
           priceForHead = 4500.00;
           strcpy(packageCode,"PK5");
       }
   }

        printf("\n\n\t\tEnter the Function      : ");
  	    scanf(" %s",function);

   total = noOfMembers * priceForHead;

   loadingProgressBar();

   system("cls");
   system("COLOR 0C");

   struct tm *myTime;
   time_t currentTime;

    currentTime = time(NULL);
    myTime = localtime(&currentTime);
    time(&currentTime);

    int monthToday, today, yearToday, hourNow, minNow, secNow;

    monthToday   = myTime->tm_mon + 1;
    today        = myTime->tm_mday;
    yearToday    = myTime->tm_year + 1900;
    hourNow      = myTime->tm_hour;
    minNow       = myTime->tm_min;
    secNow       = myTime->tm_sec;

    printf("\n\t=================================================");
    printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t|                     Bill                      |");
	printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t=================================================");
	printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t| DATE : %.2d/%.2d/%d\t                        |",monthToday,today,yearToday);
	printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t| TIME : %.2d:%.2d:%.2d\t                        |",hourNow,minNow,secNow);
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t=================================================");
    printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t|\tDate                  : %.2d - %.2d\t\t|",day,month);
	printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|\tFunction              : %s\t\t|",function);
    printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t|\tPackage Code          : %s\t\t|",packageCode);
	printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t|\tNumber of Members     : %d\t\t|",noOfMembers);
	printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t|\tPrice for Head        : %.2f\t\t|",priceForHead);
	printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t=================================================");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|\tTotal Price           : Rs. %.2f\t|",total);
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t=================================================");

    fprintf(file3,"%d  %d  %s  %s  %d  %.2f\n",day,month,packageCode,function,noOfMembers,total);

    fclose(file3);

    getch();
    exit(1);

}

void viewBookingDetails()
{
	loadingProgressBar();

	system("cls");
	system("COLOR 0C");

	printf("\n\n\t**********************************************************************************************");
    printf("\n\t**\t\t\t\t\t\t\t\t\t\t\t    **");
	printf("\n\t**                                     EVENT BOOKING                                        **");
	printf("\n\t**\t\t\t\t\t\t\t\t\t\t\t    **");
    printf("\n\t**********************************************************************************************");
    printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t     |");
	printf("\n\t|      DATE      |   PACKAGE CODE    |    FUNCTION     |    NO OF MEMBERS    |   TOTAL PRICE |");
	printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t     |");
    printf("\n\t==============================================================================================");
    printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t     |");

    char packageCode[10];
    char function[20];
    int day, month, noOfMembers;
    float total;

    FILE *file3;
	file3 = fopen("bookingDetails.dat","r");

       fscanf(file3,"%d %d %s %s %d %f",&day,&month,packageCode,function,&noOfMembers,&total);

       while(!feof(file3))
       {
           printf("\n\t|  %.2d - %.2d - 2021   |      %s\t     |    %s\t |      %.3d\t   |   %.2f     |",day,month,packageCode,function,noOfMembers,total);
           printf("\n\t|\t\t\t\t\t\t\t\t\t\t\t     |");
           fscanf(file3,"%d %d %s %s %d %f",&day,&month,packageCode,function,&noOfMembers,&total);
       }

       printf("\n\t==============================================================================================");
       printf("\n\n\n");

    fclose(file3);
}

void makeAppointments()
{

   system("cls");
   system("COLOR 0B");

   printf("\n\n\t************************************************************************************");
   printf("\n\t**\t\t\t\t\t\t\t\t\t\t  **");
   printf("\n\t**                         WELCOME TO CHILLOUT RESTAURANT                         **");
   printf("\n\t**\t\t\t\t\t\t\t\t\t\t  **");
   printf("\n\t************************************************************************************");
   printf("\n\t**\t\t\t\t\t\t\t\t\t\t  **");
   printf("\n\t**                              Table Reservation                                 **");
   printf("\n\t**\t\t\t\t\t\t\t\t\t\t  **");
   printf("\n\t************************************************************************************");

   int day, month, noOfMembers;
   float tablePrice, serviceCharge, total;

   FILE *file4;
   file4 = fopen("appointments.dat","a");

   do
   {
   	    printf("\n\n\t\tEnter day           : ");
        scanf("%d",&day);

        if(day < 1 || day > 31)
        {
        	printf("\tInvalid Input");
		}

   }while(day < 1 || day > 31);

   do
   {
   	    printf("\n\n\t\tEnter month         : ");
        scanf("%d",&month);

        if(month < 1 || month > 12)
        {
        	printf("\tInvalid Input");
		}

   }while(month < 1 || month > 12);

   do
   {
   	    printf("\n\n\t\tEnter no of members : ");
        scanf("%d",&noOfMembers);

        if(noOfMembers < 1 || noOfMembers > 25)
        {
        	printf("\tInvalid Input or No tables for more than 25 members..");
		}

   }while(noOfMembers < 1 || noOfMembers > 25);

   if( noOfMembers == 2 || noOfMembers == 3 || noOfMembers == 4)
   {
   	    tablePrice = 500.00;
   }
   else if(noOfMembers == 5 || noOfMembers == 6  || noOfMembers == 7)
   {
   	    tablePrice = 1200.00;
   }
   else if(noOfMembers == 8 || noOfMembers == 9 || noOfMembers == 10)
   {
   	    tablePrice = 1500.00;
   }
   else if(noOfMembers > 10)
   {
   	    if(noOfMembers < 26)
   	    {
   	    	tablePrice = 2000.00;
		}
   }

   serviceCharge = (tablePrice * 0.1);
   total = serviceCharge + tablePrice;

   loadingProgressBar();

   system("cls");
   system("COLOR 0C");

   struct tm *myTime;
   time_t currentTime;

    currentTime = time(NULL);
    myTime = localtime(&currentTime);
    time(&currentTime);

    int monthToday, today, yearToday, hourNow, minNow, secNow;

    monthToday   = myTime->tm_mon + 1;
    today        = myTime->tm_mday;
    yearToday    = myTime->tm_year + 1900;
    hourNow      = myTime->tm_hour;
    minNow       = myTime->tm_min;
    secNow       = myTime->tm_sec;

    printf("\n\n\t=================================================");
    printf("\n\t|\t\t\t\t\t\t|");
	printf("\n\t|                Bill for the Advance           |");
	printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t=================================================");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t| DATE : %.2d/%.2d/%d\t                        |",monthToday,today,yearToday);
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t| TIME : %.2d:%.2d:%.2d\t                        |",hourNow,minNow,secNow);
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t=================================================");
    printf("\n\t|\tDate                  : %.2d - %.2d         |",day,month);
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|\tTable Price           : Rs. %.2f      |",tablePrice);
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|\tService Charge 10%%    : Rs. %.2f       |",serviceCharge);
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t=================================================");
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t|\tTotal Price           : Rs. %.2f      |",total);
    printf("\n\t|\t\t\t\t\t\t|");
    printf("\n\t=================================================");

    fprintf(file4,"%d  %d  %d  %.2f\n",day,month,noOfMembers,total);

    fclose(file4);

}

void viewAppointmentsDetails()
{
	loadingProgressBar();

	system("cls");
	system("COLOR 0C");

	printf("\n\n\t*****************************************************************");
    printf("\n\t**\t\t\t\t\t\t\t       **");
	printf("\n\t**                        APPOINTMENTS                         **");
	printf("\n\t**\t\t\t\t\t\t\t       **");
    printf("\n\t*****************************************************************");
    printf("\n\t|\t\t\t|\t\t    |\t\t\t|");
    printf("\n\t|        DATE           |   NO OF MEMBERS   |     TOTAL PRICE   |");
    printf("\n\t|\t\t\t|\t\t    |\t\t\t|");
    printf("\n\t=================================================================");
    printf("\n\t|\t\t\t\t\t\t\t\t|");

    int day, month, noOfMembers;
    float total;

    FILE *file4;
    file4 = fopen("appointments.dat","r");

       fscanf(file4,"%d %d %d %f",&day,&month,&noOfMembers,&total);

       while(!feof(file4))
       {
           printf("\n\t|   %.2d - %.2d - 2021      |        %.2d         |        %.2f\t|",day,month,noOfMembers,total);
           printf("\n\t|\t\t\t\t\t\t\t\t|");
           fscanf(file4,"%d %d %d %f",&day,&month,&noOfMembers,&total);
       }
       printf("\n\t=================================================================");
       printf("\n\n\n");

    fclose(file4);
}

void managerLogin()
{
    char managerNic[20];
    char managerPassword[20];

    system("cls");
    system("COLOR 02");

    printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**             CHILLOUT RESTAURANT             **");
	printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");

    printf("\n\n\t  Enter Your NIC Number   : ");
    scanf(" %s", managerNic);

    printf("\n\n\t  Enter Your Password     : ");
    scanf(" %s", managerPassword);

   	if(managerNic == '1','2','3','4','5','6','7','8','9','v' && managerPassword == 'm','a','n','a','g','e','r','1','2','3')
   	{
		viewManagerMainmenu();
   	}
   	else
   	{
   		printf("\n\n\tIncorrect Password\n\tTry Again..");
   		sleep(2);
   		managerLogin();
   	}

}

void viewManagerMainmenu()
{
    system("cls");
    system("COLOR 09");

    printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**      WELCOME TO CHILLOUT RESTAURANT         **");
	printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|    [1] - Create Food Menu                     |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|    [2] - View Food Menu                       |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|    [3] - Update Food Menu                     |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|    [4] - Reports and Charts                   |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|    [5] - Exit                                 |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t=================================================");

    int option = 0;

    printf("\n\n\t  Enter Your Option : ");
    scanf("%d",&option);

    if(option == 1)
    {
        createFoodMenu();
    }
    else if(option == 2)
    {
        viewFoodMenu();

        int option1 = 0;

        printf("\n\n\t\t  1. Back to MainMenu");
        printf("\n\n\t\t  2. Exit");

        do
        {
        	printf("\n\n\t\tEnter Your Option : ");
            scanf("%d",&option1);

            if(option1 == 1)
           {
                viewManagerMainmenu();
           }
           else if(option1 == 2)
           {
                exitSystem();
           }
           else
           {
           	    printf("\tInvalid Input");
           	    sleep(2);
		   }

		}while(option1 != 1 || option1 != 2);
    }
    else if(option == 3)
    {
        updateMenu();
    }
    else if(option == 4)
    {
        viewReports();
    }
    else if(option == 5)
    {
    	exitSystem();
	}
}

void viewHeaderFoodMenu()
{
    printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**              Create Food Menu               **");
	printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");
}

void createFoodMenu()
{
    system("cls");

    int option = 0;
    int i = 0, found = 0, found1 = 0;
    int status, temp;

    FILE *file1;
    FILE *file2;
    FILE *file3;
    FILE *file4;
    FILE *file5;

    struct product p;

    do
    {
        system("cls");

        viewHeaderFoodMenu();

        file5 = fopen("foodMenu.dat","a");

        printf("\n\t|\t\t\t\t\t        |");
        printf("\n\t|     1. Breakfast                              |");
        printf("\n\t|\t\t\t\t\t        |");
        printf("\n\t|     2. Lunch                                  |");
        printf("\n\t|\t\t\t\t\t        |");
        printf("\n\t|     3. Dinner                                 |");
        printf("\n\t|\t\t\t\t\t        |");
        printf("\n\t|     4. Drinks                                 |");
        printf("\n\t|\t\t\t\t\t        |");
        printf("\n\t=================================================");

        int option1 = 0;

        printf("\n\n\t  Enter Your Option : ");
        scanf("%d",&option1);

        if(option1 == 1)
        {
            system("cls");

            viewHeaderFoodMenu();
            printf("\n\n");

            file1 = fopen("breakfast.dat","a");

            int found = 0;

            do
            {
                found = 1;

                printf("\n\t\tEnter Product Code  : ");
                status = scanf("%d",&p.productCode);

                while(status != 1)
                {

                   while((temp = getchar()) != EOF && temp != '\n');

                   printf("\n\tInvalid input... \n\t\tEnter Product Code     : ");
                   status = scanf("%d",&p.productCode);
                }

                count = (p.productCode == 0)?1:log10(p.productCode) + 1;

	            if(count > 4)
                {
                    found = 0;
                    printf("\n\tAdd a 4 digit Number.. Try Again...\n");
                }

                found1 = validateCode(p.productCode);

                if(found1 == 0)
                {
                    found = 0;
                    printf("\n\tAlready Taken.. Add another...\n");
                }

            }while(found == 0);

                printf("\n\t\tEnter Food Name     : ");
                scanf("%s",p.productName);

                printf("\n\t\tEnter Unit Price    : ");
                scanf("%f",&p.unitPrice);

                fprintf(file1,"%d %s %f\n",p.productCode,p.productName,p.unitPrice);
                fclose(file1);

        }
        else if(option1 == 2)
        {
            system("cls");

            viewHeaderFoodMenu();
            printf("\n\n");

            file2 = fopen("lunch.dat","a");

            do
            {
                found = 1;

                printf("\n\t\tEnter Product Code  : ");
                status = scanf("%d",&p.productCode);

                while(status != 1)
                {

                   while((temp = getchar()) != EOF && temp != '\n');

                   printf("\n\tInvalid input... \n\t\tEnter Product Code     : ");
                   status = scanf("%d",&p.productCode);
                }

                count = (p.productCode == 0)?1:log10(p.productCode) + 1;

	            if(count > 4)
                {
                    found = 0;
                    printf("\n\tAdd a 4 digit Number.. Try Again...\n");
                }

                found1 = validateCode(p.productCode);

                if(found1 == 0)
                {
                    found = 0;
                    printf("\n\tAlready Taken.. Add another...\n");
                }

            }while(found == 0);

            printf("\n\t\tEnter Food Name     : ");
            scanf("%s",p.productName);

            printf("\n\t\tEnter Unit Price    : ");
            scanf("%f",&p.unitPrice);

            fprintf(file2,"%d %s %.2f\n",p.productCode,p.productName,p.unitPrice);
            fclose(file2);

        }
        else if(option1 == 3)
        {
            system("cls");

            viewHeaderFoodMenu();
            printf("\n\n");

            file3 = fopen("dinner.dat","a");

            do
            {
                found = 1;

                printf("\n\t\tEnter Product Code  : ");
                status = scanf("%d",&p.productCode);

                while(status != 1)
                {

                   while((temp = getchar()) != EOF && temp != '\n');

                   printf("\n\tInvalid input... \n\t\tEnter Product Code     : ");
                   status = scanf("%d",&p.productCode);
                }

                count = (p.productCode == 0)?1:log10(p.productCode) + 1;

	            if(count > 4)
                {
                    found = 0;
                    printf("\n\tAdd a 4 digit Number.. Try Again...\n");
                }

                found1 = validateCode(p.productCode);

                if(found1 == 0)
                {
                    found = 0;
                    printf("\n\tAlready Taken.. Add another...\n");
                }

            }while(found == 0);

            printf("\n\t\tEnter Food Name     : ");
            scanf("%s",p.productName);

            printf("\n\t\tEnter Unit Price    : ");
            scanf("%f",&p.unitPrice);

            fprintf(file3,"%d %s %.2f\n",p.productCode,p.productName,p.unitPrice);
            fclose(file3);

        }
        else if(option1 == 4)
        {
            system("cls");

            viewHeaderFoodMenu();
            printf("\n\n");

            file4 = fopen("drinks.dat","a");

            do
            {
                found = 1;

                printf("\n\t\tEnter Product Code  : ");
                status = scanf("%d",&p.productCode);

                while(status != 1)
                {

                   while((temp = getchar()) != EOF && temp != '\n');

                   printf("\n\tInvalid input... \n\t\tEnter Product Code     : ");
                   status = scanf("%d",&p.productCode);
                }

                count = (p.productCode == 0)?1:log10(p.productCode) + 1;

	            if(count > 4)
                {
                    found = 0;
                    printf("\n\tAdd a 4 digit Number.. Try Again...\n");
                }

                found1 = validateCode(p.productCode);

                if(found1 == 0)
                {
                    found = 0;
                    printf("\n\tAlready Taken.. Add another...\n");
                }

            }while(found == 0);

            printf("\n\t\tEnter Food Name     : ");
            scanf("%s",p.productName);

            printf("\n\t\tEnter Unit Price    : ");
            scanf("%f",&p.unitPrice);

            fprintf(file4,"%d %s %.2f\n",p.productCode,p.productName,p.unitPrice);
            fclose(file4);
        }

        printf("\n\n\tDo You Want to Add Another?(1 - Yes or 2 - No) : ");
        scanf("%d",&option);

        fwrite(&p,sizeof(struct product),1,file5);
        fclose(file5);

        if(option == 2)
        {
            system("cls");

            int option2 = 0;

            printf("\n\t\t````````````````````````````");
            printf("\n\t\t    SUCCESSFULLY CREATED   ");
            printf("\n\n\t\t````````````````````````````");

            printf("\n\t=================================================");
            printf("\n\t|\t\t\t\t\t        |");
            printf("\n\t|    [1] - Back to Main Menu                    |");
            printf("\n\t|\t\t\t\t\t        |");
            printf("\n\t|    [2] - Exit                                 |");
            printf("\n\t|\t\t\t\t\t        |");
            printf("\n\t=================================================");

            printf("\n\n\tEnter Your Option : ");
            scanf("%d",&option2);

            if(option2 == 1)
            {
                viewManagerMainmenu();
            }
            else if(option == 2)
            {
                exitSystem();
            }

        }

    }while(option == 1);

}

int validateCode(int code)
{
    FILE *file;
    file = fopen("foodMenu.dat","r");

    struct product p;

    while(fread(&p,sizeof(struct product),1,file))
    {
        if(code == p.productCode)
        {
            return 0;
        }
    }

    fclose(file);
    return 1;
}

void viewFoodMenu()
{
	system("cls");
	system("COLOR 0E");

	printf("\n\n\t***********************************************************");
    printf("\n\t**\t\t\t\t\t\t\t **");
	printf("\n\t**                F O O D         M E N U                **");
	printf("\n\t**\t\t\t\t\t\t\t **");
    printf("\n\t***********************************************************");
    printf("\n\t|               | product Code  |  Product Name  |  Price |");
    printf("\n\t----------------------------------------------------------|");

	struct product p;

	FILE *file1;
	FILE *file2;
	FILE *file3;
	FILE *file4;

	printf("\n\t|   BREAKFAST   |\t\t\t\t\t  |");

	file1 = fopen("breakfast.dat","r");
	fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);

	while(!feof(file1))
	{
		printf("\n\t|               |  %.2d\t   %s \t  %.2f \t  |",p.productCode,p.productName,p.unitPrice);
		fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);
	}
	printf("\n\t----------------------------------------------------------|");
	fclose(file1);

	printf("\n\t|    LUNCH      |\t\t\t\t\t  |");

	file2 = fopen("lunch.dat","r");
	fscanf(file2,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);

	while(!feof(file2))
	{
		printf("\n\t|               |  %.2d\t   %s \t  %.2f \t  |",p.productCode,p.productName,p.unitPrice);
		fscanf(file2,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);
	}
	printf("\n\t----------------------------------------------------------|");
	fclose(file2);

	printf("\n\t|    DINNER     |\t\t\t\t\t  |");

	file3 = fopen("dinner.dat","r");
	fscanf(file3,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);

	while(!feof(file3))
	{
		printf("\n\t|               |  %.2d\t   %s \t  %.2f \t  |",p.productCode,p.productName,p.unitPrice);
		fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);
	}
	printf("\n\t----------------------------------------------------------|");
	fclose(file3);

	printf("\n\t|    DRINKS     |\t\t\t\t\t  |");

	file4 = fopen("drinks.dat","r");
	fscanf(file4,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);

	while(!feof(file4))
	{
		printf("\n\t|               |  %.2d\t   %s \t  %.2f \t  |",p.productCode,p.productName,p.unitPrice);
		fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);
	}
	printf("\n\t----------------------------------------------------------|");
	fclose(file4);

}

void viewReports()
{
    system("cls");
	system("COLOR 0E");

    printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**      WELCOME TO CHILLOUT RESTAURANT         **");
	printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|    [1] - Customer Details                     |");
	printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|    [2] - Sales Report                         |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|    [3] - Booking Details                      |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|    [4] - Appointment Details                  |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|    [5] - Exit                                 |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t=================================================");

    int option = 0;

    printf("\n\n\t  Enter Your Option : ");
    scanf("%d",&option);

    if(option == 1)
    {
        viewCustomerDetails();
    }
    else if(option == 2)
    {
        //viewSales();
    }
    else if(option == 3)
    {
        viewBookingDetails();
    }
    else if(option == 4)
    {
        viewAppointmentsDetails();
    }
    else if(option == 5)
    {
        exitSystem();
    }
    else
    {
        viewReports();
    }
}

void updateMenu()
{
    system("cls");

    printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**             CHILLOUT RESTAURANT             **");
	printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t                 UPDATE MENU                   **");
    printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|     [1] - Add Products                        |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|     [2] - Remove Products                     |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t=================================================");

    int option = 0;

    printf("\n\n\t  Enter Your Option : ");
    scanf("%d",&option);

    if(option == 1)
    {
        createFoodMenu();
    }
    else if(option == 2)
    {
        removeProduct();
    }
    else
    {
        printf("\n\n\tIncorrect Input..\n\tTry Again..");
   		sleep(2);
   		updateMenu();
    }

}

void removeProduct()
{
	system("cls");
	system("COLOR 0D");

	int option = 0;

	printf("\n\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
	printf("\n\t**             CHILLOUT RESTAURANT             **");
	printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");
    printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t                REMOVE PRODUCT                 **");
    printf("\n\t**\t\t\t\t\t       **");
    printf("\n\t*************************************************");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|     [1] - Breakfast                           |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|     [2] - Lunch                               |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|     [1] - Dinner                              |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t|     [2] - Drinks                              |");
    printf("\n\t|\t\t\t\t\t        |");
    printf("\n\t=================================================");

    printf("\n\n\t  Enter Your Option : ");
    scanf("%d",&option);

    if(option == 1)
    {
        removeBreakfast();
    }
    else if(option == 2)
    {
        removeLunch();
    }
    else if(option == 3)
    {
        removeDinner();
    }
    else if(option == 4)
    {
        removeDrinks();
    }
    else
    {
        printf("\n\n\tIncorrect Input..\n\tTry Again..");
   		sleep(2);
   		removeProduct();
    }

}

void removeBreakfast()
{
    system("cls");
	system("COLOR 0D");

    int code = 0;

    struct product p;

    FILE *file1;
    FILE *file2;

    file1 = fopen("breakfast.dat","r");
    file2 = fopen("copy.dat","w");

    printf("\n\t\tEnter the Food Code you want to remove : ");
    scanf("%d",&code);

    fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);

    while(!feof(file1))
    {
        if(code != p.productCode)
        {
            fprintf(file2,"%d %s %.2f\n",p.productCode,p.productName,p.unitPrice);
        }
      fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);
    }

    fclose(file1);
    fclose(file2);

    remove("breakfast.dat");
	rename("copy.dat","breakfast.dat");

	loadingProgressBar();

	system("cls");

	printf("\n\n\t\t\t```````````````````````````````````````");
    printf("\n\t\t\t****************************************");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t**     It's Removed Successfully!     **");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t````````````````````````````````````````");
    printf("\n\t\t\t****************************************");

    removeAllFoods(code);

}

void removeLunch()
{
    system("cls");
	system("COLOR 0D");

    int code = 0;

    struct product p;

    FILE *file1;
    FILE *file2;

    file1 = fopen("lunch.dat","r");
    file2 = fopen("copy.dat","w");

    printf("\n\t\tEnter the Food Code you want to remove : ");
    scanf("%d",&code);

    fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);

    while(!feof(file1))
    {
        if(code != p.productCode)
        {
            fprintf(file2,"%d %s %f\n",p.productCode,p.productName,p.unitPrice);
        }
      fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);
    }

    fclose(file1);
    fclose(file2);

    remove("lunch.dat");
	rename("copy.dat","lunch.dat");

	loadingProgressBar();

	system("cls");

	printf("\n\n\t\t\t```````````````````````````````````````");
    printf("\n\t\t\t****************************************");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t**     It's Removed Successfully!     **");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t````````````````````````````````````````");
    printf("\n\t\t\t****************************************");

    removeAllFoods(code);

}

void removeDinner()
{
    system("cls");
	system("COLOR 0D");

    int code = 0;

    struct product p;

    FILE *file1;
    FILE *file2;

    file1 = fopen("dinner.dat","r");
    file2 = fopen("copy.dat","w");

    printf("\n\t\tEnter the Food Code you want to remove : ");
    scanf("%d",&code);

    fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);

    while(!feof(file1))
    {
        if(code != p.productCode)
        {
            fprintf(file2,"%d %s %.2f\n",p.productCode,p.productName,p.unitPrice);
        }
      fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);
    }

    fclose(file1);
    fclose(file2);

    remove("dinner.dat");
	rename("copy.dat","dinner.dat");

	loadingProgressBar();

	system("cls");

	printf("\n\n\t\t\t```````````````````````````````````````");
    printf("\n\t\t\t****************************************");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t**     It's Removed Successfully!     **");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t````````````````````````````````````````");
    printf("\n\t\t\t****************************************");

    removeAllFoods(code);

}

void removeDrinks()
{
    system("cls");
	system("COLOR 0D");

    int code = 0;

    struct product p;

    FILE *file1;
    FILE *file2;

    file1 = fopen("drinks.dat","r");
    file2 = fopen("copy.dat","w");

    printf("\n\t\tEnter the Food Code you want to remove : ");
    scanf("%d",&code);

    fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);

    while(!feof(file1))
    {
        if(code != p.productCode)
        {
            fprintf(file2,"%d %s %.2f\n",p.productCode,p.productName,p.unitPrice);
        }
      fscanf(file1,"%d %s %f",&p.productCode,p.productName,&p.unitPrice);
    }

    fclose(file1);
    fclose(file2);

    remove("drinks.dat");
	rename("copy.dat","drinks.dat");

	loadingProgressBar();

	system("cls");

	printf("\n\n\t\t\t```````````````````````````````````````");
    printf("\n\t\t\t****************************************");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t**     It's Removed Successfully!     **");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t````````````````````````````````````````");
    printf("\n\t\t\t****************************************");

    removeAllFoods(code);

}

void removeAllFoods(int code)
{
    FILE *fp1,*fp2;

	struct product p;

	fp1 = fopen("foodMenu.dat","r");
	fp2 = fopen("copy.dat","a+");

	while(fread(&p,sizeof(struct product),1,fp1))
	{
		if(code != p.productCode)
		{
			fwrite(&p,sizeof(struct product),1,fp2);
		}
	}

	fclose(fp1);
	fclose(fp2);

	remove("foodMenu.dat");
	rename("copy.dat","foodMenu.dat");

}

void loadingProgressBar()
{
	system("cls");
	system("COLOR 08");

    char a = 177, b = 219;
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\tLoading....\n\n");
    printf("\t\t");

    int i;
    for (i = 0; i < 23; i++)
        printf("%c", a);

    printf("\r");
    printf("\t\t");

    for (i = 0; i < 23; i++)
    {
        printf("%c", b);
        Sleep(50);
    }
}

void exitSystem()
{
	loadingProgressBar();

    system("cls");
    system("COLOR 04");

    printf("\n\n");
    printf("\n\n\t\t\t`````````````````````````````````````");
    printf("\n\t\t\t*************************************");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t**           THANK YOU!            **");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t**         HAVE A NICE DAY         **");
    printf("\n\t\t\t**\t\t\t\t   **");
    printf("\n\t\t\t*************************************");
    printf("\n\t\t\t`````````````````````````````````````");

    printf("\n\n\n");
}
