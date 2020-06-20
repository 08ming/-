
#include<iostream>

using namespace std;

class A

{

 int p1,p2;

public:

 A(int a,int b) { p1=a; p2=b; }

 int Move1() { return ++p1; }

 int Move2() { return ++p2; }

 void Show() { cout<<"p1="<<p1<<",p2="<<p2<<endl; }

};



class B: virtual private A

{

 int p3;

public:

 B(int a, int b, int c): A(a,b) { p3=c; }

 int Move1() { return A::Move1(); }

 int Move3() { return ++p3; }

 void Show() { A::Show(); cout<<"p3="<<p3<<endl; }

};



class C: virtual public A

{

 int p4;

public:

 C(int a, int b, int c):A(a,b) { p4=c; }

 int Move1() { A::Move1(); A::Move2(); return A::Move1(); }

 int Move4() { return ++p4; }

 void Show() { A::Show(); cout<<"p4="<<p4<<endl; }

};



class D: private B, public C

{

 int p5;

public:

 D(int a, int b, int c, int d, int e, int f, int g):A(a,b), B(a,b,c),C(d,e,f) { p5=g; }

 int Move1() { C::Move1(); return C::Move1(); }

 int Move5() { return ++p5; }

 void Show() { C::Show(); cout<<"p5="<<p5<<endl; }

};



int main()

{

 D dd(10,20,30,40,50,60,70);

 dd.Show();

 dd.Move1();

 dd.Move4();

 dd.Move5();

 dd.Show();
return 0;
}
