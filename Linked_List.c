#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int info;
    struct node *next;
};
struct node *head=NULL,*ptr,*newptr,*prevptr;
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
         if(head == NULL)
            head = newptr;
        else
            last->next = newptr;
        last = newptr;
        printf("Do you want to add more(y/n) : ");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');
    printf("\nLinked List Created\n");
    getch(); 
}
/*Insertion*/
void i_front(){
    newptr=getnode();
    newptr->next=head;
    head=newptr;
    printf("%d is inserted at front",newptr->info);
}
void i_last(){
    ptr=head;
    newptr=getnode();
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=newptr;
    printf("%d is inserted at last",newptr->info);
}
void i_anywhere(){
    int key;
    newptr=getnode();
    printf("Enter the data after which you want to insert new data : ");
    scanf("%d",&key);
    ptr=head;
    while(ptr!=NULL && ptr->info!=key)
        ptr=ptr->next;
    if(ptr==NULL)
        printf("Node with key does not exist");
    else{
        newptr->next=ptr->next;
        ptr->next=newptr;
        printf("%d is inserted after %d",newptr->info,key);
    }
}
void insert(){
    int i_choice;
    printf("Insertion\n1.Insert at front\n2.Insert at last\n3.Insert at anywhere\n4.Exit\n");
        scanf("%d",&i_choice);
        switch(i_choice)
        {
            case 1: i_front();
                    break;
            case 2: i_last();
                    break;
            case 3: i_anywhere();
                    break;
            case 4: break;
                    break;
        }
}
/*Deletion*/
void d_front(){
    if(head==NULL)
        printf("Linked list is empty");
    else{
        ptr=head;
        head=head->next;
        printf("%d is deleted from front",ptr->info);
        free(ptr);   
    }
}
void d_last(){
    if(prevptr==head){
        printf("%d is deleted from last",prevptr->info);
        free(prevptr);
        head=NULL;
    }
    if(head==NULL)
        printf("\nLinked list is empty");
    else{
        ptr=head;
        while(ptr->next!=NULL){
            prevptr=ptr;
            ptr=ptr->next;
        }
        prevptr->next=NULL;
        printf("%d is deleted from last",ptr->info);
        free(ptr);
    }
}
void d_anywhere(){
    int key;
    if(head==NULL)
        printf("\nLinked list is empty");
    else{
        printf("Enter the data you want to delete : ");
        scanf("%d",&key);
        if(prevptr==head){
            printf("%d is deleted",prevptr->info);
            free(prevptr);
            head=NULL;
        }
        else{
            ptr=head;
            while(ptr!=NULL && ptr->info!=key){
                prevptr=ptr;
                ptr=ptr->next;
            }
            if(ptr==NULL)
                printf("Node with key does not exist");
            else{
                prevptr->next=ptr->next;
                printf("%d is deleted",ptr->info);
                free(ptr);
            }
        }
    }
}
void delete(){
    int d_choice;
    printf("Deletion\n1.Delete at front\n2.Delete at last\n3.Delete at anywhere\n4.Exit\n");
        scanf("%d",&d_choice);
        switch(d_choice)
        {
            case 1: d_front();
                    break;
            case 2: d_last();
                    break;
            case 3: d_anywhere();
                    break;
            case 4: break;
                    break;
        }
}
/*Traversal*/
void display(){
    ptr = head;
    if(head==NULL)
        printf("Linked list is empty");     //not mentioned in algorithm
    else{
            printf("The elements are\n");
        while(ptr != NULL){
            printf("%d ",ptr->info);
            ptr = ptr->next;
        }
    }
}
int main(){
    int choice;
    create();
    while(1)
    {
        system("cls");
        printf("Linked List\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
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
