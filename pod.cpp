#include "vector2.hpp"
#include "bbox.hpp"

#include <iostream>
#include <type_traits>

using namespace std;

#define IS_POD(X) cout << #X ": " << is_pod<X>::value << endl;

int main() {
	IS_POD(BBox);
	IS_POD(Vector2);
}