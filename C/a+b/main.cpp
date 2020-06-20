#include<iostream>
#include<algorithm>
#include"a+b.h"
#include"a+b.cpp"
using namespace std;

int main(){
    string name,address,city,number;
    cin>>name>>address>>city>>number;
    Employee my(name,address,city,number);
    return 0;
}
