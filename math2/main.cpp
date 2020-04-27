#include "log.h"
#include "bar.h"

int main() {
	log("addition of 5 and 7 is ",add(5,7));
	vec2d vec1(1, 2);
	vec2d vec2(3, 4);
	log("norm of vector(1,2)", vec1.norm());
	log("determinant of vector(1,2),vector(3,4)", vec2d::determinant(vec1, vec2));
	std::cin.get();
}
