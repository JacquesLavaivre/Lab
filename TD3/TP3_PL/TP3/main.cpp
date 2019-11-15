#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>
#include "Cell.h"
using namespace std ;


int main() {
	bool m_displayed = false;
	
	void draw_gate(const Cell *n1, const Cell *n2)
	{
    vibes::drawBox(min(n1->m_x, n2->m_x) + 0.1, max(n1->m_x, n2->m_x) + 0.9,
                   min(n1->m_y, n2->m_y) + 0.1, max(n1->m_y, n2->m_y) + 0.9,
                   "lightGray[lightGray]");
	}

  	void display_cell(Cell *cell)
  	{
    vibes::drawBox(cell->m_x, cell->m_x + 1, cell->m_y, cell->m_y + 1, "[lightGray]");
    cell->m_displayed = true;
    for(int i = 0 ; i < cell->m_nb_neighb ; i++)
    {
      if(!cell->m_neighb[i]->m_displayed)
        display_cell(cell->m_neighb[i]);
      draw_gate(cell, cell->m_neighb[i]);
    }

	}



}