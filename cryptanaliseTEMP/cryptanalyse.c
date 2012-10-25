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
int nbLettres(char *entree, int t[N],int longueurcle)
{
	FILE *f_in;
	unsigned int nbLettresTotal=0;
	int c;
	int i=0;
	int val=0;
	int test=0;
	
	if ((f_in = fopen(entree, "r")) == NULL)
		{
      fprintf(stderr,"Erreur ds l’ouverture du fichier %s\n", entree);
      return;
		}

  while (val==0){
    
    if(test==0){
      c = fgetc(f_in);
      test=1;
    }else{
   
    for(i=0;i<longueurcle;i++){
      c = fgetc(f_in);
      if(c== EOF)
	val=1;
    }
    }
    /*
    while(i<7){
      c = fgetc(f_in);
      i++;
      if(c== EOF)
	val=1;
      //printf("%c", c);
      
      
    }*/
    
			switch (c) 
			{
				case 'A' : 
						t[0]=t[0]+1;
						nbLettresTotal++;
						break;
				case 'B' : 
						t[1]=t[1]+1;
						nbLettresTotal++;
						break;
				case 'C' : 
						t[2]=t[2]+1;
						nbLettresTotal++;
						break;
				case 'D' : 
						t[3]=t[3]+1;
						nbLettresTotal++;
						break;
				case 'E' : 
						t[4]=t[4]+1;
						nbLettresTotal++;
						break;
				case 'F' : 
						t[5]=t[5]+1;
						nbLettresTotal++;
						break;
				case 'G' : 
						t[6]=t[6]+1;
						nbLettresTotal++;
						break;
				case 'H' : 
						t[7]=t[7]+1;
						nbLettresTotal++;
						break;
				case 'I' : 
						t[8]=t[8]+1;
						nbLettresTotal++;
						break;
				case 'J' : 
						t[9]=t[9]+1;
						nbLettresTotal++;
						break;
				case 'K' : 
						t[10]=t[10]+1;
						nbLettresTotal++;
						break;
				case 'L' : 
						t[11]=t[11]+1;
						nbLettresTotal++;
						break;
				case 'M' : 
						t[12]=t[12]+1;
						nbLettresTotal++;
						break;
				case 'N' : 
						t[13]=t[13]+1;
						nbLettresTotal++;
						break;
				case 'O' : 
						t[14]=t[14]+1;
						nbLettresTotal++;
						break;
				case 'P' : 
						t[15]=t[15]+1;
						nbLettresTotal++;
						break;
				case 'Q' : 
						t[16]=t[16]+1;
						nbLettresTotal++;
						break;
				case 'R' : 
						t[17]=t[17]+1;
						nbLettresTotal++;
						break;
				case 'S' : 
						t[18]=t[18]+1;
						nbLettresTotal++;
						break;
				case 'T' : 
						t[19]=t[19]+1;
						nbLettresTotal++;
						break;
				case 'U' : 
						t[20]=t[20]+1;
						nbLettresTotal++;
						break;
				case 'V' : 
						t[21]=t[21]+1;
						nbLettresTotal++;
						break;
				case 'W' : 
						t[22]=t[22]+1;
						nbLettresTotal++;
						break;
				case 'X' : 
						t[23]=t[23]+1;
						nbLettresTotal++;
						break;
				case 'Y' : 
						t[24]=t[24]+1;
						nbLettresTotal++;
						break;
				case 'Z' : 
						t[25]=t[25]+1;
						nbLettresTotal++;
						break;
				default : break;
		}
		/*
		if(c!=EOF){
		  printf("%c", c);
		}
		*/
	}
		return nbLettresTotal ;
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
	int nblettre, i,j;
	double indice;


	for(j=1; j<CLEMAX; j++){
	  initTab(t);
	  nblettre=0;
	  indice=0;
	  nblettre=nbLettres(argv[1], t,j);
	

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
