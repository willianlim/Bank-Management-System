#include <stdio.h>
#include <stdlib.h>

int i, j;
int main_exit;
void menu();

int main()
{
    char pass[10], password[10] = "codewithc";
    int i = 0;
    printf("\n\n\tEnter the password to login:");
    scanf("%s", pass);
    do
    {
        if(pass[i] != 13 && pass[i] != 8)
        {
            printf("*");
            pass[i] = getchar();
            i++;
        }
    }while(pass[i] != 13);
    pass[10] = '\0';
    
}