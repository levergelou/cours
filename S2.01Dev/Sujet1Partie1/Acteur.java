package Sujet1Partie1;

// Question 1
public class Acteur {
    // Attributs de la classe Acteur
    private String nom;
    private String prenom;

    // Constructeur de la classe Acteur
    public Acteur(String nom, String prenom) {
        this.nom = nom;
        this.prenom = prenom;
    }

    // Méthode de la classe Acteur
    // + boolean equals(a: Acteur)
    private boolean equals(Acteur a) {
        return this.nom.equals(a.nom) && this.prenom.equals(a.prenom);
    }

    // + void affiche()
    private void affiche() {
        System.out.println("Nom: " + this.nom + ", Prénom: " + this.prenom);
    }

    // Accesseurs
    public String getNom() {
        return this.nom;
    }

    public String getPrenom() {
        return this.prenom;
    }

    // Main
    public static void main(String[] args) {
        // Test affiche
        Acteur a1 = new Acteur("NEVOT", "Pierre");
        a1.affiche();

        // Test equals
        Acteur a2 = new Acteur("DLAPDKAO", "Joe");
        System.out.println(a1.equals(a2));

        Acteur a3 = new Acteur("NEVOT", "Pierre");
        System.out.println(a1.equals(a3));
    }
}

