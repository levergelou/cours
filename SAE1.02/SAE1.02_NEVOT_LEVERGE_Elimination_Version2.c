// NEVOT Pierre, LE VERGE Lou 1C1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 3 
#define TAILLE (N * N) 

typedef struct {
    int valeur;     
    bool candidats[TAILLE+1]; 
    int nbCandidats;         
} tCase2;

typedef tCase2 tGrille[TAILLE][TAILLE]; 

// Initialise la grille de Sudoku avec des valeurs par défaut
void initGrille(tGrille grille) {
    int i, j, k;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            grille[i][j].valeur = 0;
            grille[i][j].nbCandidats = TAILLE;
            for (k = 0; k <= TAILLE; k++) {
                grille[i][j].candidats[k] = true;
            }
        }
    }
}

// Charge une grille de Sudoku à partir d'un fichier spécifié
void chargerGrille(tGrille grille, char *nomFichier) {
    FILE *f = NULL;
    while (f == NULL) {
        printf("Entrez le nom du fichier : ");
        scanf("%s", nomFichier);
        if (strcmp(nomFichier + strlen(nomFichier) - 4, ".sud") == 0) {
            f = fopen(nomFichier, "rb");
        } else {
            printf("Erreur : le fichier n'est pas valide.\n");
        }
    }
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            fread(&grille[i][j].valeur, sizeof(int), 1, f);
        }
    }
    fclose(f);
}

// Affiche la grille de Sudoku actuelle
void afficherGrille(tGrille grille) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            printf("%d ", grille[i][j].valeur);
        }
        printf("\n");
    }
}

// Vérifie si la grille de Sudoku est complètement remplie
bool grillePleine(tGrille grille) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (grille[i][j].valeur == 0) {
                return false;
            }
        }
    }
    return true;
}

// Affiche les candidats pour chaque case de la grille
void afficherCandidats(tGrille grille) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            printf("Case (%d, %d) : ", i, j);
            for (int k = 1; k <= TAILLE; k++) {
                if (grille[i][j].candidats[k]) {
                    printf("%d ", k);
                }
            }
            printf("\n");
        }
    }
}

// élimine les candidats en fonction des valeurs fixées dans chaque ligne
void eliminerCandidatsLigne(tGrille grille) {
    int i, j, k;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            if (grille[i][j].valeur != 0) {
                for (k = 1; k <= TAILLE; k++) {
                    if (grille[i][k-1].candidats[grille[i][j].valeur]) {
                        grille[i][k-1].candidats[grille[i][j].valeur] = false;
                        grille[i][k-1].nbCandidats--;
                    }
                }
            }
        }
    }
}

// élimine les candidats en fonction des valeurs fixées dans chaque colonne
void eliminerCandidatsColonne(tGrille grille) {
    int i, j, k;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            if (grille[j][i].valeur != 0) {
                for (k = 1; k <= TAILLE; k++) {
                    if (grille[k-1][i].candidats[grille[j][i].valeur]) {
                        grille[k-1][i].candidats[grille[j][i].valeur] = false;
                        grille[k-1][i].nbCandidats--;
                    }
                }
            }
        }
    }
}

// élimine les candidats en fonction des valeurs fixées dans chaque bloc 3x3
void eliminerCandidatsCarre(tGrille grille) {
    int i, j, k, l;
    for (i = 0; i < TAILLE; i += N) {
        for (j = 0; j < TAILLE; j += N) {
            for (k = 0; k < TAILLE; k++) {
                if (grille[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3].valeur != 0) {
                    for (l = 1; l <= TAILLE; l++) {
                        if (grille[(i / 3) * 3 + (l-1) / 3][(j / 3) * 3 + (l-1) % 3].candidats[grille[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3].valeur]) {
                            grille[(i / 3) * 3 + (l-1) / 3][(j / 3) * 3 + (l-1) % 3].candidats[grille[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3].valeur] = false;
                            grille[(i / 3) * 3 + (l-1) / 3][(j / 3) * 3 + (l-1) % 3].nbCandidats--;
                        }
                    }
                }
            }
        }
    }
}

// Tente de résoudre les cases avec un seul candidat restant
void singletonNu(tGrille grille) {
    int i, j, k, valeurCase, nbUn;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            if (grille[i][j].valeur == 0) {
                nbUn = 0;
                for (k = 1; k <= TAILLE; k++) {
                    if (grille[i][j].candidats[k]) {
                        valeurCase = k;
                        nbUn++;
                    }
                }
                if (nbUn == 1) {
                    grille[i][j].valeur = valeurCase;
                    eliminerCandidatsCarre(grille);
                    eliminerCandidatsColonne(grille);
                    eliminerCandidatsLigne(grille);
                }
            }
        }
    }
}

// Affiche les résultats après la tentative de résolution de la grille
void afficherResultat(tGrille grille, char nomgrille[20]) {
    int casesRemplies = 0;
    int candidatsElimines = 0;

    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (grille[i][j].valeur != 0) {
                casesRemplies++;
            }
            candidatsElimines += TAILLE - grille[i][j].nbCandidats;
        }
    }

    double tauxRemplissage = (double)casesRemplies / (TAILLE * TAILLE) * 100;
    double tauxElimination = (double)candidatsElimines / (TAILLE * TAILLE * TAILLE) * 100;

    printf("\n******      RESULTAT POUR %s      ******\n", nomgrille);
    printf("Nombre de cases remplies : %d sur %d\n", casesRemplies, TAILLE * TAILLE);
    printf("Taux de remplissage : %.2f%%\n", tauxRemplissage);
    printf("Nombre de candidats éliminés : %d\n", candidatsElimines);
    printf("Pourcentage d'élimination : %.2f%%\n", tauxElimination);
}

// Fonction principale pour tester le Sudoku
int main() {
    tGrille grille;
    char nomFichier[20];
    initGrille(grille);
    chargerGrille(grille, nomFichier);
    afficherGrille(grille);
    afficherResultat(grille, nomFichier);

    //résolution de la grille de Sudoku
    eliminerCandidatsLigne(grille);
    eliminerCandidatsColonne(grille);
    eliminerCandidatsCarre(grille);
    afficherResultat(grille, nomFichier);
    while (!grillePleine(grille)) {
        singletonNu(grille);
        afficherResultat(grille, nomFichier);
    }
    afficherGrille(grille);
    return 0;
}