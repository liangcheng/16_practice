// design a point class

#include <iostream>
using namespace std;

class Point2D
{
private:
    double _x;
    double _y;

public:
    // Constructor uses default arguments to allow calling with zero, one,
    // or two values.
    Point2D(double x=0., double y=0.)
    {
        _x = x;
        _y = y;
    }
    ~Point2D(){};

    //copy  constructor by reference
    Point2D(const Point2D& p):_x(p._x),_y(p._y){};


    const Point2D& operator=(const Point2D& p)
    {
        if (this != &p)
        {
            _x = p._x;
            _y = p._y;
        }
        return *this;
    }; // point to point assignment

    const Point2D& operator+=(const Point2D& a)
    {
        _x = _x + a.x();
        _y = _y + a.y();
        return *this;
    }; // adding a point to current point

    const Point2D& operator-=(const Point2D& a)
    {
        _x = _x - a.x();
        _y = _y - a.y();
        return *this;
    }; // substrcting a point from current point

    const Point2D& operator*=(const Point2D& a)
    {
        _x = _x * a.x();
        _y = _y * a.y();
        return *this;
    }; // multiphya point by current point


    double x() const
    {
        return _x;
    };
    double y() const
    {
        return _y;
    };
};

    // operators
    double operator&&(const Point2D& a, const Point2D& b)
    {
        return a.x()*b.y() - a.y()*b.x();
    }; //vector product

    const Point2D operator+(const Point2D&a, const Point2D &b)
    {
        return Point2D(a.x()+b.x(), a.y()+b.y());
    };//P=W+Q

    const Point2D operator-(const Point2D&a, const Point2D &b)
    {
        return Point2D(a.x()-b.x(), a.y()-b.y());
    };//P=W-Q


main()
{
    // Some points.
    Point2D a(5.2, -4.8);
    Point2D b(3.0, 9.0);
    Point2D c(-3.38);
    Point2D d;

// test copy constructor
//    cout<< d.x() <<" "<< d.y()<<" -> ";
//    d = a;
//    cout<< d.x()<<" "<< d.y()<<"\n";

// test point to point assignment
//    cout<< b.x() <<" "<< b.y()<<" | "<< d.x() <<" "<< d.y()<<" -> ";
//    d = b = a;
//    cout<< b.x()<<" "<< b.y()<<" | "<< d.x() <<" "<< d.y()<<"\n";

    d = a+b;
    cout<< d.x() <<" "<< d.y() <<"\n";



    return 0;
}

