#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 5
struct  queue{
    int data[size];
    int front, rear;
};
void enqueue(struct queue *q){
    int front = 0, rear = -1;
    if( q->rear == size-1)
        printf("Queue is full");
    else{
        (q->rear)++;
        printf("Enter the data : ");
        scanf("%d",&q->data[q->rear]);
        printf("Data Added");
    }
}
void display(struct queue q){
    int i;
    if( q.rear < q.front)
        printf("Queue is Empty");
    else{
        printf("The elements are\n");
        for(i=q.front;i<=q.rear;i++)
            printf("%d\n",q.data[i]);
    }
}
void FOQ(struct queue q){
    if( q.rear < q.front)
        printf("Queue is Empty");
    else{
        printf("The element at the front of Queue is %d",q.data[q.front]);
    }
}
void LOQ(struct queue q){
    if( q.rear < q.front)
        printf("Queue is Empty");
    else{
        printf("The element at the last of Queue is %d",q.data[q.rear]);
    }
}
void dequeue(struct queue *q){              //without shifting
    if(q->rear < q->front)
        printf("Queue is Empty");
    else
        printf("%d is Dequeued",q->data[q->front]);
        (q->front)++;
}
/*
void dequeue(struct queue *q){              //with shifting
    if(q->rear < q->front)
        printf("Queue is Empty");
    else{
        for(i=q->front;i<=q->rear;i++){
            q->data[i]=q->data[i+1];
            (q->rear)--;
        }
    }
}
*/
int main(){
    struct queue q , *ptr;
    ptr = &q;
    int choice;
    q.front = 0;
    q.rear = -1;
    while(1)
    {
        system("cls");
        printf("Queue\n1.Enqueue\n2.Dequeue\n3.First Element\n4.Last Element\n5.Display\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue(&q);
                    break;
            case 2: dequeue(&q);
                    break;
            case 3: FOQ(q);
                    break;
            case 4: LOQ(q);
                    break;
            case 5: display(q);
                    break;
            case 6: exit(0);
        }
        getch();
    }
    return 0;
}
