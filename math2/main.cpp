#include "log.h"
#include "bar.h"

int main() {
	log("addition of 5 and 7 is ",add(5,7));
	vec2d vec1(1, 2);
	vec2d vec2(3, 4);
	log("norm of vector(1,2)", vec1.determinant());
	log("dot product of vector(1,2),vector(3,4)", vec2d::dotprod(vec1, vec2));
	log("cross product of vector(1,2),vector(3,4)", (float)(vec1^vec2));
	log("angle between vector(1,2), vector (3,4) is", vec2d::anglebet(vec1, vec2)); 
	log("normalize vector (3,4)", 0);
	std::cout << *(vec2+vec1);
	std::cin.get();
}
