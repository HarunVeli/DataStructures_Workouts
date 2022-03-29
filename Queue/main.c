#include <stdio.h>
#include <stdlib.h>


//ilk eklenen ilk cikar
typedef struct yas1{

    int data;
    struct yas1 *next;

}yas;

yas *ilk=NULL,*son,*temp;

void enqueue(int bilgi){

    if(ilk==NULL){
        ilk =(yas *)malloc(sizeof(yas));
        ilk->data=bilgi;
        ilk->next=NULL;
        son=ilk;
    }
    else{
        temp =(yas *)malloc(sizeof(yas));
        temp->data=bilgi;
        temp->next=ilk;
        ilk=temp;
    }
}

void dequeue(){

    if(ilk==NULL){
        printf("\nKuyruk bos.");
    }
    else{
        temp=ilk;
        if(temp->next==NULL){
            free(temp);
            ilk=NULL;
        }
        else{
            while(temp->next->next!=NULL){
            temp=temp->next;
        }
        yas *temp2=temp->next;
        free(temp2);
        temp->next=NULL;
        }
    }
}

void yazdir(){
    temp=ilk;

    while(temp!=NULL){
        printf("\n|%d|",temp->data);
        temp=temp->next;
    }
    printf("\n----");
    printf("\n");
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
    dequeue();
    yazdir();


    return 0;
}
