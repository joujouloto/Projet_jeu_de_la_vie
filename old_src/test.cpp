
5


//meme_nombre_d_elements_a_la_creation

//----------------------------------------------------------------------------------------------------------------



void tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE )
{
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "meme_nombre_d_elements_a_la_creation/tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne.txt";
	
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	
	
	//
	afficher_date();
	
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	
	cout << "----tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne-----: "<< endl 
	<<  NB_LIGNES << " lignes "  << endl
	<< NB_COLONNES << " colonnes " << endl
	<< NB_ELEMENTS_INITIAUX_PAR_LIGNE << " elements_initiaux " << endl
	<< jeu.get_nb_total_elements_presents_dans_la_grille() << " nombre total d'elements " << endl
	<< NB_LIGNES*NB_ELEMENTS_INITIAUX_PAR_LIGNE << " nombre total qui est cense y avoir " << endl;
		
	if(jeu.get_nb_total_elements_presents_dans_la_grille()== NB_LIGNES*NB_ELEMENTS_INITIAUX_PAR_LIGNE)
	{
		cout << "OK" << endl;
			
	}else
	{
		cout << "NOK" << endl;
	}
	
	
	jeu.afficher_nb_elements_par_ligne();
	
	jeu.afficher_contenu_de_la_grille();
	
	cout << "----Fin-tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne-----: "<< endl; 
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	
	
	//On redirige la sortie standard vers la sortie normale et on ferme le fichier
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
	
	
}

//Ici, on prévoit une grille de 10x10 juste pour simplifier. Quand le test sera bien établi, on modifiera la taille de la grille
void tests_en_boucle_meme_nb_elts()
{
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "meme_nombre_d_elements_a_la_creation/meme_nb_elts.txt";
	
	
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	
	afficher_date();
	
	
	//Variable aléatoire
	random_device rd;
	mt19937 gen(rd());
	int nb_elts_prevus_de_creer = 0;
	
	//On a une distribution uniforme entre 1 et 10, en gros il y peut avoir 1 element, 2 elements prevus de créer jusqu'à 10
	uniform_int_distribution<> dis(1, 10);
	
	
	
	//Nombre de tests réalisés
	int nb_tests = 100;
	
	//Numero du test
	int num_test = 1;
	
	//On veut compter le nombre de tests où il n'y a pas le même nombre d'elements prevus et reels
	int nb_tests_faux = 0;
	
	
	//grille de 10x10
	int nb_lignes = 20;
	int nb_colonnes = 20;
	
	
	cout << "tests en boucle pour verifier si on cree tel nombre d'elements, on a bien ce nombre d'elements a l'arrivee " << endl;
	cout << "Nombre de tests réalisés: " << nb_tests << endl;
	
	
	
	
	
	cout << "Nombre de lignes: " << nb_lignes << endl;
	cout << "Nombre de colonnes: " << nb_colonnes << endl;
	
	
	while (num_test <= nb_tests)
	{
		cout << "Test n°:" << num_test << endl;
		
		nb_elts_prevus_de_creer = dis(gen);
		
		
		Jeu jeu = Jeu(nb_lignes,nb_colonnes,nb_elts_prevus_de_creer);
		
		cout << "Nombre d'elements prevus a creer: " << nb_elts_prevus_de_creer * nb_colonnes << endl;
		cout << "Nombre reel d'elements crees : " << jeu.get_nb_total_elements_presents_dans_la_grille() << endl;
		
		
		if(nb_elts_prevus_de_creer * nb_colonnes != jeu.get_nb_total_elements_presents_dans_la_grille())
		{
			nb_tests_faux++;
		}
		num_test++;
	}
	
	cout << "-----------------------------------Bilan----------------------------------------------" << endl;
	cout << "nombre de tests où il n'y a pas le meme nombre d'elements prevus et reel:" << nb_tests_faux << endl;
	cout <<  "Pourcentage de tests réussis:" << ((nb_tests - nb_tests_faux) / nb_tests)*100 << '%' <<endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}



//----------------------------------------------------------------------------------------------------------------


//fonction_deplacement

//----------------------------------------------------------------------------------------------------------------

void tester_que_les_objets_se_deplacent_sans_collision(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE)
{
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "fonction_deplacement/tester_que_les_objets_se_deplacent_sans_collision.txt";
	
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	
	afficher_date();
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	cout << "----tester_que_les_objets_se_deplacent_sans_collision-------: "<< endl ;
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	cout << "-------------------------------------grille initialisee--- " << endl;
	jeu.afficher_contenu_de_la_grille();
	
	
	
	jeu.faire_deplacer_objets_dans_grille_de_transition();
	
	cout << "-------------------------------------contenu de la grille de transition " << endl;
	jeu.afficher_grille_de_transition();
	
	cout << "-------------------------------------contenu de la multimap qui contient que les elements en collision " << endl;
	
	jeu.mettre_objets_en_collision_dans_une_multimap();
	jeu.afficher_multimap_qui_contient_que_les_elements_en_collision();
	
	
	cout << "-------------------------------------contenu de la map qui contient que les elements qui etaient en collision sont priorises " << endl;
	
	jeu.appliquer_les_regles_de_priorite_sur_les_collisions();
	jeu.afficher_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite();
	
	
	cout << "------------------------------------la nouvelle grille--- " << endl;
	
	jeu.regrouper_tous_les_elements();
	jeu.afficher_contenu_de_la_grille();
	
	
	
	cout << "----Fin-tester_que_les_objets_se_deplacent_sans_collision-------: "<< endl ;
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}


void tester_que_les_objets_se_deplacent_bien(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS)
{
	
	
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "fonction_deplacement/tester_que_les_objets_se_deplacent_bien.txt";
	
	
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	// Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	afficher_date();
	
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	cout << "----tester_que_les_objets_se_deplacent_bien-------: "<< endl ;
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	cout << "-------------------------------------grille initialisee--- " << endl;
	jeu.afficher_contenu_de_la_grille();
	
	
	
	
	for(unsigned i = 1;i<=TOURS;i++)
	{
		cout << "-->>>>>>Jeu en mouvement: Tour " << i << endl;
	
		jeu.faire_deplacer_objets();
		jeu.afficher_contenu_de_la_grille();
	}
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
	
}

//quand il y a juste des déplacements
void tester_qu_il_y_a_bien_le_meme_nombre_d_elements_apres_chaque_tour(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS)
{
	int nb_elements_dans_grille_transition = 0;
	int nb_elements_en_collision = 0;
	int nb_elements_ou_on_applique_la_priorite = 0;
	
	
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "fonction_deplacement/tester_qu_il_y_a_bien_le_meme_nombre_d_elements_apres_chaque_tour.txt";
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	afficher_date();
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	jeu.initialiser_map();
	
	for(unsigned i = 1; i <= TOURS ;i++)
	{
		cout << "-->>>>>> Jeu en mouvement: Tour " << i << endl;
		
		jeu.faire_deplacer_objets_dans_grille_de_transition();
		
		

		nb_elements_dans_grille_transition = jeu.grille_de_transition->size() ;
		
		
		
		jeu.mettre_objets_en_collision_dans_une_multimap();
		nb_elements_en_collision = jeu.multimap_contenant_que_les_elements_en_collision->size();
		
		cout << "affichage multimap contenant que les elements en collision " << endl;
		jeu.afficher_multimap_qui_contient_que_les_elements_en_collision();
		
		jeu.appliquer_les_regles_de_priorite_sur_les_collisions();
		nb_elements_ou_on_applique_la_priorite = jeu.map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite->size();
		
		
		
		if(nb_elements_en_collision!=nb_elements_ou_on_applique_la_priorite)
		{
			
			cout << "affichage multimap ou on applique la priorite " << endl;
			jeu.afficher_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite();
			
			
			cout << " nombre d'elements dans grille de transition: "<< nb_elements_dans_grille_transition << endl;
			cout << " nombre d'elements dans multimap de collision: " << nb_elements_en_collision << endl;
			cout << " nombre d'elements dans map où on applique la priorité: " << nb_elements_ou_on_applique_la_priorite << endl;
			cout << "Le nombre d'elements en collision n'est pas egal au nombre d'elements auxquels on applique la priorite " << endl;
			
			
		}
		
		if(nb_elements_en_collision==1||nb_elements_ou_on_applique_la_priorite==1)
		{
			cout << " nombre d'elements dans grille de transition: "<< nb_elements_dans_grille_transition << endl;
			cout << " nombre d'elements dans multimap de collision: " << nb_elements_en_collision << endl;
			cout << " nombre d'elements dans map où on applique la priorité: " << nb_elements_ou_on_applique_la_priorite << endl;
			cout << "Le nombre d'elements en collision n'est pas egal  1 ou de meme pour les elements ou on applique la priorite" << endl;
		}
		
		
		
		jeu.regrouper_tous_les_elements();
		
		
		
		
		/*
		cout << " nombre d elements: " << jeu.get_nb_total_elements_presents_dans_la_grille() << endl;
		cout << " nombre total de gaulois et de gauloises: " << jeu.get_nb_total_gaulois() << endl;
		cout << " nombre total de gauloises: " << jeu.get_nb_total_gaulois_feminin() << endl;
		cout << " nombre total de gaulois: " << jeu.get_nb_total_gaulois_masculin() << endl;
		cout << " nombre total d'arbres: " << jeu.get_nb_total_arbres() << endl;*/
	}
	
	
	
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}

void tester_un_element_qui_se_deplace_a_gauche()
{
	
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "fonction_deplacement/tester_que_l_element_se_deplace_a_gauche.txt";
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	
	
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	
	cout << "-------------------------------------------Test de la fonction se deplacer a gauche--------------------------------------" << endl;
	
	afficher_date();
	
	//---------------------------------------------------------------------------------------------------------------------------------
	shared_ptr<Gaulois> gaulois_1;
	shared_ptr<Gaulois> gaulois_2;
	shared_ptr<Gaulois> gaulois_3;
	
	Jeu jeu = Jeu(10,10,0);
	
	
	//--------------------------------------------------------------
	gaulois_1 = make_shared<Gaulois>(homme,1,5);
	gaulois_1->seDeplacerA_Gauche(jeu.get_Map_normale());
	jeu.ajouter_objet_dans_map_normale(gaulois_1);
	
	//--------------------------------------------------------------
	gaulois_2 = make_shared<Gaulois>(homme,4,4);
	jeu.get_Map_normale()->erase(gaulois_2->getPosition());
	gaulois_2->seDeplacerA_Gauche(jeu.get_Map_normale());
	jeu.ajouter_objet_dans_map_normale(gaulois_2);
	
	
	//--------------------------------------------------------------
	gaulois_3 = make_shared<Gaulois>(homme,5,4);
	
	gaulois_2->seDeplacerA_Gauche(jeu.get_Map_normale());
	
	jeu.ajouter_objet_dans_map_normale(gaulois_3);
	
	cout << "nombre de gaulois crees depuis l'instanciation du premier gaulois: " << gaulois_3->get_nb_gaulois_crees() << endl ;
	
	
	
	
	//--------------------------------------------------------------
	
	
	jeu.afficher_contenu_de_la_grille();
	
	
	//---------------------------------------------------------------------------------------------------------------------------------
	
	cout << " On regarde si les coordonnees dans gaulois ont changé " << endl;
	
	
	
	
	gaulois_2->seDeplacerA_Gauche(jeu.get_Map_normale());
	
	jeu.ajouter_objet_dans_map_normale(gaulois_2);
	
	cout << gaulois_2->toString() << endl;
	
	
		
	//---------------------------------------------------------------------------------------------------------------------------------
	
	jeu.afficher_contenu_de_la_grille();
	
	
	//---------------------------------------------------------------------------------------------------------------------------------
	
	
	
	cout.rdbuf(stream_buffer_cout);
	

	
	
	/*
		Les coordonnees changent dans gaulois mais pas dans jeu , c'est normal grille est de type map
	
	
	
	
	*/
	
	
	
	
	
	
	file.close();
}







//----------------------------------------------------------------------------------------------------------------


//SDL

//----------------------------------------------------------------------------------------------------------------

void tester_la_SDL(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE)
{
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "SDL/tester_la_SDL.txt";
	
	
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	
	afficher_date();
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	
	jeu.SDL();
	
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}

//----------------------------------------------------------------------------------------------------------------


//vieilissement

//----------------------------------------------------------------------------------------------------------------

void tester_le_nombre_de_morts(unsigned NB_LIGNES, unsigned NB_COLONNES, unsigned NB_ELEMENTS_INITIAUX_PAR_LIGNE, unsigned TOURS, unsigned age_de_deces_probable)
{
	
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "vieillissement/tester_le_nombre_de_morts.txt";
	
	
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	afficher_date();
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,NB_ELEMENTS_INITIAUX_PAR_LIGNE);
	jeu.initialiser_map();
	
	for(unsigned i = 1; i <= TOURS ;i++)
	{
		cout << "-->>>>>>Jeu en mouvement: Tour " << i << endl;
		jeu.faire_deplacer_objets();
		jeu.faire_vieillir_population_gauloise();
		jeu.faire_mourir_les_gaulois_trop_vieux(age_de_deces_probable);
		
		
	}
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}

//----------------------------------------------------------------------------------------------------------------

//fonction_appliquer_les_regles_de_priorite

//----------------------------------------------------------------------------------------------------------------

void tester_la_fonction_appliquer_les_regles_de_priorite_sur_les_collisions(unsigned NB_LIGNES, unsigned NB_COLONNES)
{
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "fonction_appliquer_les_regles_de_priorite/tester_la_fonction_priorite.txt";
	
	
	
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	afficher_date();
	
	
	Jeu jeu = Jeu(NB_LIGNES,NB_COLONNES,0);
	
	shared_ptr<Gaulois> gaulois_1;
	shared_ptr<Gaulois> gaulois_2;
	shared_ptr<Gaulois> gauloise_3;
	shared_ptr<Gaulois> gauloise_4;
	shared_ptr<Gaulois> gaulois_5;
	
	
	cout << "---------------Création d'elements dans la grille où on applique la priorite------------------" << endl;
	cout << " On cree des elements volontairement en collision pour tester si la fonction appliquer_les_regles_de_priorite_sur_les_collisions() fonctionne bien " << endl;
	
	/*
		affichage multimap contenant que les elements en collision 
		2x5 =>  Gaulois
		1x5 >> 2x5
		age: 1
		
		2x5 =>  Gaulois
		3x5 >> 3x5
		age: 1
		
		3x5 =>  Gauloise
		3x4 >> 3x5
		age: 1
		
		3x5 =>  Gauloise
		4x5 >> 4x5
		age: 1
		
		affichage multimap ou on applique la priorite 
		2x5 =>  Gaulois
		1x5 >> 2x5
		age: 1
		
		3x5 =>  Gaulois
		3x5 >> 3x5
		age: 1
		
		4x5 =>  Gauloise
		4x5 >> 4x5
		age: 1
		
		*/
	
	gaulois_1 = make_shared<Gaulois>(homme,1,5);
	gaulois_1->seDeplacer(2,5);
	jeu.ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(gaulois_1);
	
	
	
	
	gaulois_2 = make_shared<Gaulois>(homme,2,5);
	gaulois_2->seDeplacer(3,5);
	jeu.ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(gaulois_2);
	
	gauloise_3 = make_shared<Gaulois>(femme,3, 4);
	gauloise_3->seDeplacer(3,5);
	jeu.ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(gauloise_3);
	
	gauloise_4 = make_shared<Gaulois>(femme,4, 5);
	gauloise_4->seDeplacer(3,5);
	jeu.ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(gauloise_4);
	
	
	
	gaulois_5 = make_shared<Gaulois>(homme,5, 5);
	gaulois_5->seDeplacer(4,5);
	jeu.ajouter_objet_dans_multimap_contenant_que_les_elements_en_collision(gaulois_5);
	
	jeu.afficher_multimap_qui_contient_que_les_elements_en_collision();
	
	
	//On applique la priorite
	
	
	
	cout << "----------------On applique la priorite---------------------------------------------" << endl;
	
	jeu.appliquer_les_regles_de_priorite_sur_les_collisions();
	
	jeu.afficher_map_contenant_que_les_elements_en_collision_ou_on_applique_la_priorite();
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}


//----------------------------------------------------------------------------------------------------------------


void tester_affichage_deplacements()
{
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "affichage_deplacements/affichage_deplacements.txt";
	
	
	
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	afficher_date();
	
	shared_ptr<Gaulois> gaulois_1;
	
	gaulois_1 = make_shared<Gaulois>(homme,7,5);
	gaulois_1->seDeplacer(2,5);
	gaulois_1->seDeplacer(9,4);
	gaulois_1->seDeplacer(1,1);
	gaulois_1->seDeplacer(5,8);
	
	cout << gaulois_1->getDeplacements() << endl;
	
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
}

void tester_nouvelle_architecture_de_conception()
{
	string chemin_dossier_tests = "../../tests/";
	string chemin_fichier = "nouvelle_architecture/premier_test.txt";
	
	
	
	
	fstream file;
    file.open(chemin_dossier_tests+chemin_fichier, ios::out|ios::app);
    string line;
	
	 // Backup streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
	
	// Redirect cout to file
    cout.rdbuf(stream_buffer_file);
	
	afficher_date();
	
	
	Jeu_v2 jeu = Jeu_v2();
	
	string str_contenu_grille = jeu.afficher_dans_chaine_contenu_grille();
	
	cout << str_contenu_grille;
	
	
	
	cout.rdbuf(stream_buffer_cout);
	
	
	file.close();
	
}










void tester()
{
	
	
	
	cout << " Tests " << endl;
	
	/*
	tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(3,10,4);
	tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(7,10,5);
	tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(7,10,9);
	tester_qu_il_a_bien_tel_nombre_d_elements_par_ligne(7,10,10);
	
	tester_que_les_objets_se_deplacent_sans_collision(3, 5, 2);
	
	
	tester_que_les_objets_se_deplacent_bien(10,7,3,10);

	tester_qu_il_y_a_bien_le_meme_nombre_d_elements_apres_chaque_tour(10,7,3,100);
	
	
	tester_la_SDL(10,7,3);
	
	tester_le_nombre_de_morts(7,10,5,30,10);
	
	tester_la_fonction_appliquer_les_regles_de_priorite_sur_les_collisions(10, 10);
	*/
	
	//tests_en_boucle_meme_nb_elts();
	
	
	//tester_un_element_qui_se_deplace_a_gauche();
	
	//tester_affichage_deplacements();
	
	tester_nouvelle_architecture_de_conception();
	
}
	
	











