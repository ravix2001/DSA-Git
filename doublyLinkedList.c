#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *newptr, *ptr;
struct node *getnode(){
    struct node *np;
    np = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &np->info);
    np->prev = NULL;
    np->next = NULL;
    return np;
}
/*Creation*/
void create(){
    struct node *last = NULL;
    char ch;
    do{
        newptr = getnode();
        if (head == NULL)
            head = newptr;
        else
        {
            last->next = newptr;
            newptr->prev = last;
        }
        last = newptr;
        printf("Do you want to add more (y/n) :  ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
void i_front(){
    newptr = getnode();
    if(head != NULL){
        newptr->next = head;
        head->prev = newptr;
    }
    printf("%d is inserted at front", newptr->info);
    head = newptr;
}
void i_last(){
    newptr = getnode();
    if(head != NULL){
        ptr = head;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newptr;
        newptr->prev = ptr;
    }
    else
        head = newptr;
    printf("%d is inserted at last", newptr->info);
}
void i_anywhere(){
    int key;
    if(head != NULL){
        newptr = getnode();
        ptr = head;
        printf("Enter the data after which you want to insert new data : ");
        scanf("%d", &key);
        while (ptr != NULL && ptr->info != key){
            ptr = ptr->next;
        }
        if(ptr == NULL)
            printf("Node with key does not exist");
        else{
            newptr->next = ptr->next;
            ptr->next = newptr;
            ptr->next->prev = newptr;
            newptr->prev = ptr;
            printf("%d is inserted after %d", newptr->info,key);
        }
    }
    else
        i_front();
}
void insert(){
    int i_choice;
    if (head != NULL){
        printf("\nInsertion\n1.Insert at front\n2.Insert at last\n3.Insert anywhere\n4.Exit\n");
        scanf("%d", &i_choice);
        switch (i_choice)
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
    else
        i_front();            // if the list is empty ,insert info at front directly.
}
void d_front(){
    if (head == NULL)
        printf("Linked list is empty");
    else{
        ptr = head;
        if (head->next != NULL){
            head = head->next;
            head->prev = NULL;
        }
        else{
            head = NULL;
        }
        printf("%d is deleted", ptr->info);
        free(ptr);
    }
}
void d_last(){
    if (head == NULL)
        printf("Linked list is empty");
    else{
        ptr = head;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        printf("%d is deleted", ptr->info);
        if (ptr->prev != NULL)
            ptr->prev->next = NULL;
        else
            head = NULL;
        free(ptr);
    }
}
void d_anywhere(){
    int key;
    if (head == NULL)
        printf("\nLinked list is empty");
    else{
        printf("Enter the data you want to delete : ");
        scanf("%d", &key);
        ptr = head;
        while (ptr != NULL && ptr->info != key){
            ptr = ptr->next;
        }
        if (ptr == NULL)
            printf("Node with key does not exist");
        else{
            if (ptr->prev != NULL){
                if (ptr->next != NULL){
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                }
                else
                    ptr->prev->next = NULL;
            }
            else{
                if (ptr->next){
                    ptr->next->prev = NULL;
                    head = ptr->next;
                }
                else
                    head = NULL;
            }
            printf("%d is deleted", ptr->info);
            free(ptr);
        }
    }
}
void delete(){
    int d_choice;
    if (head != NULL){
        printf("\nDeletion\n1.Delete at front\n2.Delete at last\n3.Delete anywhere\n4.Exit\n");
        scanf("%d", &d_choice);
        switch (d_choice)
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
    else
        printf("Linked list is empty");
}
void display(){
    if (head != NULL){
        ptr = head;
        printf("The elements are\n");
        while (ptr != NULL){
            printf("%d\t", ptr->info);
            ptr = ptr->next;
        }
    }
    else
        printf("Linked list is empty");
}
int main(){
    int choice;
    create();
    while (1)
    {
        system("cls");
        printf("Doubly Linked List\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
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
