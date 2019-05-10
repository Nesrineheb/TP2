#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25000
#define  MAX1 100
/*-------Déclaration des structures-------*/
typedef struct Tenreg
 {
 int  Eff;
 int  Matricule;
 char Nom[31];
 char PreNom[31];
 char Date_Naissance[50];
 char Wilaya_Naissance[50];
 char Sexe[10];
 char Groupe_sanguin[3];
 char Date_Recrutemet[50];
 char Grade[50];
 char Specialite[50];
 char Derier_Diplome[50];
 char Etablissemet_Univ[100];
 } Tenreg;
typedef struct Tbloc
 {
 Tenreg T[1000];
 int Nb;
 } Tbloc;
 typedef struct Entete
 {
 int adrDerBloc;
 int indice_libre;
int nbEnreg;
int nbcarasup;
 } Entete;
 typedef struct maillon_mat{
     int matricule;
     int pos;
     int bloc;
     struct maillon_mat *suiv;
     }maillon_mat;
 typedef struct idex_spe{
     char spec[50];
      struct maillon_mat *tete;}idex_spe;
 typedef struct TObF
 {
 FILE *fichier;
 Entete entete;
 } TObF;
 typedef struct table_index1  //structure de la table d'indes
{
    int cle;                //le matricule de l'esegieat
    int bloc;               //le numéro de bloc
    int pos;                //la position de l'enregestrement dans le bloc
    int efface;             //le bit d'effacement
}table_index1;
 TObF *f ;

 typedef struct tableindex1
 {
  table_index1 T[90000];
 }tableindex1;


  typedef struct maillon_eseg{
     int matricule;
     char date_rec[50];
     int pos;
     int bloc;
     struct maillon_eseg *suiv2;
     }maillon_eseg;

   typedef struct tind3_R
  {
     char region[50];
      struct maillon_mat *tete1;}tind3_R;



   typedef struct   idex_etab
   { char etablissement[100];
      struct  maillon_eseg *tete2;}idex_etab ;


 /*la Machine abstraite*/
 int ouvrir(TObF **f,char *chemin,char mode);
 void fermer(TObF *f);
 void lireDir(TObF *f,int N_Bloc,Tbloc *buffer);
 void ecrireDir(TObF *f,int N_Bloc,Tbloc *buffer);
 int entete(TObF *f,int i);
 void aff_entete(TObF *f, int i, int val);
 int alloc_bloc(TObF *f);
 void Charger(int N);
 void Afficher();
 void supprimer(int i,int j);
 void affich_LLC(maillon_mat* tete);
/*les fct de rempplisage*/
int rand_a_b(int a,int b);
int* init_sans_doublons(int a, int b);
void melanger(int* tableau, int taille);
char matr_alea(int a,int b );
void  nomaleat(char nom[31]);
void  prenomaleat(char prenom[31]);
void  weilaya_n(char weilaya_n[50]);
void  genr(char gen[10]);
void  grp_s(char group_sg[3]);
void grade(char grd[50]);
void  spec( char sp[50]);
void  der_dip( char drdp[50]);
void  date_recr (char mm[50]);
void itabli (char ita[100]);
/*les fonctions pour ordonner */
void tri_bulle_code1(table_index1 tab[MAX],int taille_tab);
void tri_bulle_code3(idex_spe tab[MAX1],int taille_tab);
void tri_bulle_etab(idex_etab tab[MAX1],int taille_tab);
//void tri_bulle_code2(table_index2 tab[MAX],int taille_tab);
/*les fonctions de recherche*/
void recherchedicho(idex_spe tab[MAX1],int t, char c[50], int *trouv,int *j );
/*fonction d'affichage de l'entete du fichier*/
void Affichage_Entete(TObF* fichier);
/*la machie astraite de la liste*/
void liberer(maillon_mat *tete);
int Matricule( struct maillon_mat *P);
void Aff_Adr( struct maillon_mat *P,  struct maillon_mat *Q);
void Aff_Mat(struct maillon_mat *P, int v);
struct maillon_mat *Allouer ();
void Aff_Val_pos(struct maillon_mat *P, int v);
void Aff_Val_bloc(struct maillon_mat *P, int v);
int pos( struct maillon_mat *P);
int bloc( struct maillon_mat *P);
/************************************************/
 struct maillon_eseg *Allouer2 ();
void Aff_Mat2(struct maillon_eseg *P, int v);
void Aff_date_recru(struct maillon_eseg *P, char date_recrutemet[50]);
void Aff_pos2(struct maillon_eseg *P, int v);
void Aff_bloc2(struct maillon_eseg *P, int v);
void Aff_Adr2( struct maillon_eseg *P,  struct maillon_eseg *Q);
struct maillon_eseg *Suivant2( struct maillon_eseg *P);
int Matricule2( struct maillon_eseg *P);
void  date_recrutemet1( struct maillon_eseg *P ,char dat[50] );
int pos2( struct maillon_eseg *P);
int bloc2( struct maillon_eseg *P);
void liberer2(maillon_eseg *tete);
void affich_LLC2(maillon_eseg* tete);
struct maillon_mat* Suivant(  struct maillon_mat *P);
 void insere_etabli(idex_etab ti_etb[MAX1],char etab[100],char date_recrutem[50] ,int matri ,int *taille_tetab ,int e,int nblc);

//void recherche_tindex50(idex_spe tab[MAX1],char c[50],int *taille_tindx,int *trv,int *p);
void insere100( idex_spe tix[MAX1],char specialite[50],int matri ,int *taille_ta,int e,int nblc);
void chrge_tab_index1 (tableindex1 *t);
void nb_ligne(char fichier [256],int *k);
void    remplisage_enreg(maillon_mat p,int matri,int e,int nblc);
/************recherch************************/
void Recherche_Dicho(tableindex1 t,int a,int *j,int *x,int *i);
void rech_matr(int a,int *i,int *j , int *b);
void rech(int cle , int *b,int *i,int *j,int *mm);/**marche**/
 void modifier_etab(int mat ,int b,int num,int pos);
void  chager_table_ind3(tind3_R tab3[10],char etablissemet[50],int matri ,int e,int nblc);
 void supp_mat(int mat,int i,int j,int g);
 void rech_spe (char cle[50] , int *b,int *mm);
  void supp_spe(char cle [50],int ss );
  void chrge_tab_index3 ( char cle[200], int bi, int bs);
   void rech_region (char cle[50]);
    void insert_new(int mat,int *i,int *j,int nb);
     void rech12(int a , int *bbb,int *ii,int *jj,int *mm);
// insert_new(int mat,int i,int j,int nb);





/*--------------Fonction d'ouverture d'un fichier--------------*/




int ouvrir(TObF **f,char *chemin,char mode)
{
 (*f) = malloc(sizeof(TObF));
 char s[3];
 if((mode == 'A') || (mode == 'a')) sprintf(s,"rb+");
 else if ((mode == 'N') || (mode == 'n')) sprintf(s,"wb+");
 else return 0;
 (*f)->fichier = fopen(chemin,s);
 if((*f)->fichier == NULL) return 0;
 if((mode == 'A') || (mode == 'a'))
 {
 fread(&((*f)->entete), sizeof(Entete), 1, (*f)->fichier);
 }
 else if ((mode == 'N') || (mode == 'n'))
 {
 (*f)->entete.adrDerBloc = 0;
 }
 return 1;
}
/*--------------------------------------------------------------*/
/*--------------Fonction de fermeture d'un fichier--------------*/
void fermer(TObF *f)
{
 //Sauvegarde de l'entête
 rewind(f->fichier);
 fwrite(&(f->entete), sizeof(Entete), 1, f->fichier);
 fclose(f->fichier);
 free(f);
}
/*--------------------------------------------------------------*/
/*-----------------Fonction de lecture d'un bloc----------------*/
void lireDir(TObF *f,int N_Bloc,Tbloc *buffer)
{
 if(N_Bloc <= (f->entete).adrDerBloc)
 {
 fseek(f->fichier, sizeof(Entete) + (N_Bloc-1) * sizeof(Tbloc),SEEK_SET);
 fread(buffer, 1, sizeof(Tbloc), f->fichier);
 }
}
/*--------------------------------------------------------------*/
/*-----------------Fonction d'écriture d'un bloc----------------*/
void ecrireDir(TObF *f,int N_Bloc,Tbloc *buffer)
{
 if(N_Bloc <= (f->entete).adrDerBloc)
 {
 fseek(f->fichier, sizeof(Entete) + (N_Bloc-1) * sizeof(Tbloc),SEEK_SET);
 fwrite(buffer, 1, sizeof(Tbloc), f->fichier);
 }
}
/*--------------------------------------------------------------*/
int entete(TObF *f,int i)
{
 if(i == 1) return (f->entete).adrDerBloc;
 else if(i == 2) return (f->entete).indice_libre;
 else if(i == 3) return (f->entete).nbEnreg;
  else if(i == 4) return (f->entete).nbcarasup;
 else return -1;
}
/*--------------------------------------------------------------*/
/*-------------Fonction de modification de l'entête-------------*/
void aff_entete(TObF *f, int i, int val)
{
 if(i == 1) (f->entete).adrDerBloc = val;
 else if(i == 2) (f->entete).indice_libre= val;
 else if(i == 3) (f->entete).nbEnreg= val;
  else if(i == 4) (f->entete).nbcarasup= val;
}
/*--------------------------------------------------------------*/
/*--------------------L'allocation d'un bloc--------------------*/
int alloc_bloc(TObF *f)
{
 aff_entete(f,1,entete(f,1)+1);
 return entete(f,1);
}
/*la machie straite de la liste*/

struct maillon_mat *Allouer ()   /*allouer un maillon de ty pe maillon mat*/
{ return ((struct maillon_mat *) malloc( sizeof(struct maillon_mat ))); }
void Aff_Mat(struct maillon_mat *P, int v)  /*affecter  a maillon de type maillon mat la valeur du matricule */
{ P->matricule=v; }
void Aff_pos(struct maillon_mat *P, int v)  /*affecter a maillon de type maillon mat la valeur de la position */
{ P->pos=v; }
void Aff_bloc(struct maillon_mat *P, int v)    /*affecter  a maillon de type maillon mat la valeur du umero du bloc */
{ P->bloc=v; }
void Aff_Adr( struct maillon_mat *P,  struct maillon_mat *Q)   /*affecter  a maillon de type maillon mat au champ du suiveur l'adresse*/
{ P->suiv=Q; }
struct maillon_mat *Suivant( struct maillon_mat *P)
{ return(P->suiv);}
int Matricule( struct maillon_mat *P)
{ return( P->matricule) ; }
int pos( struct maillon_mat *P)
{ return( P->pos) ; }
int bloc( struct maillon_mat *P)
{ return( P->bloc) ; }
void liberer(maillon_mat *tete)
{
    maillon_mat *p,*q;
    p=tete;
    while(p!=NULL)
    {
        q=p->suiv;
        free(p);
        p=q;
    }
}








/*la machie astraite de la liste de la tale des regio */
/*la machie straite de la liste*/

struct maillon_eseg *Allouer2 () /*allouer un maillon de ty pe maillon mat*/
{ return ((struct maillon_eseg *) malloc( sizeof(struct maillon_eseg ))); }
void Aff_Mat2(struct maillon_eseg *P, int v)   /*affecter  a maillon de type maillon eseg la valeur du matricule */
{ P->matricule=v; }
void Aff_date_recru(struct maillon_eseg *P, char date_recrutemet[50])  /*affecter a maillon de type maillon eseg la valeur de la date de recrutement */
{ strcpy(P->date_rec,date_recrutemet); }
void Aff_pos2(struct maillon_eseg *P, int v)  /*affecter a maillon de type maillon eseg la valeur de la position */
{ P->pos=v; }
void Aff_bloc2(struct maillon_eseg *P, int v)  /*affecter  a maillon de type maillon eseg la valeur du umero du bloc */
{ P->bloc=v; }
void Aff_Adr2( struct maillon_eseg *P,  struct maillon_eseg *Q) /*affecter  a maillon de type maillon eseg au champ du suiveur l'adresse*/
{ P->suiv2=Q; }
struct maillon_eseg *Suivant2( struct maillon_eseg *P)
{ return(P->suiv2);}
int Matricule2( struct maillon_eseg *P)
{ return( P->matricule) ; }
void  date_recrutemet1( struct maillon_eseg *P ,char dat[50] )
{
    sprintf(dat,P->date_rec);
  }
int pos2( struct maillon_eseg *P)
{ return( P->pos) ; }
int bloc2( struct maillon_eseg *P)
{ return( P->bloc) ; }
void liberer2(maillon_eseg *tete)
{
    maillon_eseg *p,*q;
    p=tete;
    while(p!=NULL)
    {
        q=p->suiv2;
        free(p);
        p=q;
    }
}

/*chargement initiale*/
void Charger(int N)
{
  /*Initialisation*/
  char nom2[31];
  int k=0;
  int l=0;
  int x=0;
   char datenai[50];
 char daterec[50];
 char ita[100];
 int *taillei=0;
 int  *taille_i_etb=0;
 maillon_eseg *p2;
  char specia[50]="";
  table_index1  tind1[90000];
  idex_spe ti3[100];
  tind3_R  titab[10];
  idex_etab tindex_etab[100];
 maillon_mat *p,*q,*t;
  Tbloc buf;
 /*les matricules sas doulos*/
  //srand(time(NULL));
  int* t_s_d=NULL;
  t_s_d=init_sans_doublons(111111,999999);
  melanger(t_s_d,999999-111111);
   /*deut du chargemet*/
  ouvrir(&f,"ENSEIGAT_MERS.bin",'N');
  int Num=alloc_bloc(f);
  int j=0;
  int a=0;
    for (k=0;k<=N;k++){
        if (j<1000){
buf.T[j].Eff=0;
buf.T[j].Matricule=t_s_d[k];
tind1[a].cle= t_s_d[k];
tind1[a].efface=0;
tind1[a].pos=j;
tind1[a].bloc=Num;
nomaleat(buf.T[j].Nom);
prenomaleat(buf.T[j].PreNom);
date_naiss(datenai);
strcpy(buf.T[j].Date_Naissance,datenai);
weilaya_n(buf.T[j].Wilaya_Naissance);
genr(buf.T[j].Sexe);
grp_s(buf.T[j].Groupe_sanguin);
date_recr (daterec);
strcpy(buf.T[j].Date_Recrutemet,daterec);
grade(buf.T[j].Grade);
spec(buf.T[j].Specialite);
itabli (ita);
sprintf(buf.T[j].Etablissemet_Univ,ita);
insere_etabli(tindex_etab,buf.T[j].Etablissemet_Univ,buf.T[j].Date_Recrutemet ,buf.T[j].Matricule ,&taille_i_etb ,j,Num);
insere100(ti3,buf.T[j].Specialite, buf.T[j].Matricule,&taillei,j,Num);
chager_table_ind3(titab,buf.T[j].Etablissemet_Univ,buf.T[j].Matricule ,j,Num);
der_dip(buf.T[j].Derier_Diplome);
j++;
a++;
 }
   if (j>=1000) {
buf.Nb=j-1;
ecrireDir(f,Num,&buf);
Num=alloc_bloc(f);
buf.T[0].Eff=0;
buf.T[0].Matricule=t_s_d[k];
tind1[a].cle= t_s_d[k];
tind1[a].efface=buf.T[j].Eff;
tind1[a].pos=j;
tind1[a].bloc=Num;
nomaleat(buf.T[0].Nom);
prenomaleat(buf.T[0].PreNom);
date_naiss(datenai);
strcpy(buf.T[0].Date_Naissance,datenai);
weilaya_n(buf.T[0].Wilaya_Naissance);
genr(buf.T[0].Sexe);
grp_s(buf.T[0].Groupe_sanguin);
date_recr(daterec);
strcpy(buf.T[0].Date_Recrutemet,daterec);
grade(buf.T[0].Grade);
spec(buf.T[0].Specialite);
insere100(ti3,buf.T[0].Specialite, buf.T[0].Matricule,&taillei,j,Num);
der_dip(buf.T[0].Derier_Diplome);
itabli (ita);
strcpy(buf.T[0].Etablissemet_Univ,ita);
insere_etabli(tindex_etab,buf.T[0].Etablissemet_Univ,buf.T[0].Date_Recrutemet ,buf.T[0].Matricule,&taille_i_etb,0,Num);
chager_table_ind3(titab,buf.T[0].Etablissemet_Univ,buf.T[0].Matricule,0,Num);
j=1;
}
  }
 int val1=0;
int val2=0;
int val3=0;
char  val4[50];
FILE *fi5;
fi5=fopen("Tindex_spec.txt","w+"); /*ouvrire un nouveau fichier pour sauvegarder la  table d'index des pecialites*/
int  ppp=0;
while(ppp<=(taillei))
        { sprintf(val4,ti3[ppp].spec);  /*sauvegardez le specialite dans la va41*/
          p=ti3[ppp].tete;
          while(p!=NULL) {      /*parcourire la liste de la specialite*/
        val1=Matricule(p);     /*sauvegardez le matriculedas la val1*/
        val3=pos(p);            /*sauvegardez le numero de la position dans la val3*/
        val2=bloc(p);           /*sauvegardez le numero du bloc das la val2*/
        fprintf(fi5,"%d/%d/%d/%s\n",val2,val1,val3,val4);
       p=Suivant(p);
}ppp++;

        }fclose(fi5);
tri_bulle_code1(tind1,a-1);  /* trier la premiere tale d'index des matricule */
 a=0;
 val1=0;
 val2=0;
 val3=0;
int val40=0;
FILE *fi1;
fi1=fopen("Tindex_matricule.txt","w+");   /*ouvrire un nouveau fichier pour sauvegarder la  table d'index des matricules*/
while(a<=N){      /*parcourire la table d'index des matricules et  a chaque fois on recupere les iformations dans des variale pour les reecrire das le fichier pour la sauvegarde */
        val1=tind1[a].cle;
        val3=tind1[a].pos;
        val2=tind1[a].bloc;
        val40=tind1[a].efface;
        fprintf(fi1,"%d_%d_%d_%d\n",val1,val2,val3,val40);
        a++;
}fclose(fi1);
char  val400[50];
FILE *fi3;
fi3=fopen("Tindex_region.txt","w+");    /*ouvrire un nouveau fichier pour sauvegarder la  table d'index des regions*/
int pi;
for(  pi=0;pi<=2;pi++)
        { sprintf(val400,titab[pi].region);
          p=titab[pi].tete1;
          while(p!=NULL) {

//                cpt++;
        val1=Matricule(p);
        val3=pos(p);
        val2=bloc(p);
        fprintf(fi3,"%d/%d/%d/%s\n",val2,val1,val3,val400);
        p=Suivant(p);
        }//printf("ya psss c moi le cp %d\n",cpt);
    // cpt=0;
        }fclose(fi3);



      int   val01=0;
int val02=0;
  int val03=0;
char val04[100]="";
        FILE *fi2;
fi2=fopen("Tindex_etab.txt","w+");  /*ouvrire un nouveau fichier pour sauvegarder la  table d'index des etablissemet */
int  pos1=0;
char  val_date[50]="";
while(pos1<=(taille_i_etb))
        { sprintf(val04,tindex_etab[pos1].etablissement);
          p2=tindex_etab[pos1].tete2;
          while(p2!=NULL) {   /*parcourire la liste des  etablissemetet  et a chaque fois on recupere les infos a partir du maillon pour les sauvegarder das le fichier d'index */
        val01=Matricule2(p2);
        val03=pos2(p2);
        val02=bloc2(p2);
        date_recrutemet1(p2,val_date);
        fprintf(fi2,"%s\n",val04);
        fprintf(fi2,"%d##%d##%d##%s\n",val01,val03,val02,val_date);
       p2=Suivant2(p2);
}pos1++;

        }fclose(fi2);

buf.Nb=j-1;     /*on affecte au  buf.Nb le nombre d'eregistrement affecter*/
ecrireDir(f,Num,&buf);
aff_entete(f,1,Num);   /*on affecte a l'entete  le nombre de bloc utuliser */
aff_entete(f,2,1000-buf.Nb);/*on affecte a l'entete  le nombre d'eregistrement affecter au bloc */
aff_entete(f,3,N);    /*on affecte a l'entete   le nombre d'eregistrement ajouter au totale */
aff_entete(f,4,0);   /*on affecte  a l'entete   le nombre d'eregistrement effacer */
fermer(f);
printf("fin de charger\n");
}

/*affichage du fichier */
void Afficher()
{
 Tbloc buf;
 int i=1;
 ouvrir(&f,"ENSEIGAT_MERS.bin",'A');
 printf("Nb = %d\n",buf.Nb);
 int j;
 printf("les enreg : \n");
 while(i<=entete(f,1)){
        lireDir(f,i,&buf);
 for (j=0;j<=buf.Nb;j++)
 {
if (buf.T[j].Eff==0){
printf("le matricule est %d\n  ",buf.T[j].Matricule);
printf(" le champ efface est a %d\n ",buf.T[j].Eff);
printf(" le nom du proffeseur est %s\n",buf.T[j].Nom);
printf(" son prenom est %s\n",buf.T[j].PreNom);
printf(" il est nee le %s\n",buf.T[j].Date_Naissance);
printf(" il est nee a %s\n",buf.T[j].Wilaya_Naissance);
printf(" c est un(e) %s\n",buf.T[j].Sexe);
printf(" son groupe sangun est %s\n",buf.T[j].Groupe_sanguin);
printf(" sa date re Recrutement est  %s\n",buf.T[j].Date_Recrutemet);
printf("  il est de grade %s\n",buf.T[j].Grade);
printf(" sa specialite d etude est de %s\n",buf.T[j].Specialite);
printf("  son dernier diplome est %s\n ",buf.T[j].Derier_Diplome);
printf("  son Etablissement Universitaire  %s\n ",buf.T[j].Etablissemet_Univ);
printf("--------------------------------------------------------------------------\n");}
     if(buf.T[j].Eff==1) {printf("--------------------------------------------------------------------------\n");
 printf("enreg efface\n");
 printf("--------------------------------------------------------------------------------\n");} ;
 }i++;}
printf("votre loc totale utulises das votre programmes est %d",entete(f,1));
 fermer(f);
}
/*les fonction de remplissage*/
char matr_alea(int a,int b ){
    return a + rand()%(b-a) ;
}

void  nomaleat(char nom[31]){  /*generer un nom aleatoire*/
char* pn;
int d=0;
int l=0;
char monnom[31]="";
    d=rand_a_b(4,15);
            for (l=0;l<=d;l++){
                pn= matr_alea(1,26);
                pn=pn+64;
                strcat(&monnom,&pn);

}strcpy(nom,monnom);


}
void  prenomaleat(char prenom[31]){   /*generer un nom aleatoire*/
char* pn;
int d=0;
int l=0;
char   monnom[31]="";
    d=rand_a_b(4,15);
            for (l=0;l<=d;l++){
                pn= matr_alea(1,26);
                pn=pn+64;
                strcat(&monnom,&pn);
}
strcpy(prenom,monnom);
}


void  weilaya_n(char weilaya_n[50]){  /*generer une  wilaya aleatoirement*/
   int i=rand_a_b(0,47);
char  wilaya[][48]={"Adrar","Chlef","Laghouat","Oum el_Bouaghi","Batna","Bejaia","Biskra","Bechar","Blida","Bouira","Tamanghasset","Tebessa","Tlemcen","Tiaret","Tizi_Ouzou","Algiers","Djelfa","Jijel","Setif","Saida","Skikda","Sidi_Bel_Abbes","Annaba","Guelma","Constantine","Medea","Mostaganem","MSila","Mascara","Ouargla","Oran","El_Bayadh","Illizi","Bordj_Bou_Arreridj","Boumerdes","El_Taref","Tindouf","Tissemsilt","El_Oued","Khenchela","Souk_Ahras","Tipaza","Mila","Ain_Defla","Naama","Ain_Temouchent","Ghardaia","Relizane"};
   strcpy(weilaya_n,wilaya[i]);

}
void  genr(char gen[10]){     /*generer un genr  aleatoirement*/

     int k=rand_a_b(0,1);
     if (k==0){ strcpy(gen,"MALLE");}else{strcpy(gen,"FEMELLE");}

}
void  grp_s(char group_sg[3]){  /*generer un groupe sanguin  aleatoirement*/

     int m=rand_a_b(0,7);
     char  GROUPE_SAGUN[][7]={"O+","A+","B+","O-","A-","AB+","B-","AB"};
      strcpy(group_sg,GROUPE_SAGUN[m]);

}
void grade(char grd[50]){   /*generer un grad  aleatoirement*/

     int m=rand_a_b(0,5);
    char  GRade[][50]={"Professeur(e)","Maitre de conferences Rang A","Maitre de conferences Rang B","Maitre assistant(e) Rang A","Maitre assistant(e) Rang B","Assistant(e)"};
      sprintf(grd,GRade[m]);

    }
void  spec( char sp[50]){   /*generer une specialite  aleatoirement*/

     int m=rand_a_b(0,19);
    char  specialite[][30]={"Informatique","Architecture","Medecine","Droit_prive","Droit_public","organisations_politiques","Langue_arabe","Litterature_arabe","Physique_theorique","biologie","Ecologie_et_environnement","Biochimie","Marketing","Commerce_International","Informatique_de_gestion","Finance_et_Banque","Telecommunications","orientation","Sociologie"};
      strcpy(sp,specialite[m]);

}
void  der_dip( char drdp[50]){   /*generer un dernier diplome obtenue   aleatoirement*/

     int m=rand_a_b(0,4);
    char  dernier_dip[][50]={"Doctorat dEtat","Doctorat en sciences","PhD","HDR","Magister"};
      strcpy(drdp,dernier_dip[m]);

}

void  date_naiss (char m[50])/*generer la date de naissance    aleatoirement*/

 {
     char date[30]="";
    int jour;
    int mois;
    int da;
    int quat="1954,1958,1960,1964,1968,1972,1976,1980,1984,1988,1992"; /**afin de donner une date correct */
    int ch="1,3,5,7,9,11";
    char cj[4]="";
    char cd[5]="";
    char cm[4]="";
    da = 1953 + rand()%39;
    mois = 1 + rand()%12;
    if ( mois == 2)
    {
        if(da == quat)
        {
            jour = 1 + rand()%29;
        }
        else
        {
             jour = 1 + rand()%28;
        }

    }
    else
    {
        if ( mois == ch )
        {
            jour = 1 + rand()%31;
        }
        else
        {
             jour = 1 + rand()%30;
        }
    }
    itoa(jour, cj, 10);
    itoa(da, cd, 10);
    itoa(mois, cm, 10);
    strcat(&date,&cj);
    strcat(&date,"/");
    strcat(&date,&cm);
    strcat(&date,"/");
    strcat(&date,&cd);
    strcpy(m,date);
 }

 void  date_recr (char mm[50]) /*generer la date de recrutement   aleatoirement*/
 {
        char dat[30]="";
    int j;
    int m;
    int d;
    int you="1980,1984,1988,1992,1996,2000,2004,2008,2012,2016";/**afin de donner une date correct */
    int ch="1,3,5,7,9,11";
    char ccj[4]="";
    char ccd[5]="";
    char ccm[4]="";
    d = 1979 + rand()%39;
    m = 1 + rand()%12;
    if ( m == 2)
    {
        if(d == you)
        {
            j = 1 + rand()%29;
        }
        else
        {
             j = 1 + rand()%28;
        }

    }
    else
    {
        if ( m == ch )
        {
            j = 1 + rand()%31;
        }
        else
        {
             j = 1 + rand()%30;
        }
    }

    itoa(j, ccj, 10);
    itoa(d, ccd, 10);
    itoa(m, ccm, 10);
    strcat(&dat,&ccj);
    strcat(&dat,"/");
    strcat(&dat,&ccm);
    strcat(&dat,"/");
    strcat(&dat,&ccd);
     strcpy(mm,dat);
 }

 void itabli (char ita[100])   /*generer un etablissemet   aleatoirement*/
 {
     int i,j;
     char  itablis_centre[][200]={"Universite_de_Bouira-Akli_Mohand_Oulhadj","Universite_de_Djelfa_Ziane_Achour","Universite_de_Ghardaia","Universite_de_Khemis_Miliana-Djilali_Bounaama","Universite_Medea-Yahia_Fares","Universite_d'alger_Houari_Boumediene","Universite_de_Bejaia-Abderrahmane_Mira","Universite_de_Chlef-Hassiba_Benbouali","Universite_de_Boumerdes-M'hamed_Bougara","Universite_de_Tizi_ouzou-Mouloud_Maameri","Universite_de_Laghouat-Amar_Telidji","Universite_Blida1-Saad_Dahlab","Universite_de_Blida2-Lounici_Ali","Universite_d'Alger_1-Benyoucef_Benkhedda","Universite_d'Alger2-Abou_el_Kacem_Saâdallah","Universite_d'Alger3-Brahim_Soltane_Chaibout","Universite_de_la_Formation_Continue"};
     char itablis_est[][200]={"Universite_de_Jijel-Mohammed_Seddik_Ben_yahia","Universite_de_Tebessa-Larbi_Tebessi","Universite_de_Bordj_Bou_Arreridj-Mohamed_Bachir_El_Ibahimi","Universite_d'El_Tarf-Chadli_Bendjedid","Universite_d'El_Oued-Hamma_Lakhdar","Universite_de_Souk_Ahras-Mohammed-Cherif_Messaadia","Universite_de_Annaba-Badji_Mokhtar","Universite_du_20_Août_1955_de_Skikda","Universite_8_Mai_1945_de_Gelma","Universite_de_batna1-Hadj_Lakhder","Universite_de_Biskra-Mohamed_Khider","Universite_de_M'sila-Mohamed_Boudiaf","Universite_de_Ouargla-Kasdi_Merbah","Universite_Emir_Abdelkader_de_Constantine","Universite_de_Setif1-Ferhat_Abbas","Universite_de_Setif2-Mohamed_Lamine_Debaghine","Universite_de_Constantine1-Frères_Mentouri","Universite_de_Constantine2-Abdelhamid_Mehri","Universite_de_Constantine3-Salah_Boubnider","Universite_de_Batna2-Mustapha_Ben_Boulaid"};
     char itablis_ouest [][200]={"Universite_de_Bechar-Mohamed_Tahri","Universite_de_Mascara-Mustapha_Stambouli","Universite_de_Saida-Tahar_Moulay","Universite_de_Tlemcen-Abou_Bekr_Belkaid","Universite_d'Adrar-Ahmed_Draya","Universite_de_Tiaret-Ibn_Khaldoun","Universite_Sidi_Bel_Abbès-Djillali_Liabes","Universite_de_Mostaganem_Abdelhamid_Ibn_Badis","Universite_d'Oran1_Ahmed_Ben_Bella","Universite_Mohamed_Boudiaf_d'Oran","Universite_d'Oran2-Mohamed_Ben_Ahmed"};
     i = rand()%3;
     if (i==0)/**centre*/
     {
         j=rand()%16;
         strcpy(ita,itablis_centre[j]);
     }
     else
     {
         if (i==1)
         {
            j=rand()%20;
            strcpy(ita,itablis_est[j]);
         }
         else
         {
            j=rand()%10;
            strcpy(ita,itablis_ouest[j]);
         }
     }
 }
  void itabl2 (char ita[100],int *r)  /* donne la region de l'etablissement */
 {
     int i,j,b;
     char  itablis_centre[][200]={"Universite_de_Bouira-Akli_Mohand_Oulhadj","Universite_de_Djelfa_Ziane_Achour","Universite_de_Ghardaia","Universite_de_Khemis_Miliana-Djilali_Bounaama","Universite_Medea-Yahia_Fares","Universite_d'alger_Houari_Boumediene","Universite_de_Bejaia-Abderrahmane_Mira","Universite_de_Chlef-Hassiba_Benbouali","Universite_de_Boumerdes-M'hamed_Bougara","Universite_de_Tizi_ouzou-Mouloud_Maameri","Universite_de_Laghouat-Amar_Telidji","Universite_Blida1-Saad_Dahlab","Universite_de_Blida2-Lounici_Ali","Universite_d'Alger_1-Benyoucef_Benkhedda","Universite_d'Alger2-Abou_el_Kacem_Saâdallah","Universite_d'Alger3-Brahim_Soltane_Chaibout","Universite_de_la_Formation_Continue"};
     char itablis_est[][200]={"Universite_de_Jijel-Mohammed_Seddik_Ben_yahia","Universite_de_Tebessa-Larbi_Tebessi","Universite_de_Bordj_Bou_Arreridj-Mohamed_Bachir_El_Ibahimi","Universite_d'El_Tarf-Chadli_Bendjedid","Universite_d'El_Oued-Hamma_Lakhdar","Universite_de_Souk_Ahras-Mohammed-Cherif_Messaadia","Universite_de_Annaba-Badji_Mokhtar","Universite_du_20_Août_1955_de_Skikda","Universite_8_Mai_1945_de_Gelma","Universite_de_batna1-Hadj_Lakhder","Universite_de_Biskra-Mohamed_Khider","Universite_de_M'sila-Mohamed_Boudiaf","Universite_de_Ouargla-Kasdi_Merbah","Universite_Emir_Abdelkader_de_Constantine","Universite_de_Setif1-Ferhat_Abbas","Universite_de_Setif2-Mohamed_Lamine_Debaghine","Universite_de_Constantine1-Frères_Mentouri","Universite_de_Constantine2-Abdelhamid_Mehri","Universite_de_Constantine3-Salah_Boubnider","Universite_de_Batna2-Mustapha_Ben_Boulaid"};
     char itablis_ouest [][200]={"Universite_de_Bechar-Mohamed_Tahri","Universite_de_Mascara-Mustapha_Stambouli","Universite_de_Saida-Tahar_Moulay","Universite_de_Tlemcen-Abou_Bekr_Belkaid","Universite_d'Adrar-Ahmed_Draya","Universite_de_Tiaret-Ibn_Khaldoun","Universite_Sidi_Bel_Abbès-Djillali_Liabes","Universite_de_Mostaganem_Abdelhamid_Ibn_Badis","Universite_d'Oran1_Ahmed_Ben_Bella","Universite_Mohamed_Boudiaf_d'Oran","Universite_d'Oran2-Mohamed_Ben_Ahmed"};
     i==0;
     while  (i<=16)
     {
         if (strcmp(itablis_centre[i],ita)==0)
         {
             *r=1;
             b=1;
         }
         i++;
     }
     i=0;
     if (b!=1)
     {
         while  (i<=20)
        {
         if (strcmp(itablis_est[i],ita)==0)
         {
             *r=2;
             b=1;
         }
         i++;
        }
        if (b!=1)
        {
            *r=3;
        }

     }

 }
/*les fonctions du trie*/

void tri_bulle_code1(table_index1 tab[MAX],int taille_tab) // Tri à bulles des mots d'index selon l'ordre alphabétique
{
    int cpt,h,p,m,j,c;

    do
    {
        j = 0;
        cpt = 0 ;
        while (j<=taille_tab-1)
        {
            if (tab[j].cle>tab[j+1].cle)
            {  /** si la jème cle  si elle est supérieur au j+1ème cle alors on procède à une permutation **/


                h=tab[j].cle;
               m=tab[j].efface;
                p=tab[j].bloc;                                   // Permuatation champ par champ
                c=tab[j].pos;
                tab[j].cle=tab[j+1].cle;
                tab[j].efface=tab[j+1].efface;
                tab[j].bloc=tab[j+1].bloc;
                tab[j].pos=tab[j+1].pos;
                tab[j+1].cle=h;
                tab[j+1].efface=m;
                tab[j+1].bloc=p;
                tab[j+1].pos=c;
                cpt++;
            } j++;

        }
    }while (cpt != 0) ;

}
/*fonctions d affichage de l'entete*/
void Affichage_Entete(TObF* fichier)
{
    printf("\n Les caracteristiques du fichier ----------------------------------------\n\n");
    printf(" -> Adresse dernier bloc : %d\n",entete(fichier,1));
    printf(" -> position libre dernier bloc : %d\n",entete(fichier,2));
    printf(" -> Nombre caracteres inseres : %d\n",entete(fichier,3));
    printf(" -> Nombre caracteres supprimes : %d\n",entete(fichier,4));
}

/*fonctions des  generation aleatoire */
int rand_a_b(int a,int b ){
    return a + rand()%(b-a) ;
}
int* init_sans_doublons(int a, int b){  /*fonctions des  generation aleatoire  des entiers sans doublons*/
	int taille = b-a;
	int* resultat=malloc((taille)*sizeof (int));
	int i=0;
	// On remplit le tableau de manière à ce qu'il soit trié
	for(i = 0; i< taille; i++){
		resultat[i]=i+a;
	}
	return resultat;
}

void melanger(int* tableau, int taille){   /*fonctions pour effectuer un melange  des entiers  generer sans doublons*/
	int i=0;
	int nombre_tire=0;
	int temp=0;

	for(i = 0; i< taille;i++){
		nombre_tire=rand_a_b(0,taille);
		// On échange les contenus des cases i et nombre_tire
		temp = tableau[i];
		tableau[i] = tableau[nombre_tire];
		tableau[nombre_tire]=temp;
	}
}







void affich_LLC(maillon_mat* tete)   /*fonction pour afficher la listes des matricules*/
{
    maillon_mat *p,*q;
    p=tete;
    if(tete!=NULL){
    while(p!=NULL)
    { printf(" le matricule est |----->%d \n",Matricule(p));
    printf("la positio est  |----->%d \n",pos(p));
    printf(" le bloc est |----->%d \n",bloc(p));
     p=Suivant(p);



    }
        printf("*******--------*******\n");
                    }
    else printf("la liste est vide mon ami :p");
}




 void chrge_tab_index1 (tableindex1 *t) /**charge la table d'index des matricules */
 {


       char ligne[20];
       int m1;
       int m2;
       int m3;
       int m4;
       int y=0;
       int d;
       int i=0;
       FILE *p=fopen("Tindex_matricule.txt","r");
       if ( p != NULL)
       {
            nb_ligne("Tindex_matricule.txt",&d);
            while ( y<d ) /**au nb des enregistr**/
            {
               fscanf(p,"%d_%d_%d_%d",&m1,&m2,&m3,&m4);
               (*t).T[i].cle = m1;
               (*t).T[i].bloc = m2;
               (*t).T[i].pos = m3 ;
               (*t).T[i].efface = m4;
               y++;
               i++;
            }
       }
       else
       {
           printf("le fichier n'existe pas !!!\n ");
       }
       fclose(p);

 }
 void nb_ligne(char fichier [256],int *k) /** le nombre de ligne d'un fichier */
{
    char ligne [256];
    int cpt = 0 ;
    char *m = NULL ;
    FILE *f1;
    f1 = fopen( fichier ,"r");
    if (f1!= NULL)
    {
     while (!feof(f1))
    {
        if (fgets(ligne,sizeof(ligne),f1))
        {
            cpt++;
        }
    }
      *k=cpt;
    }
    else
    {
        *k=-1;
    }
    fclose(f1);

}
void Recherche_Dicho(tableindex1 t,int a,int *j,int *x,int *i) /**module de la recherch dico dans la tabele d'index ordonnée*/
{/// j est la pos ; i et le num de bloc
    /// trouv ==1 si cle existe
    int bi,bs,m;
    x=0;
    bi=0;
    bs=10;
    while ((!x)  && (bs>=bi))
    {
        m=(bs+bi)/2;
        *x=((t.T[m].cle) == a);
        if (t.T[m].cle > a)
            {bs=m-1;}
        else
            {bi=m+1;}
    }

    if ((t.T[m].cle )!= a)
    {

        *x=-1;
        *j=t.T[m].bloc;
        *i=t.T[m].pos;
    }
    else
    {
            *x=1;
            *j=t.T[m].bloc;
            *i=t.T[m].pos;

    }
}


 void rech(int a , int *bbb,int *ii,int *jj,int *mm) /**retourne en sortie la pos et le num de bloc du matricule donnée*/
 {

     int num;
int pos;
int *b;

printf(" votre Affichage est : \n");
tableindex1 t;
chrge_tab_index1(&t);

///rech

Tbloc buffer;
int p;
int bi,bs,m;



int x;/**notre bool*/

int j; /**pos*/
int i;/**bloc*/

x=0;

bi=0;

bs=10;

    while ((!x)  && (bs>=bi))
    {
        m=(bs+bi)/2;
        x=((t.T[m].cle) == a);
        if (t.T[m].cle > a)
            {bs=m-1;
            }
        else
            {

                bi=m+1;}
    }


    if ((t.T[m].cle )!= a)
    {
        x=-1;
*bbb=x;
        (j)=t.T[m].bloc;
     *jj=j;
        (i)=t.T[m].pos;
         *ii=i;

    }
    else
    {

            x=1;
            *bbb=x;
            i=t.T[m].bloc;
            *ii=i;
            j=t.T[m].pos;
            *jj=j;
            *mm=m;

    }
    ouvrir(&f,"ENSEIGAT_MERS.bin",'A');
     if (x == -1)
     {
         printf(" il n'exsite pas un enregistrement ayant ce matricule  \n");
     }
     else///existe
     {



        lireDir(f,i,&buffer);
        printf("\n****************  voici votre enreg **********************\n"); /** enrg exsite et on a sa pos on doit l'afficher **/
        printf(" le matricule %d\n", buffer.T[j].Matricule);
        printf("la Date_Naissance %s\n", buffer.T[j].Date_Naissance);
        printf("Wilaya_Naissance %s\n", buffer.T[j].Wilaya_Naissance);
        printf("  Sexe %s\n", buffer.T[j].Sexe);
        printf("Groupe_sanguin %s\n", buffer.T[j].Groupe_sanguin);
        printf("  Date_Recrutemet %s\n", buffer.T[j].Date_Recrutemet);
        printf("  Grade %s\n", buffer.T[j].Grade);
        printf("  Specialite %s\n", buffer.T[j].Specialite);
        printf("  Derier_Diplome %s\n", buffer.T[j].Derier_Diplome);
        printf("  Etablissemet_Univ %s\n", buffer.T[j].Etablissemet_Univ);
     }
     fermer(f);

     free(&t);
 }

 void modifier_etab(int mat,int b,int num,int pos)/**modfier l'etablissement d'un enrigestremengt */
 {
     Tbloc buffer;
     char ita[70];
     char k[50];
     char ha[50];
   //  printf("%d\n",b);
    // printf("%d\n",pos);
    // printf("%d\n",num);

     ouvrir(&f,"ENSEIGAT_MERS.bin",'A');
     if (b == -1)
     {
         printf("  n'exsite pas \n");
     }
     else/** la modification dans le fichier*/
     {
          lireDir(f,num,&buffer);
          printf(" son  Etablissemet_Univ actuelle est  %s\n", buffer.T[pos].Etablissemet_Univ);
          strcpy(ita, buffer.T[pos].Etablissemet_Univ);
          strcpy(ha,buffer.T[pos].Date_Recrutemet);
          printf("donnez le nouveau itablissement \n");
          scanf("%s",k);
        //  printf("%s",k);
          strcpy( buffer.T[pos].Etablissemet_Univ,k);
          printf(" le nouvelle  Etablissemet_Univ  est  %s\n", buffer.T[pos].Etablissemet_Univ);
          ecrireDir(f,num,&buffer);
     }

     /***********la modification dans les tables d'index*******************/

     idex_etab t1[25];
        int cp=0;
       char  mm1[70];
       char mm5[50];
       int mm2;
       int mm3;
       int mm4;
       int yy=1;
       int db;
       int it=0;
       maillon_eseg *qqq;
       maillon_eseg *rr;
       maillon_eseg *vv,*ll;
       FILE *p1=fopen("Tindex_etab.txt","r");/**table d'indes des etablisements*/
       /**on la charge*/
       if ( p1 != NULL)
       {
           fscanf(p1,"%s",&mm1);
           fscanf(p1,"%d##%d##%d##%s",&mm2,&mm3,&mm4,&mm5);
            vv = Allouer2();
            Aff_date_recru(vv,mm5);
            Aff_bloc2(vv,mm4 );
            Aff_Mat2(vv,mm2);
            Aff_pos2(vv,mm3);
            Aff_Adr2(vv,NULL);
            (t1[0]).tete2= vv;
            strcpy(((t1[0]).etablissement) ,mm1);
            rr=(t1[0]).tete2;
            nb_ligne("Tindex_etab.txt",&db);
            db= db/2;
            while ( yy<db ) /**au nb des enregistr**/
            {
                  fscanf(p1,"%s",&mm1);
           fscanf(p1,"%d##%d##%d##%s",&mm2,&mm3,&mm4,&mm5);
               if (strcmp(mm1,(t1[it]).etablissement)==0)
               {

                  qqq = Allouer2();
                   Aff_Adr2(rr,qqq);
                   Aff_Adr2(qqq,NULL);
                    Aff_bloc2(qqq,mm4 );
                    Aff_Mat2(qqq,mm2);
                    Aff_pos2(qqq,mm3);
                    Aff_date_recru(qqq,mm5);
                    rr =qqq;
               }
               else
               {
                    it++;
            strcpy((t1[it]).etablissement ,mm1) ;
            vv = Allouer2();
            Aff_bloc2(vv,mm4 );
            Aff_Mat2(vv,mm2);
            Aff_pos2(vv,mm3);
            Aff_date_recru(vv,mm5);
            Aff_Adr2(vv,NULL);
            (t1[it]).tete2 = vv;
            ///strcpy(((t[i]).spec) ,m1);
            rr=(t1[it]).tete2;
               }
               yy++;

            }
       }
       else
       {
           printf("le fichier n'existe pas !!!\n ");
       }
       fclose(p1);
     int a11=0;
       int b11,mmm,aj,b12;
        while(a11<=it)
     {

          if (strcmp(ita,(t1[a11]).etablissement)==0) /** on cherche la pos de lietablissement donnee*/
          {
              b11 = 1;
              mmm = a11;

          }
          if (strcmp(k,(t1[a11]).etablissement)==0)
          {
              b12 = 1;
              aj = a11;

          }
         a11++;
     }


     maillon_eseg *k3,*k4; /**la modification dans table*/
     if (b12==1)/**si l'etablissement existe deja*/
     {
         k3 = t1[aj].tete2;
         while (Suivant2(k3)!=NULL)
         {
             k3=Suivant2(k3);
         }
             k4 = Allouer2();
            Aff_Adr2(k3,k4);
            Aff_Adr2(k4,NULL);
            Aff_bloc2(k4,num );
            Aff_Mat2(k4,mat);
            Aff_pos2(k4,pos);
            Aff_date_recru(k4,buffer.T[pos].Date_Recrutemet);
     }
     else /** s'il n'exsite pas*/
     {
            it++;
            strcpy((t1[it]).etablissement ,k) ;
            k4 = Allouer2();
            Aff_bloc2(k4,num );
            Aff_Mat2(k4,mat);
            Aff_pos2(k4,pos);
            Aff_date_recru(k4,buffer.T[pos].Date_Recrutemet);
            Aff_Adr2(k4,NULL);
            (t1[it]).tete2 = k4;
     }


     if (b11 != 1)
     {

         printf("cette etablisemet n'exsite pas \n");
     }
     else
     {
         maillon_eseg *k1;
        FILE *fii;
        int is=0;
        int za1,za2,za3;
        char za4[70];
        char te[20];
        fii =fopen("Tindex_etab.txt","w+");
    while(is<it)
        {
            k1 = t1[is].tete2;/**on sauvgarde les onformation dans le fichier index*/
            while (k1!=NULL)
            {
                    if ((k1->matricule)==mat)
                    {
                        if (strcmp(ita,t1[is].tete2)==0)
                        {
                              k1=Suivant2(k1);
                        }
                        else
                        {
                            strcpy(za4,t1[is].etablissement);
                            za1=k1->bloc;
                            za2=k1->matricule;
                            za3=k1->pos;
                            strcpy(te,k1->date_rec);
                            fprintf(fii,"%s\n",za4);
                            fprintf(fii,"%d##%d##%d##%s\n",za2,za3,za1,te);
                            k1=Suivant2(k1);
                        }

                    }

                else
                {
                strcpy(za4,t1[is].etablissement);
                za1=k1->bloc;
                za2=k1->matricule;
                za3=k1->pos;
                strcpy(te,k1->date_rec);
                fprintf(fii,"%s\n",za4);
                fprintf(fii,"%d##%d##%d##%s\n",za2,za3,za1,te);
                k1=Suivant2(k1);
                }
            }
            is++;
        }
          fclose(fii);
          insere_etabli(t1,buffer.T[pos].Etablissemet_Univ,ha ,buffer.T[pos].Matricule ,&it ,pos,num);


     free(&t1);


     }
 fermer(f);


 }

 void supp_mat(int mat,int i,int j,int g) /**j est la pos*//**supprimer par matricule*/
 {
 char cle[70];
          Tbloc buffer;
     tableindex1 t;
     chrge_tab_index1(&t);/**on charge la table des matricules*/
     char tmp[50];

     int h,s;
    ouvrir(&f,"ENSEIGAT_MERS.bin",'A');
     h=entete(f,3);
     s=j;
     while(s<h)
     {
         (t).T[s].bloc = (t).T[s+1].bloc;
         (t).T[s].cle = (t).T[s+1].cle ;
         (t).T[s].efface =(t).T[s+1].efface ;
         (t).T[s].pos = (t).T[s+1].pos ;
          s++;
     }
      (t).T[s].bloc=i;
       (t).T[s].pos=j;
     h=entete(f,3)-1;
       s=0;
    int val1=0;
    int val2=0;
    int val3=0;
    int val4=0;
    FILE *fi1;
    fi1=fopen("Tindex_matricule.txt","w+");
    while(s<=h)
        {
            val1=t.T[s].cle;
            val3=t.T[s].pos;
            val2=t.T[s].bloc;
            val4=t.T[s].efface;
            fprintf(fi1,"%d_%d_%d_%d\n",val1,val2,val3,val4);
            s++;
    }
     fclose(fi1);/*************************ok****************/
    char ita[70];

     lireDir(f,i,&buffer);/** on écrase par le dernier enrigestrement */
     strcpy(tmp,buffer.T[g].Specialite);
       s = buffer.Nb;
       strcpy(ita,buffer.T[g].Etablissemet_Univ);
     buffer.T[g].Matricule =  buffer.T[s].Matricule ;
    strcpy( buffer.T[g].Date_Naissance ,buffer.T[s].Date_Naissance);
   strcpy(buffer.T[g].Wilaya_Naissance , buffer.T[s].Wilaya_Naissance);
     strcpy (buffer.T[g].Sexe , buffer.T[s].Sexe);
    strcpy (buffer.T[g].Groupe_sanguin ,buffer.T[s].Groupe_sanguin );
    strcpy (buffer.T[g].Date_Recrutemet ,   buffer.T[s].Date_Recrutemet);
    strcpy (buffer.T[g].Grade ,buffer.T[s].Grade) ;
    strcpy (buffer.T[g].Specialite ,buffer.T[s].Specialite );
    strcpy (buffer.T[g].Derier_Diplome ,  buffer.T[s].Derier_Diplome);
    strcpy(cle , buffer.T[g].Etablissemet_Univ);
     strcpy(buffer.T[g].Etablissemet_Univ ,buffer.T[s].Etablissemet_Univ);
       aff_entete(f,3,(entete(f,3))-1 );
       buffer.Nb = (buffer.Nb) -1 ;
       ecrireDir(f,i,&buffer);
     fermer(f);
     free(&t);
     /********************la suppretion  dans les autre tables d'index*/
    idex_spe tt[25];/**table de speaciality*/
       char  m1[50];
       int m2;
       int m3;
       int m4;
       int y=0;
       int d;
       int ii=1;
       int b,mm;
       maillon_mat *q;
       maillon_mat *r;
       maillon_mat *v;
       FILE *p=fopen("Tindex_spec.txt","r");
       if ( p != NULL)
       {
           fscanf(p,"%d/%d/%d/%s",&m4,&m2,&m3,&m1);
            v = Allouer();
            Aff_bloc(v,m4 );
            Aff_Mat(v,m2);
            Aff_pos(v,m3);
            Aff_Adr(v,NULL);
            (tt[0]).tete = v;
            strcpy(((tt[0]).spec) ,m1);
            r=(tt[0]).tete;
            nb_ligne("Tindex_spec.txt",&d);
         while ( y<d )
            {
               fscanf(p,"%d/%d/%d/%s",&m4,&m2,&m3,&m1);
               if (strcmp(m1,(tt[ii]).spec)==0)
               {

                  q = Allouer();
                   Aff_Adr(r,q);
                   Aff_Adr(q,NULL);
                    Aff_bloc(q,m4 );
                    Aff_Mat(q,m2);
                    Aff_pos(q,m3);
                    r =q;
               }
               else
               {
                    ii++;
                   strcpy((tt[ii]).spec ,m1) ;
            v = Allouer();
            Aff_bloc(v,m4 );
            Aff_Mat(v,m2);
            Aff_pos(v,m3);
            Aff_Adr(v,NULL);
            (tt[ii]).tete = v;
            r=(tt[ii]).tete;
               }
               y++;
            }
       }
       else
       {
           printf("le fichier n'existe pas !!!\n ");
       }


     int a,is;
     a=0;
     while(a<=ii)
     {
          if (strcmp(tmp,(tt[a]).spec)==0)
          {
              b = 1;
              mm = a;
          }
         a++;
     }
maillon_mat *k;
    FILE *fi;
        is=0;
        int zal1,zal2,zal3;
        char zal4[50];
        fi =fopen("Tindex_spec.txt","w+");
    while(is<ii)
        {
            k = tt[is].tete;
            while (k!=NULL)
            {
                if (k->matricule==mat)
                {
                    k=Suivant(k);
                }
                else
                {
                strcpy(zal4,tt[is].spec);
                zal1=k->bloc;
                zal3=k->matricule;
                zal2=k->pos;
                fprintf(fi,"%d/%d/%d/%s\n",zal1,zal3,zal2,zal4);
                k=Suivant(k);
                }
            }
            is++;
        }
     fclose(fi);
     free(&tt);
     /***********************************etabli*/

     idex_etab t1[60];/**tables des etablissemnet*/
        int cp=0;
       char  mm1[70];
       char mm5[50];
       int mm2;
       int mm3;
       int mm4;
       int yy=1;
       int db;
       int it=0;
       maillon_eseg *qqq;
       maillon_eseg *rr;
       maillon_eseg *vv,*ll;
       FILE *p1=fopen("Tindex_etab.txt","r");
       if ( p1 != NULL)
       {
           fscanf(p1,"%s",&mm1);
           fscanf(p1,"%d##%d##%d##%s",&mm2,&mm3,&mm4,&mm5);
            vv = Allouer2();
            Aff_date_recru(vv,mm5);
            Aff_bloc2(vv,mm4 );
            Aff_Mat2(vv,mm2);
            Aff_pos2(vv,mm3);
            Aff_Adr2(vv,NULL);
            (t1[0]).tete2= vv;
            strcpy(((t1[0]).etablissement) ,mm1);
            rr=(t1[0]).tete2;
            nb_ligne("Tindex_etab.txt",&db);
            db= db/2;
            while ( yy<db ) /**au nb des enregistr**/
            {
                  fscanf(p1,"%s",&mm1);
           fscanf(p1,"%d##%d##%d##%s",&mm2,&mm3,&mm4,&mm5);
               if (strcmp(mm1,(t1[it]).etablissement)==0)
               {

                  qqq = Allouer2();
                   Aff_Adr2(rr,qqq);
                   Aff_Adr2(qqq,NULL);
                    Aff_bloc2(qqq,mm4 );
                    Aff_Mat2(qqq,mm2);
                    Aff_pos2(qqq,mm3);
                    Aff_date_recru(qqq,mm5);
                    rr =qqq;
               }
               else
               {
                    it++;
                   strcpy((t1[it]).etablissement ,mm1) ;
            vv = Allouer2();
            Aff_bloc2(vv,mm4 );
            Aff_Mat2(vv,mm2);
            Aff_pos2(vv,mm3);
            Aff_date_recru(vv,mm5);
            Aff_Adr2(vv,NULL);
            (t1[it]).tete2 = vv;
            ///strcpy(((t[i]).spec) ,m1);
            rr=(t1[it]).tete2;
               }
               yy++;

            }
       }
       else
       {
           printf("le fichier n'existe pas !!!\n ");
       }
       fclose(p1);


     int a11=0;
       int b11,mmm=0;
        while(a11<=it)
     {
          if (strcmp(ita,(t1[a11]).etablissement)==0)
          {
              b11 = 1;
              mmm = a11;

          }
         a11++;
     }

     if (b11 != 1)
     {

         printf("cette speciality n'exsite pas \n");
     }
     else
     {
         maillon_eseg *k1;
        FILE *fii;
        is=0;
        int za1,za2,za3;
        char za4[50];
        char te[70];
        fii =fopen("Tindex_etab.txt","w+");
    while(is<it)
        {
            k1 = t1[is].tete2;

            while (k1!=NULL)
            {

                if (k1->matricule==mat)
                {

                    k1=Suivant2(k1);
                }

                else
                {
                strcpy(za4,t1[is].etablissement);
                za1=k1->bloc;
                za2=k1->matricule;
                za3=k1->pos;
                strcpy(te,k1->date_rec);
                fprintf(fii,"%s\n",za4);
                fprintf(fii,"%d##%d##%d##%s\n",za2,za3,za1,te);
                k1=Suivant2(k1);
                }
            }
            is++;
        }
     fclose(fii);
     free(&t1);

     }

     int m9;
     int b0;
      tind3_R t0[4];/**table d'index des regions*/
       char  m6[50];
       int m8;
       int m7;
       int m0;
       int y0=1;
       int d0;
       int i0=0;
       maillon_mat *q0,*l0;
       maillon_mat *r0;
       maillon_mat *v0;
       FILE *p0=fopen("Tindex_region.txt","r");
       if ( p0 != NULL)
       {
           fscanf(p0,"%d/%d/%d/%s",&m9,&m8,&m7,&m6);
            v = Allouer();
            Aff_bloc(v,m9 );
            Aff_Mat(v,m8);
            Aff_pos(v,m7);
            Aff_Adr(v,NULL);
            (t0[0]).tete1 = v;
            strcpy(((t0[0]).region) ,m6);
            r0=(t0[0]).tete1;
            nb_ligne("Tindex_region.txt",&d0);
            while ( y0<d0 ) /**au nb des enregistr**/
            {
               fscanf(p0,"%d/%d/%d/%s",&m9,&m8,&m7,&m6);
               if (strcmp(m6,(t0[i0]).region)==0)
               {

                  q0 = Allouer();
                   Aff_Adr(r0,q0);
                   Aff_Adr(q0,NULL);
                    Aff_bloc(q0,m9 );
                    Aff_Mat(q0,m8);
                    Aff_pos(q0,m7);
                    r0 =q0;
               }
               else
               {
                    i0++;
                   strcpy((t0[i0]).region ,m6) ;
            v0 = Allouer();
            Aff_bloc(v0,m9 );
            Aff_Mat(v0,m8);
            Aff_pos(v0,m7);
            Aff_Adr(v0,NULL);
            (t0[i0]).tete1 = v0;
            ///strcpy(((t[i]).spec) ,m1);
            r0=(t0[i0]).tete1;
               }

               y0++;

            }

       }
       else
       {
           printf("le fichier n'existe pas !!!\n ");
       }
       fclose(p0);

       /***********************rech*********************************/
     int e0,a0,j0;
     a0=0;

     char wow[10];
     int ro;
     itabl2 (cle,&ro);/**pour savoir la region de l'etablissement*/
     if (ro==1)
     {
            strcpy(wow,"Centre");
     }
     else
     {
         if (ro==2)
         {
              strcpy(wow,"Est");
         }
         else
         {
             strcpy(wow,"Ouest");
         }
     }
     while(a0<=i0)
     {

          if (strcmp(wow,(t0[a0]).region)==0)
          {
              b0 = 1;
              m0 =a0;
          }
         a0++;
     }
     if (b0 != 1)
     {

         printf("cette speciality n'exsite pas \n");
     }
     else
     {
         maillon_mat *k2;
    FILE *fi3;
        is=0;
        int z0,z01,z02;
        char z03[10];
        fi3  =fopen("Tindex_region.txt","w+");
    while(is<=i0)
        {
            k2 = t0[is].tete1;
            while (k2!=NULL)
            {
                if (k2->matricule==mat)
                {
                    k2=Suivant(k2);
                }
                else
                {
                strcpy(z03,t0[is].region);


                z0=k2->bloc;
                z01=k2->matricule;
                z02=k2->pos;
                fprintf(fi3,"%d/%d/%d/%s\n",z0,z01,z02,z03);
                k2=Suivant(k2);
                }
            }
            is++;
        }

     fclose(fi3);
     free(&t0);
     }

 }


void insere100( idex_spe tix[MAX1],char specialite[50],int matri ,int *taille_ta ,int e,int nblc) /*insertion et creation   de la table d'index des specialites*/
 {
  maillon_mat *p,*q,*g,*o,*k,*i;
if (*taille_ta==0)
    { sprintf(tix[*taille_ta].spec,specialite);  /*on recopie le nom de la specialite dans la premiere case*/
        o=Allouer();                      /*on alloue un nouveau maillon qui va contenir le premier matricule de cette specialite*/
        Aff_Adr(o,NULL);     /*on affecte au champ suivante de ce maillon au null*/
        Aff_Mat(o,matri);     /*on affecte le matricule*/
        Aff_pos(o,e);      /*on affecte la position du matricule dan le fichier binaire au champ pos*/
        Aff_bloc(o,nblc);     /*affectation du numero du bloc */
        tix[*taille_ta].tete=o;  /*le champ tete de la table index qui correspond a cette specialite va pointer sur o*/
        *taille_ta=*taille_ta+1;    /*la tille d'index s'incremente de 1*/
   }


else
   {int mm=0;  int trv=0; int  posexi=0;  int indice=0;
    while((mm<=(*taille_ta-1)&&(trv==0)))
{
if (strcmp(tix[mm].spec,specialite)!=0)   /*on compare les specialite du tableau avec la specialite donner en entre*/
    {mm++; trv=0;}        //on incremente le mm si on a pas encor trouver la specialite pour avancer dans la table d'index
   else              {trv=1;   /*si les deux chaine sont egale alor la specialite existe dans le tableau  alor on affecte 1 a trv */
                    posexi=mm;}   /*on recupere la position ou se trouve la specialite dans le tableau de  specialite*/
}
  if (trv==1)

        {

          k=tix[posexi].tete;    /*on recupere la tete de la liste qui exerce cette specialite*/
            while((k!=NULL)&&(matri>Matricule(k)))   //on parcour la liste tanque soit on a pas arriver a la fin de liste ou le matricule donner en entree superieur au matricule de p
                {
                i=k;
                k=Suivant(k);
                }

                         if (k==NULL)   //on est arriver a la fin de la liste et le matricule est toujours superieur a tous les matricules  de la liste
                    {
                                     o=Allouer();
                                    //on fait les affectations
                                     Aff_Adr(o,NULL);
                                     Aff_bloc(o,nblc);
                                     Aff_Mat(o,matri);
                                     Aff_pos(o,e);
                                     Aff_Adr(i,o);
                    }

                    //si on sort de la boucle car le matricule qu'on veut l'inserer est inferieur a une valeur dant la liste
       else {if  (matri<=Matricule(k)){
            if (k==tix[posexi].tete)  //si la tete est inferieur a la valeur du mat de la specialite a ajouter
                       {
                           //on fait le chainage et puis les affectation
                                     o=Allouer();
                           //on fait les affectations
                                     Aff_Adr(o,NULL);
                                     Aff_Mat(o,matri);
                                     Aff_pos(o,e);
                                     Aff_bloc(o,nblc);
                                     Aff_Adr(o,k);
                                    tix[posexi].tete=o;
                        }
                        else{
                                    //on fait le chainage et puis les affectation
                                    o=Allouer();
                                      //on fait les affectations
                                     Aff_Adr(o,NULL);
                                     Aff_Mat(o,matri);
                                     Aff_pos(o,e);
                                     Aff_bloc(o,nblc);
                                     Aff_Adr(i,o);
                                     Aff_Adr(o,k);}
                        }}

                        }

                         //la fin du if de comparaisance d'existence


   else
   {
                                    sprintf(tix[mm].spec,specialite);    //on insere la nouvelle specialite dans la table d"index
                                    o=Allouer();

                            //on fait les affectations
                                     Aff_Adr(o,NULL);
                                     Aff_Mat(o,matri);
                                     Aff_pos(o,e);
                                     Aff_bloc(o,nblc);
                        //on pointe le champ tete sur le maillon allouer qui va contenir les information du matricule qui exerce cette specialite
                                     tix[mm].tete=o;
                                       *taille_ta=*taille_ta+1;

   }
}


 }





void  chager_table_ind3(tind3_R tab3[10],char etablissemet[50],int matri ,int e,int nblc) /*insertion et creation   de la table d'index des regions*/
 {

maillon_mat *p,*i,*o;

char  itablis_centre[][200]={"Universite_de_Bouira-Akli_Mohand_Oulhadj","Universite_de_Djelfa_Ziane_Achour","Universite_de_Ghardaia","Universite_de_Khemis_Miliana-Djilali_Bounaama","Universite_Medea-Yahia_Fares","Universite_d'alger_Houari_Boumediene","Universite_de_Bejaia-Abderrahmane_Mira","Universite_de_Chlef-Hassiba_Benbouali","Universite_de_Boumerdes-M'hamed_Bougara","Universite_de_Tizi_ouzou-Mouloud_Maameri","Universite_de_Laghouat-Amar_Telidji","Universite_Blida1-Saad_Dahlab","Universite_de_Blida2-Lounici_Ali","Universite_d'Alger_1-Benyoucef_Benkhedda","Universite_d'Alger2-Abou_el_Kacem_Saâdallah","Universite_d'Alger3-Brahim_Soltane_Chaibout","Universite_de_la_Formation_Continue"};
     char itablis_est[][200]={"Universite_de_Jijel-Mohammed_Seddik_Ben_yahia","Universite_de_Tebessa-Larbi_Tebessi","Universite_de_Bordj_Bou_Arreridj-Mohamed_Bachir_El_Ibahimi","Universite_d'El_Tarf-Chadli_Bendjedid","Universite_d'El_Oued-Hamma_Lakhdar","Universite_de_Souk_Ahras-Mohammed-Cherif_Messaadia","Universite_de_Annaba-Badji_Mokhtar","Universite_du_20_Août_1955_de_Skikda","Universite_8_Mai_1945_de_Gelma","Universite_de_batna1-Hadj_Lakhder","Universite_de_Biskra-Mohamed_Khider","Universite_de_M'sila-Mohamed_Boudiaf","Universite_de_Ouargla-Kasdi_Merbah","Universite_Emir_Abdelkader_de_Constantine","Universite_de_Setif1-Ferhat_Abbas","Universite_de_Setif2-Mohamed_Lamine_Debaghine","Universite_de_Constantine1-Frères_Mentouri","Universite_de_Constantine2-Abdelhamid_Mehri","Universite_de_Constantine3-Salah_Boubnider","Universite_de_Batna2-Mustapha_Ben_Boulaid"};
     char itablis_ouest [][200]={"Universite_de_Bechar-Mohamed_Tahri","Universite_de_Mascara-Mustapha_Stambouli","Universite_de_Saida-Tahar_Moulay","Universite_de_Tlemcen-Abou_Bekr_Belkaid","Universite_d'Adrar-Ahmed_Draya","Universite_de_Tiaret-Ibn_Khaldoun","Universite_Sidi_Bel_Abbès-Djillali_Liabes","Universite_de_Mostaganem_Abdelhamid_Ibn_Badis","Universite_d'Oran1_Ahmed_Ben_Bella","Universite_Mohamed_Boudiaf_d'Oran","Universite_d'Oran2-Mohamed_Ben_Ahmed"};


   strcpy( tab3[0].region,"Centre");  /*initialiser la premier case au centre*/
   strcpy( tab3[1].region,"Est");   /*initialiser la 2 eme  case au Est*/
   strcpy( tab3[2].region,"Ouest");  /*initialiser la 3 case au ouest*/
   int i1=0;
   int  trv=0;
     while((i1<=16)&&(trv==0)) /*on compare la valeur du trv et la taille du tableau avat d'entrer dans la boucle */
       {
           if(strcmp(etablissemet,itablis_centre[i1])==0) /*on compare a chaque fois l'etblisemet doe e etre avec l'etablisemet  la table des etablisement du centre */
            {   trv=1;  /*si on la trouve  on affecte a trrv 1*/
              if (tab3[0].tete1==NULL) //on fait verifier si la tete du Centre est a NULL
                 {
                  o=Allouer();
                 Aff_Adr(o,NULL);
                //on fait les affectations
                 Aff_Mat(o,matri);
                 Aff_pos(o,e);
                 Aff_bloc(o,nblc);
                 tab3[0].tete1=o; }
            else         //si la liste existe deja
              { p=tab3[0].tete1; //on recupere la tete
                  while ((p!=NULL) && (matri>Matricule(p))) // on  parcoure la liste des etablissemet

             //on parcour la liste tanque soit on a pas arriver a la fin de liste ou le matricule donner en entree et toujour superieur
                  {
                    i=p;
                    p=Suivant(p);
                 }
                         if (p==NULL)     //on est arriver a la fin de la liste et le matricule est toujours superieur a tous les matricules  de la liste
                    {
                                o=Allouer();

                                Aff_Adr(o,NULL);
                                Aff_bloc(o,nblc);
                                Aff_Mat(o,matri);
                                Aff_pos(o,e);
                                Aff_Adr(i,o);

                    }
                    //si on sort de la boucle car le matricule qu'on veut l'inserer est inferieur a une valeur dant la liste

                    else {if  (matri<=Matricule(p)){
                         if (p==tab3[0].tete1)    //si la tete est inferieur a la valeur du mat de l'etablissement a ajouter
                       {
                                     o=Allouer();
                                       //on fait le chainage et puis les affectation
                                     Aff_Adr(o,NULL);
                                     Aff_Mat(o,matri);
                                     Aff_pos(o,e);
                                     Aff_bloc(o,nblc);
                                     Aff_Adr(o,p);
                                     tab3[0].tete1=o;
                        }
                        else{
                                o=Allouer();
                          //on fait le chainage et puis les affectation
                                     Aff_Adr(o,NULL);
                                     Aff_Mat(o,matri);
                                     Aff_pos(o,e);
                                     Aff_bloc(o,nblc);
                                     Aff_Adr(i,o);
                                     Aff_Adr(o,p);}


                                }



              }}}

            else
              {
                 i1++;   //on incremente le i1 si on a pas encor trouver l 'etablissement  pour avancer dans la table du centre
              }


      }





int trv2=0;
if (trv==0)//si on a pas trouver l'etablissement dans la table du cetre  on effectue les meme operation saufe que avec une nouvelle region et danc nouveau tableau des etablissements
    { int i2=0;

     while ((i2<=21)&& (trv2==0))   /*on compare la valeur du trv2 et la taille du tableau avnat d'entrer dans la boucle */
       {
           if(strcmp(etablissemet,itablis_est[i2])==0)
            {   trv2=1;
              if (tab3[1].tete1==NULL)
                 {
                 o=Allouer();
                   //on fait le chainage et puis les affectation
                 Aff_Adr(o,NULL);
                 Aff_Mat(o,matri);
                 Aff_pos(o,e);
                 Aff_bloc(o,nblc);
                 tab3[1].tete1=o;
                 }
            else
              {   p=tab3[1].tete1;
                  while ((p!=NULL) && (matri>Matricule(p)))

                  {
                    i=p;
                    p=Suivant(p);
                 }
                         if (p==NULL)
                    {
                                o=Allouer();
                                  //on fait le chainage et puis les affectation
                                Aff_Adr(o,NULL);
                                Aff_bloc(o,nblc);
                                Aff_Mat(o,matri);
                                Aff_pos(o,e);
                                Aff_Adr(i,o);


                    }

                    else
                      {
                        if  (matri<=Matricule(p))
                      {
                         if (p==tab3[1].tete1)
                       {
                                     o=Allouer();
                                       //on fait le chainage et puis les affectation
                                     Aff_Adr(o,NULL);
                                     Aff_Mat(o,matri);
                                     Aff_pos(o,e);
                                     Aff_bloc(o,nblc);
                                     Aff_Adr(o,p);
                                     tab3[1].tete1=o;
                        }
                        else
                            {
                                     o=Allouer();
                                       //on fait le chainage et puis les affectation
                                     Aff_Adr(o,NULL);
                                     Aff_Mat(o,matri);
                                     Aff_pos(o,e);
                                     Aff_bloc(o,nblc);
                                     Aff_Adr(i,o);
                                     Aff_Adr(o,p);
                           }


                                }



              }}}

            else
              {
                 i2++;    //on incremente le i2 si on a pas encor trouver l 'etablissement  pour avancer dans la table du centre
              }


      }

 }
 if(trv2==0)   //si on a pas trouver l'etablissement dans la table du cetre  on effectue les meme operation saufe que avec une nouvelle region et danc nouveau tableau des etablissements
 {  int i3=0;
      while((i3<=10) &&(trv2==0))  /*on compare la valeur du trv3 et la taille du tableau avant d'entrer dans la boucle */
       {
           if(strcmp(etablissemet,itablis_ouest[i3])==0)
            {   trv2=1;
              if (tab3[2].tete1==NULL)
                 {
                 o=Allouer();
                   //on fait le chainage et puis les affectation
                 Aff_Adr(o,NULL);
                 Aff_Mat(o,matri);
                 Aff_pos(o,e);
                 Aff_bloc(o,nblc);
                 tab3[2].tete1=o; }
            else
              { p=tab3[2].tete1;
                  while ((p!=NULL) && (matri>Matricule(p)))

                  {
                    i=p;
                    p=Suivant(p);
                 }
                         if (p==NULL)
                    {
                                o=Allouer();
                                  //on fait le chainage et puis les affectation
                                Aff_Adr(o,NULL);
                                Aff_bloc(o,nblc);
                                Aff_Mat(o,matri);
                                Aff_pos(o,e);
                                Aff_Adr(i,o);

                    }

                    else {if  (matri<=Matricule(p)){
                         if (p==tab3[2].tete1)
                       {
                                     o=Allouer();
                                       //on fait le chainage et puis les affectation
                                     Aff_Adr(o,NULL);
                                     Aff_Mat(o,matri);
                                     Aff_pos(o,e);
                                     Aff_bloc(o,nblc);
                                     Aff_Adr(o,p);
                                     tab3[2].tete1=o;
                        }
                        else{        o=Allouer();
                          //on fait le chainage et puis les affectation
                                     Aff_Adr(o,NULL);
                                     Aff_Mat(o,matri);
                                     Aff_pos(o,e);
                                     Aff_bloc(o,nblc);
                                     Aff_Adr(i,o);
                                     Aff_Adr(o,p);}


                                }



              }}}

            else
              {
                 i3++;  //on incremente le i3 si on a pas encor trouver l 'etablissement  pour avancer dans la table du centre
              }


      }

 }
 }


 void insere_etabli(idex_etab ti_etb[MAX1],char etab[100],char date_recrutem[50] ,int matri ,int *taille_tetab ,int e,int nblc)   /*la fonction pour inser dans la table index des etablissement */
 {
  maillon_eseg *p,*q,*g,*o,*k,*i;
if (*taille_tetab==0)
    {

        /*on recopie le nom de l'etablissement  dans la premiere case*/
         sprintf(ti_etb[*taille_tetab].etablissement,etab);

       /*on alloue un nouveau maillon qui va contenir le premier matricule de cet etablissement*/
        o=Allouer2();

       /*on affecte au champ suivante de ce maillon au null*/
        Aff_Adr2(o,NULL);

         /*on affecte le matricule*/
        Aff_Mat2(o,matri);

        /*on affecte la position du matricule dan le fichier binaire au champ pos*/
        Aff_pos2(o,e);

        /*affectation du numero du bloc */
        Aff_bloc2(o,nblc);

         /*affectation de la date de recrutemennt*/
        Aff_date_recru(o,date_recrutem);

        /*le champ tete de la table index qui correspond a cet etablissement  va pointer sur o*/
        ti_etb[*taille_tetab].tete2=o;

         /*la tille d'index s'incremente de 1*/
        *taille_tetab=*taille_tetab+1;
   }


else
   {
      //Initialisation

      int mm=0;
      int trv=0;
      int  posexi=0;
      int indice=0;


    /*on compare les specialite du tableau avec la specialite donner en entre*/
    while((mm<=(*taille_tetab-1)&&(trv==0)))
{
if (strcmp(ti_etb[mm].etablissement,etab)!=0)
    {

        //on incremente le mm si encore on est pas arriver a la fin de la table et on a pas trouver l'etablissement
        mm++;
        //trouve reste toujour a 0
        trv=0;
    }

   else                                {
                                        trv=1;    /*si les deux chaine sont egale alor l'etalissement existe dans le tableau d ou on enchaine le nv matricule dans la liste de cette specialite*/
                                        posexi=mm; /*on recupere la position ou se trouve l'etablissement dans le tableau de  specialite*/
                                        }
}
  if (trv==1)  //si o a trouver l'etablisemet dans la tablisement dans la table on effectue le chainage

        {


          k=ti_etb[posexi].tete2;        /*on recupere la tete de la liste qui exerce cette etablisemet*/


        //on parcour la liste tanque soit on a pas arriver a la fin de liste ou le matricule donner en entree
        while((k!=NULL)&&(matri>Matricule2(k)))

                {
                i=k;
                k=Suivant2(k);
                }

                         if (k==NULL)  //on est arriver a la fin de la liste et le matricule est toujours superieur a tous les matricules  de la liste
                    {
                                //on fait le chainage et puis les affectation

                                     o=Allouer2();
                                     Aff_Adr2(o,NULL);
                                     Aff_bloc2(o,nblc);
                                     Aff_Mat2(o,matri);
                                     Aff_pos2(o,e);
                                      Aff_date_recru(o,date_recrutem);
                                     Aff_Adr2(i,o);


                    }

       else {if  (matri<=Matricule2(k))   //si on sort de la boucle car le matricule qu'on veut l'inserer est inferieur a une valeur dant la liste
        {
            if (k==ti_etb[posexi].tete2)  //si c'est superieur a la tete de la liste
                       {

                           //on fait le chainage et puis les affectation et on change la tete
                                   o=Allouer2();
                                     Aff_Adr2(o,NULL);
                                     Aff_Mat2(o,matri);
                                     Aff_pos2(o,e);
                                      Aff_date_recru(o,date_recrutem);
                                     Aff_bloc2(o,nblc);
                                    Aff_Adr2(o,k);
                                   ti_etb[posexi].tete2=o;

                        }
                        else

                        {        //on fait le chainage et puis les affectation
                                     o=Allouer2();
                                     Aff_Adr2(o,NULL);
                                     Aff_Mat2(o,matri);
                                     Aff_pos2(o,e);
                                     Aff_bloc2(o,nblc);
                                      Aff_date_recru(o,date_recrutem);
                                     Aff_Adr2(i,o);
                                     Aff_Adr2(o,k);}
                        }
                        }

                        }
                          //la fin du if de comparaisance d'existence


                      else
                          {
                                   //on insere la nouveau etablissement  dans la table d"index
                                    sprintf(ti_etb[mm].etablissement,etab);
                                     o=Allouer2();
                                     //on fait  les affectation

                                     Aff_Adr2(o,NULL);
                                     Aff_Mat2(o,matri);
                                     Aff_pos2(o,e);
                                     Aff_bloc2(o,nblc);
                                     Aff_date_recru(o,date_recrutem);
                                     //on pointe le champ tete sur le maillon allouer qui va contenir les information du matricule qui exerce cette specialite

                                       ti_etb[mm].tete2=o;
                                       //on incremente la taille de la tale d'index
                                        *taille_tetab=*taille_tetab+1;

   }
}


 }

  void rech_spe (char cle[50] , int *b,int *mm)/**rechere un specialty donnée*/
 {
     idex_spe t[MAX1];/**on charge la teble d'index des specialtes*/
       char ligne[100];
       char  m1[50];
       int m2;
       int m3;
       int m4;
       int y=1;
       int d;
       int i=0;
       maillon_mat *q;
       maillon_mat *r;
       maillon_mat *v;
       FILE *p=fopen("Tindex_spec.txt","r");
       if ( p != NULL)
       {
           fscanf(p,"%d/%d/%d/%s",&m4,&m2,&m3,&m1);
            v = Allouer();
            Aff_bloc(v,m4 );
            Aff_Mat(v,m2);
            Aff_pos(v,m3);
            Aff_Adr(v,NULL);
            (t[0]).tete = v;
            strcpy(((t[0]).spec) ,m1);
            r=(t[0]).tete;
            nb_ligne("Tindex_spec.txt",&d);
         while ( y<d ) /**au nb des enregistr**/
            {
               fscanf(p,"%d/%d/%d/%s",&m4,&m2,&m3,&m1);
               if (strcmp(m1,(t[i]).spec)==0)
               {

                  q = Allouer();
                   Aff_Adr(r,q);
                   Aff_Adr(q,NULL);
                    Aff_bloc(q,m4 );
                    Aff_Mat(q,m2);
                    Aff_pos(q,m3);
                    r =q;
               }
               else
               {
                    i++;
                   strcpy((t[i]).spec ,m1) ;
            v = Allouer();
            Aff_bloc(v,m4 );
            Aff_Mat(v,m2);
            Aff_pos(v,m3);
            Aff_Adr(v,NULL);
            (t[i]).tete = v;
            ///strcpy(((t[i]).spec) ,m1);
            r=(t[i]).tete;
               }

               y++;

            }

       }
       else
       {
           printf("le fichier n'existe pas !!!\n ");
       }
       /***********************rech*********************************/
     int a,e;
     a=0;
     ///void rech_spe (char cle[50] , int *b,int *ii,int *j,int *mm)
     while(a<=i)
     {

          if (strcmp(cle,(t[a]).spec)==0)
          {
              *b = 1;
              *mm =a;/**son emplacement dans la table d'index*/
          }
         a++;
     }
     if (*b != 1)
     {

         printf("cette speciality n'exsite pas \n");
     }
 }
 void supp_spe(char cle [50],int ss )/**suppretion par speciality*/
 {
        idex_spe t[30];
       char  m1[50];
       int m2;
       int m3;
       int m4;
       int y=1;
       int d;
       int i=0;
       maillon_mat *q;
       maillon_mat *r;
       maillon_mat *v;
       FILE *p=fopen("Tindex_spec.txt","r");
       if ( p != NULL)
       {
           fscanf(p,"%d/%d/%d/%s",&m4,&m2,&m3,&m1);
            v = Allouer();
            Aff_bloc(v,m4 );
            Aff_Mat(v,m2);
            Aff_pos(v,m3);
            Aff_Adr(v,NULL);
            (t[0]).tete = v;
            strcpy(((t[0]).spec) ,m1);
            r=(t[0]).tete;
            nb_ligne("Tindex_spec.txt",&d);
         while ( y<d ) /**au nb des enregistr**/
            {
               fscanf(p,"%d/%d/%d/%s",&m4,&m2,&m3,&m1);
               if (strcmp(m1,(t[i]).spec)==0)
               {
                  q = Allouer();
                   Aff_Adr(r,q);
                   Aff_Adr(q,NULL);
                    Aff_bloc(q,m4 );
                    Aff_Mat(q,m2);
                    Aff_pos(q,m3);
                    r =q;
               }
               else
               {
                    i++;
                   strcpy((t[i]).spec ,m1) ;
            v = Allouer();
            Aff_bloc(v,m4 );
            Aff_Mat(v,m2);
            Aff_pos(v,m3);
            Aff_Adr(v,NULL);
            (t[i]).tete = v;
            ///strcpy(((t[i]).spec) ,m1);
            r=(t[i]).tete;
               }

               y++;

            }

       }
       else
       {
           printf("le fichier n'existe pas !!!\n ");
       }


       /*************************************************************/
   Tbloc buffer;/**la suppresion dans le fichier*/
    maillon_mat *z,*u,*k;
    int qq,g,s,h,cpt,h1;
    cpt=0;
    int numee;
    z=t[ss].tete;
    u=t[ss].tete;;
      ouvrir(&f,"ENSEIGAT_MERS.bin",'A');
      h1=entete(f,3);
        h=entete(f,3);
    while (z!= NULL)
    {
        cpt++;
        qq =  z->matricule;
        numee = z->bloc;
        g=z->pos;
        lireDir(f,numee,&buffer);
        s = buffer.Nb ;/** on ecrese par le dirnier enrigistrelent*/
         buffer.T[g].Matricule =  buffer.T[s].Matricule ;
        strcpy( buffer.T[g].Date_Naissance ,buffer.T[s].Date_Naissance);
       strcpy(buffer.T[g].Wilaya_Naissance , buffer.T[s].Wilaya_Naissance);
         strcpy (buffer.T[g].Sexe , buffer.T[s].Sexe);
        strcpy (buffer.T[g].Groupe_sanguin ,buffer.T[s].Groupe_sanguin );
        strcpy (buffer.T[g].Date_Recrutemet ,   buffer.T[s].Date_Recrutemet);
        strcpy (buffer.T[g].Grade ,buffer.T[s].Grade) ;
        strcpy (buffer.T[g].Specialite ,buffer.T[s].Specialite );
        strcpy (buffer.T[g].Derier_Diplome ,  buffer.T[s].Derier_Diplome);
         strcpy(buffer.T[g].Etablissemet_Univ ,buffer.T[s].Etablissemet_Univ);
           buffer.Nb = (buffer.Nb )-1;
           ecrireDir(f,numee,&buffer);
           z= Suivant(z);
    }
     aff_entete(f,3,(entete(f,3))-cpt );

       /// t[ss].tete=z;
       int is;
       is =ss;
        ///liberer(t[ss].tete);
        while (ss<i)/**la suppresion de la table d'index des speciality*/
        {
            strcpy(t[ss].spec,t[ss+1].spec);
            t[ss].tete= t[ss+1].tete;
            liberer(t[ss+1].tete);
            ss++;
        }
        maillon_mat *n;
        n=t[is].tete;
        while (n!=NULL)
        {
            n->pos=buffer.Nb;
            buffer.Nb--;
            n=Suivant(n);
         }

        FILE *fi;
        is=0;
        int val1,val2,val3;
        char val4[50];

        fi =fopen("Tindex_spec.txt","w+");/**on enregistre les modifications  dans le fichier*/
    while(is<i)
        {
            k= t[is].tete;
            while (k!=NULL)
            {
                strcpy(val4,t[is].spec);
                val1=k->bloc;
                val3=k->matricule;
                val2=k->pos;
                fprintf(fi,"%d/%d/%d/%s\n",val1,val3,val2,val4);

                k=Suivant(k);

            }
            is++;
        }
     fclose(fi);
     z=t[ss].tete;
     while (u!= NULL)
     {
         qq=u->matricule;
tableindex1 tt;/**la suppresion de la table d'index des matrucule*/
chrge_tab_index1(&tt);
Tbloc bufferr;
int pp;
int bi,bs,m;
int x;
int jjp;
int ij;
x=0;
bi=0;
bs=h1;
    while ((!x)  && (bs>=bi))
    {
        m=(bs+bi)/2;
        x=((tt.T[m].cle) == qq);
        if (tt.T[m].cle > qq)
            {bs=m-1;
            }
        else
            {
                bi=m+1;
            }
    }

    if ((tt.T[m].cle )!= qq)
    {
        x=-1;
        (jjp)=tt.T[m].pos;
        (ij)=tt.T[m].bloc;
    }
    else
    {
            x=1;
            ij=tt.T[m].bloc;
            jjp=tt.T[m].pos;
            pp=m;
    }
     if (x == -1)
     {
         printf("n'exsite pas \n");
     }
     else///existe
     {
     int hf,sd;
     int ps,ne;

     hf=entete(f,3);
     sd=m;
     while(sd<h1+1)
     {
         tt.T[sd].bloc = tt.T[sd+1].bloc;
         tt.T[sd].cle = tt.T[sd+1].cle ;
         tt.T[sd].efface =tt.T[sd+1].efface ;
         tt.T[sd].pos = tt.T[sd+1].pos ;
          sd++;
     }

     hf=entete(f,3);
     sd=0;
    int mal1=0;
    int mal2=0;
    int mal3=0;
    int mal4=0;
    FILE *fi1;
    fi1=fopen("Tindex_matricule.txt","w+");
    while(sd<h1)
        {
            mal1=tt.T[sd].cle;
            mal3=tt.T[sd].pos;
            mal2=tt.T[sd].bloc;
            mal4=tt.T[sd].efface;
            fprintf(fi1,"%d_%d_%d_%d\n",mal1,mal2,mal3,mal4);
            sd++;
    }
    aff_entete(f,3,entete(f,3)-1);
    aff_entete(f,4,entete(f,4)+1);
    h1 = h1-1;
     fclose(fi1);
     u=Suivant(u);
     }
     }
    liberer(z);
    liberer(u);
    fermer(f);
 }
   void chrge_tab_index3 ( char cle[200], int bi, int bs)/**afiche tous les enseignants exerçant dans un établissement'cle'*/
   /**  bi le valeur inf et bs la valeur sup*/
 {
       idex_etab t[1000];/**on charge la table des etabliseemnt*/
        int cpt=0;
       char  m1[200];
       char m5[50];
       int m2;
       int m3;
       int m4;
       int y=1;
       int d;
       int i=0;
       maillon_eseg *q;
       maillon_eseg *r;
       maillon_eseg *v,*l;
       FILE *p=fopen("Tindex_etab.txt","r");
       if ( p != NULL)
       {
           fscanf(p,"%s",&m1);
           fscanf(p,"%d##%d##%d##%s",&m2,&m3,&m4,&m5);/**on cree la table*/
            v = Allouer2();
            Aff_date_recru(v,m5);
            Aff_bloc2(v,m4 );
            Aff_Mat2(v,m2);
            Aff_pos2(v,m3);
            Aff_Adr2(v,NULL);
            (t[0]).tete2= v;
            strcpy(((t[0]).etablissement) ,m1);
            r=(t[0]).tete2;
            nb_ligne("Tindex_etab.txt",&d);
            d= d/2;
            while ( y<d ) /**au nb des enregistr**/
            {
                  fscanf(p,"%s",&m1);
           fscanf(p,"%d##%d##%d##%s",&m2,&m3,&m4,&m5);
               if (strcmp(m1,(t[i]).etablissement)==0)
               {

                  q = Allouer2();
                   Aff_Adr2(r,q);
                   Aff_Adr2(q,NULL);
                    Aff_bloc2(q,m4 );
                    Aff_Mat2(q,m2);
                    Aff_pos2(q,m3);
                    Aff_date_recru(q,m5);
                    r =q;
               }
               else
               {
                    i++;
                   strcpy((t[i]).etablissement ,m1) ;
            v = Allouer2();
            Aff_bloc2(v,m4 );
            Aff_Mat2(v,m2);
            Aff_pos2(v,m3);
            Aff_date_recru(v,m5);
            Aff_Adr2(v,NULL);
            (t[i]).tete2 = v;
            ///strcpy(((t[i]).spec) ,m1);
            r=(t[i]).tete2;
               }
               y++;

            }
       }
       else
       {
           printf("le fichier n'existe pas !!!\n ");
       }
       fclose(p);
     int a=0;
       int b,mm;
        while(a<=i)
     {
          if (strcmp(cle,(t[a]).etablissement)==0)
          {
              b = 1;
              mm = a;

          }
         a++;
     }
     if (b != 1)
     {
         printf("cette speciality n'exsite pas \n");
     }
     else
     {
         int tmp;
         char da[50];
         l=t[mm].tete2;
            Tbloc buffer;
            ouvrir(&f,"ENSEIGAT_MERS.bin",'A');
         while (l!=NULL)
         {
              int a1,a2,a3,a4,d,in,kl,hh,nu,j;
              in=0;
            char *q,*w,*x,*g;
             strcpy(da,l->date_rec);

            while (da[in]!= '/')
            {
                in++;
            }
            in++;
            while (da[in]!= '/')
            {
                in++;
            }

            g=da[in+1]; /**on prend la date de recrutment*/
            q=da[in+2];
            w=da[in+3];
            x=da[in+4];
            a1= atoi (&g);/**vue qu'elle est de type char on doit la convertire à int*/
            a2= atoi (&q);
            a3= atoi (&w);
            a4= atoi (&x);
            kl=(a1*1000)+(a2*100)+(a3*10)+a4;/**le resultat de la convertion*/
            int annee=2018;
            hh= 2018-kl;
            if (hh>bi)/**on compare a la valeur inf*/
            {

                if (hh<bs)/**on compare a la valeur sup*/
                {
                    nu = l->bloc;
                    j= l->pos;/**on affiche le resultat*/
                    lireDir(f,nu,&buffer);
                    printf("\n****************  voici votre enreg **********************\n");
                    printf(" le matricule %d\n", buffer.T[j].Matricule);
                    printf("la Date_Naissance %s\n", buffer.T[j].Date_Naissance);
                    printf("Wilaya_Naissance %s\n", buffer.T[j].Wilaya_Naissance);
                    printf("  Sexe %s\n", buffer.T[j].Sexe);
                    printf("Groupe_sanguin %s\n", buffer.T[j].Groupe_sanguin);
                    printf("  Date_Recrutemet %s\n", buffer.T[j].Date_Recrutemet);
                    printf("  Grade %s\n", buffer.T[j].Grade);
                    printf("  Specialite %s\n", buffer.T[j].Specialite);
                    printf("  Derier_Diplome %s\n", buffer.T[j].Derier_Diplome);
                    printf("  Etablissemet_Univ %s\n", buffer.T[j].Etablissemet_Univ);
                    cpt++;

                }

            }

             l=Suivant2(l);/**on compare toute la liste*/
         }
         fermer(f);
     }

 }
 void rech_region (char cle[50])/** on afiche tous les enrgitrement dans une region donnée ''cle''*/
 {
     int mm;
     int b;
      tind3_R t[4];/**la table d'index des region*/
       char ligne[100];
       char  m1[50];
       int m2;
       int m3;
       int m4;
       int y=1;
       int d;
       int i=0;
       maillon_mat *q,*l;
       maillon_mat *r;
       maillon_mat *v;
       FILE *p=fopen("Tindex_region.txt","r");/**on chrage la table d'index*/
       if ( p != NULL)
       {
           fscanf(p,"%d/%d/%d/%s",&m4,&m2,&m3,&m1);
            v = Allouer();
            Aff_bloc(v,m4 );
            Aff_Mat(v,m2);
            Aff_pos(v,m3);
            Aff_Adr(v,NULL);
            (t[0]).tete1 = v;
            strcpy(((t[0]).region) ,m1);
            r=(t[0]).tete1;
            nb_ligne("Tindex_region.txt",&d);/**on cree la table*/
            while ( y<d ) /**au nb des enregistr**/
            {
               fscanf(p,"%d/%d/%d/%s",&m4,&m2,&m3,&m1);
               if (strcmp(m1,(t[i]).region)==0)
               {

                  q = Allouer();
                   Aff_Adr(r,q);
                   Aff_Adr(q,NULL);
                    Aff_bloc(q,m4 );
                    Aff_Mat(q,m2);
                    Aff_pos(q,m3);
                    r =q;
               }
               else
               {
                    i++;
                   strcpy((t[i]).region ,m1) ;

            v = Allouer();
            Aff_bloc(v,m4 );
            Aff_Mat(v,m2);
            Aff_pos(v,m3);
            Aff_Adr(v,NULL);
            (t[i]).tete1 = v;
            ///strcpy(((t[i]).spec) ,m1);
            r=(t[i]).tete1;
               }

               y++;

            }

       }
       else
       {
           printf("le fichier n'existe pas !!!\n ");
       }
       fclose(p);
       /***********************rech*********************************/
     int e,a,j;
     a=0;
     while(a<=i)
     {

          if (strcmp(cle,(t[a]).region)==0)
          {
              b = 1;
              mm =a;
          }
         a++;
     }
     if (b != 1)
     {

         printf("cette region n'exsite pas \n");
     }
     else
     {
          Tbloc buffer;
        ouvrir(&f,"ENSEIGAT_MERS.bin",'A');
         l= t[mm].tete1;
         while (l!= NULL)
         {
             i = l->bloc;
             j= l->pos;
         lireDir(f,i,&buffer);/**on affiche les resultats*/
        printf("\n****************  voici votre enreg **********************\n"); /** enrg exsite et on a sa pos on doit l'afficher **/
        printf(" le matricule %d\n", buffer.T[j].Matricule);
        printf("la Date_Naissance %s\n", buffer.T[j].Date_Naissance);
        printf("Wilaya_Naissance %s\n", buffer.T[j].Wilaya_Naissance);
        printf("  Sexe %s\n", buffer.T[j].Sexe);
        printf("Groupe_sanguin %s\n", buffer.T[j].Groupe_sanguin);
        printf("  Date_Recrutemet %s\n", buffer.T[j].Date_Recrutemet);
        printf("  Grade %s\n", buffer.T[j].Grade);
        printf("  Specialite %s\n", buffer.T[j].Specialite);
        printf("  Derier_Diplome %s\n", buffer.T[j].Derier_Diplome);
        printf("  Etablissemet_Univ %s\n", buffer.T[j].Etablissemet_Univ);
        l=Suivant(l);
         }

     }
      fermer(f);


     free(&t);

 }
 void insert_new(int mat,int *i,int *j,int nb)
 {
     /***insertion dans la table d'index des matricules**/
     /**on de la rech la pos ou il doit etre**/
     /**table index par des décalage **/
     ///le fichier on voit si le bloc est comlet ou pas
     tableindex1 t;
     chrge_tab_index1(&t);
     Tbloc buffer;
     int h,s,p;
     char n[20];
     ouvrir(&f,"ENSEIGAT_MERS.bin",'A');
     aff_entete(f,3,entete(f,3)+1);
     h=entete(f,3);
     s=*i;
     lireDir(f,s,&buffer);
     printf("entrer les informations du nouveau enseignant\n");
     if (*j<=(buffer.Nb))/**si le bloc n'est pas plien*/
     {
         printf("entrer les informations du nouveau enseignant\n");
         buffer.T[*j].Matricule=mat;/**les affectation*/
         printf("\n----- le nom");
         scanf("%s",n);
         strcpy(buffer.T[*j].Nom,n);
         printf("\n----- le prenom");
         scanf("%s",n);
         strcpy(buffer.T[*j].PreNom,n);
         printf("\n----- la date de naissance ");
         scanf("%s",n);
         strcpy(buffer.T[*j].Date_Naissance,n);
         printf("\n----- la wilaya de naissance ");
         scanf("%s",n);
         strcpy(buffer.T[*j].Wilaya_Naissance,n);
         printf("\n----- le sexe");
         scanf("%s",n);
         strcpy(buffer.T[*j].Sexe,n);
         printf("\n----- le groupe sanguin ");
         scanf("%s",n);
         strcpy(buffer.T[*j].Groupe_sanguin,n);
         printf("\n----- la date de recrutmenet "); /**le jour meme ++ la date du systeme**/
         scanf("%s",n);
         strcpy(buffer.T[*j].Date_Recrutemet,n);
         printf("\n----- le grade"); /**a revoir avec les choix */
         scanf("%s",n);
         strcpy(buffer.T[*j].Grade,n);
         printf("\n----- la spéciality ");
         scanf("%s",n);
         strcpy(buffer.T[*j].Specialite,n);
         printf("\n----- le derbier diplome");
         scanf("%s",n);
         strcpy(buffer.T[*j].Derier_Diplome,n);
         printf("\n----- l'etablissement ");
         scanf("%s",n);
         strcpy(buffer.T[*j].Etablissemet_Univ,n);
         /************matrucule!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!**/
         buffer.Nb = (buffer.Nb) + 1 ;
         ecrireDir(f,s,&buffer); /** l'enregistrement dans le fichier*/
         aff_entete(f,3,(entete(f,3))+1 );/**nb d'enre**/
         /**pos dans la table */
         p=nb;
         while (nb < entete(f,3))
         {
             t.T[h+1].cle = t.T[h].cle ;
             t.T[h+1].efface = t.T[h].efface;
             t.T[h+1].bloc = t.T[h].bloc ;
             t.T[h+1].pos = t.T[h].pos ;
             nb++;
         }
         t.T[p].cle = mat;
         t.T[p].efface = 0;
         t.T[p].bloc = s;
         t.T[p].pos = (*j);
          h=entete(f,3);
          s=0;
          int val1=0;
          int val2=0;
          int val3=0;
          int val4=0;
          FILE *fi1;
          fi1=fopen("Tindex_matricule.txt","w+");
          while(s<h)
                {
                    val1=t.T[s].cle;
                    val3=t.T[s].pos;
                    val2=t.T[s].bloc;
                    val4=t.T[s].efface;
                    fprintf(fi1,"%d_%d_%d_%d\n",val1,val2,val3,val4);
                    s++;
            }
             fclose(fi1);/*************************ok****************/
     }
     else /**cree new block */
     {
         buffer.T[*j].Matricule=mat;
         s=alloc_bloc(f);
         printf("entrer les information du nouveau enseignant\n");
         printf("\n----- le nom");
         scanf("%s",n);
         strcpy(buffer.T[*j].Nom,n);
         printf("\n----- le prenom");
         scanf("%s",n);
         strcpy(buffer.T[*j].PreNom,n);
         printf("\n----- la date de naissance ");
         scanf("%s",n);
         strcpy(buffer.T[*j].Date_Naissance,n);
         printf("\n----- la wilaya de naissance ");
         scanf("%s",n);
         strcpy(buffer.T[*j].Wilaya_Naissance,n);
         printf("\n----- le sexe");
         scanf("%s",n);
         strcpy(buffer.T[*j].Sexe,n);
         printf("\n----- le groupe sanguin ");
         scanf("%s",n);
         strcpy(buffer.T[*j].Groupe_sanguin,n);
         printf("\n----- la date de recrutmenet "); /**le jour meme ++ la date du systeme**/
         scanf("%s",n);
         strcpy(buffer.T[*j].Date_Recrutemet,n);
         printf("\n----- le grade"); /**a revoir avec les choix */
         scanf("%s",n);
         strcpy(buffer.T[*j].Grade,n);
         printf("\n----- la spéciality ");
         scanf("%s",n);
         strcpy(buffer.T[*j].Specialite,n);
         printf("\n----- le derbier diplome");
         scanf("%s",n);
         strcpy(buffer.T[*j].Derier_Diplome,n);
         printf("\n----- l'etablissement ");
         scanf("%s",n);
         strcpy(buffer.T[*j].Etablissemet_Univ,n);
         /************matrucule!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!**/
         buffer.Nb = (buffer.Nb) + 1 ;
         ecrireDir(f,s,&buffer);
         aff_entete(f,3,(entete(f,3))+1 );/**nb d'enre**/
         while (nb < entete(f,3))
         {
             t.T[h+1].cle = t.T[h].cle ;
             t.T[h+1].efface = t.T[h].efface;
             t.T[h+1].bloc = t.T[h].bloc ;
             t.T[h+1].pos = t.T[h].pos ;
             nb++;

         }
         t.T[p].cle = mat;
         t.T[p].efface = 0;
         t.T[p].bloc = s;
         t.T[p].pos = (*j);
          h=entete(f,3);
          s=0;
          int val1=0;
          int val2=0;
          int val3=0;
          int val4=0;
          FILE *fi1;
          fi1=fopen("Tindex_matricule.txt","w+");/**enregistrer les modification dans la table d'index*/
          while(s<=h)
                {
                    val1=t.T[s].cle;
                    val3=t.T[s].pos;
                    val2=t.T[s].bloc;
                    val4=t.T[s].efface;
                    fprintf(fi1,"%d_%d_%d_%d\n",val1,val2,val3,val4);
                    s++;
            }
             fclose(fi1);/*************************ok****************/
     }

     fermer(f);
      }

       void rech12(int a , int *bbb,int *ii,int *jj,int *mm)/**rechere du matricule sans affichage**/
 {
     int num;
int pos;
int b;
tableindex1 t;
chrge_tab_index1(&t);
Tbloc buffer;
int p;
int bi,bs,m;
ouvrir(&f,"ENSEIGAT_MERS.bin",'A');

int x;/**notre bool*/

int j; /**pos*/
int i;/**bloc*/

x=0;

bi=0;

bs = entete(f,3);

    while ((!x)  && (bs>=bi))
    {
        m=(bs+bi)/2;
        x=((t.T[m].cle) == a);
        if (t.T[m].cle > a)
            {bs=m-1;
            }
        else
            {

                bi=m+1;}
    }


    if ((t.T[m].cle )!= a)
    {
        x=-1;
        *bbb=x;
        (j)=t.T[m].pos;
     *jj=j;
        (i)=t.T[m].bloc;
         *ii=i;
         *mm=m;

    }
    else
    {
            x=1;
            *bbb=x;
            i=t.T[m].bloc;
            *ii=i;
            j=t.T[m].pos;
            *jj=j;
            *mm=m;
    }
fermer(f);
 }

int main()
{
    int choix=0;

    printf("---------------------TP01_Structures simples de fichiers_Methode :  TObareF   ------------------------------------------\n");
    printf("1-Chargement Initiale \n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("2-Ajout d'un nouvel enseignant au fichier \n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("3- Modification de l’etablissement universitaire d’un enseignant en raison de sa mutation \n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("4-Supprimer un enregistrement donne par le matricule\n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("5-Supprimer tous les enregistrements relatifs a une specialite donnee\n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("6-Afficher tous les enseignants exercant dans un etablissement donne ayant une anciennete entre deux valeurs donnees\n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("7-Consulter tous les enseignants exercant dans une region donnee (Centre ,Est et Ouest) \n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("8- Afficher sur votre ecran l’en-tete du fichier\n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("9-Affichage du cotenue du fichier  \n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("10- Fin du programme\n");
     printf("-----------------------------------------------------------------------------------------------------------------------\n");
while(choix!=10){
     printf("veuillez entrer le numero de votre choix svp *_* :  ");
     scanf("%d",&choix);

    switch (choix){
   case 1 :
       printf("----------------------------Chargement Initiale-----------------------\n");
       printf("veuillez entrz le numero d'enregistremet que vous voulez inserez");
       int n;
       scanf("%d",&n);
       Charger(n);
       printf("---------------------------------------------------------------------------------------------------------------------\n");

       break;
   case 2 :
     printf("------------------------Ajout d’un nouvel enseignant au fichier-----------------------------------\n");
     printf("\n on chereche un matricule\n  ");
     int a1,num,pos,in;
     int b=1;

     while (b==1)
    {
         a1=111111+rand()%999999;/**on cherche un matricule non exsitant*/
         rech12(a1,&b,&num,&pos,&in);
     }
     printf("\n le matricule est %d--->",a1);
    insert_new(a1,&num,&pos,in);

    printf("----------------------------------------------------------------------------------------------------------\n");

     break;
   case 3:
    printf("-------------------Modification de l’etablissement universitaire d’un enseignant en raison de sa mutation----------------------\n ");
    printf("veuillez entrez le matricule de l'enregistrement a modifier  \n");
    a1=0;b=0;num=0;pos=0;in=0;
    scanf("%d",&a1);
    rech(a1,&b,&num,&pos,&in);
    if (b ==-1)
    {
      printf("\n le matricule n'existe pas !!! \n");
    }
    else
    {
         modifier_etab(a1,b,num,pos);
    }

    printf("-----------------------------------------------------------------------------------------------------------------------\n");

     break;
   case 4:
    printf("--------------------------Supprimer un enregistrement donne par le matricule--------------------------------\n");
    printf("veuillez entrez le matricule de l'enregistrement a Supprimer \n");
    a1=0;b=0;num=0;pos=0;in=0;
    scanf("%d",&a1);
    rech(a1,&b,&num,&pos,&in);
    if (b ==-1)
    {
      printf("\n le matricule n'existe pas !!! \n");
    }
    else
    {
        supp_mat(a1,num,in,pos);
      //  int ret;
   // ret=entete(f,4);
   //  aff_entete(f,4,ret+1);
    }
    printf("votre enregistrement a ete suprimmer\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");

    break;
   case 5:
    printf("---------------------------Supprimer tous les enregistrements relatifs a une specialite donnee-----------------------");
    printf("veuillez entrez la spécialité a Supprimer \n");
    char sp[50];
    a1=0;b=0;num=0;pos=0;in=0;
    scanf("%s",sp);
    rech_spe(sp,&b,&in);
    if (b==1)
        {
            supp_spe(sp,in);
            printf("\n votre specialite a ete suprimmer\n");
        }
    else
    {
        printf("\n specialite n'existe pas !!! \n");
    }

    printf("--------------------------------------------------------------------------------------------------------------------\n");

    break;
    case 6:
    printf("--------Afficher tous les enseignants exerçant dans un etablissement donne ayant une anciennete entre deux valeurs donnees -----------------------");
    printf("veuillez entrez l' établissement \n");
    a1=0;b=0;num=0;pos=0;in=0;
    scanf("%s",sp);
    printf(" veuillez entrez la premiere borne \n");
    scanf("%d",&pos);
    printf(" veuillez entrez la premiere borne \n");
    scanf("%d",&num);
    chrge_tab_index3 (sp,pos,num);
    printf("\n c'est fini \n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    break;
     case 7:
    printf("----------------------Consulter tous les enseignants exerçant dans une region donnée (Ouest, Centre et Est)-----------------------");
    printf("veuillez entrez la region  \n");
    scanf("%s",sp);
    rech_region (sp);
    printf("\n c'est fini \n");
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
     break;
     case 8:
    printf("---------------------------Afficher sur votre ecran l’en-tete du fichier -----------------------");
      ouvrir(&f,"ENSEIGAT_MERS.bin",'A');
     Affichage_Entete(f);
    printf("--------------------------------------------------------------------------------------------------\n");

    break;

     case 9:
    printf("---------------------------Affichage du cotenue du fichier-----------------------");
    printf("votre fichier contients : ");
    Afficher();
    printf("---------------------------------------------------------------------------------------------------------------------\n");

    break;
    case 10:
    printf("---------------------------Fin du programme-----------------------");
    printf("Et voila la fin du votre programme ");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    break;
     default :
     printf("------------------------------------------------------------------------\n");

    break;

     }
}

}



