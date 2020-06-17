#include <iostream> 
#include <math.h>
#include "classlib.h"

using namespace std;

int classlib::counter = 0;

classlib::classlib() {
	m_re = 0;
	m_im = 0;
	m_form = 0;
	classlib::counter++;
}

classlib::classlib(double re = 0, double im = 0) {
	m_re = re;
	m_im = im;
	m_form = 0;
	classlib::counter++;
}

classlib::~classlib() {
	classlib::counter--;
}

void classlib::__show__() {
	if (m_form == 0) {
		cout << "(" << m_re << ", " << m_im << ")" << endl;
		return;
	}
	else if (m_form == 1) {
		if (m_re < 0 && m_im < 0) {
			if (m_im == -1) {
				cout << m_re << " - i" << endl;
			}
			else {
				cout << m_re << " - " << abs(m_im) << "i" << endl;
			}
		}
		else if (m_re < 0 && m_im == 0) {
			cout << m_re << endl;
		}
		else if (m_re < 0 && m_im > 0) {
			if (m_im == 1) {
				cout << m_re << " + i" << endl;
			}
			else {
				cout << m_re << " + " << m_im << "i" << endl;
			}
		}
		else if (m_re == 0 && m_im < 0) {
			if (m_im == -1) {
				cout << "-i" << endl;
			}
			else {
				cout << m_im << "i" << endl;
			}
		}
		else if (m_re == 0 && m_im == 0) {
			cout << m_re << endl;
		}
		else if (m_re == 0 && m_im > 0) {
			if (m_im == 1) {
				cout << "i" << endl;
			}
			else {
				cout << m_im << "i" << endl;
			}
		}
		else if (m_re > 0 && m_im < 0) {
			if (m_im == -1) {
				cout << m_re << " - i" << endl;
			}
			else {
				cout << m_re << " - " << abs(m_im) << "i" << endl;
			}
		}
		else if (m_re > 0 && m_im == 0) {
			cout << m_re << endl;
		}
		else if (m_re > 0 && m_im > 0) {
			if (m_im == 1) {
				cout << m_re << " + i" << endl;
			}
			else {
				cout << m_re << " + " << m_im << "i" << endl;
			}
		}
		return;
	}
	else if (m_form == 2) {
		double f = 0.0;
		double r = sqrt(m_re * m_re + m_im * m_im);
		if (m_re == 0) {
			if (m_im < 0) {
				f = -M_PI_2;
			}
			else {
				f = M_PI_2;
			}
		}
		else {
			f = atan(m_im / m_re);
		}
		cout << r << "(cos" << f << " + i * sin" << f << ")" << endl;
	}
	else if (m_form == 3) {
		double f = 0.0;
		double r = sqrt(m_re * m_re + m_im * m_im);
		if (m_re == 0) {
			if (m_im < 0) {
				f = -M_PI_2;
			}
			else {
				f = M_PI_2;
			}
		}
		else {
			f = atan(m_im / m_re);
		}
		cout << r << "e^(i * " << f << ")" << endl;
	}

}

void classlib::howManyObjects() {
	cout << "Count of object - " << classlib::counter << endl;
}

void classlib::changeForm(int arg) {
	string name_of_form;
	if (arg == 0) {
		m_form = 0;
		name_of_form = "COMPLEX";

	}
	else if (arg == 1) {
		m_form = 1;
		name_of_form = "ALGEBRAIC";
	}
	else if (arg == 2) {
		m_form = 2;
		name_of_form = "TRIGONOMETRIC";
	}
	else if (arg == 3) {
		m_form = 3;
		name_of_form = "EXPONENTIAL";
	}
	else {
		cout << "ERROR: wrong argument for function" << endl;
		return;
	}
	cout << "You have chosen option: " << m_form << ". It is " << name_of_form << " form." << endl;
}

classlib operator+(cclasslib& a, cclasslib& b) {
	return classlib(a.m_re + b.m_re, a.m_im + b.m_im);
}

classlib operator-(cclasslib& a, cclasslib& b) {
	return classlib(a.m_re - b.m_re, a.m_im - b.m_im);
}

classlib operator*(cclasslib& a, cclasslib& b) {
	return classlib(a.m_re * b.m_re - a.m_im * b.m_im, a.m_re * b.m_im + a.m_im * b.m_re);
}

classlib operator/(cclasslib& a, cclasslib& b) {
	double x = ((a.m_re * b.m_re) + (a.m_im * b.m_im)) / (pow(b.m_re, 2) + pow(b.m_im, 2));
	double y = ((a.m_im * b.m_re) + (a.m_re * b.m_im)) / (pow(b.m_re, 2) + pow(b.m_im, 2));
	return classlib(x, y);
}

classlib operator^(cclasslib& a, const double b) {
	double r = pow(pow(a.m_re, 2) + pow(a.m_im, 2), 0.5);
	double f = 0.0;
	if (a.m_re == 0) {
		if (a.m_im < 0) {
			f = -M_PI_2;
		}
		else {
			f = M_PI_2;
		}
	}
	else {
		f = atan(a.m_im / a.m_re);
	}
	double x = pow(r, b) * floor(cos(b * f));
	double y = pow(r, b) * floor(sin(b * f));
	return classlib(x, y);
}