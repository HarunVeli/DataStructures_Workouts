#include <stdio.h>
#include <stdlib.h>
typedef struct listeler{

    int data;
    struct listeler *next,*back;

}liste;
liste *ilk=NULL,*temp,*son;

//basa ekleme
void basaekle(int bilgi){

    if(ilk==NULL){
        ilk = (liste *)malloc(sizeof(liste));
        ilk->data=bilgi;
        ilk->next=NULL;
        ilk->back=NULL;
        son=ilk;
    }
    else{
        temp = (liste *)malloc(sizeof(liste));
        temp->data=bilgi;
        temp->next=ilk;
        ilk->back=temp;
        temp->back=NULL;
        ilk=temp;
    }
}
//sona ekleme
void sonaekle(int bilgi){
    temp=son;
    if(ilk==NULL){
        ilk = (liste *)malloc(sizeof(liste));
        son=ilk;
        ilk->next=NULL;
        ilk->back=NULL;
        ilk->data=bilgi;
    }
    else{
        temp = (liste *)malloc(sizeof(liste));
        son->next=temp;
        temp->back=son;
        temp->data=bilgi;
        temp->next=NULL;
        son=temp;
    }
}
//araya ekleme(verilen indise ekleme yapar)
void arayaekleme(int indis,int bilgi){
    temp=ilk;
    if(ilk==NULL){
        //ilk = (liste *)malloc(sizeof(liste));
        ilk = (liste *)malloc(sizeof(liste));
        son=ilk;
        ilk->next=NULL;
        ilk->back=NULL;
        ilk->data=bilgi;
    }
    else{
        int sira=0;
        while(sira!=indis){
            temp=temp->next;
            sira+=1;
        }
        if(temp->back==NULL){
                //temp ile de yapýlabilir.
            liste *temp2=(liste *)malloc(sizeof(liste));
            temp2->data=bilgi;
            temp2->next=temp;
            temp->back=temp2;
            temp2->back=NULL;
            ilk=temp2;
        }
        else if(temp->next==NULL){
            liste *temp2=(liste *)malloc(sizeof(liste));
            temp=temp->back;
            temp2->data=bilgi;
            temp2->back=temp;
            temp2->next=temp->next;
            temp->next=temp2;
            temp2->next->back=temp2;
            son=temp2->next;
        }
        else{
            liste *temp2=(liste *)malloc(sizeof(liste));
            temp2->data=bilgi;
            temp2->back=temp->back;
            temp2->next=temp;
            temp->back->next=temp2;
            temp->back=temp2;
        }
    }

}
//aranan elemean sil
void arananelamansilme(int bilgi){
    temp=ilk;
    if(ilk=NULL){
        printf("Eleman yok silme yapilamaz.");
    }
    else{
        while(temp->data!=bilgi){
            temp=temp->next;
        }
        if(temp->back==NULL){
            ilk=temp->next;
            ilk->back=NULL;
            printf("\n-->%d basariyla silindi.",temp->data);
            free(temp);
        }
        else if(temp->next==NULL){//ilk pointeri kaybediyor sonra bak
            son=temp->back;
            son->next=NULL;
            printf("\n-->%d basariyla silindi.",temp->data);
            free(temp);
        }
        else{//ilk pointeri kaybediyor sonra bak
            temp->back->next=temp->next;
            temp->next->back=temp->back;
            printf("\n-->%d basariyla silindi.",temp->data);
            free(temp);
        }
    }
}

void listele(){
    temp =ilk;
    printf("\n");
    while(temp!=NULL){
        printf("->%d",temp->data);
        temp=temp->next;
    }
}
//tersten listeleme
void sliste(){
    temp=son;
    printf("\n");
    while(temp!=NULL){
        printf("->%d",temp->data);
        temp=temp->back;
    }

}

int main()
{
    basaekle(29);
    basaekle(93);
    basaekle(47);
    basaekle(38);
    basaekle(14);
    listele();
    sonaekle(15);
    sonaekle(72);
    listele();
    arayaekleme(4,11);
    listele();
    arayaekleme(7,53);
    listele();
    arananelamansilme(47);
    sliste();
    listele();//ilk elemani arananelamansilme(47);'de kaybettigi icin bosluk birakiyor


    return 0;
}
