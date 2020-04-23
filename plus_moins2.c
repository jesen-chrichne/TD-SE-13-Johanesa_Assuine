#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int plus_moins();

int main(int argc, char** argv){

	srand(time(NULL)); //Fait en sorte que le random soit base sur le temps


	int r = rand() % 20; //obtenir un nombre random, stocke dans r

	
	int input=0;
	int dejavu = -1; 
	int count = 0;
	printf("%d \n",r);

	do {
			
			printf("Devinez le nombre : ");
			
			
			scanf("%d", &input);
			
			plus_moins(input, r);
		
		
		
		
		
	}
	while (1);
	
	
	return 0;

}



int plus_moins(int choix_joueur, int nb_atrouver){ //une fonction qui va afficher Plus si 

	if (choix_joueur > nb_atrouver){

		printf("Plus \n"); 

	}
	else if (choix_joueur < nb_atrouver) {

		printf("Moins \n");

	}
	else {

		printf("Bingo\n");
	} 
	
	
	

}
