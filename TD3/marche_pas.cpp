Cell c1(0,3);
 	Cell c2(1,3);
 	Cell c3(2,3);
 	Cell c4(3,3);
	c1.add_neighb(&c2);
	c2.add_neighb(&c3);
	c3.add_neighb(&c4);
 	
 	Cell c5(3,2);
 	Cell c6(3,1);
 	Cell c7(3,0);
 	c4.add_neighb(&c5);
	c5.add_neighb(&c6);
	c6.add_neighb(&c7);

 	Cell c8(2,0);
 	Cell c9(2,1);
 	Cell c10(1,1);
 	c7.add_neighb(&c8);
	c8.add_neighb(&c9);
	c9.add_neighb(&c10);	

 	Cell c11(1,2);
 	Cell c12(2,2);
 	c10.add_neighb(&c11);
	c11.add_neighb(&c12);

	Cell c13(1,0);
 	Cell c14(0,0);
 	Cell c15(0,1);
 	Cell c16(0,2);
 	c10.add_neighb(&c13);
	c13.add_neighb(&c14);
	c14.add_neighb(&c15);
	c15.add_neighb(&c16);	
 	display_cell(&c1);



/*
Maze create_maze()
{
	Maze newMaze;
	int i =0, j=0, cpt=0;
	newMaze.taille = 16;
	Cell **tab_ptr= new Cell *[newMaze.taille];   // création d'un nouveau tableau
	for (j==0; j<4; j++)
	{
		i = 0; 
		for (i==0; i<4; i++)
		{
			Cell c(i,j);
			cout << "-----------" << endl;
			cout << "cx = " << c.m_x << " and cy = " << c.m_y << endl;
			tab_ptr[cpt] = &c;
			cout << &c << endl;
			cpt += 1;	
		}
	}
	newMaze.graphe = tab_ptr;
	delete [] tab_ptr;
	cout << "j'ai termine" << endl;
	return newMaze;
}
*/



struct Maze
{
	int taille = 16;  //taille de la grille 4*4
	Cell **graphe = NULL;  
	//vector<Cell *> graphe; //tableau contenant les pointeurs vers les cellules
	//Cell **graphe = NULL;
	Cell *cellStart = NULL;	//cellule de départ
	Cell *cellEnd = NULL;//cellule d'arrivée
};

Maze create_maze()
{
	Maze newMaze;
	int i =0, j=0;
	newMaze.taille = 16;
	Cell **tab_ptr= new Cell *[newMaze.taille];   // création d'un nouveau tableau
	// pas trouvé mieux :(
	Cell c1(0,3), c2(1,3), c3(2,3), c4(3,3), c5(3,2), c6(3,1), c7(3,0), c8(2,0), c9(2,1), c10(1,1),
	c11(1,2), c12(2,2), c13(1,0), c14(0,0), c15(0,1), c16(0,2); 
	tab_ptr[0] = &c1, tab_ptr[1] = &c2, tab_ptr[2] = &c3, tab_ptr[3] = &c4, 
	tab_ptr[4] = &c5, tab_ptr[5] = &c6, tab_ptr[6] = &c7, tab_ptr[7] = &c8,
	tab_ptr[8] = &c9, tab_ptr[9] = &c10, tab_ptr[10] = &c11, tab_ptr[11] = &c12,
	tab_ptr[12] = &c13, tab_ptr[13] = &c14, tab_ptr[14] = &c15, tab_ptr[15] = &c16;

	//voisins
	c1.add_neighb(&c2), c2.add_neighb(&c3), c3.add_neighb(&c4), c4.add_neighb(&c5),
	c5.add_neighb(&c6), c6.add_neighb(&c7), c7.add_neighb(&c8), c8.add_neighb(&c9),
	c9.add_neighb(&c10), c10.add_neighb(&c11), c11.add_neighb(&c12), c10.add_neighb(&c13),
	c13.add_neighb(&c14), c14.add_neighb(&c15), c15.add_neighb(&c16);	

	//création du labyrinthe
	newMaze.graphe = tab_ptr;
	display_cell(newMaze.graphe[0]);
	//delete tab_ptr;
	return newMaze;
}


//test
/*
 	 	Cell c1(0,3);
 	Cell c2(1,3);
 	Cell c3(0,0);

 	
 	cout << "avant = " << c1.m_nb_neighb << endl; 	
 	c1.add_neighb(&c2);
 	cout << c1.m_neighb[0] << endl;
 	cout << &c2 << endl;
 	cout << "apres1 = " << c1.m_nb_neighb << endl;
 	c1.add_neighb(&c3);
 	//cout << "apres2 = " << c1.m_nb_neighb << endl;

 	cout << c1.m_neighb[0] << endl;
 	cout << &c2 << endl;
 	cout << c2.m_neighb[0] << endl;
 	cout << &c1 << endl;

 	cout << "check for c3" << endl;
 	cout << c1.m_neighb[1] << endl;
 	cout << &c3 << endl;
 	cout << c3.m_neighb[0] << endl;
 	cout << &c1 << endl;
 	cout << "voisins de c1" << endl;
 	int i =0;
	for (i==0; i<c1.m_nb_neighb; i++) 
	{
		cout << "& voisin = " << c1.m_neighb[i] << endl;	
	}

*/