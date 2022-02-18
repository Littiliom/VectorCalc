#include "Vector.hpp"

Vector::Vector()
    : x(0.0), y(0.0)
    , magnitude(0.0), angle(0.0)
{
    PI = atan(1) * 4;
}

Vector::Vector(double argX, double argY)
    : x(argX)
    , y(argY)
    , magnitude(0)
    , angle(0)
{
    PI = atan(1) * 4;
    magnUpdate();
}


void Vector::PrintMagnDiference(const Vector& other) const
{
    std::cout << "||" << *this << "|| - ||" << other << "|| == ";
    std::cout << magnitude - other.GetMagnitude() << std::endl;
}


void Vector::EnterAsPolar()
{
    double l_theta, l_magn;
    std::cout << "Enter angle (degrees): ";
    std::cin >> l_theta;
    std::cout << "Enter magnitude: ";
    std::cin >> l_magn;
    double PI = atan(1) * 4.0;
    angle = l_theta * PI / 180.0;
    magnitude = l_magn;
    x = magnitude * cos(angle);
    y = magnitude * sin(angle);
}

std::ostream& operator<<(std::ostream& out, const Vector& data)
{
    out << "(" << data.x << ", " << data.y << ")";

    return out;
}

double Vector::GetMagnitude() const
{
    return magnitude;
}

void Vector::magnUpdate()
{
    double PI_L = atan(1) * 4;
    magnitude = sqrt(x * x + y * y);

    angle = atan2(y, x);
    if (angle < 0)
        angle = 2 * PI_L + angle;
    /*
    if(x==0 && y==0)
    {
        angle = 0;
        cout << "A";
        return;
    }
    if((x == 0 || y == 0) && !(x==0 && y==0))
    {
        if(x == 0)
        {
            if(y > 0)
                angle = PI/2;
            else if (y < 0)
                angle = 3*PI/2;
        } else
        {
            if(x < 0)
                angle = PI;
            if (x > 0)
                angle = 0;
        }
        cout << "BBB";
        return;
    }


    angle = atan2(abs(y), abs(x)); // first quadrant

    if(x  < 0.0 && y > 0.0) ///Second quadrant
        angle = PI_L-angle;
    else if( x < 0.0 && y < 0.0)///third quadrant
        angle = PI_L+angle;
    else if( x > 0.0 && y < 0.0)///fourth quadrant
    {
        cout << angle << endl;
        angle = 2*PI - angle;

    }
//*/
}

std::istream& operator>>(std::istream& in, Vector& data)
{
    double x, y;
    cout << "Enter x: ";
    in >> x;
    cout << "Enter y: ";
    in >> y;

    data.y = y;
    data.x = x;
    data.magnUpdate();
    return in;
}

double Vector::PrintDistance(const Vector& arg)
{
    double c_squared = (x - arg.x) * (x - arg.x) + (y - arg.y) * (y - arg.y);
    double out = sqrt(c_squared);
    cout << "Distance between " << *this << " and " << arg;
    cout << " is " << out << endl;
    cout << "\t\t\t::: sqrt(" << c_squared << ") \n";
    return out;
}

void Vector::PrintInfo()
{
    cout << *this << "   magnitude sqrt(" << magnitude * magnitude
        << ") == " << magnitude << endl;
    cout << "angle: " << angle << " degrees: " << 180.0 * angle / PI << endl;
}

void Vector::PrintInfoTest()
{
    std::cout << "\nBefore magnUpdate:\n";
    PrintInfo();
    magnUpdate();
    std::cout << "\nAfter magnUpdate:\n";
    PrintInfo();
}

Vector Vector::Add(const Vector& other) const
{
    return Vector(x + other.x, y + other.y);
}
Vector Vector::Sub(const Vector& other) const
{
    return Vector(x - other.x, y - other.y);
}
Vector Vector::Mul(const Vector& other) const
{
    return Vector(x * other.x, y * other.y);
}
Vector Vector::Div(const Vector& other) const
{
    return Vector(x / other.x, y / other.y);
}
Vector Vector::operator/(const Vector& other) const
{
    return Div(other);
}
Vector Vector::operator*(const Vector& other) const
{
    return Mul(other);
}
Vector Vector::operator+(const Vector& other) const
{
    return Add(other);
}
Vector Vector::operator-(const Vector& other) const
{
    return Sub(other);
}
Vector Vector::Mul(double arg) const
{
    return Vector(arg * x, arg * y);
}
Vector Vector::Div(double arg) const
{
    return Vector(x / arg, y / arg);
}
