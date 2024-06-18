package Sujet1Partie1;

import java.util.Date;
import java.util.Calendar;

// Question 3
public class Seance {
    private Date date;
    private String type;
    private Film film;

    // Constructeur de la classe Seance
    public Seance(Date date, String type) {
        this.date = date;
        this.type = type;
    }

    // Méthode de la classe Seance
    // Celui-ci vient de la relation en la classe Film et Seance
    public void ajouterProgrammer(Film f) {
        if (f == null) {
            System.out.println("Erreur: Le film ne peut pas être null");
        } else {
            affecterFilm(f);
        }
    }
    
    // Setter de la classe Seance
    public void affecterFilm(Film f) {
        this.film = f;
    }

    // Méthode de la classe Seance
    // + void affiche()
    private void affiche() {
        System.out.println("Date: " + date + " Type: " + type);
        if (film == null) {
            System.out.println("Aucun film n'est programmé à cette séance");
        } else {
            System.out.println("Film: " + film.getTitre());
        }
    }

    // + boolean equals(s: Seance)
    private boolean equals(Seance s) {
        return this.date.equals(s.date) && this.type.equals(s.type);
    }

    // Question 4
    // Méthode pour enlever film du programme

    /*
     * Question 4
Dans la classe Seance, il faut aussi prévoir le cas où l'on souhaite déprogrammer un film : si
le film n'est plus programmé à cette séance, il faut enlever le lien entre la séance et le film.
Réfléchissez à une méthode public void enleverProgrammer(Film f) et
écrivez-la (elle fera appel à une méthode public void enleverFilm(Film f).
Là encore vous programmerez les vérifications nécessaires : vérifier que le film à
déprogrammer n'est pas null et vérifier qu'il correspond bien au film programmé à cette
séance (afficher des messages d'erreur sinon).
     */
    
    public void enleverProgrammer(Film f) {
        if (f == null) {
            System.out.println("Erreur: Le film ne peut pas être null");
        } else if (film == null) {
            System.out.println("Erreur: Aucun film n'est programmé à cette séance");
        } else if (!this.film.equals(f)) {
            System.out.println("Erreur: Le film à déprogrammer ne correspond pas au film programmé à cette séance");
        } else if (this.date.before(new Date())) {
            System.out.println("Erreur: La séance est déjà passée");
        } else {
            enleverFilm(f);
        }
    }

    public void enleverFilm(Film f) {
        this.film = null;
    }


    public static void main(String[] args) {
        // Test affiche
        Calendar calendar = Calendar.getInstance();
        calendar.set(2024, 5, 29, 12, 0, 0);
        Date test = calendar.getTime();
        calendar.set(2024, 5, 26, 12, 0, 0);
        Date test2 = calendar.getTime();
        Film f1 = new Film("Cars", 142, "USA", "vroom vroom");
        Film f2 = new Film("Cars 2", 130, "USA", "vroom vroom espion");
        Seance s1 = new Seance(test, "Soirée");
        s1.ajouterProgrammer(f1);
        s1.affiche();

        // Test equals
        Seance s2 = new Seance(test2, "Soirée");
        s2.ajouterProgrammer(f2);
        System.out.println(s1.equals(s2));

        Seance s3 = new Seance(test, "Soirée");
        s3.ajouterProgrammer(f1);
        System.out.println(s1.equals(s3));

        // Test enleverProgrammer
        s1.enleverProgrammer(f1);
        s1.affiche();

        s2.enleverProgrammer(f2);
        s2.affiche();

        s3.enleverProgrammer(f2);
        s3.affiche();


    }
}
