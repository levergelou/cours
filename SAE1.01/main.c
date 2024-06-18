/**
 *  \page Sudoku
 * 
 *  \author LE VERGE Lou
 *  \version 1.0
 *  \date 26/11/2023
 * 
 *  sudoku
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



#define TAILLE 9



typedef int tGrille[TAILLE][TAILLE];

void chargerGrille(tGrille grille);
void afficherGrille(tGrille grille, tGrille grilleDepart);
bool fichierGrilleValide(char *nomFichier);
void saisirValeur(int *S);
int possible(tGrille grille, int numLigne, int numColonne, int valeur);
bool grillePleine(tGrille grille);


int main()
{
    tGrille grille, grilleDepart;
    int i, j, S, valeur;
    bool rejouer = true;
    while (rejouer == true)
    {
        chargerGrille(grille);
        for (i = 0; i < TAILLE; i++)
        {
            for (j = 0; j < TAILLE; j++)
            {
                grilleDepart[i][j] = grille[i][j];
            }
        }
        afficherGrille(grille, grilleDepart);
        while (grillePleine(grille) == false)
        {
            printf("Indices de la case ? ");
            saisirValeur(&i);
            saisirValeur(&j);
            if (grille[i - 1][j - 1] == grilleDepart[i - 1][j - 1] && grilleDepart[i - 1][j - 1] != 0)
            {
                printf("IMPOSSIBLE, la case n'est pas libre.\n");
            }
            else
            {
                printf("Valeur a inserer ? ");
                saisirValeur(&valeur);
                if (possible(grille, i - 1, j - 1, valeur) == true)
                {
                    grille[i - 1][j - 1] = valeur;
                }
            }
            afficherGrille(grille, grilleDepart);
        }
        printf("Bravo, vous avez gagne !\n");
        printf("Voulez-vous rejouer ? (1+ pour oui, 0 pour non) ");
        saisirValeur(&S);
        if (S == 0)
        {
            rejouer = false;
        }
    }
    return EXIT_SUCCESS;
}



void afficherGrille(tGrille grille, tGrille grilleDepart)
{
    int i, j;
    printf("       1  2  3   4  5  6   7  8  9\n");
    printf("     +---------+---------+---------+\n");
    for (i = 0; i < TAILLE; i++)
    {
        printf("  %d  |", i + 1);
        for (j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] == 0)
            {
                printf(" . ");
            }
            else if (grille[i][j] == grilleDepart[i][j] && grilleDepart[i][j] != 0)
            {
                printf("\033[0;32m %d \033[0m", grille[i][j]);
            }
            else
            {
                printf(" %d ", grille[i][j]);
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



void chargerGrille(tGrille g)
{
    char nomFichier[20];
    int i, j;
    printf("Entrez le nom du fichier : ");
    scanf("%s", nomFichier);
    while (fichierGrilleValide(nomFichier) == false)
    {
        printf("Entrez le nom du fichier : ");
        scanf("%s", nomFichier);
    }
    FILE *f = fopen(nomFichier, "rb");
    fread(g, sizeof(int), TAILLE*TAILLE, f);
    fclose(f);
}



bool fichierGrilleValide(char *nomFichier)
{
    FILE *fichier;
    int i, j, S;
    bool valide;
    valide = true;
    fichier = fopen(nomFichier, "rb");
    if (strcmp(nomFichier + strlen(nomFichier) - 4, ".sud") != 0) {
        printf("Erreur dans le nom du fichier\n");
        valide = false;
    }
    else
    {
        if (fichier == NULL)
        {
            printf("Erreur lors de l'ouverture du fichier\n");
            valide = false;
        }
        else
        {
            for (i = 0; i < TAILLE; i++)
            {
                for (j = 0; j < TAILLE; j++)
                {
                    fscanf(fichier, "%d", &S);
                    printf("%d ", S); // Ajoutez cette ligne pour afficher la valeur lue.
                    if (S < 0 || S > 9)
                    {
                        printf("Erreur dans le fichier, valeur non valide.\n");
                        valide = false;
                    }
                }
            }
        }
    }
    fclose(fichier);
    return valide;
}



bool grillePleine(tGrille grille)
{
    bool pleine;
    int i, j;
    pleine = true;
    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] == 0)
            {
                pleine = false;
            }
        }
    }
    return pleine;
}


 possible(tGrille grille, int numLigne, int numColonne, int valeur)
{
    int i, j, k, l;
    bool possible;
    for (i = 0; i < TAILLE; i++)
    {
        possible = true;
        if (grille[numLigne][i] == valeur)
        {
            printf("IMPOSSIBLE, la valeur %d est deja presente sur la ligne %d\n", valeur, numLigne + 1);
            possible = false;
        }
    }
    for (i = 0; i < TAILLE; i++)
    {
        if (grille[i][numColonne] == valeur)
        {
            printf("IMPOSSIBLE, la valeur %d est deja presente sur la colonne %d\n", valeur, numColonne + 1);
            possible = false;
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {

            if (grille[(numLigne / 3) * 3 + i][(numColonne / 3) * 3 + j] == valeur)
            {
                printf("IMPOSSIBLE, la valeur %d est deja presente dans le carre %d\n", valeur, (numLigne / 3) * 3 + (numColonne / 3) + 1);
                possible = false;
            }
        }
    }
    return possible;
}


void saisirValeur(int *S)
{
    char chaine[20];
    int x;
    scanf("%s", chaine);
    if (sscanf(chaine, "%d", &x) != 0)
    {
        if (x >= 1 && x <= TAILLE)
        {
            *S = x;
        }
        else
        {
            printf("Erreur, la valeur doit être comprise entre 1 et %d\n", TAILLE);
            saisirValeur(S);
        }
    }
    else
    {
        printf("Erreur, la valeur doit être un entier\n");
        saisirValeur(S);
    }
}


