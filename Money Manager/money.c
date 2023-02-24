#include <stdio.h>

int is_file_empty(FILE *file)
{
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

    int main()
{
    FILE *ptr1 = NULL;
    FILE *ptr2 = NULL;
    FILE *ptr3 = NULL;

    ptr2 = fopen("expense.txt", "a+");
    ptr1 = fopen("savings.txt", "w");
    ptr3 = fopen("Received.txt","a+");

    int initialsaving, menu, money;

    if (is_file_empty(ptr1))
    {
        printf("Please enter your Initial Saving : ");
        scanf("%d", &initialsaving);
        fprintf(ptr1, "%d", initialsaving);
    }
    else
    {
        fscanf(ptr1, "%d", &initialsaving);
    }


    printf("Please enter an option to proceed : \n______________________________________\n");
    printf("1. Enter Money Spent.\n2. Enter Money Received\n3. Exit\n_____________________________\n");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        printf("Enter the money you spent : ");
        scanf("%d", &money);
        initialsaving = initialsaving - money;
        printf("You have ₹%d left with you.\n_____________________\n", initialsaving);
        fprintf(ptr1, "%d\n", initialsaving);
        fprintf(ptr2, "%d\n", money);
        break;

    case 2:
        printf("Enter the money you received : ");
        scanf("%d", &money);
        initialsaving = initialsaving + money;
        printf("You have ₹%d left with you.\n_____________________\n", initialsaving);
        fprintf(ptr1, "%d\n", initialsaving);
        fprintf(ptr3, "%d\n", money);
        break;

    case 3:
        printf("Thank You for using our Program.\n");
        break;

    default:
        printf("Please enter proper option.\n");
        break;
    }
    

    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);

    return 0;
}