#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Figure
{
private:
  string m_name;

protected:
  string Name() const;

public:
  Figure(string name = "");
  virtual ~Figure() {}
  virtual float Area() const = 0;
  virtual float Perimeter() const = 0;
  virtual void Info() const = 0;
};
