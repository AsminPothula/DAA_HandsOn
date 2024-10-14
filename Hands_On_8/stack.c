#include <stdio.h>
#include <stdlib.h>

int stack[10], max = 10, top = -1, i;

int PUSH()
{
    if (top == max - 1) 
    {
        printf(" Stack Overflow\n");
        return 0;
    }
    top++;
    printf(" Enter that element to be inserted: ");
    scanf("%d", &stack[top]);
    printf(" New stack element added\n");
    return 0;
}

int POP()
{
    if(top == -1)
    {
        printf(" Stack Underflow\n");
        return 0;
    }
    top--;
    printf(" Top stack element removed.\n");
    return 0;
}

int LIST()
{
    if(top == -1)
    {
        printf(" Stack is Empty.\n");
        return 0;
    }
    for (i = top; i >= 0; i--)
    {
        printf("\n %d ", stack[i]);
    }
    return 0;
}

int main (void)
{
    int choice;
    while(1)
    {
        printf("\n\n Stack Menu:");
        printf("\n 1. PUSH\n 2. POP\n 3. LIST\n 4. EXIT");
        printf("\n Select Menu Option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                PUSH();
                break;
            case 2:
                POP();
                break;
            case 3:
                LIST();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf(" Wrong Menu Choice.");
        }
    }
    return 0;
}