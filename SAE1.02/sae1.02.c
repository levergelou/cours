#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4
#define TAILLE (N * N)
typedef int tGrille[TAILLE][TAILLE];

void afficheGrille(tGrille grille);
bool absentSurLigne(int valeur, tGrille grille, int ligne);
bool absentSurColonne(int valeur, tGrille grille, int colonne);
bool absentSurBloc(int valeur, tGrille grille, int ligne, int colonne);
bool backtracking(tGrille grille, int numeroCase);
void chargerGrille(tGrille grille);
void initGrille(tGrille grille);

int main() {
  tGrille grille;
  chargerGrille(grille);
  afficheGrille(grille);
  if (backtracking(grille, 0) == true) {
    afficheGrille(grille);
  } else {
    printf("Pas de solution\n");
  }
  return 0;
}

bool backtracking(tGrille grille, int numeroCase) {
  int ligne, colonne;
  bool resultat = false;

  if (numeroCase == TAILLE * TAILLE) {
    resultat = true;
  } else {
    ligne = numeroCase / TAILLE;
    colonne = numeroCase % TAILLE;

    if (grille[ligne][colonne] != 0) {
      resultat = backtracking(grille, numeroCase + 1);
    } else {
      for (int valeur = 1; valeur <= TAILLE; valeur++) {
        if (absentSurLigne(valeur, grille, ligne) &&
            absentSurColonne(valeur, grille, colonne) &&
            absentSurBloc(valeur, grille, ligne, colonne)) {
          grille[ligne][colonne] = valeur;
          printf("Trying value %d at (%d, %d)\n", valeur, ligne, colonne);

          if (backtracking(grille, numeroCase + 1)) {
            resultat = true;
          } else {
            grille[ligne][colonne] = 0;
            printf("Backtracking from (%d, %d)\n", ligne, colonne);
          }
        }
      }
    }
  }

  return resultat;
}

void chargerGrille(tGrille grille) {
  FILE *fichier;
  char *nomFichier;
  nomFichier = "MaxiGrilleA.sud";
  fichier = fopen(nomFichier, "r");
  for (int i = 0; i < TAILLE; i++) {
    for (int j = 0; j < TAILLE; j++) {
      fread(&grille[i][j], sizeof(int), 1, fichier);
    }
  }
}

bool absentSurLigne(int valeur, tGrille grille, int ligne) {
  bool resultat = true;
  for (int colonne = 0; colonne < TAILLE; colonne++) {
    if (grille[ligne][colonne] == valeur) {
      resultat = false;
    }
  }
  return resultat;
}

bool absentSurColonne(int valeur, tGrille grille, int colonne) {
  bool resultat = true;
  for (int ligne = 0; ligne < TAILLE; ligne++) {
    if (grille[ligne][colonne] == valeur) {
      resultat = false;
    }
  }
  return resultat;
}

bool absentSurBloc(int valeur, tGrille grille, int ligne, int colonne) {
  bool resultat = true;
  int ligneBloc, colonneBloc;
  ligneBloc = ligne / TAILLE;
  colonneBloc = colonne / TAILLE;
  for (int i = 0; i < TAILLE; i++) {
    for (int j = 0; j < TAILLE; j++) {
      if (grille[TAILLE * ligneBloc + i][TAILLE * colonneBloc + j] == valeur) {
        resultat = false;
      }
    }
  }
  return resultat;
}

void afficheGrille(tGrille t) {
  printf(
      "     1   2   3   4    5   6   7   8    9   10  11  12   13  14  15  16  "
      " \n");
  int ligne;    // indice de ligne
  int colonne;  // indice de colonne
  for (ligne = 0; ligne < TAILLE; ligne++) {
    if (ligne % N == 0) {
      printf(
          "   "
          "+----------------+----------------+----------------+----------------"
          "+\n");
    }
    if (ligne < 9) {
      printf("%d  |", ligne + 1);
    } else {
      printf("%d |", ligne + 1);
    }

    for (colonne = 0; colonne < TAILLE; colonne++) {
      // acces a chaque case t[ligne][colonne] du tableau
      if (colonne % N == 0 && colonne != 0) {
        printf("|");  // tout les N valeur affiche un | pour la formatation
      }
      if (t[ligne][colonne] == 0) {
        printf(" .  ");  // affiche un . quand la case est vide
      }

      else {
        if (t[ligne][colonne] < 10) {
          printf(" %d  ", t[ligne][colonne]);
        } else {
          printf(
              " %d ",
              t[ligne][colonne]);  // affiche la case du tableau correspondante
        }
      }
    }
    printf("|\n");
  }
  printf(
      "   "
      "+----------------+----------------+----------------+----------------+"
      "\n");
}

void initGrille(tGrille grille) {
  int i, j;
  for (i = 0; i < TAILLE; i++) {
    for (j = 0; j < TAILLE; j++) {
      grille[i][j] = 0;
    }
  }
}
