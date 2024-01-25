#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int info;
    struct node *next;
};
struct node *nodeptr=NULL,*ptr,*newptr,*prevptr;
/*getnode() function*/
struct node* getnode(){                             //type  func_name
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));         //pointer = (pointer_type)malloc(size);
    printf("Enter the data:");
    scanf("%d",&np->info);
    np->next = NULL;
    return np;
}
/*Creation*/
void create(){
    struct  node *last;
    char ch;
    do{
        newptr = getnode();
        if(nodeptr == NULL)
            nodeptr = newptr;
        else
            last->next = newptr;
        newptr->next = nodeptr;
        last = newptr;
        printf("Do you want to add more(y/n) : ");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');
    printf("\nLinked List Created\n");
    getch(); 
}
/*Insertion*/
void insert(){
    int key;
    newptr = getnode();
    if(nodeptr!=NULL){
        printf("Enter the data after which you want to insert new data : ");
        scanf("%d",&key);
        ptr = nodeptr;
        do{
            ptr = ptr->next;
        }while(ptr->info!=key && ptr!=nodeptr);
        if(ptr->info!=key)
            printf("Node with key does not exist");
        else{
            newptr->next=ptr->next;
            ptr->next=newptr;
            printf("%d is inserted after %d",newptr->info,key);
        }
    }
    else{
        nodeptr = newptr;
        newptr->next = nodeptr;
        printf("%d is inserted after",newptr->info,key);
    }
}
/*Deletion*/
void delete(){ 
    int key;
    if(nodeptr!=NULL){
        printf("Enter the data you want to delete : ");
        scanf("%d",&key);
        ptr = nodeptr;
        do{
            prevptr = ptr;
            ptr = ptr->next;
        }while(ptr->info!=key && ptr!=nodeptr);
        if(ptr->info!=key)
            printf("Node with key does not exist");
        else{
            if(ptr==nodeptr){
                if(ptr->next == nodeptr){
                    nodeptr=NULL;
                }
                else{
                    nodeptr = ptr->next;
                    prevptr->next = ptr->next;
                    //printf("%d is deleted",ptr->info);
                    //free(ptr);
                }
            }
            else{
                prevptr->next = ptr->next;
            }
            printf("%d is deleted",ptr->info);
            free(ptr);
        }
    }
    else{
        printf("Linked list is empty");
    }
}
/*Traversal*/
void display(){
    if(nodeptr!=NULL){
        ptr = nodeptr;
        printf("The elements are\n");
        do{
            printf("%d ",ptr->info);
            ptr = ptr->next;
        }while(ptr!=nodeptr);
    }
    else{
        printf("Linked list is empty");
    }
}
int main(){
    int choice;
    create();
    while(1)
    {
        system("cls");
        printf("Circular Linked List\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
        }
        getch();
    }
    return 0;
}
