#ifndef TEST_H
#define TEST_H



//Afficher date

void afficher_date();



//meme_nombre_d_elements_a_la_creation

//----------------------------------------------------------------------------------------------------------------

void tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE);


void tests_en_boucle_meme_nb_elts();




//----------------------------------------------------------------------------------------------------------------

//fonction_deplacement

//----------------------------------------------------------------------------------------------------------------


void tester_que_les_objets_se_deplacent_sans_collision(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE);

void tester_que_les_objets_se_deplacent_bien(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS );

void tester_qu_il_y_a_bien_le_meme_nombre_d_elements_apres_chaque_tour();

void tester_un_element_qui_se_deplace_a_gauche();

//----------------------------------------------------------------------------------------------------------------

//SDL

//----------------------------------------------------------------------------------------------------------------

void tester_la_SDL(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE);

//----------------------------------------------------------------------------------------------------------------

//vieillissement

//----------------------------------------------------------------------------------------------------------------


void tester_le_nombre_de_morts(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS, unsigned age_de_deces_probable);

//----------------------------------------------------------------------------------------------------------------

//fonction_appliquer_les_regles_de_priorite
//----------------------------------------------------------------------------------------------------------------

void tester_la_fonction_appliquer_les_regles_de_priorite_sur_les_collisions(unsigned NB_LIGNES, unsigned NB_COLONNES);

//----------------------------------------------------------------------------------------------------------------

void tester_affichage_deplacements();

//-----------------------------------------------------------------------------------------------------------------

void tester_nouvelle_architecture_de_conception();



void tester();





#endif