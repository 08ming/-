#include <iostream>
#include"client.h"
#include"client.cpp"
using namespace std;


int main()
{
    CLIENT one(10);
    CLIENT two(13);
    one.showPrice();
    two.showPrice();
    char name;
    CLIENT::showServerName();
    cout<<"change the serverName :";
    cin>>name;
    CLIENT::ChangeServerName(name);
    CLIENT::showServerName();
    cout<<" the average price = "<<CLIENT::AVE_PRICE()<<endl;
    CLIENT::showClientNum();
}
