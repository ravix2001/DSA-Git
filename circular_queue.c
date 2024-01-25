#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 5
struct  queue{
    int data[size];
    int rear;
    int front;
};
void Enqueue(struct queue *q){
    if((q->rear+1)%size==q->front)
        printf("Queue is Full");
    else{
        (q->rear)=(q->rear+1)%size;
        printf("Enter the data:");
        scanf("%d",&q->data[q->rear]);
        printf("Data Added");
    }
}
void display(struct queue *q){
    int i;
    if(q->rear ==q->front)
        printf("Queue is Empty");
    else{
        printf("The elements are :\n");
        for(i=(q->front+1)%size;i!=q->rear;i=(i+1)%size)
            printf("%d\n",q->data[i]);
        printf("%d\n",q->data[q->rear]);
    }
}
void Dequeue(struct queue *q){
    if(q->rear==q->front)
        printf("Queue is Empty");
    else{
        q->front=(q->front+1)%size;
        printf("%d is Dequeued",q->data[q->front]);
    }
}
int main(){
    struct queue q;
    int choice;
    q.rear = 0;
    q.front = 0;
    while(1){
        system("cls");
        printf("Circular Queue\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: Enqueue(&q);
                    break;
            case 2: Dequeue(&q);
                    break;
            case 3: display(&q);
                    break;
            case 4: exit(0);
        }
        getch();
    }
    return 0;
}
