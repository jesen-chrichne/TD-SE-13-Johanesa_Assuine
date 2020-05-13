#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int plus_moins();
void mode_unJoueur(int nb_cache);
void mode_deuxJoueurs(int nb_cache, int nb_tours, int joueur, int pt1, int pt2);
int main(int argc, char** argv){

	srand(time(NULL)); //Fait en sorte que le random soit base sur le temps


	int r = rand() % 100; //obtenir un nombre random, stocke dans r

	int choix;
	printf("Voulez-vous jouer en 1 joueur ou 2 joueurs (1 ou 2): ");
	scanf("%d",&choix);
	switch (choix){
		case 1:
			mode_unJoueur(r);
		break;
		case 2:
			printf("Combien de tours voulez vous: ");
			scanf("%d",&choix);
			mode_deuxJoueurs(r,choix,1,0,0);
		break;
		default:
			printf("choix incorrect.\n");
	}
	
	
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

void mode_unJoueur(int nb_cache){

	int input=0;
	int count = 0;
	
	int choix;
	int difficulte[] = {0,9999,25,10}; // 9999 pour infini
	printf("Choisissez la difficulte\n(1:facile,2:normale,3:difficile): ");
	scanf("%d", &choix);
	int trouve = 0;

	while (count < difficulte[choix]) {
			
			printf("Devinez le nombre : ");
			
			scanf("%d", &input);
			
			if (plus_moins(input, nb_cache)){
				trouve = 1;				
				break;
			}
			count +=1;
			
	} 
		if (!trouve){
			printf("Vous aviez %d essais \n",difficulte[choix]);
			printf("La reponse est %d \n",nb_cache);
		}
}

void mode_deuxJoueurs(int nb_cache, int nb_tours, int joueur, int pt1, int pt2) {
	int input=0;
	int count = 0;
	

	

	int nb_coup;
	printf("Le joueur %d met un nombre de coup (>=10): ", joueur);
	scanf("%d", &nb_coup);
	
	
	 
	if (nb_coup >= 10){
		printf("Le joueur %d doit deviner le nombre.\n",(joueur%2) + 1);//l' autre joueur 
		int trouve = 0;
		while (count < nb_coup) {
				
				printf("Devinez le nombre : ");
				
				scanf("%d", &input);
				
				if (plus_moins(input, nb_cache)){
					trouve = 1;
					break;	
				}
					
				count +=1;
				
					
			
		}
		//fin de tour
		if (!trouve){
			printf("Vous n'avez plus de coup");
			printf("La reponse est %d \n",nb_cache);
		}
		
		int ptObtenu = nb_coup - count; 
		

		if (joueur == 1){
			joueur = 2;
			pt2 += ptObtenu; 
		}
		else{
			joueur = 1;
			nb_tours -= 1;
			pt1 += ptObtenu;
		}
		printf("le joueur %d a obtenu %d points \n", joueur, ptObtenu); 
		srand(time(NULL)); 
		int r = rand() % 100; 
		if (nb_tours)
			mode_deuxJoueurs(r, nb_tours,joueur,pt1,pt2); //tour suivant
		else {
			printf("FIN DE LA PARTIE\n");			
			printf("joueur 1 | joueur 2\n   %d    |   %d\n",pt1,pt2); 
		}
		
	}	
	else{
		printf("le nombre doit etre superieur ou egal a 10. \n");
		mode_deuxJoueurs(nb_cache, nb_tours,joueur,pt1,pt2);
	}
		
}
