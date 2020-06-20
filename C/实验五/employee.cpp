#include<iostream>
#include<algorithm>
#include<string>
#include"employee.h"
using namespace std;
Employee::Employee(string xname,string xaddress,string xcity,string xnumber){
    name=xname;
    address=xaddress;
    city=xcity;
    number=xnumber;
};
Employee::Employee(Employee &p1){
    name=p1.name;
    address=p1.address;
    city=p1.city;
    number=p1.number;
};
void Employee::display(){
    cout<<"name: "<<name<<endl;
    cout<<"addres: "<<address<<endl;
    cout<<"city: "<<city<<endl;
    cout<<"number: "<<number<<endl;
    cout<<"====================="<<endl;
};
void Employee::change_name(string new_name){
    name=new_name;
}
