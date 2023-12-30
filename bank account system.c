                                                 /******************************************
                                                  **                                      **
                                                  **    BANK ACCOUNT MANANGEMENT SYSTEM   **
                                                  **    PROGRAMMED IN C                   **
                                                  **    BY PRANAV BHATLAPENUMARTHI        **
                                                  **                                      **
                                                  ******************************************/

// IMPORTING ALL NECCESSARY HEADER FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DECLARING ALL NECCESSARY FUNCTIONS
void checkbalance(void);
void transfermoney(void);
void display(char*);
void login(void);
void login1(void);
void acc(void);
void acc_created(void);
void logout(void);

// CREATING A STRUCTURE OT STORE THE DATA OF THE USER
struct user_data{
    char username[50];
    int date, month, year; // for D.O.B
    char mobilenumber[15];
    char aadharnumber[15];
    char firstname[25];
    char lastname[25];
    char fathername[50];
    char mothername[50];
    char address[100];
    char acc_type[20];
    char password[35];
    int initial_amount;
};

// CREATING A STRUCTURE TO KEEP TRACK OF MONEY TRANSFER
struct transact{
    char username_to[50];
    char username_from[50];
    long int amount;
};

// DRIVER CODE
int main(void)
{
    int choice;

    printf("\n\n\t\t\t\t===== BANK MANAGEMENT SYSTEM ======\n\n\n\n");
    printf("\t1...CREATE NEW BANK ACCOUNT\n\n\t2...LOGIN INTO EXISTING ACCOUNT\n\n\t3...EXIT PORTAL");
    printf("\n\n\t----------------------------------------------------------------------------");
    printf("\n\n\tENTER YOUR CHOICE:  "); scanf("%d", &choice); //Receiving input from the user

    // Initialising switch case w.r.t choice

    switch(choice){
    case 1:
        system("cls");
        printf("\n\n\tENTER USER NAME (MAX. 50 CHARACTERS)");
        printf("\n\tENTER PASSWORD(MAX. 20 CHARACTERS)");
        acc();
        break;

    case 2:
        login();
        break;

    case 3:
        exit(0);
        break;

    default:
        break;
    }
    //printf("\n\n\t\tthis is a test run\n\n");
}

// DEFINING THE FUNCTION BODY USED TO CREATE NEW ACCOUNTS
void acc(void)
{
    char password[20], ch;
    int passwdlen, i, seek = 0;
    FILE *fp, *fu;
    struct user_data u1;

    // Opening file to write the data of the user
    fp = fopen("user3.txt", "wb");

    //Receiving the inputs from the user
    system("cls");
    printf("\n\n\t*****CREATING A NEW ACCOUNT*****\n\n");
    printf("\n\tFIRST NAME:   "); scanf("%s", &u1.firstname);
    printf("\n\tLAST NAME:   "); scanf("%s", &u1.lastname);

    // Taking input for DOB and checking respective conditions
    printf("\n\tDATE OF BIRTH:"); printf("\n\t\tDATE:   "); scanf("%d", &u1.date);
    if((u1.date > 31) | (u1.date < 0))
    {
        printf("\n\t\tINVALID INPUT !\n");
        printf("\n\t\tDATE:   "); scanf("%d", &u1.date);
    }
    printf("\n\t\tMONTH(1-12):   "); scanf("%d", &u1.month);
    if((u1.month < 0) | (u1.month > 12))
    {
        printf("\n\t\tINVALID INPUT !\n");
        printf("\n\t\tMONTH:   "); scanf("%d", &u1.month);
    }
    printf("\n\t\tYEAR:   "); scanf("%d", &u1.year);
    if(u1.year > 2024)
    {
        printf("\n\t\tINVALID INPUT !\n");
        printf("\n\t\tYEAR:   "); scanf("%d", &u1.year);
    }
    // Proceeding with other information inputs

    printf("\n\tAADHAR NUMBER:   "); scanf("%s", &u1.aadharnumber);
    if (strlen(u1.aadharnumber) > 13)
    {
        printf("\n\tINVALID INPUT !\n");
        printf("\n\tAADHAR NUMBER:   "); scanf("%s", &u1.aadharnumber);
    }
    printf("\n\tMOBILE NUMBER(NO SPACE BETWEEN COUNTRY CODE AND MOBILE NUMBER):   "); scanf("%s", &u1.mobilenumber);
    if (strlen(u1.mobilenumber) > 14)
    {
        printf("\n\tINVALID INPUT !\n");
        printf("\n\tMOBILE NUMBER(NO SPACE BETWEEN COUNTRY CODE AND MOBILE NUMBER):   "); scanf("%s", &u1.mobilenumber);
    }
    for(i = 0; i<strlen(u1.mobilenumber); i++){
        if(i >=48 & i<= 57)
            continue;
        else
            break;
    }
    printf("\n\n\tINVALID INPUT. PLEASE ENTER VALID MOBILE NUMBER");
    printf("\n\tMOBILE NUMBER(NO SPACE BETWEEN COUNTRY CODE AND MOBILE NUMBER):   "); scanf("%s", &u1.mobilenumber);

    printf("\n\tFATHER NAME:   "); scanf("%s", &u1.fathername);
    printf("\n\tMOTHER NAME:   "); scanf("%s", &u1.mothername);
    printf("\n\tADDRESS:   "); scanf("%s", &u1.address);
    printf("\n\tACCOUNT TYPE(FD/RD/Savings/Salary):   "); scanf("%s", &u1.acc_type);
    printf("\n\tINITIAL AMOUNT OF MONEY TO BE STORED:   "); scanf("%d", &u1.initial_amount);

    printf("\n\tUSERNAME(NO SPACE):   ");scanf("%s", &u1.username);
    printf("\n\tPASSWORD:   "); scanf("%s", &u1.password);

    fwrite(&u1, sizeof(u1), 1, fp);

    fclose(fp);

    acc_created(); // Calling another function after the account is created successfully

}

// DEFINING FUNCTION BODY FOR THE NEXT STEP AFTER ACCOUNT CREATION
void acc_created(void)
{
    int i; char ch;
    printf("\n\n\t\tPLEASE WAIT WHILE WE PROCESS YOUR DATA...");

    for(i = 0; i < 20000000; i++)
    {
        i++;i--;
    }
    printf("\n\n\t\tACCOUNT CREATED SUCCESSFULLY !");

    login();
}

// FUNCTION DEFINITION FOR LOGIN PROCESS
void login(void)
{
    char username[50], password[50];
    int i; char ch;
    FILE *fp;
    struct user_data u1;

    fp = fopen("user3.txt", "rb");
    if (fp == NULL)
    {
        printf("\n\n\tERROR IN OPENING FILE");
    }

    printf("\n\n\t\t ==== LOGIN ====");

    printf("\n\n\tUSERNAME... "); scanf("%s", &username);
    printf("\n\tPASSWORD... "); scanf("%s", &password);



    // verifying username and password of the user with the data in the file
    while(fread(&u1, sizeof(u1),1, fp))
    {
        if((strcmp(username, u1.username) == 0) & (strcmp(password, u1.password) == 0))
            {
                login1();
                display(username);
                break;
            }
        else
        {
            while((strcmp(username, u1.username) != 0) | (strcmp(password, u1.password) != 0))
            {
                printf("\n\tINVALID USER ID OR PASSWORD. PLEASE TRY AGAIN.");
                printf("\n\n\tUSERNAME... "); scanf("%s", &username);
                printf("\n\tPASSWORD... "); scanf("%s", &password);

                if((strcmp(username, u1.username) == 0) & (strcmp(password, u1.password) == 0))
                {
                    login1();
                    display(username);
                    break;
                }
            }
        }
    }

    fclose(fp);
}

// REDIRECTING AFTER SUCCESSFUL LOGIN
void login1(void)
{
    int i; char ch;

    system("cls");
    printf("\nVERIFYING LOGIN CREDENTIALS....");

    for(i = 0; i < 200000; i++)
    {
        i++; i--;
    }

    printf("\n\nLOGIN SUCCESSFUL !\nPRESS ENTER TO CONTINUE..");

    ch = getchar();

    if(ch == 13)
    {
        printf("\n\nPLEASE WAIT WHILE WE FETCH YOUR ACCOUNT DETAILS....");
    }
}

// DISPLAYING ACCOUNT DETAILS OF USER
void display(char username1[])
{
    system("cls");
    FILE *fp;
    int choice, i;
    fp = fopen("user3.txt", "rb");
    struct user_data u1;

    if( fp == NULL )
    {
        printf("\n\tERROR ENCOUNTERED WHILE ACCESSING FILE.");
    }

    while(fread(&u1, sizeof(u1) , 1, fp))
    {
        if(strcmp(username1, u1.username) == 0)
        {
            printf("\n\n\tWELCOME %s %s", u1.firstname, u1.lastname);
            printf("\n\t--------------------------------------");
            printf("\n\n\t\t===== ACCOUNT HOLDER DATA =====");
            printf("\n\n\tFATHER NAME: %s %s", u1.fathername, u1.lastname);
            printf("\n\n\tMOTHER NAME: %s %s", u1.mothername, u1.lastname);
            printf("\n\n\tAADHAR NUMBER: %s", u1.aadharnumber);
            printf("\n\n\tACCOUNT TYPE: %s", u1.acc_type);
        }
    }

    fclose(fp);

    // Menu options to perform different actions after logging in

    printf("\n\n\t\t ===== HOME =====");
    printf("\n\n\t1...CHECK ACCOUNT BALANCE");
    printf("\n\n\t2...TRANSFER MONEY");
    printf("\n\n\t3...LOG OUT");
    printf("\n\n\t4...EXIT");

    printf("\n\n\t\tENTER YOUR PREFERENCE:  "); scanf("%d", &choice);\

    // Initialising switch case according to user choice

    switch(choice){
    case 1:
        checkbalance();
        break;

    case 2:
        transfermoney();
        break;

    case 3:
        logout();
        break;

    case 4:
        exit(0);
        break;

    default:
        break;
    }

}

// FUNCTION DEFINITION TO CHECK TRANSACTION HISTORY AND AMOUNT BALANCE
void checkbalance(void)
{
    system("cls");
    FILE *fm, *fp;
    struct user_data u1;
    struct transact t1;
    char ch;
    int i = 1, tot_amount = 0, ini,p,q;

    fm = fopen("transactions3.txt", "rb");
    fp = fopen("user3.txt", "rb");

    printf("\n\n\t\t========== TRANSACTION HISTORY ==========");
    printf("\n\n\n\tS.NO"); printf("\t\tTRANSACTION ID"); printf("\t\tAMOUNT TRANSFERRED");

    while(fread(&t1, sizeof(t1), 1, fm))
    {
        printf("\n\n\t%d", i++); printf("\t\t%s", t1.username_to); printf("\t\t\t%d", t1.amount);
        printf("\n\n");
        tot_amount += t1.amount;
    }

    while(fread(&u1, sizeof(u1), 1, fp))
    {
        ini = u1.initial_amount;
    }
    printf("\n\n\tINITIAL AMOUNT IN THE ACCOUNT:  %d", ini);
    printf("\n\n\tTOTAL MONEY TRANSACTED:  %d", tot_amount); ini -= tot_amount;
    printf("\n\n\tREMAINING AMOUNT: %d\n\n",ini);

    fclose(fm);fclose(fp);

    printf("\n\n\tGOING BACK TO USER MENU...");
    for(p = 0; p < 100000; p++)
        for(q = 0 ; q < 20000; q++)
            continue;

    display(u1.username);
}

// FUNCTION BODY FOR MONEY TRANSACTIONS
void transfermoney(void)
{
    int i, j;
    FILE *fm, *fp;
    struct user_data u1;
    struct transact t1;
    char receiver[50], sender[50], ch, chr;

    system("cls");

    fp = fopen("user3.txt", "rb");
    fm = fopen("transactions3.txt", "ab"); // Creating new file to store transaction history

    printf("\n\n\t ===== TRANSFER MONEY =====");
    printf("\n\t SENDER(your username):  ");scanf("%s", &sender);
    printf("\n\t RECIPIENT(receiver's username):  "); scanf("%s", &receiver);

    while(fread(&u1, sizeof(u1), 1, fp))
    {
        if(strcmp(u1.username, sender) == 0)
        {
            strcpy(t1.username_from, sender);
            strcpy(t1.username_to, receiver);
        }
        else if(strcmp(u1.username, sender) != 0)
        {
            while(strcmp(u1.username, sender) != 0)
            {
                printf("\n\t INVALID SENDER USERNAME. PLEASE TRY AGAIN");
                printf("\n\t SENDER(your username):  ");scanf("%s", &sender);

                if(strcmp(u1.username, sender) == 0)
                {
                    strcpy(t1.username_from, sender);
                    strcpy(t1.username_to, receiver);
                }
            }
        }

        if(strcmp(sender, receiver) == 0)
        {
            while(strcmp(sender, receiver) == 0)
            {
                printf("\n\t SENDER AND RECEIVER CANNOT BE THE SAME. PLEASE ENTER VALID RECIPIENT ID");
                printf("\n\t RECIPIENT:  ");scanf("%s", &receiver);
            }

            if(strcmp(sender, receiver) != 0)
            {
                strcpy(t1.username_from, sender);
                strcpy(t1.username_to, receiver);
            }
        }

    }

    printf("\n\n\t\tENTER AMOUNT TO TRANSFERRED:   ");scanf("%ld", &t1.amount);
    if(t1.amount > u1.initial_amount)
    {
        printf("\n\t\tINSUFFICIENT AMOUNT IN ACCOUNT. TOTAL AMOUNT IN ACCOUNT: %d", u1.initial_amount);
        printf("\n\n\t\tENTER AMOUNT TO TRANSFERRED:   ");scanf("%ld", &t1.amount);

        if(t1.amount == u1.initial_amount)
        {
            printf("\n\n\tMONEY TO BE TRANSCATED IS EQUAL TO THE REMAINING BALANCE AMOUNT IN THE ACCOUNT...");
            printf("\n\tPRESS ENTER TO PROCEED WITH THE TRANSACTION. PRESS ANY KEY TO REVIEW THE AMOUNT TO BE TRANSACTED...");
            chr = getchar();

            if( ch != 13)
                printf("\n\n\t\tENTER AMOUNT TO TRANSFERRED:   ");scanf("%ld", &t1.amount);
        }
    }

    fwrite(&t1, sizeof(t1), 1, fm);

    printf("\n\n\t\tTRANSACTION IN PROCESS...\n");

    for(i = 0; i < 10; i++)
        printf("\t*");

    for(j = 0; j < 100000000; j++)
        j++; j--;

    printf("\n\n\t\tTRANSACTION SUCCESSFULL");

    fclose(fp);
    fclose(fm);

    printf("\n\n\tGOING BACK TO USER MENU...");
    for(i = 0; i < 100000; i++)
        for(j = 0 ; j < 5000; j++)
            continue;

    display(sender);
}

// FUNCTION DEFINTION TO LOGOUT OF THE PORTAL
void logout(void)
{
    int i,j;
    char ch;

    system("cls");
    printf("\n\n\t\tLOGGING YOU OUT....");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 25000000; j++) {
            i++;
            i--;
        }
        printf(".");
    }

    printf("\n\n\t\tSUCCESSFULLY LOGGED OUT..");
}




                                                            /***************************

                                                                  PROGRAM COMPLETE

                                                             ***************************/
