// NEVOT Pierre, LE VERGE Lou 1C1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 3
#define TAILLE (N * N) // Définir la taille totale de la grille de Sudoku

typedef struct {
    int valeur;               
    int candidats[TAILLE];    
    int nbCandidats;          
} tCase1;

typedef tCase1 tGrille[TAILLE][TAILLE]; 

// Initialise la grille de Sudoku avec des valeurs par défaut
void initGrille(tGrille grille) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            grille[i][j].valeur = 0;
            grille[i][j].nbCandidats = TAILLE;
            for (int k = 0; k < TAILLE; k++) {
                grille[i][j].candidats[k] = k + 1;
            }
        }
    }
}

// Charge une grille de Sudoku à partir d'un fichier spécifié
void chargerGrille(tGrille grille, char *nomFichier) {
    FILE *f = fopen(nomFichier, "rb");
    if (!f) {
        printf("Erreur : le fichier n'est pas valide.\n");
        return;
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
            for (int k = 0; k < TAILLE; k++) {
                if (grille[i][j].candidats[k] != -1) {
                    printf("%d ", grille[i][j].candidats[k]);
                }
            }
            printf("\n");
        }
    }
}

// élimine les candidats en fonction des valeurs fixées dans chaque ligne
void eliminerCandidatsLigne(tGrille grille) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (grille[i][j].valeur != 0) {
                for (int k = 0; k < TAILLE; k++) {
                    int candidat = grille[i][j].valeur - 1;
                    if (grille[i][k].candidats[candidat] != -1) {
                        grille[i][k].candidats[candidat] = -1;
                        grille[i][k].nbCandidats--;
                    }
                }
            }
        }
    }
}

// élimine les candidats en fonction des valeurs fixées dans chaque colonne
void eliminerCandidatsColonne(tGrille grille) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (grille[j][i].valeur != 0) {
                for (int k = 0; k < TAILLE; k++) {
                    int candidat = grille[j][i].valeur - 1;
                    if (grille[k][i].candidats[candidat] != -1) {
                        grille[k][i].candidats[candidat] = -1;
                        grille[k][i].nbCandidats--;
                    }
                }
            }
        }
    }
}

// élimine les candidats en fonction des valeurs fixées dans chaque bloc 3x3
void eliminerCandidatsCarre(tGrille grille) {
    for (int i = 0; i < TAILLE; i += N) {
        for (int j = 0; j < TAILLE; j += N) {
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    int cx = i + x, cy = j + y;
                    if (grille[cx][cy].valeur != 0) {
                        int candidat = grille[cx][cy].valeur - 1;
                        for (int k = 0; k < N; k++) {
                            for (int l = 0; l < N; l++) {
                                int tx = i + k, ty = j + l;
                                if (grille[tx][ty].candidats[candidat] != -1) {
                                    grille[tx][ty].candidats[candidat] = -1;
                                    grille[tx][ty].nbCandidats--;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// Remplit les cases qui n'ont qu'un seul candidat restant
void singletonNu(tGrille grille) {
    bool change = true;
    while (change) {
        change = false;
        for (int i = 0; i < TAILLE; i++) {
            for (int j = 0; j < TAILLE; j++) {
                if (grille[i][j].valeur == 0 && grille[i][j].nbCandidats == 1) {
                    for (int k = 0; k < TAILLE; k++) {
                        if (grille[i][j].candidats[k] != -1) {
                            grille[i][j].valeur = grille[i][j].candidats[k];
                            change = true;
                            break;
                        }
                    }
                    if (change) {
                        eliminerCandidatsLigne(grille);
                        eliminerCandidatsColonne(grille);
                        eliminerCandidatsCarre(grille);
                    }
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

int main() {
    tGrille grille;
    char nomFichier[20];
    printf("Entrez le nom du fichier : ");
    scanf("%s", nomFichier);
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