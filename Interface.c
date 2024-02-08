#include"bibliotheque.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
char non[20];
int RAM,TAI,y,id,x,nb,tr,s=1;
tarbreprocessus rch;
 tarbreprocessus A;
  listeprocessus pret,t;
  listeprocessus elue,v;
  listeprocessus bloc;
  bloc=NULL;
  pret=NULL;
 y=2;




    do{
    printf("entrez la taille de RAM :  ");
    scanf("%d",&RAM);
       }while(RAM<2);


          cre_root( &A,&elue);
           RAM=RAM-((A)->ram);
          printf(" \n la reteni de taile de la RAME  %d",RAM);


while(s!=0){
printf("\n \n \n pour cree un processus entrez 1 \n  pour lancer un processus entrez 2 \n  pour bloquer un processus entrez 3 \n pour desbloquer un processus entrez  4\n pour tuer un procussus entrez 5\npour terminer un procussus entrez 6 \n pour aficher la list entrez 7");
printf(" pour quiter entrez 0 : ");
printf("\n Votre choix : ");
scanf("%d",&s);

switch(s)
{

case 1:
    {
    do{
    printf("\nentrez la taille :  ");
    scanf("%d",&TAI);

    }while(TAI>RAM||TAI<=0);
    RAM=RAM-TAI;

    printf("\ndonne id de per :  ");
    scanf("%d",&id);
v=elue;
tr=0;

while(v!=NULL&&tr==0)
{
    if(v->PID==id){tr=1;}
    v=v->suivant;
}

if(tr==0){
printf("lelement nexect pas dans lalist dexecution ");
}
else{
cree(A,id,TAI,elue,&x,y,&pret);
htop(A);
y=y+1;



     }

    }
break;
case 2:
    {


nb=0;
v=elue;
while(v!=NULL)
{
   nb=nb+1;
    v=v->suivant;

}

if(nb>=4){printf("l'espace est complet");}
else{

lanc(pret,&elue,A);
depile_debit(&pret);
htop(A);
}
    }

break;
case 3:
    {
do{
printf("\nentrez ID de lelement que vous souhaitez bloqer :  ");
scanf("%d",&id);
}while(id==0);
v=elue;
tr=0;

while(v!=NULL&&tr==0)
{
  if(v->PID==id){tr=1;}
  v=v->suivant;
}
if(tr==0){printf("l'element n'exict pas dans la list d'execution");}
else{

       bloque(&elue,&bloc,id,A);
       htop(A);
   }
    }
break;
case 4:
    {

do{
printf("\n entrez  ID de l'element que vous souhaitez  debloqer :  ");
scanf("%d",&id);
}while(id==0);
tr=0;
v=bloc;
while(v!=NULL&&tr==0)
{
    if(v->PID==id){tr=1;}
    v=v->suivant;
}

if(tr==0){printf("l'element n'exict pas das la list de bloquage");}
else{

       debloque(&elue,&bloc,id,A);
       htop(A);
   }
    }

break;
case 5:
    {

do{
   printf("entrez le id l'element que vous souhaitez  supprimer ");
   scanf("%d",&id);
}while(id==0);
   rch=recherch(A,id);

   if(rch==NULL){
        printf("l'element n'exite pas dans larbre");
   }
   else
    {
    if(rch->ETAT==0){
    tuer(&A,&pret,id);
    }
    else{
        if(rch->ETAT==1){
                tuer(&A,&elue,id);
        }
        else{
                if(rch->ETAT==2){
                        tuer(&A,&bloc,id);
                }
        }

    }


    htop(A);


    }

break;
case 6:
    {


do{
   printf("entrez le id l'element que vous souhaitez  supprimer ");
   scanf("%d",&id);
}while(id==0);
v=elue;
tr=0;

while(v!=NULL&&tr==0)
{
  if(v->PID==id){tr=1;}
  v=v->suivant;
}
if(tr==0){printf("l'element n'exict pas dans la list d'execution");}
else{
    rch=recherch(A,id);

   if(rch==NULL){
        printf("l'element n'exite pas dans larbre");
   }
   else
    {
    if(rch->ETAT==0){
    tuer(&A,&pret,id);
    }
    else{
        if(rch->ETAT==1){
                tuer(&A,&elue,id);
        }
        else{
                if(rch->ETAT==2){
                        tuer(&A,&bloc,id);
                }
        }
    }
    htop(A);
}

}

}
break;
case 7:
    {
        htop(A);
    }
}

}

}
    return 0;
}
