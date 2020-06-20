#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#define FILENAME "carInfo.txt"
bool isEnd;

class Car{

private:
    string name;                   //汽车名字
    double price;                  //汽车价格
    string color;                  //汽车颜色
    string num;                       //汽车编号(从1开始)
    int Size;                      //汽车载量

public:
    Car();
    Car(string name,double price, string color , string num ,int Size ):name(name),price(price),color(color),num(num),Size(Size){};//构造函数

    void setname(string name)      //设置汽车名字
    {
        this -> name = name;
    }
    string getname()               //获取汽车名字
    {
        return name;
    }

    void setprice(double price)    //设置汽车售价
    {
        this -> price = price;
    }
    double getprice()              //获取汽车售价
    {
        return price;
    }

    void setcolor(string color)    //设置汽车颜色
    {
        this -> color = color;
    }
    string getcolor()              //获取汽车颜色
    {
        return color;
    }

    void  setnum(string num)
    {
        this -> num = num;
    }
    string getnum()                   //获取汽车数量编号
    {
        return num;
    }

    void setSize(int Size)                  //获取汽车载量
    {
       this -> Size=Size;
    }
    int getSize()
    {
        return Size;
    }

    void show()
    {
        cout <<"\n\t"<<"名字"<<"\t" <<"价格" <<"\t"<<"颜色" <<"\t"<<"编号"<<"\t"<<"载量";
        cout <<"\n\t"<< name <<"\t "<< price <<"\t"<< color <<"\t"<< num <<"\t"<< Size;
        cout <<"\n\n\t";
    }

    bool save()
    {
        ofstream out(FILENAME,ios::out | ios::app | ios::binary);
        if ( out.is_open() )
        {
            out <<"\n"<< name <<"\t "<< price <<"\t"<< color <<"\t"<< num <<"\t"<< Size<<"\n";
            out.close();
            return true;
        }
        return false;
    }
};

vector<Car> cars;

class Controller
{
public:
    void showCopy();               //展示版权信息
    void menu();                   //主菜单
    void changeInfo();             //更改汽车信息
    void findCar();                //根据汽车名字查找汽车
    void showInfo();               //显示所有汽车信息
    void sortCar();                //根据汽车售价排序（从小到大）
    void deleteCar();              //删除汽车信息
    void addCar();                 //添加汽车
    void initData();
    void rewrite();                //重写文件
};

void Controller::showCopy()        //展示版权信息
{
    system("cls");                 //清屏
    cout << "\n\n\t***************欢迎使用对对队汽车信息管理系统****************";
    cout << "\n\n\t*********************对对队信息版权所有**********************";
}

void Controller::menu()            //主菜单
{
    int option=1;
    showCopy();
    cout << "\n\n\t***********************1.添加汽车信息************************";
    cout << "\n\n\t***********************2.查找汽车****************************";
    cout << "\n\n\t***********************3.更改汽车信息************************";
    cout << "\n\n\t***********************4.显示所有汽车信息********************";
    cout << "\n\n\t***********************5.删除汽车信息************************";
    cout << "\n\n\t***********************6.根据汽车价格排序********************";
    cout << "\n\n\t***********************7.退出系统****************************";


    do{
        cout << "\n\n\t请输入您想要的服务编号：";
        cin >> option;
    }while ( option<=0&&option>6 );

    switch(option)
    {
        case 1: addCar();        break;
        case 2: findCar();         break;
        case 3: changeInfo();      break;
        case 4:  showInfo();       break;
        case 5: deleteCar();       break;
        case 6: sortCar();         break;
        case 7: rewrite();isEnd = true;      break;

    }
}



void Controller::addCar()          //添加汽车
{
    string name, color, num;
    double price;
    int Size;
    showCopy();

    cout << "\n\n\t请输入新汽车的名字：";
    cin >> name;

    cout << "\n\n\t请输入新汽车的价格：";
    cin >> price;

    cout << "\n\n\t请输入新汽车的颜色：";
    cin >> color;

    cout << "\n\n\t请输入新汽车的编号：";
    cin >> num;

    cout << "\n\n\t请输入新汽车的载量：";
    cin >> Size;

    Car car = Car(name, price, color, num, Size);
    int result = MessageBox(NULL,"您确定要添加此信息吗？","添加提醒",MB_YESNO | MB_ICONQUESTION);
    if(result == 6)
    {
        if( car.save() )
        {
            cars.push_back(car);
            cout << "\n\n\t新汽车信息添加成功！"<<endl;
            cout << "\n\n\t新添汽车信息如下：";
            car.show();
        }
        else cout << "\n\n\t新汽车信息添加失败！"<<endl;
    }
    system("pause");

}



void Controller::findCar()         //查找汽车信息
{
    showCopy();
    string name;
    cout << "\n\n\t请输入你要查找车的名字或编号:";
    cin >> name;
    int i=0;
    for( ; i < cars.size(); i++)
    {
        if(cars[i].getname() == name || cars[i].getnum() == name)
        {
            cout << "\n\n\t您所要查找的车辆信息如下：";
            cars[i].show();
            break;
        }

    }
    if(i>=cars.size()) cout << "\n\n\t暂无此车辆信息...";
    cout<<"\n\t";
    system("pause");
}

void Controller::deleteCar()       //删除汽车信息
{
    showCopy();
    string num;
    //cout<<"************************* 删 除 *************************";
    cout << "\n\n\t请输入要删除汽车编号：";
    cin >> num;
    int i = 0, len=cars.size();
    for(;i<len;i++)
    {
        if(cars[i].getnum() == num)
        {
            cout<<"\n\n\t您要删除的汽车信息如下：";
            cars[i].show();
            break;
        }
    }
    if(i>=len)
    {
        cout<<"\n\n\t该汽车不存在...";
        system("pause");
        return;
    }

    int result=MessageBox(NULL,"您确定要删除此汽车的信息吗？","确认提示",MB_YESNO | MB_ICONQUESTION);
    if(result == 6)
    {
        cars.erase(cars.begin()+i);
        cout<<"\n\n\t删除成功..."<<endl;

        system("pause");
    }
    else cout<<"\n\n\t删除失败...";
    rewrite();

    return;

}


void Controller::showInfo()        //显示所有汽车信息
{
    showCopy();
    fstream read;
    read.open(FILENAME,ios::in| ios ::binary);
    if(!read.is_open())
    {
        return;
    }
    string line;
    int index = 0,position = 0 ,num = 0;
    string arrs [5];
    while(getline(read,line))
    {
        position = 0;
        num = 0;
        index = line.find("\t",position);
        cout<<"\n\n\t";
        while(index>0)
        {
            arrs[num++] = line.substr(position,index - position);
            position = index +1 ;
            index = line.find("\t",position);
        }
        arrs[num]=line.substr(position,line.find("\r",position));
        Car car=Car(arrs[0], atof(arrs[1].c_str()), arrs[2], arrs[3], atoi(arrs[4].c_str()));
        car.show();
     }
     system("pause");
}

void Controller::changeInfo()      //更改汽车信息
{
    showCopy();
    int option=0,count;
    string name;
    cout << "\n\n\t请输入你需要修改的车的名字或编号:";
    cin >> name;
    int i=0;
    for( ; i < cars.size(); i++)
    {
        if(cars[i].getname() == name || cars[i].getnum() == name)
        {
            cout << "\n\n\t您所要修改的车辆信息如下：";
            cars[i].show();
            count=i;
            break;
        }

    }
    if(i>=cars.size()) cout << "\n\n\t暂无此车辆信息...";
    cout<<"\n\t";
    do{

        cout << "\n\n\t请选择你要修改的信息...";
        cout << "\n\n\t1.汽车名\n"<< "\n\n\t2.价格\n"<< "\n\n\t3.颜色\n"<< "\n\n\t4.编号\n"<< "\n\n\t5.汽车载量\n"<<"6.返回上一级";
        cout <<"\n\n";
        cout << "请选择你需要的操作：";
        cin  >> option;
        if(option == 1)
        {
            showCopy();
            string name;
            cout<< "\n\n\t请输入新的车名：";
            cin>> name;
            cars[count].setname(name);
            cout << "\n\n\t该汽车信息如下：";
            cars[count].show();
        }

        if(option == 2)
        {
            showCopy();
            double price;
            cout<< "\n\n\t请输入新的车价：";
            cin>> price;
            cars[count].setprice(price);
            cout << "\n\n\t该汽车信息如下：";
            cars[count].show();
        }

        if(option == 3)
        {
            showCopy();
            string color;
            cout<< "\n\n\t请输入新的车色：";
            cin>> color;
            cars[count].setcolor(color);
            cout << "\n\n\t该汽车信息如下：";
            cars[count].show();
        }

        if(option == 4)
        {
            showCopy();
            string num;
            cout<< "\n\n\t请输入新的车号：";
            cin>> num;
            cars[count].setnum(num);
            cout << "\n\n\t该汽车信息如下：";
            cars[count].show();
        }

        if(option == 5)
        {
            showCopy();
            int Size;
            cout<< "\n\n\t请输入新的车载：";
            cin>> Size;
            cars[count].setSize(Size);
            cout << "\n\n\t该汽车信息如下：";
            cars[count].show();
        }

        if(option == 6)
        {
            break;
        }

    }while( option>0&&option<7 );

}


bool cmp (Car x,Car y)
{
    return x.getprice()<y.getprice();
}
void Controller::sortCar()         //排序
{
    showCopy();
    int i;
    sort(cars.begin(),cars.begin()+cars.size(),cmp);
    for(i=0;i<cars.size();i++)
        cars[i].show();
    system("pause");
}

void Controller::initData()
{
    fstream read;
    read.open(FILENAME,ios::in| ios ::binary);
    if(!read.is_open())
    {
        return;
    }
    string line;
    int index = 0,position = 0 ,num = 0;
    string arrs [5];
    while(getline(read,line))
    {
        position = 0;
        num = 0;
        index = line.find("\t",position);
        cout<<"\n\n\t";
        while(index>0)
        {
            arrs[num++] = line.substr(position,index - position);
            position = index +1 ;
            index = line.find("\t",position);
        }
        arrs[num]=line.substr(position,line.find("\r",position));
        /*cout<<"\n\n\t"<<arrs[0]<<"\t"<<arrs[1]<<"\t"<<arrs[2]<<"\t"<<arrs[3]<<"\t"<<arrs[4];
        cout<<"\n\t"<<line<<endl;
        ICCard card =ICCard(arrs[0], atof(arrs[1].c_str()), arrs[2], atoi(arrs[3].c_str()), atoi(arrs[4].c_str()));
        */
        cars.push_back(Car(arrs[0], atof(arrs[1].c_str()), arrs[2], arrs[3], atoi(arrs[4].c_str())));
    }
}

void Controller::rewrite()         //重写
{
    int len = cars.size();
    if (len <= 0)
    {
        ofstream out(FILENAME, ios::out | ios::trunc);
        out.close();
        return;
    }
    ofstream out(FILENAME,ios::out | ios::binary);
    if(out.is_open())
    {
        for(int i = 0; i <len ; i++)
        {
            out <<"\n"<< cars[i].getname() <<"\t "<< cars[i].getprice() <<"\t"<< cars[i].getcolor() <<"\t"<< cars[i].getnum() <<"\t"<< cars[i].getSize();
        }
        out.close();
    }
}


int main()
{
    Controller user;

    user.initData();
    do{

        user.menu();
    }while(!isEnd);

    return 0;
}
