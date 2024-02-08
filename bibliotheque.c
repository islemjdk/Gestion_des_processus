#include"bibliotheque.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cree(tarbreprocessus T,int per,int taille,listeprocessus elu,int* x,int d,listeprocessus* pre)
{

tarbreprocessus p;
 int tr;
 *x=0;

 if(T!=NULL)

       {
        if(T->pid==per)
         {
              *x=1;
            if(T->fils==NULL)
              {
                T->fils=malloc(sizeof(struct elementarbre));
               printf("entrez le non :  ");
               getchar();
               gets(T->fils->Nom);
                T->fils->ETAT=0;
                T->fils->ram=taille;
                T->fils->fils=NULL;
                T->fils->frere=NULL;
                T->fils->pid=d;
                do{
                printf("\nentrez la priorite :  ");
                scanf("%d",&T->fils->priorite);
                }while(T->fils->priorite>7||T->fils->priorite<1);
                 ajout_pret(pre,d,T->fils->priorite,T);

              }
         else
              {
               p=T->fils;
               while(p->frere!=NULL){p=p->frere;}
               p->frere=malloc(sizeof( struct elementarbre ));
                printf("entrez le non : ");
               getchar();
               gets(p->frere->Nom);
                p->frere->ETAT=0;
                p->frere->ram=taille;
                p->frere->fils=NULL;
                p->frere->frere=NULL;
                p->frere->pid=d;
                do{
                printf("\nentrez la priorite : ");
              scanf("%d",&p->frere->priorite);
                }while(p->frere->priorite>7||p->frere->priorite<1);
                 ajout_pret(pre,d,p->frere->priorite,T);
             }


        }
     else{

        int y;
        cree(T->fils,per,taille,elu,&y,d,pre);
        if(y==0)
            {

            cree(T->frere,per,taille,elu,&y,d,pre);}
           }

     }

       }



void htop( tarbreprocessus a)
{

    if(a!=NULL)
   {

 if(a->pid==0) {printf(" \n\n\n pid=%d    la taille=%d   etat=%d   priorite=%d",a->pid,a->ram,a->ETAT,a->priorite);}
 else{ printf("\n non=%s     pid=%d    la taille=%d   etat=%d   priorite=%d",a->Nom,a->pid,a->ram,a->ETAT,a->priorite);}



 for( tarbreprocessus I=a->fils;I!=NULL;I=I->frere){
htop(I);

 }
}
}
tarbreprocessus recherch(tarbreprocessus E,int id)
{

  if(E==NULL){return NULL;}
  else{
    if(E->pid==id){return E;}
    else{
        if(recherch(E->fils,id)==NULL){return recherch(E->frere,id);}

        else{return recherch(E->fils,id);}

    }
  }
}
void lanc(listeprocessus pr,listeprocessus* el, tarbreprocessus a)
{
 listeprocessus p,e;
 int x;
  tarbreprocessus t;

   if(pr==NULL){printf("il n'exicte pa dun processus");}
    else{

         if(*el==NULL)
            {

                  *el=malloc(sizeof(struct elementprocessus));
                 (*el)->PID=pr->PID;
                 (*el)->suivant=NULL;
                  x=pr->PID;
                 t=recherch(a,x);
                 if(t==NULL){printf("\n il ya un ereur");}
                 else{

                 t->ETAT=1;
          }
         }
         else{
              p=*el;
             while(p->suivant!=NULL){p=p->suivant;}
             p->suivant=malloc(sizeof(struct elementprocessus));
             p->suivant->PID=(pr)->PID;
             p->suivant->suivant=NULL;
            x=(pr)->PID;
            t=recherch(a,x);
              if(t==NULL){printf("\n il ya un ereur");}
             else{

           t->ETAT=1;

           printf("%d",pr->PID);

         }

         }

    }

}
void bloque(listeprocessus* el,listeprocessus* bloq,int ID,tarbreprocessus p)
{

tarbreprocessus t;
 int tr;
 listeprocessus e,v,tem;
 e=malloc(sizeof(struct elementprocessus));
 e->PID=ID;
 e->suivant=*bloq;
 *bloq=e;

 if((*el)->PID==ID)
  {
    tem=*el;
 *el=(*el)->suivant;
 free(tem);

  }
  else
    {
     v=(*el)->suivant;
     tem=*el;
     while(v!=NULL&&tr==0)
     {
        if(v->PID==ID)
        {
           tr=1;
        tem->suivant=v->suivant;
        free(v);
        }

         else
            {
             tem=tem->suivant;
             v=v->suivant;
           }

     }


    }

   t=recherch(p,ID);
   if(t==NULL){printf("il ya un ereur");}
         else{
  if(t->ETAT==1){t->ETAT=2;}
  else{printf("lelement nexist pas");}

         }
}
void debloque(listeprocessus* el,listeprocessus* bloq,int ID,tarbreprocessus p)
{
 tarbreprocessus t;
 int tr;
 listeprocessus e,tem,v;
 e=malloc(sizeof(struct elementprocessus));
 e->PID=ID;
 e->suivant=*el;
 *el=e;
 if((*bloq)->PID==ID)
  {
    tem=*bloq;
 *bloq=(*bloq)->suivant;
 free(tem);

  }
  else
    {
     v=(*bloq)->suivant;
     tem=*bloq;
     tr=0;
     while(v!=NULL&&tr==0)
     {
        if(v->PID==ID)
        {
           tr=1;
        tem->suivant=v->suivant;
        free(v);


        }

         else
            {
             tem=tem->suivant;
             v=v->suivant;
           }

     }
}

   t=recherch(p,ID);
   if(t==NULL){printf("il ya un ereur");}
         else{
   if(t->ETAT==2){t->ETAT=1;}
   else{printf("lelement nexiste pas");}
         }
}

void liberaebre(tarbreprocessus processus){
          if( processus!=NULL)
          {
              liberaebre(processus->fils);
                 liberaebre(processus->frere);
                 free(processus);
          }
      }

       tarbreprocessus processusAsuprimer=NULL;
      tarbreprocessus parentDprocessusAsuprimer=NULL;

      void recherchprocessus(tarbreprocessus parent,tarbreprocessus actuel , int pid)
           {
             if(actuel!=NULL)
             {
                 if(actuel->pid==pid)
                 {
                    processusAsuprimer= actuel;
                    parentDprocessusAsuprimer=parent;
                    return;
                 }
                 recherchprocessus(actuel,actuel->fils , pid);
                  recherchprocessus(parent,actuel->frere , pid);
             }
           }

void tuer(tarbreprocessus* A, listeprocessus* list,int pid)
{
    
           recherchprocessus(NULL,*A , pid);
           
    if( processusAsuprimer!=NULL)
    {
        liberaebre(processusAsuprimer->fils);
        if(*list!=NULL&&(*list)->PID==pid)
        {
             listeprocessus temp= *list;
              *list= (*list)->suivant;
              free(temp);
        }
        else
        {
             listeprocessus tempparent=*list;
             while( tempparent!=NULL&& tempparent->suivant!=NULL&&tempparent->suivant->PID!=pid)
             {
                 tempparent=tempparent->suivant;
             }
             if(tempparent!=NULL&&tempparent->suivant!=NULL)
             {
                    listeprocessus temp=tempparent->suivant;
                    tempparent->suivant=temp->suivant;
                    free(temp);

             }
        }
       if(parentDprocessusAsuprimer!=NULL)
       {
           if(parentDprocessusAsuprimer->fils==processusAsuprimer)
           {
               parentDprocessusAsuprimer->fils=processusAsuprimer->frere;

           }
           else{
              tarbreprocessus tempfrere=parentDprocessusAsuprimer->fils;
              while(tempfrere!=NULL&&tempfrere->frere!=processusAsuprimer)
              {
                  tempfrere=tempfrere->frere;
              }
              if(tempfrere!=NULL)
              {
                  tempfrere->frere=processusAsuprimer->frere;
              }
           }
       }
      free(processusAsuprimer);

    }
    else{
       printf("ERREUR:process avec pid %d non trouve.\n",pid);
    }
}
void cre_root( tarbreprocessus* p, listeprocessus* el)
{
    *p =malloc(sizeof(struct elementarbre));
    (*p)->pid=0;
    (*p)->ETAT=1;
    (*p)->ram=2;
    (*p)->fils=NULL;
    (*p)->frere=NULL;
    (*p)->priorite=1;
    (*el)=malloc(sizeof(struct elementprocessus));
    (*el)->PID=(*p)->pid;
    (*el)->suivant=NULL;
}
void ajout_pret(  listeprocessus* pr,int ID,int prior ,tarbreprocessus a)
{

    int c,tr;
    tarbreprocessus R;
    listeprocessus p,tem;
    if(*pr==NULL)
    {

        (*pr)=malloc(sizeof(struct elementprocessus));
        (*pr)->PID=ID;
        (*pr)->suivant=NULL;
    }
    else
    {


          R=recherch(a,(*pr)->PID);

          c=R->priorite;

           if(c>prior)
              {

                    p=malloc(sizeof(struct elementprocessus));
                    p->PID=ID;
                    p->suivant=*pr;
                   *pr=p;


              }
          else
             {


                    p=*pr;
                    tr=0;
                    while(p->suivant!=NULL&&tr==0)
                        {

                             R=recherch(a,p->suivant->PID);
                             c=R->priorite;


                            if(c<=prior){p=p->suivant;}
                            else
                            {
                                tr=1;
                                tem=malloc(sizeof(struct elementprocessus));
                                tem->PID=ID;
                                tem->suivant=p->suivant;
                                p->suivant=tem;
                            }

                        }
                    if(tr==0&&p->suivant==NULL)
                    {
                       p->suivant=malloc(sizeof(struct elementprocessus));
                       p->suivant->PID=ID;
                       p->suivant->suivant=NULL;

                    }

             }
    }
}
void depile_debit( listeprocessus* l)
{
 
   if(*l!=NULL)
  {       
        listeprocessus tem;
       tem=*l;
      *l=(*l)->suivant;
       free(tem);
   }
}