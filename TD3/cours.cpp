#include <iostream>
#include <math.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

enum Direction { TRIBORD, BABORD };

struct Position
{
	double x, y, z;
};

int T[3] = {5, 10, 15};
char voyelle[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
int M[2][3] = {{1, 2, 3}, {4, 5, 6}};
// ou : int M[2][3] = {1, 2, 3, 3, 4, 5}

int main()
{
	cout << BABORD << endl;
	cout << TRIBORD << endl;
	Position p;
	p.x = 2.;
	p.y = 1.;
	p.z = 8.;
	cout << p.z << endl;
	cout << T[0] << endl;
	cout << M[0][0] << endl;

	return 0;
}