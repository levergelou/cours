#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 3
#define TAILLE (N * N)
typedef struct {
    int valeur;
    int candidats[TAILLE];
    int nbCandidats;
} tCase1;

typedef tCase1 tGrille[TAILLE][TAILLE];

void initGrille(tGrille grille) {
    int i, j, k;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            grille[i][j].valeur = 0;
            grille[i][j].nbCandidats = TAILLE;
            for (k = 0; k < TAILLE; k++) {
                grille[i][j].candidats[k] = k + 1;
            }
        }
    }
}

// nomFichier en paramètre d'entrée-sortie
void chargerGrille(tGrille grille, char *nomFichier) {
    FILE *f = NULL;
    int i, j;
    while (f == NULL) {
        if (strcmp(nomFichier + strlen(nomFichier) - 4, ".sud") == 0) {
            f = fopen(nomFichier, "rb");
        } else {
            printf("Erreur : le fichier n'est pas valide.\n");
            printf("Entrez le nom du fichier : ");
            scanf("%s", nomFichier);
        }
    }
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            fread(&grille[i][j].valeur, sizeof(int), 1, f);
        }
    }
    fclose(f);
}

void afficherGrille(tGrille grille) {
    int i, j;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            printf("%d ", grille[i][j].valeur);
        }
        printf("\n");
    }
}

bool grillePleine(tGrille grille) {
    int i, j;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            if (grille[i][j].valeur == 0) {
                return false;
            }
        }
    }
    return true;
}

void afficherCandidats(tGrille grille) {
    int i, j, k;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            printf("Case (%d, %d) : ", i, j);
            for (k = 0; k < TAILLE; k++) {
                if (grille[i][j].candidats[k] != -1) {
                    printf("%d ", grille[i][j].candidats[k]);
                }
            }
            printf("\n");
        }
    }
}

void eliminerCandidatsLigne(tGrille grille) {
    int i, j, k;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            if (grille[i][j].valeur != 0) {
                for (k = 0; k < TAILLE; k++) {
                    if (grille[i][k].candidats[grille[i][j].valeur - 1] != -1) {
                        grille[i][k].candidats[grille[i][j].valeur - 1] = -1;
                        grille[i][k].nbCandidats--;
                    }
                }
            }
        }
    }
}

void eliminerCandidatsColonne(tGrille grille) {
    int i, j, k;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            if (grille[j][i].valeur != 0) {
                for (k = 0; k < TAILLE; k++) {
                    if (grille[k][i].candidats[grille[j][i].valeur - 1] != -1) {
                        grille[k][i].candidats[grille[j][i].valeur - 1] = -1;
                        grille[k][i].nbCandidats--;
                    }
                }
            }
        }
    }
}

void eliminerCandidatsCarre(tGrille grille) {
    int i, j, k, l;
    for (i = 0; i < TAILLE; i += 3) {
        for (j = 0; j < TAILLE; j += 3) {
            for (k = 0; k < TAILLE; k++) {
                if (grille[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3].valeur != 0) {
                    for (l = 0; l < TAILLE; l++) {
                        if (grille[(i / 3) * 3 + l / 3][(j / 3) * 3 + l % 3].candidats[grille[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3].valeur - 1] != -1) {
                            grille[(i / 3) * 3 + l / 3][(j / 3) * 3 + l % 3].candidats[grille[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3].valeur - 1] = -1;
                            grille[(i / 3) * 3 + l / 3][(j / 3) * 3 + l % 3].nbCandidats--;
                        }
                    }
                }
            }
        }
    }
}

void singletonNu(tGrille grille) {
    int i, j, k, l;
    int valeurCase;
    int nbUn;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            if (grille[i][j].valeur == 0) {
                nbUn = 0;
                for (k = 0; k < TAILLE; k++) {
                    if (grille[i][j].candidats[k] != -1) {
                        valeurCase = grille[i][j].candidats[k];
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

void afficherResultat(tGrille grille, char nomgrille[20]) {
    int i, j;
    int casesRemplies = 0;
    int candidatsElimines = 0;

    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
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
    eliminerCandidatsLigne(grille);
    eliminerCandidatsColonne(grille);
    eliminerCandidatsCarre(grille);
    afficherResultat(grille, nomFichier);
    while (!grillePleine(grille)) {
        singletonNu(grille);
        afficherResultat(grille, nomFichier);
    }
    return 0;
}
