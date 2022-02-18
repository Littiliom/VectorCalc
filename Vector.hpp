#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#include <iostream>
#include <cmath>
using std::endl;
using std::cout;
using std::cin;

class Vector
{
    double PI;
    double x, y, magnitude, angle;
public:
    Vector();
    Vector(double, double);
    friend std::ostream& operator<<(std::ostream&, const Vector&);
    friend std::istream& operator>>(std::istream&, Vector&);

    double PrintDistance(const Vector&);
    void PrintInfo();
    void PrintInfoTest();
    void magnUpdate();
    void EnterAsPolar();

    double GetMagnitude() const;
    void PrintMagnDiference(const Vector&) const;

    Vector Add(const Vector&) const;
    Vector Sub(const Vector&) const;
    Vector Mul(const Vector&) const;
    Vector Div(const Vector&) const;
    Vector Mul(double) const;
    Vector Div(double) const;
    Vector operator/(const Vector&) const;
    Vector operator*(const Vector&) const;
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
};

#endif //VECTOR_HPP_
