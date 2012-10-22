#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//en-tête de la fonction de chiffrement
void chiffrement(char *, char *, unsigned int *, unsigned int) ;


//fonction de chiffrement ( pointeur ,poiteur , pointeur, taille de la clef)

void chiffrement(char *entree, char *sortie, unsigned int *clef, unsigned int n)
{
  //pointeur sur les fichiers d'entree et de sortie
  FILE *f_in, *f_out ;
  
  /*
   * c code ASCII du caractère de lecture du fichier source
   * chiffre code ASCII du caractère de lecture du fichier de sortie
   * 
   */
  int c, chiffre ;
  
  //incrémente la clef pour passer au caractère suivant
  unsigned int i = 0 ;
  
  //ouverture du fichier source
  if ((f_in = fopen(entree, "r")) == NULL)
    {
      fprintf(stderr,"Erreur ds l’ouverture du fichier %s\n", entree) ;
      return ;
    }
    
  //ouverture du fichier de sortie
  if ((f_out = fopen(sortie, "w")) == NULL)
    {
      fprintf(stderr,"Erreur ds l’ouverture du fichier %s\n", sortie) ;
      return ;
    }
    
  //boucle sur le caractère du fichier source jusqu'à la fin de fichier 
  while ((c = fgetc(f_in)) != EOF)
    {
      
      if (Anthony){
	
	
      }else if (ponctuation(c)==0){
	chiffre ==32;
	
      }else{
	chiffre = (((c-97) + clef[i%n]) % 26) + 97 ;
      }
      
      fprintf(f_out,"%c",chiffre) ;
      i++ ;
       
    }
    
  //fermeture des fichiers source et sortie  
  fclose(f_in) ;
  fclose(f_out) ;
  return ;
}
  
/*
 *fonction qui retourne 1 si le caractère est une ponctuation, 0 si il ne l'est pas 
 *
 */  
int ponctuation (char c){
  if ((c>=33 && c<=64)||(c>=91 && c<=96)||(c>=123 && c<=126)){
    return 1;
  }else{
    return 0;
  }
}

void suppr_espace(char * mot ){
  
  
  
}

int main(int argc, char *argv[0])
{
 
  //chaine de caractère de la clef
  char mot[20];
  //longeur de la clef
  int longeur_clef;
  //tester le nombre d'arguments, exit si nombre incorrect 
   if (argc != 3)
    {
      fprintf(stderr, "\nErreur : nombre d’arguments invalide\n") ;
      fprintf(stderr, "Syntaxe : %s fichier_entree fichier_sortie\n", argv[0]) ;
      return(EXIT_FAILURE) ;
    }
    
  printf("Entrez la clef sous forme d’un mot : \n") ;
  scanf("%s",&mot);
  
  longeur_clef=strlen(mot);
  
  chiffrement(argv[1], argv[2], *mot, longeur_clef) ;
}