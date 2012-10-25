#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#define N 26

#define CLEMAX 30

void initTab(int t[N])

{

   int i;

   for(i=0; i<N; i++)

       t[i]=0;

}

   

//renvoie le nombre de lettres totales dans le texte et compte le nombre de chaque lettres du texte

void nbLettres(char *entree, int t[N], int *tailleText, int tailleCle)

{

   FILE *f_in;

   unsigned int nbLettresTotal=0;

   int c;

   int i=0;

   //valeur pour sortir du while principal quand on atteint la fin de fichier

   int val=0;

   //valeur pour lire obligatoirement le premier caractere du fichier source et ne pas tout decaler

   int test=0;

   if ((f_in = fopen(entree, "r")) == NULL)

       {

     fprintf(stderr,"Erreur ds l’ouverture du fichier %s\n", entree);

     return;

       }

 while (val==0)

   {

    //lit obligatoirement le premier caractere, pour eviter davoir le texte decaler : a expliquer a Romain et Anthony

    if(test==0)

       {

     c = fgetc(f_in);

     test=1;

    }

       else

       {  

       for(i=0;i<tailleCle;i++) //boucle permettant d'avancer le caractere lu en fonction de la longeur de la clef testee

           {

               if(c==32)

               {

                   c = fgetc(f_in);

                   i--;

               }

               else

             c = fgetc(f_in);

         if(c== EOF)

                   val=1;

       }

       }

       

       if((c>=65) && (c<=90)) //si la lettre est majuscule

       {

           t[c-65]=t[c-65]+1; /*retire 65 a la lettre pour qu'elle corresponde a sa case das le tableau (0 pour A, 1 our B etc..) et ajoute                                                         *+1 a chaque fois que la lettre 'c' est rencontrée*/

           nbLettresTotal++;

       }

   }

   *tailleText=nbLettresTotal;

}

double indiceCoincidence(int t[N], int nblettres)

{

   int i;

   double indice=0;

   double indice2=0;

   for(i=0; i<N; i++)

   {

       indice=indice+(t[i]*(t[i]-1));

       indice=indice/(nblettres*(nblettres-1));

       indice2+=indice;

   }

   return indice2 ;

}


/*void longueurcle(char *entree)

{

   FILE *f_in;

   if ((f_in = fopen(entree, "r")) == NULL)

       {

     fprintf(stderr,"Erreur ds l’ouverture du fichier %s\n", entree);

     return;

       }

 while ((c = fgetc(f_in)) != EOF)

     {

   */

int main(int argc, char *argv[0])

{

   int t[N];

   int nblettre, i, j;

   double indice;

   nblettre=0;

   //boucle permettant de test chaque valeur de clef voulu, avec un CLEMAX defini

   for(j=1; j<CLEMAX; j++)

   {

       //obligation de reinitiliser les valeurs sinon on les rajoute au test precedent

       initTab(t);

       nblettre=0;

       indice=0;

       nbLettres(argv[1], t, &nblettre, j);

       for(i=0; i<N; i++)

           printf(" %d %c |", t[i],(65+i));

       printf("\n");    

       printf("longeur cle teste : %d",j);

       printf("\n");

       indice=indiceCoincidence(t, nblettre);

       printf("nombre de lettre total %d\n", nblettre);

       printf("indice de coincidence %f\n", indice);

       printf("\n");

       printf("**********************************************************************************");

       printf("\n");

   }

   

   return 0;
}