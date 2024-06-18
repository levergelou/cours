Maquette

Le Sudoku est un jeu de réflexion dont le but est de remplir une grille de 9 × 9 cases.
Cette grille est divisée en 9 sous-grilles de 3 × 3 cases. Certaines cases de la grille sont  
déjà remplies par des chiffres, appelés indices. Le but du jeu est de remplir les cases vides
avec des chiffres allant de 1 à 9, de telle sorte que chaque ligne, chaque colonne et chaque
sous-grille de 3 × 3 cases contiennent une et une seule fois chaque chiffre de 1 à 9.
Je vous présente le programme que j'ai conçu pour pouvoir un jeux de sudoku pour des collégiens.

La grille de sudoku est composée de 9 lignes et 9 colonnes, soit 81 cases.
Quand le programme est lancé une grille sera crée avec des valeurs aléatoires.
Dont la solution sera calculer ou est déjà connue.
Tel que :

      1   2   3   4   5   6   7   8   9
    ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗               
  1 ║ 5 ║ 3 ║   ║   ║ 7 ║   ║   ║   ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  2 ║ 6 ║   ║   ║ 1 ║ 9 ║ 5 ║   ║   ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  3 ║   ║ 9 ║ 8 ║   ║   ║   ║   ║ 9 ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  4 ║ 8 ║   ║   ║   ║ 6 ║   ║   ║   ║ 3 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  5 ║ 4 ║   ║   ║ 8 ║   ║ 3 ║   ║   ║ 1 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  6 ║ 7 ║   ║   ║   ║ 2 ║   ║   ║   ║ 6 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  7 ║   ║ 6 ║   ║   ║   ║   ║ 2 ║ 8 ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  8 ║   ║   ║   ║ 4 ║ 1 ║ 9 ║   ║   ║ 5 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  9 ║   ║   ║   ║   ║ 8 ║   ║   ║ 7 ║ 9 ║
    ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝

    [Veuillez sélectionner une colonne : 3]
    [Veuillez sélectionner une ligne : 2]
    [Séléctionnez une valeur : 7]

Comme montrez ci-dessus, le texte entre crochets est ce que le programme affiche et est situé en dessous de la grille.
Tout les textes demandant une valeur à l'utilisateur sont situés en dessous de la grille.

Une fois la grille affichée, le joueur doit pouvoir sélectionner une case et y insérer une valeur.
Un message sera affiché avant que le joueur ne sélectionne une case, lui indiquant de sélectionner une case.
Les messages affichés seront : 
-"Séléctionnez une colonne :"
-"Séléctionnez une ligne :"
-"Séléctionnez une valeur :"

Si une des valeurs sélectionnées n'est pas entre 1 et 9 alors la valeur sera considéré incorrecte, un message d'erreur sera affiché.
Le message d'erreur sera : "Valeur incorrecte, veuillez entrer une valeur entre 1 et 9 :"

Une fois ceci fais la valeur sera insérée dans la case sélectionnée.
Par exemple je rentre une valeur de 7 dans la case 3,2.

"Veuillez sélectionner une colonne : 3"
"Veuillez sélectionner une ligne : 2"
"Séléctionnez une valeur : 18"
"Valeur incorrecte, veuillez entrer une valeur entre 1 et 9 : 7"
Puis le tableau est affiché :

      1   2   3   4   5   6   7   8   9
    ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗               
  1 ║ 5 ║ 3 ║   ║   ║ 7 ║   ║   ║   ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  2 ║ 6 ║   ║ 7 ║ 1 ║ 9 ║ 5 ║   ║   ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  3 ║   ║ 9 ║ 8 ║   ║   ║   ║   ║ 9 ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  4 ║ 8 ║   ║   ║   ║ 6 ║   ║   ║   ║ 3 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  5 ║ 4 ║   ║   ║ 8 ║   ║ 3 ║   ║   ║ 1 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  6 ║ 7 ║   ║   ║   ║ 2 ║   ║   ║   ║ 6 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  7 ║   ║ 6 ║   ║   ║   ║   ║ 2 ║ 8 ║   ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  8 ║   ║   ║   ║ 4 ║ 1 ║ 9 ║   ║   ║ 5 ║
    ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
  9 ║   ║   ║   ║   ║ 8 ║   ║   ║ 7 ║ 9 ║
    ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝

    On peut voir ici que la valeur 7 a été insérée dans la case 3,2.

Puis on répète l'opération jusqu'à ce que la grille soit complète.
Une fois la grille complète, le programme vérifie si la grille est correcte.
Et renvoie un message de victoire si la grille est correcte.
"Vous avez gagné !"
Sinon il envoie un message défaite.
"Vous avez perdu !"

Et demande au joueur s'il veut rejouer.
"Voulez-vous rejouer ? (O/N) :"
Si le joueur répond "N" alors le programme s'arrête.
Si le joueur répond "O" alors le programme affiche si le joueur a perdu :
"Voulez-vous rejouer avec la même grille ? (O/N) :"
Si le joueur répond "O" alors le programme recommence avec la même grille.

Sinon le programme recommence avec une nouvelle grille.
Si le joueur répond par autre chose que "O" ou "N" alors le programme affiche une erreur tel que :
"Veuillez entrer une réponse valide (O/N) :"