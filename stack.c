#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 5
struct  stack{
    int data[size];
    int top;
}s;
void push(){
    if(s.top == size-1)
        printf("Stack Overflow");
    else{
        (s.top)++;
        printf("Enter the data : ");
        scanf("%d",&s.data[s.top]);
        printf("Data Added");
    }
}
void display(){
    int i;
    if(s.top == -1)
        printf("Stack is Empty");
    else{
        printf("The elements are\n");
        for(i=s.top;i>=0;i--)
            printf("%d\n",s.data[i]);
    }
}
void tos(){
    if(s.top == -1)
        printf("Stack is Empty");
    else
        printf("Data at the top of stack is %d",s.data[s.top]);
}
void pop(){
    if(s.top == -1)
        printf("Stack is Empty");
    else{
        printf("%d is popped",s.data[s.top]);
        (s.top)--;
    }
}
int main(){
    int choice;
    s.top = -1;
    while(1)
    {
        system("cls");
        printf("Stack\n1.Push\n2.Pop\n3.Display\n4.Exit\n5.TOS\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            case 5: tos();
                    break;
        }
        getch();
    }
    return 0;
}
