#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

using namespace std;
#include<string>

class Employee{
private:
    string name;
    string address;
    string city;
    string  number;
public:
    Employee(string xname,string xaddress,string xcity,string xnumber);
    Employee(Employee &p1);
    void display();
    void change_name(string new_name);
};

#endif // EMPLOYEE_H_INCLUDED
