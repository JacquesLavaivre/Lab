#ifndef __Cell_H__
#define __Cell_H__



#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>



using namespace std ;

class Cell {
public:
	Cell(int x, int y);
	int m_nb_neighb = 0;
	Cell **m_neighb = NULL;
	void add_neighb(Cell *c);
	void Cadd_neighb(Cell *c1, Cell *c2);



};

#endif;
