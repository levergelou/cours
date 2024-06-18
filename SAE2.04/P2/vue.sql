set schema 'colleges2';

DROP VIEW vue_performance_scolaire;

CREATE OR REPLACE VIEW vue_performance_scolaire AS
SELECT 
    e.uai,
    e.nom_etablissement,
    e.lattitude,
    cc.ips,
    cc.nbre_eleves_hors_segpa_hors_ulis AS total_eleves_hors_segpa_ulis,
    cc.nbre_eleves_segpa AS total_eleves_segpa,
    cc.nbre_eleves_ulis AS total_eleves_ulis,
    AVG(cs.effectifs_filles::numeric / NULLIF((cs.effectifs_filles + cs.effectifs_garcons), 0)) * 100 AS pourcentage_filles
FROM 
    _etablissement e
LEFT JOIN 
    _caracteristiques_college cc ON e.uai = cc.uai
LEFT JOIN 
    _caracteristiques_tout_etablissement cte ON e.uai = cte.uai
LEFT JOIN 
    _caracteristiques_selon_classe cs ON e.uai = cs.uai
WHERE 
    cte.annee_scolaire = '2022-2023'
GROUP BY
    e.uai, 
    e.nom_etablissement, 
    e.lattitude,
    cc.ips, 
    cc.nbre_eleves_hors_segpa_hors_ulis,
    cc.nbre_eleves_segpa,
    cc.nbre_eleves_ulis;

WbExport -file=./Colleges.csv
         -type=text
         -delimiter=';'
         -header=true
         -dateFormat='d/M/y'
         -timestampFormat='d/M/y H:m:s';

SELECT * FROM vue_performance_scolaire;
