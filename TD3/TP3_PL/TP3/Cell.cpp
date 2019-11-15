#include <math.h>
#include <list>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include <unistd.h>
#include "Cell.h"
using namespace std ;




void Cell::add_neighb(Cell *c){
	bool test = false;  // test si c est dans m_neighb
	for (int i=0; i<m_nb_neighb; i++){

		if (m_neighb[i]==c){
			test=true;
		}	
	}


	if (test=false){
		m_nb_neighb+=1;
		Cell **tab_inter= new Cell* [m_nb_neighb];   // création d'un nouveau tableau
		for (int i=0; i<m_nb_neighb-1; i++) tab_inter[i]=m_neighb[i];  
		delete [] m_neighb;
		tab_inter[m_nb_neighb-1]=c;
		m_neighb=tab_inter;
		

}

	c->add_neighb(this);   // ajout a c du voisin 

}

void Cell::add_neighb(Cell *c1, Cell *c2){

	add_neighb(Cell *c1);
	add_neighb(Cell *c2);

}