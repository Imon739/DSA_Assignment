#include<stdio.h>
int size = 5;
int s[5];
int top=-1;

void push(int value){
    if(top == size-1){
        printf("Stack Overflow");
        return;
    }
    top++;
    s[top] = value;
}

int pop(){
    if(top == -1){
        printf("Stack Underflow");
        return -1;
    }

    int y = s[top];
    top--;
    return y;
}
void print_stack()
{
    printf("\nCurrent Stack: ");
    for(int i = 0;i <= top;i++){
        printf("%d ",s[i]);
    }
    printf("\n\n");
}
int main()
{
    int choice, data, y;
    while(1)
    {
        printf("\n1.Push \n2.Pop \n3.Print \n0.Exit \n\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nEnter val to insert to stack: ");
            scanf("%d", &data);
            push(data);
        }
        else if(choice == 2)
        {
            y = pop();
            if(y != -1)
            {
               printf("\nPopped the val %d ", y);
            }
        }
        else if(choice == 3)
        {
            print_stack();
        }
        else if(choice == 0)
        {
            return 0;
        }
        else
        {
            printf("\nWrong choice, enter again!\n");
        }
    }
    return 0;
}
