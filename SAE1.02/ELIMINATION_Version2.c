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

void initGrille(tGrille grille) {
    int i, j, k;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            grille[i][j].valeur = 0;
            grille[i][j].nbCandidats = TAILLE;
            for (k = 0; k < TAILLE; k++) {
                grille[i][j].candidats[k] = true;
            }
        }
    }
}


void chargerGrille(tGrille grille, char *nomFichier) {
    FILE *f = NULL;
    int i, j;
    while (f == NULL) {
        printf("Entrez le nom du fichier : ");
        scanf("%s", nomFichier);
        if (strcmp(nomFichier + strlen(nomFichier) - 4, ".sud") == 0) {
            f = fopen(nomFichier, "rb");
        } else {
            printf("Erreur : le fichier n'est pas valide.\n");
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
                if (grille[i][j].candidats[k]) {
                    printf("%d ", k + 1);
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
                    grille[i][k].candidats[grille[i][j].valeur - 1] = false;
                    grille[i][k].nbCandidats--;
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
                    grille[k][i].candidats[grille[j][i].valeur - 1] = false;
                    grille[k][i].nbCandidats--;
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
                        grille[(i / 3) * 3 + l / 3][(j / 3) * 3 + l % 3].candidats[grille[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3].valeur - 1] = false;
                        grille[(i / 3) * 3 + l / 3][(j / 3) * 3 + l % 3].nbCandidats--;
                    }
                }
            }
        }
    }
}

void singletonNu(tGrille grille) {
    int i, j, k, valeurCase, nbUn;
    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            if (grille[i][j].valeur == 0) {
                nbUn = 0;
                for (k = 0; k < TAILLE; k++) {
                    if (grille[i][j].candidats[k]) {
                        valeurCase = k + 1;
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

int main() {
    tGrille grille;
    char nomgrille[20];
    initGrille(grille);
    chargerGrille(grille, &nomgrille);
    afficherGrille(grille);
    eliminerCandidatsLigne(grille);
    eliminerCandidatsColonne(grille);
    eliminerCandidatsCarre(grille);
    afficherCandidats(grille);
    while (!grillePleine(grille)) {
        singletonNu(grille);
    }
    afficherGrille(grille);
    return 0;
}