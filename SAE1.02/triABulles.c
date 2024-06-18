#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
/*******************************************************************
*
* @brief programme de TRI A BULLES sur un tableau de 100 000 entiers
* initialis� avec des valeurs al�atoires
*
*******************************************************************/
#define TAILLE 100000

typedef int typeTab[TAILLE];

void triABulles(typeTab tab);
void remplirTableau(typeTab tab);

int main () {
    typeTab leTableau;
    time_t temp_debut = time(NULL);
    clock_t clock_debut = clock();
    srand(time(NULL));
    remplirTableau(leTableau);
    triABulles(leTableau);
    clock_t clock_final = clock();
    double tempsCPU = (double)(clock_final-clock_debut)/CLOCKS_PER_SEC;
    printf("Temps CPU : %f\n", tempsCPU);
    time_t temp_final = time(NULL);
    double duree = difftime(temp_final, temp_debut);
    printf("Durée d'exécution : %f\n", duree);
    return EXIT_SUCCESS;
}

void triABulles(typeTab t){
    int i, j;
    int tmp;

    for(i=0;i<TAILLE-1;i++){
        for(j=0;j<TAILLE-i-1;j++){
            if (t[j]>t[j+1]){
                tmp = t[j];
                t[j] = t[j+1];
                t[j+1] = tmp;
            }
        }
    }
}

void remplirTableau(typeTab tab){
    int i;
    for (i=0 ; i<TAILLE ; i++){
        tab[i] = rand();
    }
}
