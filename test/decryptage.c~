#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define VRAI 1
#define FAUX 0 

void dechiffrement(char *, char *, unsigned int *,unsigned int) ;
int accent(int c);


void dechiffrement(char *entree, char *sortie,unsigned int *clef,unsigned int n)
{
  FILE *f_in, *f_out ;
  int c;
  int chiffre=0 ;
  unsigned int i = 0 ;

  if ((f_in = fopen(entree, "r")) == NULL)
    {
      fprintf(stderr,"Erreur ds l’ouverture du fichier %s\n", entree) ;
      return ;
    }
    
  if ((f_out = fopen(sortie, "w")) == NULL)
    {
      fprintf(stderr,"Erreur ds l’ouverture du fichier %s\n", sortie) ;
      return ;
    }

	while ((c = fgetc(f_in)) != EOF)
    {
			if (c==32)
				chiffre=32;
	
		 	else
			{
					chiffre = ((((c-65) - clef[i%n])+26) % 26)+ 65 ;
					i++ ;
			}
		 
		 
		 	fprintf(f_out,"%c",chiffre) ;
		}


  fclose(f_in) ;
  fclose(f_out) ;
  return ;
}

int accent(int c)
{
		if( c == 169 || c == 168 || c == 170 )
			c = 'e';

		else 
			if( c == 160)
			c = 'a';
			else 
				if( c == 185)
					c = 'u';
		
		 		else 
					if( c == 167)
						c = 'c';
		
return c;		
}


int main(int argc, char *argv[0])
{
 
  int i,c;
  unsigned int longueur_clef;
  unsigned int *clef ;
	int booleen = FAUX;
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
  
  c = getchar() ;
  i=0;


  while(i< longueur_clef)
	{
      c = getchar() ;

      if (c == 195)
				booleen = VRAI;

			else
			 if (booleen == VRAI)
				{
					c = accent(c);
					booleen = FAUX;
					clef[i] = c - 97 ;
					i++ ;
				} 
				else
				{
					if((c!=32) &&((c<65) || (c>90)))
					{ 
						clef[i] = c - 97 ;
						i++;
				 	}
					else
					{
					clef[i] = c - 65 ; 
					i++;
					}
				}
	
	}

	
 	dechiffrement(argv[1], argv[2], clef, longueur_clef);

	return 0;
}
