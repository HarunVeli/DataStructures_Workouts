#include <stdio.h>
#include <stdlib.h>

typedef struct liste1
{

    int data;
    struct liste1 *next;

} liste;

liste *ilk=NULL,*temp;

//basa ekleme
void eklebasa(int bilgi)
{

    if(ilk==NULL)
    {
        ilk=(liste *)malloc(sizeof(liste));
        ilk->data=bilgi;
        ilk->next=NULL;
    }
    else
    {
        temp=(liste *)malloc(sizeof(liste));
        temp->data=bilgi;
        temp->next=ilk;
        ilk=temp;
    }
}
//sona ekleme
void eklesona(int bilgi)
{

    if(ilk==NULL)
    {
        ilk = (liste *)malloc(sizeof(liste));
        ilk->data=bilgi;
        ilk->next=NULL;
    }
    else
    {
        temp=ilk;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        liste *temp2;
        temp2=(liste *)malloc(sizeof(liste));
        temp2->data=bilgi;
        temp->next=temp2;
        temp2->next=NULL;
    }
}
//araya ekleme (verilen indisin sonrasýna ekler)
int eklearaya(int indis,int bilgi)
{

    if(ilk==NULL)
    {
        printf("Araya eklenemez cunku eleman yok.");
        return 0;
    }
    else
    {
        temp=ilk;
        int sira=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            sira+=1;
            if(sira==indis)
            {
                liste *temp2;
                temp2 = (liste *)malloc(sizeof(liste));
                temp2->data=bilgi;
                temp2->next=temp->next;
                temp->next=temp2;
                return 0;
            }
        }
    }
    if(temp==NULL)
    {
        printf("Eleman sayisindan buyuk indis girdiniz.");
    }
    return 0;
}
//Listeleme
void listele()
{
    temp=ilk;
    printf("\n");
    while(temp!=NULL)
    {

        printf("->%d",temp->data);
        temp=temp->next;
    }
}
//sondan silme
void sondansilme()
{
    temp=ilk;
    if(temp==NULL)
    {
        printf("Silinecek eleman yok.");
    }
    else
    {
        if(temp->next==NULL)
        {
            ilk=NULL;
            printf("\n-->%d Basariyla silindi",temp->data);
            free(temp);

        }
        else
        {
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            liste *temp2;
            temp2=temp->next;
            temp->next=NULL;
            printf("-->%d Basariyla silindi",temp2->data);
            free(temp2);

        }

    }

}
//bastan silme
void bastansilme()
{
    temp=ilk;
    if(ilk==NULL)
    {
        printf("Silinecek eleman yok");
    }
    else
    {
        ilk=temp->next;
        printf("\n-->%d Basariyla silindi",temp->data);
        free(temp);
    }
}
//aradan silme (Verilen indisin sonrasýný siler)
int aradansilme(int indis)
{

    if(ilk==NULL)
    {
        printf("Silinecek eleman yok");
    }
    else
    {
        temp=ilk;
        int sira=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            sira+=1;
            if(sira==indis)
            {
                liste *temp2=temp->next;
                temp->next=temp->next->next;
                printf("\n-->%d Basariyla silindi",temp2->data);
                free(temp2);
                return 0;
            }
        }
    }
    if(temp==NULL)
    {
        printf("Eleman sayisindan buyuk indis girdiniz.");
    }

}
//Ýstenilen elemaný silme
int istelemansilme(int sil)
{
    temp=ilk;
    if(ilk==NULL)
    {
        printf("Silinecek eleman yok");
    }
    else
    {
        if(ilk->data==sil)
        {
            ilk=temp->next;
            printf("\n-->%d Basariyla silindi.",temp->data);
            free(temp);
            return 0;
        }
        while(temp!=NULL)
        {
            if(temp->next->data==sil)
            {
                liste *temp2=temp->next;
                temp->next=temp->next->next;
                printf("\n-->%d Basariyla silindi.",temp2->data);
                free(temp2);
                return 0;
            }
            temp=temp->next;
        }
    }
    if(temp==NULL)
    {
        printf("Aradiginiz eleman bulunamadi.");
    }

}
//Bagli listeyi ters çevirme
void terscevir()
{
    temp=ilk;
    liste *tempo=NULL,*temps;
    while(temp!=NULL)
    {
        temps=temp->next;
        if(tempo==NULL)
        {
            tempo=temp;
            tempo->next=NULL;
            temp=temps;
        }
        else
        {
            temp->next=tempo;
            tempo=temp;
            temp=temps;
        }
    }
    if(temp==NULL)
    {
        ilk=tempo;
    }
}
struct liste* recursiveters(liste *temp){

    if(temp==NULL){
        return;
    }
    if(temp->next==NULL){
        ilk=temp;
        return temp;
    }

    liste *temp2=recursiveters(temp->next);
    temp2->next=temp;
    temp->next=NULL;

    return temp;
}

int main()
{
    eklebasa(20);
    eklebasa(18);
    eklebasa(39);
    eklebasa(47);
    listele();
    eklesona(1);
    eklesona(2);
    eklesona(3);
    listele();
    //Verilen indisin sonrasýna ekler
    eklearaya(3,111);
    eklearaya(6,119);
    //sondansilme();
    //bastansilme();
    listele();
    aradansilme(3);
    listele();
    istelemansilme(3);
    listele();
    eklesona(2);
    listele();
    terscevir();
    listele();
    eklearaya(2,31);
    listele();
    recursiveters(ilk);
    listele();

    return 0;
}
