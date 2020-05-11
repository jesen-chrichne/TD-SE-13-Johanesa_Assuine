#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

	Le programme pour Kali linux seulement
	(ou alternatif si le premier ne marche pas)

*/

int plus_moins();

int main(int argc, char** argv){

	srand(time(NULL)); //Fait en sorte que le random soit base sur le temps


	int r = rand() % 100; //obtenir un nombre random, stocke dans r

	
	int input=0;
	int dejavu = -1; 
	int count = 0;
	printf("Le nombre est %d (test) \n",r); //Pour la phase test

	do {
			if (dejavu != input)
			printf("Devinez le nombre : ");
			else {
			count += 1;
			}
			if (count < 2){
				dejavu = input;
				getchar();
				
				scanf("%d", &input);
			} else {
				count = 0;
				dejavu = -1;
				printf("Vous avez deja insere ce nombre. \n");
				continue;
			}
			
			if (dejavu != input)
			plus_moins(input, r);
		
		
		
		
		
	}
	while (1);
	
	
	return 0;

}



int plus_moins(int choix_joueur, int nb_atrouver){ //une fonction qui va afficher Plus ou moins si 

	if (choix_joueur > nb_atrouver){

		printf("Moins \n"); 

	}
	else if (choix_joueur < nb_atrouver) {

		printf("Plus \n");

	}
	else {

		printf("Bingo\n");
		
	} 
	
	
	

}
