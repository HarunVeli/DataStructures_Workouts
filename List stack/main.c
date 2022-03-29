#include <stdio.h>
#include <stdlib.h>
typedef struct dugum1{
    int data;
    struct dugum1 *next;
}dugum;

dugum *top,*temp;

void push(int bilgi){

    if(top==NULL){
        temp=(dugum *)malloc(sizeof(dugum));
        temp->data=bilgi;
        temp->next=NULL;
        top=temp;
        printf("\n-->%d<--Basariyla eklendi.\n",temp->data);
    }
    else{
        temp=(dugum *)malloc(sizeof(dugum));
        temp->data=bilgi;
        temp->next=top;
        top=temp;
        printf("\n-->%d<--Basariyla eklendi.\n",temp->data);
    }
}
void pop(){

    if(top==NULL){
        printf("Silinecek eleman yok.\n");
    }
    else{
        temp=top;
        top=top->next;
        printf("\n-->%d<--Basariyla silindi.\n",temp->data);
        free(temp);
    }
}
void yazdir(){
    temp=top;
    while(temp!=NULL){
        printf("\n|%d|",temp->data);
        temp=temp->next;
    }
    printf("\n----");
    printf("\n");
}

int main()
{
    push(7);
    push(35);
    push(27);
    yazdir();
    pop();
    yazdir();
    push(94);
    push(19);
    yazdir();
    pop();
    yazdir();


    return 0;
}
