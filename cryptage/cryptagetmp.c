#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define VRAI 1
#define FAUX 0 


//en-tête de la fonction de chiffrement
void chiffrement(char *, char *, unsigned int *,unsigned int) ;
int ponctuation (char c);
int accent(int c);

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
  //variable de test sur les accents
  int booleen = FAUX; 
  
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
      
		if( (c<65) || (c>90) ){  //si la lettre n'est pas majuscule

		//printf("cinit= %d\n",c);
      if (c == 195){
	booleen = VRAI;

     }else{

		 if (booleen == VRAI){
		//printf("caccent= %d\n",c);
		c = accent(c);
		booleen = FAUX;
		chiffre = (((c-97) + clef[i%n]) % 25) + 65 ; 
		/*si la lettre est minuscule, 'c' est compris entre 0 et 25 
		 *et on lui ajoute la clé puis on ajoute 65 pour que le résultat soit compris entre 65 et 90 i.e codes ascii de A et Z*/
		i++ ;
	
		 }else if (ponctuation(c)==1){
		chiffre =32;
	
		 }else{
		chiffre = (((c-97) + clef[i%n]) % 25) + 65 ;
		i++ ;
		 }
		 
		 fprintf(f_out,"%c",chiffre) ;
    }
	} 
	else //si la lettre est majuscule
	{
		chiffre = (((c-65) + clef[i%n]) % 25) + 65 ;
		i++ ;
		fprintf(f_out,"%c",chiffre) ;
	}  
}
    
  //fermeture des fichiers source et sortie  
  fclose(f_in) ;
  fclose(f_out) ;
  return ;
}
  
/*
 *Fonction de test sur les accents
 */
int accent(int c)
{
		if( c == 169 || c == 168 || c == 170 ){
		c = 'e';

		 }else if( c == 160){
		c = 'a';


		 }else if( c == 185){
		c = 'u';
		
		 }else if( c == 167){
		c = 'c';
		}
//printf("c3= %d\n",c);

return c;		
}

/*
 *fonction qui retourne 1 si le caractère est une ponctuation, 0 si il ne l'est pas 
 *
 */  
int ponctuation (char c){
  if ((c>=0 && c<=64)||(c>=91 && c<=96)||(c>=123 && c<=126)){
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
	int booleen = FAUX;
  //tester le nombre d'arguments, exit si nombre incorrect 
   if (argc != 3)
    {
      fprintf(stderr, "\nErreur : nombre d’arguments invalide\n") ;
      fprintf(stderr, "Syntaxe : %s fichier_entree fichier_sortie\n", argv[0]) ;
      return(EXIT_FAILURE) ;
    }
   
  printf("\nEntrez la longueur de la clef sans espace (exemple : texte sans espace = 15 )\t") ;
  scanf("%u", &longueur_clef) ;
  clef = malloc(longueur_clef * sizeof(unsigned int)) ;
  
  
  printf("Entrez un mot clé ou une phrase clé de %d caractères (sans compter les espaces) : ",longueur_clef) ;
  
  //lire une foi le caractère pour lire entrée. 
  c = getchar() ;
  i=0;


  while(i< longueur_clef){
      c = getchar() ;

      if (c == 195){
				booleen = VRAI;

    	 }else{

		 if (booleen == VRAI){
			c = accent(c);
			booleen = FAUX;
			clef[i] = c - 97 ;
			i++ ;
		} else{
		
       if((c!=32) &&((c<65) || (c>90))){ //si 'c' n'est pas un espace et n'est pas une lettre majuscule
						clef[i] = c - 97 ; //affecte des résultats entre 0 et 25 sur les lettre minuscules
						i++;
			 	}
			else
				{
				clef[i] = c - 65 ; //affecte des résultats entre 0 et 25 sur les lettre majuscules
				i++;
				}
		}
	}

	}

  
  chiffrement(argv[1], argv[2], clef, longueur_clef) ;
	return 0;
}