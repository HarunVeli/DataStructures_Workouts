#include <stdio.h>
#include <stdlib.h>

int dizi[5];
int top=-1;

int dolu_mu(){

    if(top==4){
        return 1;
    }
    else{
        return 0;
    }
}
int bos_mu(){

    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){

    int deger=dolu_mu();
    if(deger==1){
        printf("Stack dolu ekleme yapilamadi.");
    }
    else{
        top+=1;
        dizi[top]=data;
    }
}

void pop(){

    int deger=bos_mu();
    if(deger==1){
        printf("Stack bos silme yapilamadi.");
    }
    else{
        //int eskitop =dizi[top];
        top-=1;
    }
}

void yazdir(){
    printf("\n");
    for(int i=0;i<top+1;i++){
        printf("->%d",dizi[i]);
    }
}

int main()
{
    push(5);
    push(15);
    push(25);
    push(35);
    push(45);
    yazdir();
    pop();
    pop();
    yazdir();

    return 0;
}
