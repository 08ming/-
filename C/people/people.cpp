#include "people.h"
#include <iostream>
#include<string.h>

using namespace std;

date::date(int y,int m,int r)
{
    year=y;
    month=m;
    ri=r;
}
date::date(date &d)
{
    this->year=d.year;
    this->month=d.month;
    this->ri=d.ri;
}
date::~date()
{
    cout<<"date�������";
}
void date::get_date()
{
    cin>>year>>month>>ri;
}
void date::out_date()
{
    cout<<year<<"."<<month<<"."<<ri<<endl;
}
People::People(char *na,char *nu,char *s,int y,int m,int r,char *i):birthday(y,m,r)
{
    int j;
    for(j=0; j<11; j++)
    {
        name[j]=na[j];
    }
    for(j=0; j<7; j++)
    {
        number[j]=nu[j];
    }
    for(j=0; j<3; j++)
    {
        sex[j]=s[j];
    }
    for(j=0; j<16; j++)
    {
        id[j]=i[j];
    }
}
People::People(People &p)
{
    /*this->name=p.name;
    this->number=number;
    this->sex=p.sex;
    this->birthday=p.birthday;
    this->id=p.id;*/
    strcpy(name,p.name);
    strcpy(number,p.number);
    strcpy(id,p.id);
    strcpy(sex,p.sex);
    birthday=p.birthday;
}
void People::get_People()
{
    cout<<"������������"<<endl;
    cin>>name;
    cout<<"�������ţ�"<<endl;
    cin>>number;
    cout<<"�������Ա�(m ���� wm Ů��)"<<endl;
    cin>>sex;
    cout<<"������������ڣ�"<<endl;
    birthday.get_date();
    cout<<"���������֤��:"<<endl;
    cin>>id;
}
void People::out_People()
{
    cout<<"����Ϊ:"<<name<<endl;
    cout<<"���Ϊ��"<<number<<endl;
    cout<<"�Ա�Ϊ��"<<sex<<endl;
    cout<<"��������Ϊ��"<<endl;
    birthday.out_date();
    cout<<"���֤��Ϊ��"<<id<<endl;
}
People::~People()
{
    cout<<"People���������"<<endl;
}
