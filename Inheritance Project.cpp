#include <iostream>
using namespace std;
class Shape
{
  private:
  string name;
public:
Shape() { name = "Shape";}
Shape(string n){name = n;}
void setName(string n){name = n;}
string getName(){return name;}
virtual double calcarea() = 0; //pure virtual

/*
virtual double calcarea()   //virtual
{ return 0; }
*/

virtual double calcperimeter() = 0;
virtual double calcvolume(){return 0;}
};

class Square : public Shape
{
private:
double side;
public:
Square() :Shape("Square") { side = 1; }
Square(double s) :Shape("Square") { side = s; }
void setSide(double s) { side = s; }
double getSide() { return side; }
double calcarea() override { return side * side; }
double calcperimeter() override {return side + side + side + side;}
};

class Circle : public Shape
{
private:
double radius;
public:
Circle() :Shape("Circle") { radius = 1; }
Circle(double r) :Shape("Circle") { radius = r; ; }
Circle(double r, string n) :Shape(n) { radius = r; }
void setRadius(double r) { radius = r; }
double getRadius() { return radius; }
double calcarea(){return 3.14 * (radius * radius);}
double calcperimeter(){return 3.14 * 2 * radius;}
};

class Cube : public Shape
{
private:
double height;
public:
Cube() : Shape("Cube") { height = 0; }
Cube(double h) : Shape("Cube") { height = h; }
void setHeight(double h) { height = h; }
double getHeight() { return height; }
double calcarea(){return (height * height) * 6;}
double calcvolume(){return height * height * height;}
double calcperimeter(){return 6 * (height * height);}
};

class Cylinder : public Shape
{
private:
double height;
double radius;
public:
Cylinder() : Shape("Cylinder") { height = 0, radius = 0; }
Cylinder(double h, double r) : Shape("Cylinder") { height = h, radius = r; }
void setRadius(double r) { radius = r; }
double getRadius() { return radius; }
void setHeight(double h) { height = h; }
double getHeight() { return height; }
double calcarea() override{ return (2 * 3.14 * radius * height) + (2 * 3.14 * (radius * radius));}
double calcvolume() override{ return 3.14 * (radius * radius) * height;}
double calcperimeter(){ return (2 * (radius * 2)) + (2 * height);}
};

class Sphere : public Circle
{
public:
double radius;
Sphere() : Circle(1, "Sphere") { };
Sphere(double r) { radius = r; }
double calcarea() override { return 4 * 3.14 * (radius * radius);}
double calcvolume() override { return (4 / 3) * 3.14 * (radius * radius * radius);}
};

int main()
{
  /* Part 1
  Shape* shapepointer[5];
  shapepointer[0] = new Shape();
  shapepointer[1] = new Square(3);
  shapepointer[2] = new Circle(2);
  shapepointer[3] = new Circle(7);
  shapepointer[4] = new Square(5);
  for (int i = 0; i <= 5; i++)
  {
    cout << shapepointer[i]->getName() << ": " << shapepointer[i]->calcarea() << endl;
  }
  for (int i = 0; i <= 5; i++)
  {
    cout << shapepointer[i]->getName() << ": Area: " << shapepointer[i]->calcarea() << " Perimeter: " << endl;
  }
  */
  
  // Part 2
  Shape* shapepointer[5];
  shapepointer[0] = new Circle(5);
  shapepointer[1] = new Cube(3);
  shapepointer[2] = new Cylinder(5, 2);
  shapepointer[3] = new Square(4);
  shapepointer[4] = new Cylinder(2, 4);
  for (int i = 0; i <= 5; i++)
  {
    cout << shapepointer[i]->getName() << " --> Area: " << shapepointer[i]->calcarea() << ", Perimeter: " << shapepointer[i]->calcperimeter()
    << ", Volume: " << shapepointer[i]->calcvolume() << endl;
  }
}
