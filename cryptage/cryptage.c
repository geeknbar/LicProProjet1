#include <stdlib.h>
#include <string.h>
#include <stdio.h>




//en-tête de la fonction de chiffrement
void chiffrement(char *, char *, unsigned int *,unsigned int) ;
int ponctuation (char c);


//fonction de chiffrement ( pointeur ,poiteur , pointeur, taille de la clef)

void chiffrement(char *entree, char *sortie,unsigned int *clef,unsigned int n)
{
  //pointeur sur les fichiers d'entree et de sortie
  FILE *f_in, *f_out ;
  
  /*
   * c code ASCII du caractère de lecture du fichier source
   * chiffre code ASCII du caractère de lecture du fichier de sortie
   * 
   */
  int c;
  int chiffre=0 ;
  
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
      
      if (ponctuation(c)==1){
	chiffre=32;
	
      }else{
	chiffre = (((c-97) + clef[i%n]) % 26) + 97 ;
	i++ ;
      }
      
      fprintf(f_out,"%c",chiffre) ;
      
       
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
  if ((c>=32 && c<=64)||(c>=91 && c<=96)||(c>=123 && c<=126)){
    return 1;
  }else{
    return 0;
  }
}




int main(int argc, char *argv[0])
{
 
  int i,c;
  unsigned int longueur_clef;
 
  unsigned int *clef ;
  //tester le nombre d'arguments, exit si nombre incorrect 
   if (argc != 3)
    {
      fprintf(stderr, "\nErreur : nombre d’arguments invalide\n") ;
      fprintf(stderr, "Syntaxe : %s fichier_entree fichier_sortie\n", argv[0]) ;
      return(EXIT_FAILURE) ;
    }
   
  printf("\n Entrez la longueur de la clef sans espace (exemple : texte sans espace = 15 )\t") ;
  scanf("%u", &longueur_clef) ;
  clef = malloc(longueur_clef * sizeof(unsigned int)) ;
  
  
  printf("Entrez la clef sous forme d’un mot sans espace de %d (exemple : textesansespace) : ",longueur_clef) ;
  
  //lire une foi le caractère pour lire entrée. 
  c = getchar() ;
  
  for (i=0 ; i< longueur_clef ; i++){
      c = getchar() ;

      
       if(c==32){
	printf("erreur d'espace");
	return(EXIT_FAILURE) ;
      }else{
    
	clef[i] = c - 97 ;
      }
      
    
  }
  
  
  
  
  chiffrement(argv[1], argv[2], clef, longueur_clef) ;
}