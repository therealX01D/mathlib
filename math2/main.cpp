#include "pch.h"
#include "log.h"
#include "bar.h"


int main() {
	log("addition of 5 and 7 is ",add(5,7));
	//creation of a vector of two elements 
	vec2d vec1(1, 2);
	vec2d vec2(3, 4);
	//finding determinant of vector
	log("norm of vector(1,2)", vec1.determinant());
	log("dot product of vector(1,2),vector(3,4)", vec2d::dotprod(vec1, vec2));
	log("cross product of vector(1,2),vector(3,4)", (float)(vec1^vec2));
	log("angle between vector(1,2), vector (3,4) is", vec2d::anglebet(vec1, vec2)); 
	log("normalize vector (3,4)", 0);
	std::cout << *(vec2+vec1);

	// in order for the multiplying between two matrices to occur 
	//mat1 must have higher number of rows then mat2 and lower number of columns
	int  multi[3][2];
	//creation of a dummy matrix
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
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
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
				multi1[i][j] = j;
		}
	}

	matrix mat2((int*)multi1, SIZE_ROW(multi1), SIZE_COL(multi1));
	int multi2[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			multi2[i][j] = j + i;
		}
	}

	matrix mat3((int*)multi2, SIZE_ROW(multi2), SIZE_COL(multi2));
	std::cout << mat1;
	std::cout << mat2;
	std::cout << mat3;
	//summation 
	//std::cout << *(mat1 + mat2);
	std::cout << "determinant of mat1\t" << matrix::determinant(mat3) << "\n";
	std::cout <<"multiplication between mat1, mat2 \n"<< *(matrix::multipl(mat1, mat2));
	

	std::cin.get();
}
