#include <stdio.h>
#include <stdlib.h>

struct student
{
    int SNo; //student number
    char SNa[50]; //student name
    float tution; 
    struct student *ad; 
};

struct student *f = NULL, *l = NULL, *N = NULL, *t = NULL;

void create()
{
    N = (struct student *)malloc(sizeof(struct student));
    printf("Enter Student Number: ");
    scanf("%d", &N->SNo);
    printf("Enter Student Name: ");
    scanf("%s", N->SNa);
    printf("Enter Student tution: ");
    scanf("%f", &N->tution);
    N->ad = NULL;
}

void start()
{
    for (int i = 0; i < 5; i++)
    {
        create();
        if (f == NULL)
        {
            f = l = N;
        }
        else
        {
            l->ad = N;
            l = N;
        }
    }
}

void display()
{
    for (t = f; t != NULL; t = t->ad)
    {
        printf("\n%d\t%s\t%f", t->SNo, t->SNa, t->tution);
    }
}

void insbeg()
{
    create();
    if (f == NULL)
    {
        f = l = N;
    }
    else
    {
        N->ad = f;
        f = N;
    }
}

void insend()
{
    create();
    if (f == NULL)
    {
        f = l = N;
    }
    else
    {
        l->ad = N;
        l = N;
    }
}

void delbeg()
{
    if (f == NULL)
    {
        printf("Not Possible");
    }
    else
    {
        t = f;
        f = f->ad;
        free(t);
        printf("\nOne node deleted");
    }
}

void delend()
{
    if (f == NULL)
    {
        printf("Not Possible");
    }
    else if (f == l)
    {
        free(f);
        f = l = NULL;
        printf("\nOne node deleted");
    }
    else
    {
        for (t = f; t->ad->ad != NULL; t = t->ad)
        {
            // Traverse the list until the second last node
        }
        free(t->ad);
        t->ad = NULL;
        l = t;
        printf("\nOne node deleted");
    }
}

void ins_sp()
{
    int p, i;
    printf("Enter Position: ");
    scanf("%d", &p);
    i = 1;
    for (t = f; t != NULL; t = t->ad)
    {
        i++;
        if (i >= p)
        {
            break;
        }
    }
    create();
    if (f == NULL)
    {
        f = l = N;
    }
    else
    {
        N->ad = t->ad;
        t->ad = N;
    }
}

void del_sp()
{
    int p, i;
    printf("Enter Position: ");
    scanf("%d", &p);
    i = 1;
    for (t = f; t != NULL; t = t->ad)
    {
        i++;
        if (i >= p)
        {
            break;
        }
    }
    N = t->ad;
    t->ad = t->ad->ad;
    free(N);
}

int main (void)
{
    int choice;
    while(1)
    {
        printf("\n 1. Create List\n 2. Insert at beginning\n 3. Insert at End\n 4. Insert at a Position\n 5. Delete at Beginning\n 6. Delete at End\n 7. Delete at a Position\n 8. Display\n 9. Exit");
        printf("\n\nSelect Menu Option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                start(); //create list
                break;
            case 2:
                insbeg(); //insert at beginning
                break;
            case 3:
                insend(); //insert at end
                break;
            case 4:
                ins_sp(); //insert at a position
                break;
            case 5:
                delbeg(); //delete at begininng
                break;
            case 6:
                delend(); // delete at end 
                break;
            case 7:
                del_sp(); //delete at a specific position
                break;
            case 8:
                display(); //display
                break;
            case 9:
                exit(0); //exit
                break;
            default:
                printf("Wrong Menu Choice.");
        }
    }
    return 0;
}
