#include <stdio.h>
#include <stdlib.h>
#define boyut 10

int kuyruk[boyut];
int front=-1,rear=-1;

void enqueue(int bilgi){
    if((rear==boyut-1 && front==0) ||  rear+1==front){
        printf("\nKuyruk dolu.");
        return;
    }

    if(front==-1)
        front=0;
    rear=(rear+1)%boyut;
    kuyruk[rear]=bilgi;

}
int dequeue(){

    if(front==-1){
        printf("Kuyruk bos.");
        return -1;
    }
    int cikan=kuyruk[front];
    if(front==rear){
        front=-1;
        rear=-1;
        return cikan;
    }

    front=(front+1)%boyut;
    return cikan;
}

void yazdir(){

    for(int i=front; i!=rear ;i=(i+1)%boyut){
        printf("\n->%d",kuyruk[i]);
    }
    printf("\n->%d\n",kuyruk[rear]);
}

int main()
{
    enqueue(15);
    enqueue(98);
    enqueue(73);
    enqueue(13);
    enqueue(47);
    enqueue(39);
    yazdir();
    dequeue();
    yazdir();
    dequeue();
    yazdir();
    dequeue();
    dequeue();
    yazdir();
    dequeue();
    dequeue();
    yazdir();
    dequeue();


    return 0;
}
