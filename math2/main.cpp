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
	//mat1 must have higher number of rows then mat2 and lower number of columns
	int  multi[3][2];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 6; j++) {
			if (j%2==0)
			{
				multi[i][j] = 7;
			}
			else {
				multi[i][j] = 5;
			}
		}
	}
	//multi[6][5] = 51;
	matrix mat1((int*)multi, SIZE_ROW(multi), SIZE_COL(multi));
	int multi1[2][3];
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
				multi1[i][j] = j;
		}
	}

	matrix mat2((int*)multi1, SIZE_ROW(multi1), SIZE_COL(multi1));
	std::cout << mat1;
	std::cout << mat2;
	
	//std::cout << *(mat1 + mat2);
	std::cout <<"multiplication"<< *(matrix::multipl(mat1, mat2));
	std::cout << mat1;

	std::cin.get();
}
