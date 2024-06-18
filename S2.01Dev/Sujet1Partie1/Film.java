package Sujet1Partie1;

// Question 2
public class Film {
    private String titre;
    private int duree;
    private String nationalite;
    private String resume;

    // Constructeur de la classe Film
    public Film(String titre, int duree, String nationalite, String resume) {
        this.titre = titre;
        this.duree = duree;
        this.nationalite = nationalite;
        this.resume = resume;
    }

    // Méthode de la classe Film
    // + boolean equals(f: Film)
    private boolean equals(Film f) {
        return this.titre.equals(f.titre);
    }

    // + void affiche()
    private void affiche() {
        System.out.println(this.titre + "      Film " + this.nationalite + " de " + this.duree + " mn\n\nRésumé : " + this.resume); 
    }

    // Accesseurs
    public String getTitre() {
        return this.titre;
    }

    public int getDuree() {
        return this.duree;
    }

    public String getNationalite() {
        return this.nationalite;
    }

    public String getResume() {
        return this.resume;
    }

    // Main
    public static void main(String[] args) {
        // Test affiche
        Film f1 = new Film("Cars", 142, "USA", "vroom vroom");
        f1.affiche();

        // Test equals
        Film f2 = new Film("Cars 2", 130, "USA", "vroom vroom espion");
        System.out.println(f1.equals(f2));
    
        Film f3 = new Film("Cars", 142, "USA", "vroom vroom");
        System.out.println(f1.equals(f3));
    }
}