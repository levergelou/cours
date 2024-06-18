# La problématique de notre sujet est :
# Est-ce qu'on peut retrouver la lattilude d'un collège en fonction des données de notre fichier ?

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# 2 - (a) Import des données
CollegeDF = pd.read_csv("Colleges.csv", delimiter=";")

# 2 - (b) Mise en forme des données
CollegeDF = CollegeDF.dropna()
CollegeAr = CollegeDF.to_numpy()

# 2 - (c) Centrer et réduire les données

# Centrer les données on retire les 2 premières colonnes qui ne sont pas des données numériques
CollegeAr0 = CollegeAr[:, 2:]

# Réduire les données
def Centreduire(Ar):
    n = len(Ar)  # Nombre de lignes dans Ar
    p = len(Ar[0])  # Nombre de colonnes dans Ar
    ResAr = np.zeros((n, p))  # Initialisation de la matrice résultat ResAr avec des zéros
    for j in range(p):  # Parcours de chaque colonne de Ar
        mean = 0  # Initialisation de la moyenne à zéro
        std = 0  # Initialisation de l'écart type à zéro
        # Calcul de la moyenne des éléments de la colonne j
        for i in range(n):
            mean += Ar[i][j]  # Somme des éléments de la colonne j
        mean /= n  # Division par le nombre d'éléments pour obtenir la moyenne
        # Calcul de l'écart type des éléments de la colonne j
        for i in range(n):
            std += (Ar[i][j] - mean) ** 2  # Somme des carrés des écarts par rapport à la moyenne
        std = (std / n) ** 0.5  # Calcul de l'écart type comme la racine carrée de la variance
        # Centrage et réduction des éléments de la colonne j et mise à jour de ResAr
        for i in range(n):
            ResAr[i][j] = (Ar[i][j] - mean) / std  # Formule de centrage et réduction
    return ResAr  # Retourne la matrice ResAr centrée et réduite

CollegeAr0_CR = Centreduire(CollegeAr0)

# 3 - (a) Représentation graphique

#  Diagramme en batons du nombre d'établissements en fonction de la latitude
latitudesAr = CollegeAr0[:, 0]
ipsAr = CollegeAr0[:, 1]
nbElevesHorsUlisSegpaAr = CollegeAr0[:, 2]
nbElevesSegpaAr = CollegeAr0[:, 3]
nbElevesUlisAr = CollegeAr0[:, 4]
pourcentageFillesAr = CollegeAr0[:, 5]

# On peut choisir d'afficher les diagrammes ou non
afficheDiagramme = True

# On évite d'afficher les diagrammes à chaque lancement 
if afficheDiagramme:
    # Définir le nombre de bins (plus c'est grand, plus c'est précis)
    num_bins = 50

    plt.hist(latitudesAr, bins=num_bins, edgecolor='black')
    plt.xlabel("Latitude")
    plt.ylabel("Nombre d'établissements")
    plt.title("Nombre d'établissements en fonction de la latitude")
    plt.show()

    # Diagramme en batons du nombre d'établissements en fonction de l'ips

    plt.hist(ipsAr, bins=num_bins, edgecolor='black')
    plt.xlabel("Ips")
    plt.ylabel("Nombre d'établissements")
    plt.title("Nombre d'établissements en fonction de l'ips")
    plt.show()

    # Diagramme en batons du nombre d'établissements en fonction du nombre d'élèves hors Ulis et Segpa

    plt.hist(nbElevesHorsUlisSegpaAr, bins=num_bins, edgecolor='black')
    plt.xlabel("Nombre d'élèves en dehors d'Ulis et Segpa")
    plt.ylabel("Nombre d'établissements")
    plt.title("Nombre d'établissements en fonction du nombre d'élèves hors Ulis et Segpa")
    plt.show()

    # Diagramme en batons du nombre d'établissements en fonction du nombre d'élèves Segpa

    plt.hist(nbElevesSegpaAr, bins=num_bins, edgecolor='black')
    plt.xlabel("Nombre d'élèves Segpa")
    plt.ylabel("Nombre d'établissements")
    plt.title("Nombre d'établissements en fonction du nombre d'élèves Segpa")
    plt.show()

    # Diagramme en batons du nombre d'étalissements en fonction du nombre d'élèves Ulis

    plt.hist(nbElevesUlisAr, bins=num_bins, edgecolor='black')
    plt.xlabel("Nombre d'élèves Ulis")
    plt.ylabel("Nombre d'établissements")
    plt.title("Nombre d'établissements en fonction du nombre d'élèves Ulis")
    plt.show()

    # Diagramme en batons de nombre d'établissements en fonction du pourcentage de filles

    plt.hist(pourcentageFillesAr, bins=num_bins, edgecolor='black')
    plt.xlabel("Pourcentage de filles")
    plt.ylabel("Nombre d'établissements")
    plt.title("Nombre d'établissements en fonction du pourcentage de filles")
    plt.show()

# 3 - (b) Matrice de covariance
MatriceCov = np.cov(CollegeAr0_CR, rowvar = False)

# Excel
MatriceCovDF = pd.DataFrame(MatriceCov)
MatriceCovDF.to_excel("MatriceCov.xlsx")
# J'utilise Excel et je crée une heatmap sur excel pour visualiser la matrice de covariance

# 4 - (d) Régression linéaire multiple
X = CollegeAr0[:,[1,2,4,5,3]]
Y = CollegeAr0[:,0]

reg = LinearRegression().fit(X, Y)
print("Coefficients de la régression linéaire multiple : \n", reg.coef_)
print("Intercept de la régression linéaire multiple : \n", reg.intercept_)
print("Score de la régression linéaire multiple : \n", reg.score(X, Y))