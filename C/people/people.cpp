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
    cout<<"date析构完成";
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
    cout<<"请输入姓名："<<endl;
    cin>>name;
    cout<<"请输入编号："<<endl;
    cin>>number;
    cout<<"请输入性别：(m 男性 wm 女性)"<<endl;
    cin>>sex;
    cout<<"请输入出生日期："<<endl;
    birthday.get_date();
    cout<<"请输入身份证号:"<<endl;
    cin>>id;
}
void People::out_People()
{
    cout<<"姓名为:"<<name<<endl;
    cout<<"编号为："<<number<<endl;
    cout<<"性别为："<<sex<<endl;
    cout<<"出生日期为："<<endl;
    birthday.out_date();
    cout<<"身份证号为："<<id<<endl;
}
People::~People()
{
    cout<<"People类析构完成"<<endl;
}
