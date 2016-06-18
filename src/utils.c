#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void affichechar(char * tab){
	printf("chaine %s\n",tab );
}
void string_to_int(char * tab, char * alphabet, int * itab){
	int i;
	affichechar(tab);
	for (i = 0; tab [i] !='\0' ; ++i)
	{
		
		itab[i]=alphatoint(tab[i],alphabet);
		printf("caract en cours de traitement%d\n",itab[i] );
	}
}

int alphatoint(char l,char * alphabet){
	int i;
	for (i = 0; alphabet [i] != '\0' ; ++i)
	{
		printf("carac %c recherche %c\n",l,alphabet[i] );
		if (l == alphabet[i])
		{
			return i;
		}
	}
	/*la lettre n'est pas dans l'alphabet*/
	return 0;
}

void codclef (int * iclef,int * itab,int tailletab,int tailleclef,int taillalpha, operation_t operation){
	int i,j;
	for (i=0, j=0; i < tailletab; ++i, j = (j + 1) % tailleclef)
	{
		printf("itab %d iclef %d\n", itab[i], iclef[j]);

		/* itab[i]=itab[i]+iclef[j];

		passage d'une fonction en parametre par pointeur
		resolution du pointeur et appele de la fonction*/
		itab[i] = (*operation)(itab[i], iclef[j], taillalpha);

		printf("resultat par clef %d\n", itab[i]);
		/* code */
	}
}

void inttoalpha(int * itab, char * tab, char * alphabet,int tailletab){
	int i;
	for (i = 0; i < tailletab ; ++i)
	{
		tab[i] = alphabet[itab[i]];
	}

	tab[tailletab] = '\0';
	/*transcript num to alpha*/

}

void afficheint(int * tab,int tailletab){
	int i;
	for (i = 0; i < tailletab; ++i)
	{
		printf("%d;",tab[i] );
		/* code */
	}
	printf("\n");
}

void * filetostring(char * read_file){
    char * buffer;
    FILE *file;
    buffer= malloc(100*sizeof(char));
    if(buffer==NULL)
    	error(1);
    file = fopen(read_file, "r");
    if (file == NULL) {
      perror("Error");
    } else {
    		fscanf(file,"%s",buffer);
	printf("CONTENT: %s\n",buffer);

      fclose(file);
      
    }

   
    return buffer;
}

void write_file(char * filename, char * var)
{
    FILE *file;
 	
    file = fopen(filename, "r+");
    if (file== NULL)
      error(1);
  	
    fprintf(file,"%s\n",var);
    fclose(file);
      
}

void rm_unknown_char(char * tab, cahr * alphabet){
	int i;
	int j;
	char tmp;
	for (i = 0; tab[i] != '\0'; ++i)
	{
		/* parsing tab in search of uknown cahr */
		if (((alphatoint(tab[i],char * alphabet))<0)||tab[i]=='\0')
		{
			j++;
		}
		else
			tab[i-j]=tab[i];
	}
	printf("%s\n",tab );
}


void error(int e){
	switch(e){
		case 1: printf("erreur d'alloc\n"); break;
		default: printf("errur incunue\n"); break;
	}
	exit(e);
}