#ifndef __CELL_H__ // pour éviter les inclusions cycliques
#define __CELL_H__
#include <cstddef>
#include <fstream>

class Cell
{
 public:
 	Cell(); // constructeur par défaut (non paramétré)
 	Cell(int x, int y); // constructeur paramétré	
 	//~Cell();  //destructeur
 	
 	// variables de classe
 	int m_x = 0;
 	int m_y = 0;
 	int m_nb_neighb = 0;
 	Cell **m_neighb = NULL;
 	bool m_displayed = false;
 	bool m_saved = false;

 	//méthodes de la classe
 	void add_neighb(Cell *c);
 	//void add_neighb(Cell *c1, Cell *c2);
 	friend std::ostream & operator<<(std::ostream & stream, const Cell &c);
 	friend std::istream & operator>>(std::istream & stream, Cell &c);
};

#endif!