#pragma once

#include "pch.h"
#include "log.h"

#define PI 3.1415926

#define SIZE_ROW(multi) (sizeof multi / sizeof multi[0] )
#define SIZE_COL(multi) (sizeof multi[0] / sizeof (int) )

//#define SIZE_MUL(multi) (SIZE_ROW(multi),SIZE_COL(multi))
int pwr(int no, char pwr);
int add(int st, int sond);

class vec2d {
private:
	float m_x, m_y;
public:
	vec2d():
		m_x(0),
		m_y(0)
	{}
	vec2d(float x, float y)
		:m_x(x),
		m_y(y)
	{}
	vec2d(const vec2d& vec)
		:
		m_x(vec.m_x),
		m_y(vec.m_y)
	{
		log("copied", 0);
	}
	float virtual determinant() {
		return sqrt(pwr(this->m_x, 2) + pwr(this->m_y, 2));
	}
	
	std::unique_ptr<vec2d> normalize() {
		return std::make_unique<vec2d>(this->m_x / this->determinant(), this->m_y / this->determinant());
	}
	static float dotprod( const vec2d& vec1, const vec2d& vec2) {
		return (vec1.m_x * vec2.m_y) + (vec2.m_x * vec1.m_y);
	}
	static float* crossprod(const vec2d& vec1, const vec2d& vec2) {
		float d=(vec1.m_x * vec2.m_y) - (vec2.m_x * vec1.m_y);
		return &d;
	} 
	static float anglebet(vec2d& const vec1, vec2d& const vec2) {
		return (acosf((abs(dotprod(vec1, vec2))) / (vec1.determinant() * vec2.determinant())))*180/PI;
	}
	friend std::unique_ptr<vec2d> operator+(const vec2d& vec1, const vec2d& vec2) {
		return std::make_unique<vec2d>(vec1.m_x + vec2.m_x, vec1.m_y + vec2.m_y);
	}
	friend float operator^(const vec2d& vec1, const vec2d& vec2) {
		return *crossprod(vec1, vec2);
	}
	friend std::ostream& operator<<(std::ostream& stream, const vec2d& vec) {
		stream << "the coordinates are " << vec.m_x << "," << vec.m_y << "\n";
		return stream;
	}
	~vec2d() {
		m_x = 0;
		m_y = 0;
	}
};
class matrix :public vec2d {
private:
	std::vector <int> m_matrix;
	int m_len[2];
	int size;
	std::vector<int> m_matrix_copy;
	std::vector<int> coeff;
public:
	
	matrix() {}
	matrix(int* i_matrix, int rw_len, int col_len) :
		m_matrix(std::vector<int>(i_matrix, i_matrix +rw_len*col_len)),
		m_matrix_copy(std::vector<int>(i_matrix, i_matrix + rw_len*col_len)),
		m_len{rw_len,col_len},
		size(rw_len*col_len)
	{
		
		coeff.reserve(rw_len);
	}
  
	friend std::unique_ptr<matrix> operator+(const matrix& mat1,const matrix& mat2) {
		if (mat1.m_len[0] * mat1.m_len[1] == mat2.m_len[0] * mat2.m_len[1])
		{ 
			
			for (int i = 0; i < mat1.size; i++)
			{
				const_cast<matrix&>(mat1).m_matrix_copy.emplace_back((mat1.m_matrix[i] + mat2.m_matrix[i]));
			}
			return std::make_unique<matrix>((int*)mat1.m_matrix_copy.data(), mat1.m_len[0], mat1.m_len[1]);
		}
		else {
			return nullptr;
		}
	}
	//todo 
	std::unique_ptr<matrix> transbose() {}
	static float determinant(const matrix& mat)  {
		int sum =0;
			for (int i : mat.m_matrix_copy)
			{
				auto index = std::distance(mat.m_matrix_copy.begin(), find(mat.m_matrix_copy.begin(), mat.m_matrix_copy.end(), i));
					//removed rows
				const_cast<matrix&>(mat).m_matrix_copy.erase(mat.m_matrix_copy.begin(), mat.m_matrix_copy.begin() + mat.m_len[0]);
				sum+= pow(-1, index) * i;
				const_cast<matrix&>(mat).coeff.emplace_back(sum);
				sum = 0;
				for (int j = 0; j < sqrt(mat.m_matrix_copy.size()) - 1; j++)
				{
					const_cast<matrix&>(mat).m_matrix_copy.erase(const_cast<matrix&>(mat).m_matrix_copy.begin() + j * (sqrt(mat.m_matrix_copy.size())-1));
				}
				if (mat.m_matrix_copy.size() < mat.m_len[0]) break;
			}
			for (int v : mat.coeff)
			{
				sum += v;
			}
			return sum * mat.m_matrix_copy[0];

	}
	//endtodo
	static std::unique_ptr<matrix> multipl(const matrix& mat1, const matrix& mat2) {
		int sum = 0;

		const_cast<matrix&>(mat1).m_matrix_copy = {};
		if (mat1.m_len[1] == mat2.m_len[0])
		{
			for (int i = 0; i <= mat2.m_len[0]; i++)
			{
				for  (int j = 0;  j < mat1.m_len[1];  j++)
				{
					sum += mat1.m_matrix[i+j*mat1.m_len[1]] * mat2.m_matrix[j];
				}
				const_cast<matrix&>(mat1).m_matrix_copy.emplace_back(sum);
				sum = 0;
			}
		}
		else {
			const_cast<matrix&>(mat1).m_matrix_copy = {-1};
		}
		return std::make_unique<matrix>((int*)mat1.m_matrix_copy.data(), mat1.m_len[0], mat2.m_len[1]);
	}
	friend std::ostream& operator<<(std::ostream& stream, const matrix& mat) {
		for  (int i = 0;  i < mat.m_len[1];  i++)
		{
			for (int j = 0; j < mat.m_len[0]; j++)
			{
				stream << mat.m_matrix[j]<<" , ";
			}
			stream << "\n";
		}
		return stream;
	}
	~matrix() {
		m_matrix_copy = { 0 };
		
	}
};