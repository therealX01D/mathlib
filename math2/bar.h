#pragma once
#include <cmath>
#include "bar.h"
#include "log.h"
#define PI 3.1415926
int pwr(int no, char pwr);
int add(int st, int sond);
class vec2d {
private:
	float m_x, m_y;
public:
	vec2d(){}
	vec2d(float x, float y)
		:m_x(x), m_y(y)
	{}
	vec2d(const vec2d& vec) {
		log("copied", 0);
	}
	float determinant() {
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
	int** m_matrix;
	int* m_o_matrix;
	int m_len[2];
public:

	matrix(int ** i_matrix,int rw_len,int col_len):
	    m_matrix(i_matrix),
		m_len{ rw_len,col_len }
	{

	}
	void fold() {
	for(int i=0;i<sizeof(m_matrix[m_len[0]])- )
	}
	int* get() {
	
	}
	~matrix() {
	}
};