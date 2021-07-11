#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j;
int main_exit;
void menu();
void close();
struct date
{
    int month, day, year;
};
struct
{
    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
}add, upd, check, rem, transaction;

void fordelay(int j)
{
    int i, k;

    for(i = 0; i < j; i++)
        k = i;
}

void new_acc()
{
    int choice;
    FILE *ptr;

    ptr = fopen("record.dat", "a+");
    account_no:
    system("clear");
    printf("\t\t\txB2\xB2\xB2\\ ADD RECORD \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy): ");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    printf("\nEnter the account number: ");
    scanf("%d", &check.acc_no);

    while(fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if(check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;
        }
    }

    add.acc_no = check.acc_no;
    printf("\nEnter the name: ");
    scanf("%s", add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy): ");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter the age: ");
    scanf("%d", &add.age);
    printf("\nEnter the address");
    scanf("%s", add.address);
    printf("\nEnter the citizenship number: ");
    scanf("%s", add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf", &add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f", &add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\n\tEnter your choice: ");
    scanf("%s", add.acc_type);

    fprintf(ptr, "%d %s %d;%d;%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

    fclose(ptr);

    printf("\nAcount creted successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go the main and 0 to exit: ");
    scanf("%d", &main_exit);
    system("clear");

    if(main_exit == 1)
        menu();
    else if(main_exit == 0)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

void close()
{
    printf("\n\n\n\nThis C Mini Project is developed by Code With C team!\n");
}

void menu()
{
    int choice;
    system("clear");
    system("color 6F");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\t\t1.Create new account\n\t\t2.Updaet information of existin account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice: ");
    scanf("%d", &choice);

    system("clear");

    switch(choice)
    {
        case 1: new_acc(); break;
        //case 2: edit(); break;
        //case 3: transact(); break;
        //case 4: see(); break;
        //case 5: erase(); break;
        //case 6: view_list(); break;
        case 7: close(); break;
    }
}

int main()
{
    char pass[10], password[10] = "codewithc";
    int i = 0;
    printf("\n\n\tEnter the password to login:");
    fgets( pass, 10, stdin);
    /*do
    {
        if(pass[i] != 13 && pass[i] != 8)
        {
            printf("*");
            pass[i] = getchar();
            i++;
        }
    }while(pass[i] != 13);
    pass[10] = '\0';*/
    
    if(strcmp(pass, password) == 0)
    {
        printf("\n\nPassword Match!\nLOADIN");

        for(i = 0; i <= 6; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("clear");
        menu();
    }
    else
    {
        printf("\n\nWrong password!!\a\a\a");
        login_try:
        printf("\nEnter 1 to try again and 0 to exit: ");
        scanf("%d", &main_exit);

        if(main_exit == 1)
        {
            system("clear");
            main();
        }
        else if(main_exit == 0)
        {
            system("clear");
            close();
        }
        else
        {
            printf("\nInvalid!");
            fordelay(100000000);
            system("clear");
            goto login_try;
        }
    }

    return(0);
}
