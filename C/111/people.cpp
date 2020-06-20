#include"people.h"
#include<string.h>
#include<iostream>
using namespace std;
people::people(char *myname,char *mynumber,char *myID,char *mysex){
    strcpy(name,myname);
    strcpy(number,mynumber);
    strcpy(ID,myID);
    strcpy(sex,mysex);
    cout<<"people 构造函数调用"<<endl;
}
people::people(people &p){
   strcpy(name,p.name);
   strcpy(ID,p.ID);
   strcpy(number,p.number);
   strcpy(sex,p.sex);
}
