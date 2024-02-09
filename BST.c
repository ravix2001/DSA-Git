#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int info;
    struct node *lcptr,*rcptr;
};
struct node *root=NULL,*ptr,*newptr,*parent;
struct node* getnode(){
    struct node *np;
    np = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&np->info);
    np->lcptr=NULL;
    np->rcptr =NULL;
    return np;
}
void create(){
    char ch;
    do{
        newptr = getnode();
        if(root==NULL)
            root = newptr;
        else{
            ptr = root;
            while(ptr!=NULL){
                parent=ptr;
                if(newptr->info < ptr->info)
                    ptr = ptr->lcptr;
                else
                    ptr = ptr->rcptr;
            }
            if(newptr->info < parent->info)
                parent->lcptr = newptr;
            else
                parent->rcptr = newptr;
        }
        printf("Do you want to add more(y or n): ");
        scanf(" %c",&ch);
    }while(ch=='Y'||ch=='y');
}
void insert(){
    ptr = root;
    newptr = getnode();
    while(ptr!= NULL){
        parent=ptr;
        if(newptr->info < ptr->info)
            ptr = ptr->lcptr;
        else
            ptr = ptr->rcptr;
    }
    if(newptr->info < parent->info)
        parent->lcptr = newptr;
    else
        parent->rcptr = newptr;
    printf("%d is inserted",newptr->info);
}
void search(){      //modified wrt algorithm
    int key;
    printf("\nEnter the key you want to search : ");
    scanf("%d",&key);
    ptr = root;
    while(ptr!= NULL && ptr->info!= key){
        if(key < ptr->info)
            ptr = ptr->lcptr;
        else
            ptr = ptr->rcptr;
    }
    if(ptr->info == key)
        printf("%d found",key);
}
void preorder(struct node *ptr){        //bug
    if(ptr!= NULL){
        printf("%d  ",ptr->info);
        preorder(ptr->lcptr);
        preorder(ptr->rcptr);
    }
}
void inorder(struct node *ptr){
    if(ptr!= NULL){
        inorder(ptr->lcptr);
        printf("%d  ",ptr->info);
        inorder(ptr->rcptr);
    }
    /*else      //for visual representation
        printf("* ");*/
}
void delete(struct node *ptr, int key){     //bug -> deleting root gives error
    ptr = root;
    printf("\nEnter the node to be deleted : ");
    scanf("%d",&key);
    while(ptr!= NULL && ptr->info!= key){
        parent = ptr;
        if(key < ptr->info)
            ptr = ptr->lcptr;
        else
            ptr = ptr->rcptr;
    }
    if(ptr == NULL){
       printf("\nNode with key doesnot exist"); 
    }
    //no child or leaf node
    else if(ptr->lcptr == NULL && ptr->rcptr == NULL){
        if(key < parent->info)
            parent->lcptr = NULL;
        else
            parent->rcptr = NULL;
        printf("\n%d is deleted",ptr->info);
        free(ptr);
    }
    //single child
    else if(ptr->lcptr == NULL || ptr->rcptr == NULL){
        if(key < parent->info){
            if(ptr->lcptr != NULL)
                parent->lcptr = ptr->lcptr;
            else
                parent->lcptr = ptr->rcptr;
            printf("\n%d is deleted",ptr->info);
            free(ptr);
        }
        else{
            if(ptr->rcptr != NULL)
                parent->rcptr = ptr->rcptr;
            else
                parent->rcptr = ptr->lcptr;
            printf("\n%d is deleted",ptr->info);
            free(ptr);
        }
    }
    //two child
    else{
        struct node* InsuccParent = ptr;
        struct node* Insucc = ptr->rcptr;
        while (Insucc->lcptr != NULL) {
            InsuccParent = Insucc;
            Insucc = Insucc->lcptr;
        }
        if (InsuccParent != ptr)
            InsuccParent->lcptr = Insucc->rcptr;
        else
            InsuccParent->rcptr = Insucc->rcptr;
        printf("\n%d is deleted",ptr->info);
        ptr->info = Insucc->info;
        free(Insucc);
    }
}
int main(){
    int choice;
    struct node *pr;
    int item;
    create();
    while(1)
    {
        system("cls");
        printf("Binary Search Tree\n1.Insert\n2.Delete\n3.Traversal\n4.Search\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: delete(pr,item);
                    break;
            case 3: printf("\nThe Preorder traversal is\n");
                    preorder(root);
                    printf("\nThe Inorder traversal is\n");
                    inorder(root);
                    break;
            case 4: search();
                    break;       
            case 5: exit(0);
                    break;
        }
        getch();
    }
    return 0;
}
