#include <iostream>
using namespace std;
#include"client.h"
char CLIENT::ServerName='L';
int  CLIENT::ClientNum=0;
int  CLIENT::AveNum=0;
CLIENT::CLIENT(int MYprice){
    price=MYprice;
    ClientNum++;
    AveNum+=price;
}
void CLIENT::ChangeServerName(char newServerName){
    ServerName=newServerName;
}
CLIENT::CLIENT(CLIENT &p) {
    price=p.price;
    ClientNum++;
}
CLIENT::~CLIENT(){ClientNum--;}
void CLIENT::showClientNum(){
    cout<< " the object number ="<<ClientNum<<endl;
}
void CLIENT::showServerName(){
    cout<< " the object ServerName ="<<ServerName<<endl;
}
float CLIENT::AVE_PRICE(){
    return  (float)AveNum/ClientNum;
}
void CLIENT::showPrice(){
    cout<<"the price is :"<<price<<endl;
}
