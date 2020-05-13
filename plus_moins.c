#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int plus_moins();

int main(int argc, char** argv){

	srand(time(NULL)); //Fait en sorte que le random soit base sur le temps


	int r = rand() % 100; //obtenir un nombre random, stocke dans r

	
	int input=0;
	int dejavu = -1; 
	int count = 0;
	printf("Le nb est %d (test) \n",r);
	int choix;
	int difficulte[] = {0,9999,25,10};
	printf("Choisissez la difficulte\n(1:facile,2:normale,3:difficile): ");
	scanf("%d", &choix);

	while (count < difficulte[choix]) {
			
			printf("Devinez le nombre : ");
			
			scanf("%d", &input);
			
			if (plus_moins(input, r))
				break;
			count +=1;
		
		
		
		
		
	} 
		printf("Vous aviez %d essais \n",difficulte[choix]);
	
	return 0;

}



int plus_moins(int choix_joueur, int nb_atrouver){ //une fonction qui va afficher Plus si 

	if (choix_joueur > nb_atrouver){

		printf("Moins \n"); 
		return 0;
	}
	else if (choix_joueur < nb_atrouver) {

		printf("Plus \n");
		return 0;
	}
	else {

		printf("Bingo\n");
		return 1;
	} 
	
	
	

}
