#include<iostream>
#define pi 3.14
using namespace std;

class Container
{
   protected:
      double radius;
   public:
      Container(double r):radius(r){};
      virtual double surface_area()=0;
      virtual double volume()=0;
};
class sphere:public Container
{
public:
    sphere(double r):Container(r){};
    double surface_area()
    {
        return 4*pi*radius*radius;
    }
    double volume()
    {
        return 4/3*pi*radius*radius*radius;
    }
};
class cylinder:public Container
{
protected:
    double hight;
public:
    cylinder(double r,double h):Container(r){
        hight=h;
    }
    double surface_area()
    {
        return pi*radius*radius*2+2*pi*radius*hight;
    }
    double volume()
    {
        return pi*radius*radius*hight;
    }
};
class cube:public Container
{
public:
    cube(double r):Container(r){};
    double surface_area()
    {
        return radius*radius*6;
    }
    double volume()
    {
        return radius*radius*radius;
    }
};
int main()
{
    sphere mysphere(5.0);
    cylinder mycylinder(5.0,6.0);
    cube mycube(6.0);
    cout<<"球体的表面积和体积："<<mysphere.surface_area()<<"  ,  "<<mysphere.volume()<<endl;
    cout<<"圆柱体的表面积和体积："<<mycylinder.surface_area()<<"  ,  "<<mycylinder.volume()<<endl;
    cout<<"正方体的表面积和体积："<<mycube.surface_area()<<"  ,  "<<mycube.volume()<<endl;
    return 0;
}
