/*
--------------------------------------------------------------------------------------------------
>Owner:              Sabyasachi Hazra
--------------------------------------------------------------------------------------------------
>Date of creation:   30/03/2023
--------------------------------------------------------------------------------------------------
>File name:          Stack.c
--------------------------------------------------------------------------------------------------
>Topic name:         Stack
--------------------------------------------------------------------------------------------------
>Description:        Stack is a data structure in computer science in which any operation is
                     performed according to LIFO (last-in-first-out) principle, in which the last
                     thing added (pushed) is the first thing that gets pulled (popped). When the
                     stack is full trying to push more will result in stack overflow, whereas when
                     the stack is empty trying to pop will result in stack underflow.
--------------------------------------------------------------------------------------------------
*/

// Libraries and Header files
#include <stdio.h>
#include <stdlib.h>

// Method prototypes and declarations
void push();
void pop();
void disp();
void clear_screen();

// Global Variables
int *Stack, SP = -1, max;

// Method definitions
// method: Stack.main
int main()
{
    int ch;
    clear_screen();
    printf("\nEnter the maximum storage size for stack memory: ");
    scanf("%d", &max);
    Stack = (int *) calloc(max, sizeof(int));
    printf("\nInteger stack of size %d is created.\n", max);
    while(1)
    {
        printf("\nEnter your choice:\n[1] > PUSH\n[2] > POP\n[0] > EXIT\n> ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 0:
                disp();
                printf("\nPress \"ENTER\" to clear screen and exit!");
                getchar();
                if(getchar() == '\n')
                {
                    clear_screen();
                }
                free(Stack);
                return 0;
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            default:
                disp();
                printf("Invalid choice!\nPlease choose again...\n");
        }
    }
}

// method: Stack.push
void push()
{
    if(SP == max - 1)
    {
        disp();
        printf("\n<<< Stack OVERFLOW! >>>\n");
    }
    else
    {
        printf("Enter the value to be pushed: ");
        SP++;
        scanf("%d", Stack + SP);
        disp();
    }
}

// method: Stack.pop
void pop()
{
    if(SP == -1)
    {
        disp();
        printf("\n<<< Stack UNDERFLOW! >>>\n");
    }
    else
    {
        SP--;
        disp();
    }
}

// method: Stack.disp
void disp()
{
    int i;
    clear_screen();
    if(SP != -1)
    {
        printf("\nStack:\n");
    }
    for(i = SP; i >= 0; i--)
    {
        printf("------------------\n%d>\t%d\t<%d\n", i, *(Stack + i), i);
    }
    if(SP != -1)
    {
        printf("------------------\n");
    }
}

// method: Stack.clear_screen
void clear_screen()
{
    system("cls||clear");
    return;
}

