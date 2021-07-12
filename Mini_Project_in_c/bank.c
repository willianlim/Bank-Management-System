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
struct format
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

float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate*t*amount)/100.0;
    return(SI);
}

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
    char p;

    ptr = fopen("record.dat", "a+");
    account_no:
    system("clear");
    printf("\t\t\txB2\xB2\xB2\\ ADD RECORD \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy): / / ");
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    setbuf(stdin, NULL);
    printf("\nEnter the account number: ");
    scanf("%d", &check.acc_no);
    setbuf(stdin, NULL);

    while(fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if(check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!");
            fordelay(1000000000);
            goto account_no;
        }
        break;
    }

    add.acc_no = check.acc_no;
    printf("\nEnter the name: ");
    scanf("%s", add.name);
    setbuf(stdin, NULL);
    printf("\nEnter the date of birth(mm/dd/yyyy): ");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    setbuf(stdin, NULL);
    printf("\nEnter the age: ");
    scanf("%d", &add.age);
    setbuf(stdin, NULL);
    printf("\nEnter the address");
    scanf("%s", add.address);
    setbuf(stdin, NULL);
    printf("\nEnter the citizenship number: ");
    scanf("%s", add.citizenship);
    setbuf(stdin, NULL);
    printf("\nEnter the phone number: ");
    scanf("%lf", &add.phone);
    setbuf(stdin, NULL);
    printf("\nEnter the amount to deposit:$");
    scanf("%f", &add.amt);
    setbuf(stdin, NULL);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\n\tEnter your choice: ");
    scanf("%s", add.acc_type);
    setbuf(stdin, NULL);

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

void view_list()
{
    FILE *view;
    view = fopen("record.dat", "r");
    int test = 0;
    system("clear");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("\n%6d\t\t%10s\t\t\t%10s\t\t%11.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
        break;
    }

    fclose(view);

    if(test == 0)
    {
        system("clear");
        printf("\nNO RECORDS!!\n");
    }

    view_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d", &main_exit);
    system("clear");

    if(main_exit == 1)
        menu();
    else if(main_exit == 0)
        close();
    else
    {
        printf("\nInvalid!\n");
        goto view_list_invalid;
    }
}

void edit()
{
    int choice, test = 0;
    FILE *old, *newrec;

    old = fopen("record.dat", "r");
    newrec = fopen("nex.dat", "w");
    
    printf("\nEnter the account no. of the customer whose info you want to change: ");
    scanf("%d", &upd.acc_no);
    setbuf(stdin, NULL);

    while(fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF)
    {
        if(add.acc_no == upd.acc_no)
        {
            test = 1;
            printf("\nWhich infromation do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone): ");
            scanf("%d", &choice);
            system("clear");

            if(choice == 1)
            {
                printf("Enter the new address: ");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("clear");
                printf("Changes saved!");
            }
            else if(choice == 2)
            {
                printf("Enter the nex phone number: ");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("clear");
                printf("Changes saved!");
            }
        }
        else
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        break;
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if(test != 1)
    {
        system("clear");
        printf("\nRecord note found!!\a\a\a");
        eddit_invalid:
        printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
        scanf("%d", &main_exit);
        system("clear");

        if(main_exit == 1)
            menu();
        else if(main_exit == 2)
            close();
        else if(main_exit == 0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto eddit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);
        system("clear");

        if(main_exit == 1)
            menu();
        else
            close();
    }
}

void transact()
{
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("Enter the account no. of the customer: ");
    scanf("%d", &transaction.acc_no);

    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF)
    {
        if(add.acc_no == transaction.acc_no)
        {
            test = 1;

            if(strcmp(add.acc_type, "fixed1") == 0 || strcmp(add.acc_type, "fixed2") == 0 || strcmp(add.acc_type, "fixed3") == 0)
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!");
                fordelay(1000000000);
                system("clear");
                menu();
            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 withdraw): ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("Enter the amount you want to deposit:$ ");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
            else
            {
                printf("Enter the amount you want to withdraw:$ ");
                scanf("%f", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\nWithdrawn successfully!");
            }
        }
        else
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        
        break;
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if(test != 1)
    {
        printf("\n\nRecord not found!!");
        transact_invalid:
        printf("\n\nEnter 0 to try again, 1 to reutur to main menu and 2 to exit: ");
        scanf("%d", &main_exit);
        system("clear");

        if(main_exit == 0)
            transact();
        else if(main_exit == 1)
            menu();
        else if(main_exit == 2)
            close();
        else
        {
            printf("\nInvalid!");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);

        if(main_exit == 1)
            menu();
        else
            close();
    }
    
}

void erase()
{
    FILE *old, *newrec;
    int test = 0;

    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("Enter the account no. of the customer you want to delete: ");
    scanf("%d", &rem.acc_no);


    while(fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF)
    {
        if(add.acc_no != rem.acc_no)
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        else
        {
            test++;
            printf("\nRecord deleted successfully!\n");
        }
        break;
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if(test == 0)
    {
        printf("\nRecord note found!!\a\a\a");
        erase_invalid:
        printf("\nEnter 0 to try again, 1 to reutrn to main menu and 2 to exit: ");
        scanf("%d", &main_exit);

        if(main_exit == 1)
            menu();
        else if(main_exit == 2)
            close();
        else if(main_exit == 0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);
        system("clear");

        if(main_exit == 1)
            menu();
        else
            close();
    }
}

void see()
{
    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;

    ptr = fopen("record.dat", "r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Enter the account number: ");
        scanf("%d", &check.acc_no);

        while(fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF)
        {
            if(add.acc_no == check.acc_no)
            {
                system("clear");
                test = 1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAdrress:%s \nCitizienship No:%s \nPhone number:%.01lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

                if(strcmp(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year+1);
                }
                else if(strcmp(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year+2);
                }
                else if(strcmp(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year+3);
                }
                else if(strcmp(add.acc_type, "saving") == 0)
                {
                    time = (1.0/12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if(strcmp(add.acc_type, "current") == 0)
                    printf("\n\nYou will get no interest\a\a");
            }
            break;
        }
    }
    else if(choice == 2)
    {
        printf("Enter tha name:");
        scanf("%s", check.name);

        while(fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year) != EOF)
        {
            if(strcmp(add.name, check.name) == 0)
            {
                system("clear");
                test = 1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAdrress:%s \nCitizienship No:%s \nPhone number:%11lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

                if(strcmp(add.acc_type, "fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year+1);
                }
                else if(strcmp(add.acc_type, "fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year+2);
                }
                else if(strcmp(add.acc_type, "fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year+3);
                }
                else if(strcmp(add.acc_type, "saving") == 0)
                {
                    time = (1.0/12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $.%.2f as interest on %d of every month", intrst, add.deposit.day);
                }
                else if(strcmp(add.acc_type, "current") == 0)
                    printf("\n\nYou will get no interest\a\a");
            }
            break;
        }
    }

    fclose(ptr);

    if(test != 1)
    {
        system("clear");
        printf("\nRecord not found!!\a\a\a");
        see_invalid:
        printf("\nEnter 0 to try again, 1 to return to main menu and 2 to exit: ");
        scanf("%d", &main_exit);
        system("clear");

        if(main_exit == 1)
            menu();
        else if(main_exit == 2)
            close();
        else if(main_exit == 0)
            see();
        else
        {
            system("clear");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);
    }
    
    if(main_exit == 1)
    {
        system("clear");
        menu();
    }
    else
    {
        system("clear");
        close();
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
        case 2: edit(); break;
        case 3: transact(); break;
        case 4: see(); break;
        //case 5: erase(); break;
        case 6: view_list(); break;
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
