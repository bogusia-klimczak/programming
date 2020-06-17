#pragma once
class classlib;

typedef const classlib cclasslib;

#define M_PI_2 1.570796326794 // 0.5 * PI

class classlib {
private:
	double m_re;
	double m_im;
	int m_form;
	static int counter;

public:
	classlib();
	classlib(double re, double im);
	~classlib();
	void __show__();
	void howManyObjects();
	void changeForm(int arg);
	friend classlib operator+(cclasslib& a, cclasslib& b);
	friend classlib operator-(cclasslib& a, cclasslib& b);
	friend classlib operator*(cclasslib& a, cclasslib& b);
	friend classlib operator/(cclasslib& a, cclasslib& b);
	friend classlib operator^(cclasslib& a, const double b);
};