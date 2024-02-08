
typedef struct elementarbre* tarbreprocessus;
struct elementarbre{
int pid;
char Nom[12];
int ram;
int ETAT;
struct elementarbre* fils;
struct elementarbre* frere;
int priorite;
};

typedef struct elementprocessus* listeprocessus;
struct elementprocessus{
int PID;
struct elementprocessus* suivant;
};







void cree(tarbreprocessus T,int per,int taille,listeprocessus elu,int* x,int d,listeprocessus* pre);
void htop( tarbreprocessus a);
tarbreprocessus recherch(tarbreprocessus E,int id);
void lanc(listeprocessus pr,listeprocessus* el, tarbreprocessus a);
void bloque(listeprocessus* el,listeprocessus* bloq,int ID,tarbreprocessus p);
void debloque(listeprocessus* el,listeprocessus* bloq,int ID,tarbreprocessus p);
void tuer(tarbreprocessus* A, listeprocessus* list,int pid);
void cre_root( tarbreprocessus* p, listeprocessus* el);
void ajout_pret(  listeprocessus* pr,int ID,int prior ,tarbreprocessus a);
void depile_debit( listeprocessus* l);