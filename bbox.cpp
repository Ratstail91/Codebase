#include "bbox.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
	if (argc != 9) {
		cerr << "Usage: " << argv[0] << " Ax Ay Aw Ah Bx By Bw Bh" << endl;
		return 1;
	}

/*
	BBox A, B;

	A.x = atof(argv[1]);
	A.y = atof(argv[2]);
	A.w = atof(argv[3]);
	A.h = atof(argv[4]);
	B.x = atof(argv[5]);
	B.y = atof(argv[6]);
	B.w = atof(argv[7]);
	B.h = atof(argv[8]);
*/
	BBox A = {atof(argv[1]),atof(argv[2]),atof(argv[3]),atof(argv[4])};
	BBox B = {atof(argv[5]),atof(argv[6]),atof(argv[7]),atof(argv[8])};

	cout << "A.Size(): " << A.Size() << endl;
	cout << "B.Size(): " << B.Size() << endl;

	cout << "Collision: " << (A.IsCollision(B) ? "true" : "false") << endl;

	BBox I = A.Intersect(B);

	cout << "Ix:" << I.x << endl;
	cout << "Iy:" << I.y << endl;
	cout << "Iw:" << I.w << endl;
	cout << "Ih:" << I.h << endl;
	cout << "I.Size(): " << I.Size() << endl;

	return 0;
}
