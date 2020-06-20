#include<iostream>
#include<algorithm>
#include<string>
#include"a+b.h"
using namespace std;
Employee::Employee(string xname,string xaddress,string xcity,string xnumber){
    name=xname;
    addres=xaddress;
    city=xcity;
    number=xnumber;
};
void Employee::show(){
    cout<<"name: "<<name<<endl;
    cout<<"addres: "<<addres<<endl;
    cout<<"city: "<<city<<endl;
    cout<<"number: "<<number<<endl;
};
