#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED

#include <iostream>
class date
{
public:
    date() {};
    date(int y,int m,int r);
    date(date &d);
    ~date();
    void get_date();
    void out_date();
private:
    int year;
    int month;
    int ri;
};

class People
{
public:
    People() {};
    People(char *na,char *nu,char *s,int y,int m,int r,char *i);
    People(People &p);
    ~People();
    void get_People();
    void out_People();
private:
    char name[11];//����
    char number[7];//���
    char sex[3];//�Ա�
    date birthday;//��������
    char id[16];//���֤��
};

#endif // PEOPLE_H_INCLUDED
