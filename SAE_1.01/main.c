/*
programme sudoku c’est
    type tGrille = tableau[1..TAILLE, 1..TAILLE] de entier1;
    var grille1 : tGrille;
numLigne, numColonne, valeur : entier;
début
    chargerGrille(grille1);
    tant que la grille n’est pas pleine2 faire
        afficherGrille(grille1);
        ecrireEcran("Indices de la case ? ");
        saisir(numLigne);
        saisir(numColonne);
        si (grille1[numLigne][numColonne]!=0)alors
            ecrireEcran("IMPOSSIBLE, la case n'est pas libre.");
        sinon
            ecrireEcran("Valeur à insérer ? ");
            saisir(valeur);
            si (possible(grille1, numLigne, numColonne, valeur)) alors
                grille1[numLigne][numColonne] = valeur;
            finsi
        finsi
    finfaire
    ecrireEcran("Grille pleine, fin de partie");
fin
*/

// Chemin de grille : grilles/Grille[1-10].sud

#include <stdio.h>
#include <stdlib.h>

#define TAILLE 9
typedef int tGrille[TAILLE][TAILLE];
void chargerGrille(tGrille grille1);
void afficherGrille(tGrille grille1);
int possible(tGrille grille1, int numLigne, int numColonne, int valeur);

int main()
{
    tGrille grille1;
    int numLigne, numColonne, valeur;
    numColonne = 0;
    numLigne = 0;
    valeur = 0;

    chargerGrille(grille1);
    while (grille1[numLigne][numColonne] != 0)
    {
        afficherGrille(grille1);
        printf("Indices de la case ? ");
        scanf("%d", &numLigne);
        scanf("%d", &numColonne);
        if (grille1[numLigne][numColonne] != 0)
        {
            printf("IMPOSSIBLE, la case n'est pas libre.\n");
        }
        else
        {
            printf("Valeur à insérer ? ");
            scanf("%d", &valeur);
            if (possible(grille1, numLigne, numColonne, valeur))
            {
                grille1[numLigne][numColonne] = valeur;
            }
        }
    }
    printf("Grille pleine, fin de partie");
    return 0;
}

void chargerGrille(tGrille grille1)
{
    char nomFichier[30];
    FILE *f;
    printf("Nom du fichier ? ");
    scanf("%s", nomFichier);
    f = fopen(nomFichier, "rb");
    if (f == NULL)
    {
        printf("\n ERREUR sur le fichier %s\n", nomFichier);
    }
    else
    {
        fread(grille1, sizeof(int), TAILLE * TAILLE, f);
    }
    fclose(f);
}

void afficherGrille(tGrille grille1)
{
    int i, j;
    printf("       1  2  3   4  5  6   7  8  9\n");
    printf("     +---------+---------+---------+\n");
    for (i = 0; i < TAILLE; i++)
    {
        printf("  %d  |", i + 1);
        for (j = 0; j < TAILLE; j++)
        {
            if (grille1[i][j] == 0)
            {
                printf(" . ");
            }
            else
            {
                printf(" %d ", grille1[i][j]);
            }
            if (j == 2 || j == 5)
            {
                printf("|");
            }
        }
        printf("|\n");
        if (i == 2 || i == 5 || i == 8)
        {
            printf("     +---------+---------+---------+\n");
        }
    }
}


int possible(tGrille grille1, int numLigne, int numColonne, int valeur){
    int i, j;
    int ligne, colonne;
    ligne = numLigne - 1;
    colonne = numColonne - 1;
    for (i = 0; i < TAILLE; i++)
    {
        if (grille1[ligne][i] == valeur)
        {
            return 0;
        }
    }
    for (i = 0; i < TAILLE; i++)
    {
        if (grille1[i][colonne] == valeur)
        {
            return 0;
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++){
            if (grille1[(ligne / 3) * 3 + i][(colonne / 3) * 3 + j] == valeur)
            {
                return 0;
            }
        }
    }
    return 1;
}
