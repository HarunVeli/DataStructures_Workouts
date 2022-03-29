#include <stdio.h>
#include <stdlib.h>
typedef struct bilgiler
{

    int data;
    struct bilgiler *next;
    struct bilgiler *back;
} agrup,bgrup;

agrup *ilka,*sona;//*kontrol=NULL;
bgrup *ilkb,*sonb;


void ekle(int secim,int bilgi)
{
    //1 agrup ,2 bgrup ekler.
    agrup *temp;
    if(secim==1)
    {
        if(ilka==NULL)
        {
            temp = (agrup *)malloc(sizeof(agrup));
            temp->data=bilgi;
            ilka=temp;
            sona=temp;
            temp->next=NULL;
            temp->back=NULL;
        }
        else
        {
            temp =(agrup *)malloc(sizeof(agrup));
            temp->data=bilgi;
            ilka->back=temp;
            temp->back=NULL;
            temp->next=ilka;
            ilka=temp;
        }
    }
    if(secim==2)
    {
        if(ilkb==NULL)
        {
            temp = (bgrup *)malloc(sizeof(bgrup));
            temp->data=bilgi;
            ilkb=temp;
            sonb=temp;
            temp->next=NULL;
            temp->back=NULL;
        }
        else
        {
            temp =(bgrup *)malloc(sizeof(bgrup));
            temp->data=bilgi;
            ilkb->back=temp;
            temp->back=NULL;
            temp->next=ilkb;
            ilkb=temp;
        }
    }

}

void listele()
{
    agrup *tempa=ilka;
    bgrup *tempb=ilkb;
    printf("\nListe->1\n");
    while(tempa!=NULL)
    {
        printf("->%d",tempa->data);
        tempa = tempa->next;
    }
    printf("\nListe->2\n");
    while(tempb!=NULL)
    {
        printf("->%d",tempb->data);
        tempb = tempb->next;
    }
    printf("\n----------------------------");
}

void tekcift()
{
    //ciftleri a,tekleri b listesine tasir.
    agrup *tempa=ilka,*oncekia=ilka;
    bgrup *tempb=ilkb,*oncekib=ilkb;
    while(tempb!=NULL)
    {
        if(tempb->data %2==0 && tempb->back==NULL)//İlk eleman ise
        {
            ilkb=tempb->next;
            ilkb->back=NULL;
            tempb->next=NULL;
            tempb->back=sona;
            sona->next=tempb;
            tempb->next=NULL;//silinebilir.
            sona=tempb;
            tempb=ilkb;
        }
        if(tempb->data %2==0 && tempb->next==NULL)//son eleman ise
        {
            sonb=tempb->back;
            sonb->next=NULL;
            tempb->back=sona;
            sona->next=tempb;
            tempb->next=NULL;
            sona=tempb;
            tempb=ilkb;
        }
        if(tempb->data %2==0 && tempb->next!=NULL && tempb->back!=NULL)//ortada ise
        {
            oncekib=tempb->back;
            oncekib->next=tempb->next;
            tempb->next->back=oncekib;
            tempb->back=sona;
            sona->next=tempb;
            tempb->next=NULL;
            sona=tempb;
            tempb=oncekib;
        }
        else
        {
            tempb=tempb->next;
        }
    }
    while(tempa!=NULL)
    {
        if(tempa->data %2!=0 && tempa->back==NULL)//İlk eleman ise
        {
            ilka=tempa->next;
            ilka->back=NULL;
            tempa->next=NULL;
            tempa->back=sonb;
            sonb->next=tempa;
            tempa->next=NULL;
            sonb=tempa;
            tempa=ilka;
        }
        if(tempa->data %2!=0 && tempa->next==NULL)//son eleman ise
        {
            sona=tempa->back;
            sona->next=NULL;
            tempa->back=sonb;
            sonb->next=tempa;
            tempa->next=NULL;
            sonb=tempa;
            tempa=ilka;
        }
        if(tempa->data %2!=0 && tempa->next!=NULL && tempa->back!=NULL)//ortada ise
        {
            oncekia=tempa->back;
            oncekia->next=tempa->next;
            tempa->next->back=oncekia;
            tempa->back=sonb;
            sonb->next=tempa;
            tempa->next=NULL;
            sonb=tempa;
            tempa=oncekia;
        }
        else
        {
            tempa=tempa->next;
        }
    }
}

void sirala()
{
    agrup *tempa=ilka,*oncekia=ilka;
    bgrup *tempb=ilkb,*oncekib=ilkb;

    while(tempb->next!=NULL)//tekleri buyukten kucuge siralar.
    {

        if(tempb->data>=tempb->next->data )
        {
            tempb=tempb->next;
        }
        else
        {
            if(tempb->back==NULL) //ilk sira ise kullanilir.
            {
                oncekib=tempb;
                tempb=tempb->next;
                oncekib->next=tempb->next;
                tempb->next->back=oncekib;
                tempb->next=oncekib;
                oncekib->back=tempb;
                tempb->back=NULL;
                ilkb=tempb;
                tempb=ilkb;
            }
            else if(tempb->next->next==NULL ) //son sira ise kullanilir.
            {
                tempb->back->next=tempb->next;
                tempb->next->next=tempb;
                tempb->next->back=tempb->back;
                tempb->back= tempb->next;
                tempb->next=NULL;
                sonb=tempb;
                tempb=ilkb;
            }
            else //orta sirada ise
            {
                oncekib=tempb;
                tempb=tempb->next;
                tempb->back=oncekib->back;
                oncekib->back->next=tempb;
                oncekib->back=tempb;
                oncekib->next=tempb->next;
                tempb->next=oncekib;
                oncekib->next->back=oncekib;
                tempb=ilkb;
            }
        }
    }

    while(tempa->next!=NULL)//ciftleri kucukten buyuge siralar.
    {
        if(tempa->data<=tempa->next->data )
        {
            tempa=tempa->next;
        }
        else
        {
            if(tempa->back==NULL) //ilk sira ise kullanilir.
            {
                oncekia=tempa;
                tempa=tempa->next;
                oncekia->next=tempa->next;
                tempa->next->back=oncekia;
                tempa->next=oncekia;
                oncekia->back=tempa;
                tempa->back=NULL;
                ilka=tempa;
                tempa=ilka;
            }
            else if(tempa->next->next==NULL ) //son sira ise kullanilir.
            {
                tempa->back->next=tempa->next;
                tempa->next->next=tempa;
                tempa->next->back=tempa->back;
                tempa->back= tempa->next;
                tempa->next=NULL;
                sona=tempb;
                tempa=ilka;
            }
            else //orta sirada ise
            {
                oncekia=tempa;
                tempa=tempa->next;
                tempa->back=oncekia->back;
                oncekia->back->next=tempa;
                oncekia->back=tempa;
                oncekia->next=tempa->next;
                tempa->next=oncekia;
                oncekia->next->back=oncekia;
                tempa=ilka;
            }
        }
    }
}

void topla()
{
    agrup *tempa=ilka,*oncekia=ilka;
    bgrup *tempb=ilkb,*oncekib=ilkb;
    int sayac=1,adim_sayisi=0;
    while(1)
    {
        if(sayac%2==0) //tek listeye ciftleri ekleme
        {

            if(tempb->next!=NULL || sayac == 8)//adimsayisi ,8yerine
            {
                oncekib=oncekib->back;
                tempb->back=tempa;
                tempa=tempa->next;
                ilka=tempa;
                tempa->back=NULL;
                tempb->back->back=oncekib;
                oncekib->next=tempb->back;
                oncekib->next->next=tempb;
                oncekib=tempb;

            }
            else //liste2 bittiginde direk eklemeye gecis.
            {
                tempb->next=tempa;
                tempb->next->back=tempb;
                tempa=tempb->next->next;
                tempa->back=NULL;
                tempb->next->next=NULL;
                tempb=tempb->next;
                //sayac+=1;
                if(tempa->next==NULL) //tempa(liste1-cift) son degerine ulastiginda
                {
                    tempb->next=tempa;
                    tempa->back=tempb;
                    tempb=tempa;
                    sonb=tempb;

                    break;
                }
            }
        }

        sayac+=1;

        if(tempb->next!=NULL && sayac%2==0)
        {
            //oncekib=tempb;
            oncekib=oncekib->next;
            tempb=tempb->next;
        }
    }
}

int main()
{
    ekle(1,46);
    ekle(1,2);
    ekle(1,4);
    ekle(1,10);
    ekle(1,8);
    ekle(1,7);
    ekle(1,6);
    ekle(1,4);
    ekle(1,16);
    ekle(2,48);
    ekle(2,60);
    ekle(2,40);
    ekle(2,82);
    ekle(2,12);
    ekle(2,46);
    ekle(2,0);

    printf("Listelerin normal hali");
    listele();
    tekcift();
    printf("\nListelerin tek cift ayrilmis hali");
    listele();
    sirala();
    printf("\nListelerin buyuk-kucuk durumuna gore sirali hali");
    listele();
    topla();
    printf("\nListelerin birlestirilmis hali");
    listele();

    return 0;
}
