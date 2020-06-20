#ifndef A+B_H_INCLUDED
#define A+B_H_INCLUDED
using namespace std;
#include<string>

class Employee{
private:
    string name;
    string addres;
    string city;
    string  number;
public:
    Employee(string xname,string xaddress,string xcity,string xnumber);
    void show();
    void change_name(char *new_name);
};
#endif // A+B_H_INCLUDED
