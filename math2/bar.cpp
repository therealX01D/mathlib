#include "bar.h"
#include <cmath>
#include "log.h"
int add(int st, int sond) {
	return st + sond;
}
int pwr(int no, char pwr) {
	int res = 1;
	for (char i = 0; i < pwr; i++)
	{
		res *= no;
	}
	return res;
}
class vec2d {
private:
	float m_x, m_y;
public:
	vec2d(float x,float y)
	:m_x(x),m_y(y)
	{}
	vec2d(const vec2d& vec) {
		log("copied",0);
	}
	float norm() {
		return sqrt(pwr(this->m_x, 2) + pwr(this->m_y, 2));
	}
	static float determinant(const vec2d& vec1, const vec2d& vec2) {
		return (vec1.m_x * vec2.m_y) - (vec2.m_x * vec1.m_y);
	}
    vec2d* normalize() {
		vec2d vec(this->m_x / norm(), this->m_y / norm());
		return &vec;
	}
	~vec2d() {
		m_x = 0;
		m_y = 0;
	}
};