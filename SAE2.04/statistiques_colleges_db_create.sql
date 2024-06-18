-- Table Région
CREATE TABLE _region (
    code_region VARCHAR(255),
    libelle_region VARCHAR(255) UNIQUE NOT NULL,
    CONSTRAINT pk_region PRIMARY KEY (code_region)
);

-- Table Académie
CREATE TABLE _academie (
    code_academie INT,
    lib_academie VARCHAR(255) NOT NULL,
    CONSTRAINT pk_academie PRIMARY KEY (code_academie)
);

-- Table Département
CREATE TABLE _departement (
    code_du_departement VARCHAR(255),
    nom_departement VARCHAR(255) UNIQUE NOT NULL,
    code_region VARCHAR(255),
    CONSTRAINT pk_departement PRIMARY KEY (code_du_departement),
    CONSTRAINT departement_fk_region FOREIGN KEY (code_region) REFERENCES _region(code_region)
);

-- Table Commune
CREATE TABLE _commune (
    code_insee_de_la_commune VARCHAR(255),
    nom_de_la_commune VARCHAR(255) UNIQUE NOT NULL,
    code_du_departement VARCHAR(255),
    CONSTRAINT pk_commune PRIMARY KEY (code_insee_de_la_commune),
    CONSTRAINT commune_fk_departement FOREIGN KEY (code_du_departement) REFERENCES _departement(code_du_departement)
);

-- Table Quartier_prioritaire
CREATE TABLE _quartier_prioritaire (
    code_quartier_prioritaire VARCHAR(255),
    nom_quartier_prioritaire VARCHAR(255) NOT NULL,
    CONSTRAINT pk_quartier_prioritaire PRIMARY KEY (code_quartier_prioritaire)
);

-- Table Type
CREATE TABLE _type (
    code_nature VARCHAR(255),
    libelle_nature VARCHAR(255) NOT NULL,
    CONSTRAINT pk_type PRIMARY KEY (code_nature)
);

-- Table Année
CREATE TABLE _annee (
    annee_scolaire VARCHAR(255),
    CONSTRAINT pk_annee PRIMARY KEY (annee_scolaire)
); 

-- Table Etablissement
CREATE TABLE _etablissement (
    uai VARCHAR(255),
    nom_etablissement VARCHAR(255) NOT NULL,
    secteur VARCHAR(255),
    code_postal VARCHAR(255),
    latitude FLOAT,
    longitude FLOAT,
    code_academie INT,
    code_insee_de_la_commune VARCHAR(255),
    code_quartier_prioritaire VARCHAR(255),
    CONSTRAINT pk_etablissement PRIMARY KEY (uai),
    CONSTRAINT etablissement_fk_academie FOREIGN KEY (code_academie) REFERENCES _academie(code_academie),
    CONSTRAINT etablissement_fk_commune FOREIGN KEY (code_insee_de_la_commune) REFERENCES _commune(code_insee_de_la_commune),
    CONSTRAINT etablissement_fk_quartier FOREIGN KEY (code_quartier_prioritaire) REFERENCES _quartier_prioritaire(code_quartier_prioritaire)
);

-- Table Classe
CREATE TABLE _classe (
    id_classe VARCHAR(255),
    uai VARCHAR(255),
    annee_scolaire VARCHAR(255),
    code_nature VARCHAR(255),
    CONSTRAINT pk_classe PRIMARY KEY (id_classe),
    CONSTRAINT classe_fk_etablissement FOREIGN KEY (uai) REFERENCES _etablissement(uai),
    CONSTRAINT classe_fk_annee FOREIGN KEY (annee_scolaire) REFERENCES _annee(annee_scolaire),
    CONSTRAINT classe_fk_type FOREIGN KEY (code_nature) REFERENCES _type(code_nature)
);

-- Table caractéristiques_tout_etablissement
CREATE TABLE _caracteristiques_tout_etablissement (
    id INT AUTO_INCREMENT,
    uai VARCHAR(255),
    annee_scolaire VARCHAR(255),
    effectifs INT,
    ips FLOAT,
    ecart_type_de_l_ips FLOAT,
    ep VARCHAR(255),
    CONSTRAINT pk_caracteristiques_tout_etablissement PRIMARY KEY (id),
    CONSTRAINT cte_fk_etablissement FOREIGN KEY (uai) REFERENCES _etablissement(uai),
    CONSTRAINT cte_fk_annee FOREIGN KEY (annee_scolaire) REFERENCES _annee(annee_scolaire)
);

-- Table caractéristiques_college
CREATE TABLE _caracteristiques_college (
    id INT AUTO_INCREMENT,
    uai VARCHAR(255),
    annee_scolaire VARCHAR(255),
    nbre_eleves_hors_segga_hors_ulis INT,
    nbre_eleves_segga INT,
    nbre_eleves_ulis INT,
    CONSTRAINT pk_caracteristiques_college PRIMARY KEY (id),
    CONSTRAINT cc_fk_etablissement FOREIGN KEY (uai) REFERENCES _etablissement(uai),
    CONSTRAINT cc_fk_annee FOREIGN KEY (annee_scolaire) REFERENCES _annee(annee_scolaire)
);

-- Table caractéristiques_selon_classe
CREATE TABLE _caracteristiques_selon_classe (
    id INT AUTO_INCREMENT,
    id_classe VARCHAR(255),
    nbre_eleves_hors_segap_hors_ulis_selon_niveau INT,
    nbre_eleves_segap_selon_niveau INT,
    nbre_eleves_ulis_selon_niveau INT,
    effectif_filles INT,
    effectif_garcons INT,
    CONSTRAINT pk_caracteristiques_selon_classe PRIMARY KEY (id),
    CONSTRAINT csc_fk_classe FOREIGN KEY (id_classe) REFERENCES _classe(id_classe)
);
