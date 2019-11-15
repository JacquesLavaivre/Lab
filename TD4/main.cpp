#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>
#include <cstddef>
#include <fstream>

#include "Cell.h"
#include "vibes.h"
using namespace std ;


void draw_gate(const Cell *n1, const Cell *n2)
{
	vibes::drawBox(min(n1->m_x, n2->m_x) + 0.1, max(n1->m_x, n2->m_x) + 0.9,
		min(n1->m_y, n2->m_y) + 0.1, max(n1->m_y, n2->m_y) + 0.9, "lightGray[lightGray]");
}

void display_cell(Cell *cell)
{
	vibes::drawBox(cell->m_x, cell->m_x + 1, cell->m_y, cell->m_y + 1, "[lightGray]");
	cell->m_displayed = true;
	for(int i = 0 ; i < cell->m_nb_neighb ; i++)
	{
		if(cell->m_neighb[i]->m_displayed==false) display_cell(cell->m_neighb[i]);
		draw_gate(cell, cell->m_neighb[i]);
	}
}

struct Maze
{
	Cell *cellStart = NULL;	//cellule de départ
	Cell *cellEnd = NULL;//cellule d'arrivée
};

Maze create_maze()
{
	Maze newMaze;
	Cell *pc1 = new Cell; pc1->m_x = 0; pc1->m_y = 3;  //c1(0,3);
	Cell *pc2 = new Cell; pc2->m_x = 1; pc2->m_y = 3; //c2(1,3); 
	Cell *pc3 = new Cell; pc3->m_x = 2; pc3->m_y = 3; //c3(2,3);
	Cell *pc4 = new Cell; pc4->m_x = 3; pc4->m_y = 3; //c4(3,3); 
	Cell *pc5 = new Cell; pc5->m_x = 3; pc5->m_y = 2; //c5(3,2); 
	Cell *pc6 = new Cell; pc6->m_x = 3; pc6->m_y = 1; //c6(3,1); 
	Cell *pc7 = new Cell; pc7->m_x = 3; pc7->m_y = 0; //c7(3,0); 
	Cell *pc8 = new Cell; pc8->m_x = 2; pc8->m_y = 0; //c8(2,0); 
	Cell *pc9 = new Cell; pc9->m_x = 2; pc9->m_y = 1; //c9(2,1); 
	Cell *pc10 = new Cell; pc10->m_x = 1; pc10->m_y = 1; //c10(1,1);
	Cell *pc11 = new Cell; pc11->m_x = 1; pc11->m_y = 2; //c11(1,2); 
	Cell *pc12 = new Cell; pc12->m_x = 2; pc12->m_y = 2; //c12(2,2); 
	Cell *pc13 = new Cell; pc13->m_x = 1; pc13->m_y = 0; //c13(1,0); 
	Cell *pc14 = new Cell; pc14->m_x = 0; pc14->m_y = 0; //c14(0,0); 
	Cell *pc15 = new Cell; pc15->m_x = 0; pc15->m_y = 1; //c15(0,1); 
	Cell *pc16 = new Cell; pc16->m_x = 0; pc16->m_y = 2; //c16(0,2); 
	//voisins
	pc1->add_neighb(pc2), pc2->add_neighb(pc3), pc3->add_neighb(pc4), pc4->add_neighb(pc5),
	pc5->add_neighb(pc6), pc6->add_neighb(pc7), pc7->add_neighb(pc8), pc8->add_neighb(pc9),
	pc9->add_neighb(pc10), pc10->add_neighb(pc11), pc11->add_neighb(pc12), pc10->add_neighb(pc13),
	pc13->add_neighb(pc14), pc14->add_neighb(pc15), pc15->add_neighb(pc16);

	/*newMaze.graphe.push_back(&c1), newMaze.graphe.push_back(&c2), newMaze.graphe.push_back(&c3), newMaze.graphe.push_back(&c4), 
	newMaze.graphe.push_back(&c5), newMaze.graphe.push_back(&c6), newMaze.graphe.push_back(&c7), newMaze.graphe.push_back(&c8), 
	newMaze.graphe.push_back(&c9), newMaze.graphe.push_back(&c10), newMaze.graphe.push_back(&c11), newMaze.graphe.push_back(&c12), 
	newMaze.graphe.push_back(&c13), newMaze.graphe.push_back(&c14), newMaze.graphe.push_back(&c15), newMaze.graphe.push_back(&c16);*/
	
	newMaze.cellStart = pc1;
	newMaze.cellEnd = pc16;

	/*display_cell(newMaze.cellStart);*/
	return newMaze;
}

void display_Maze(Maze m)
{
	display_cell(m.cellStart);
	vibes::drawCircle(m.cellStart->m_x+0.5, m.cellStart->m_y+0.5, 0.25, "black[green]");
	vibes::drawCircle(m.cellEnd->m_x+0.5, m.cellEnd->m_y+0.5, 0.25, "black[red]");
}


void save_cell(Cell *cell, ofstream *f)
{
	*f << *cell << cell->m_nb_neighb;
	for(int i = 0 ; i < cell->m_nb_neighb ; i++)
	{
		*f << *cell->m_neighb[i];
	}
	*f << endl;
	cell->m_saved = true;
	for(int i = 0 ; i < cell->m_nb_neighb ; i++)
	{
		if(cell->m_neighb[i]->m_saved==false) save_cell(cell->m_neighb[i], f);
	}
}

void save_maze(const Maze &maze, const string &file_name)
{
	ofstream ofst(file_name);
//test d'ouverture
	if (!ofst.is_open())
	{
		cout << "Erreur d'ouverture de " << file_name << endl;
	}
	else
	{
		ofst << "# Start :" << endl;
		ofst << *maze.cellStart << endl;
		ofst << "# End :" << endl;
		ofst << *maze.cellEnd << endl;
		ofst << "# Cells :" << endl;
		save_cell(maze.cellStart, &ofst);
	}
// fermeture du fichier
	ofst.close();
}


int main()
{
/*	vibes::beginDrawing();
	vibes::newFigure("Jam");
	vibes::setFigureProperties("Jam",
	vibesParams("x", 100, "y", 100, "width", 400, "height", 400));
 	vibes::axisLimits(0-0.5, 4+0.5, 0-0.5, 4+0.5);
// code here
	Maze labyrinthe;
	labyrinthe = create_maze();
	display_Maze(labyrinthe);



//end drawing
	vibes::endDrawing();*/
//TP04
/*	Cell c1(0,3);
	Cell c2(1,3);
	Cell c3(2,3);
	c1.add_neighb(&c2);
	c1.add_neighb(&c3);
	string filename = "labyrinthe_tp03.txt";
	Maze labyrinthe;
	labyrinthe = create_maze();
	save_maze(labyrinthe, filename);*/
	string filename = "file.txt";
	ifstream f(filename);
	if (!f.is_open())
	{
		cout << "erreur" << endl;
	}
	else
	{
		Cell c;
		f >> c;
		cout << c;
	}


	return 0;
}