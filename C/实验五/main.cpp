#include<iostream>
#include<algorithm>
#include"employee.h"
#include"employee.cpp"
using namespace std;

int main(){
    string name,address,city,number;
    cin>>name>>address>>city>>number;
    const Employee my(name,address,city,number);
    Employee  cp[5]=my;
    for(int i=0;i<5;i++)
        cp[i].display();
    return 0;
}
