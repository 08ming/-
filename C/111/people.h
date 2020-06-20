#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED
#include <string.h>
#include<iostream>
using namespace std;
class people{
protected:
    char name[11],number[7],sex[4],ID[16];
public:
    people(char *myname,char *mynumber,char *myID,char* mysex);//people构造函数
    people(people &p);
    void myshow()
    {
        cout<<" name:  "<<name<<endl<<"  number:"<<number<<endl<<"  id:"<<ID<<endl<<"  sex: "<<sex<<endl;
    };
};
class student:virtual public people
{
protected:
    char classNO[7];
public:
    student(char *myname,char *mynumber,char *myID,char* mysex,char *myclassNO):people(myname,mynumber,myID,mysex)
    {
        strcpy(classNO,myclassNO);
        cout<<"student 构造函数调用！ "<<endl;
    }
    void show()
    {
        cout<<" name:  "<<name<<endl<<"  number:"<<number<<endl<<"  id:"<<ID<<endl<<"  sex: "<<sex<<endl<<" classNO="<<classNO<<endl;
    }
};
class teacher:virtual public people
{
protected:
    char principalship[11],department[21];
public:
    teacher(char *myname,char *mynumber,char *myID,char* mysex,char *myprincipalship,char *mydepartment ):people(myname,mynumber,myID,mysex)
    {
        strcpy(principalship,myprincipalship);
        strcpy(department,mydepartment);
        cout<<"teacher 构造函数调用 "<<endl;
    }
    void show()
    {
        cout<<" name:  "<<name<<endl<<"  number:"<<number<<endl<<"  id:"<<ID<<endl<<"  sex: "<<sex<<endl<<" principalship="<<principalship<<endl<<"  department= "<<department<<endl;
    }
};
class graduate:virtual public student, virtual public teacher
{
protected:
    char subject[21];
    teacher adviser;
public:
    graduate(char *myname,char *mynumber,char *myID,char* mysex,char *myclassNO,char* mysubject,char *myprincipalship,char *mydepartment):people(myname,mynumber,myID,mysex),teacher(myname,mynumber,myID,mysex,myprincipalship,mydepartment),student(myname,mynumber,myID,mysex,myclassNO),adviser(myname,mynumber,myID,mysex,myprincipalship,mydepartment)
    {
        strcpy(subject,mysubject);
        cout<<"graduate构造函数调用  "<<endl;
    }
    void show(){
    cout<<" name:  "<<name<<endl<<"  number:"<<number<<endl<<"  id:"<<ID<<endl<<"  sex: "<<sex<<endl<<"classNO="<<classNO<<endl<<"  subject= "<<subject<<endl<<"  principalship = "<<principalship<<endl<<"  department= "<<department<<endl;
    }
};
class TA:virtual public graduate,virtual public teacher
{
public:
    TA(char *myname,char *mynumber,char *myID,char* mysex,char *myclassNO,char* mysubject,char *myprincipalship,char *mydepartment):graduate(myname,mynumber,myID,mysex,myclassNO,mysubject,myprincipalship,mydepartment),student(myname,mynumber,myID,mysex,myclassNO),people(myname,mynumber,myID,mysex),teacher(myname,mynumber,myID,mysex,myprincipalship,mydepartment)
    {cout<<"TA助教构造函数调用！"<<endl;}
    void show(){cout<<" name:  "<<name<<endl<<"  number:"<<number<<endl<<"  id:"<<ID<<endl<<"  sex: "<<sex<<endl<<"classNO="<<classNO<<endl<<"  subject= "<<subject<<endl<<"  principalship = "<<principalship<<endl<<"  department= "<<department<<endl;}
};
#endif // PEOPLE_H_INCLUDED
