#include "Cell.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
#include <cstddef>

using namespace std ;


Cell::Cell() : m_x(0), m_y(0)
{
	//valeur par défaut
}

Cell::Cell(int x, int y) : m_x(x), m_y(y)
{
	//valeur par défaut
}

void Cell::add_neighb(Cell *c)
{
	//cout << "je rentre" << endl;
	int i = 0, j=0;
	bool found = false;
	while (i < m_nb_neighb && found==false)
	{
		if (m_neighb[i] == c) found = true;
		i += 1;
	}
	if (found == false)
	{
		m_nb_neighb += 1;
		Cell **tab_inter= new Cell *[m_nb_neighb];   // création d'un nouveau tableau
		for (j==0; j<m_nb_neighb-1; j++) tab_inter[j] = m_neighb[j];
		delete [] m_neighb;
		tab_inter[m_nb_neighb-1] = c;
		m_neighb = tab_inter;
		c->add_neighb(this);
	}
}

/*void Cell::add_neighb(Cell *c1, Cell *c2)
{
	add_neighb(c1);
	add_neighb(c2);
}*/
