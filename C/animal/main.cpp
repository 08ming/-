#include <iostream>

using namespace std;
class vehicle
{
protected:
    int maxspeed,weight;
public:
    vehicle(int myspeed,int myweight)
    {
        maxspeed=myspeed;
        weight=myweight;
    }
    void run()
    {
        cout<<"the vehicle is run!"<<endl;
    }
    void stop()
    {
        cout<<"the vehicle is stop!"<<endl;
    }
};
class bicycle: public vehicle
{
protected:
   int  height;
public:
    bicycle(int a,int b,int c):vehicle(a,b),height(c){}
};
class motorcar: public vehicle
{
protected:
    int seatnum;
public:
    motorcar(int a,int b,int c):vehicle(a,b),seatnum(c){}
};
class motorcycle:public bicycle,public motorcar
{
public:
    motorcycle(int a,int b,int c,int d):vehicle(a,b),bicycle(a,b,c),motorcar(a,b,d){}
    void show()
    {
        cout<<"the maxspead is " <<maxspeed<<endl;
        cout<<"the weight is  "<<weight<<endl;
        cout<<"the height is "<<height<<endl;
        cout<<"the seatnum is "<<seatnum<<endl;
    }
};
int main()
{
    motorcycle mymoto(1,2,3,4);
    mymoto.run();
    mymoto.stop();
    mymoto.show();
    return 0;
}
