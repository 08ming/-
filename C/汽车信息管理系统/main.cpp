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
    string name;                   //��������
    double price;                  //�����۸�
    string color;                  //������ɫ
    string num;                       //�������(��1��ʼ)
    int Size;                      //��������

public:
    Car();
    Car(string name,double price, string color , string num ,int Size ):name(name),price(price),color(color),num(num),Size(Size){};//���캯��

    void setname(string name)      //������������
    {
        this -> name = name;
    }
    string getname()               //��ȡ��������
    {
        return name;
    }

    void setprice(double price)    //���������ۼ�
    {
        this -> price = price;
    }
    double getprice()              //��ȡ�����ۼ�
    {
        return price;
    }

    void setcolor(string color)    //����������ɫ
    {
        this -> color = color;
    }
    string getcolor()              //��ȡ������ɫ
    {
        return color;
    }

    void  setnum(string num)
    {
        this -> num = num;
    }
    string getnum()                   //��ȡ�����������
    {
        return num;
    }

    void setSize(int Size)                  //��ȡ��������
    {
       this -> Size=Size;
    }
    int getSize()
    {
        return Size;
    }

    void show()
    {
        cout <<"\n\t"<<"����"<<"\t" <<"�۸�" <<"\t"<<"��ɫ" <<"\t"<<"���"<<"\t"<<"����";
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
    void showCopy();               //չʾ��Ȩ��Ϣ
    void menu();                   //���˵�
    void changeInfo();             //����������Ϣ
    void findCar();                //�����������ֲ�������
    void showInfo();               //��ʾ����������Ϣ
    void sortCar();                //���������ۼ����򣨴�С����
    void deleteCar();              //ɾ��������Ϣ
    void addCar();                 //�������
    void initData();
    void rewrite();                //��д�ļ�
};

void Controller::showCopy()        //չʾ��Ȩ��Ϣ
{
    system("cls");                 //����
    cout << "\n\n\t***************��ӭʹ�öԶԶ�������Ϣ����ϵͳ****************";
    cout << "\n\n\t*********************�ԶԶ���Ϣ��Ȩ����**********************";
}

void Controller::menu()            //���˵�
{
    int option=1;
    showCopy();
    cout << "\n\n\t***********************1.���������Ϣ************************";
    cout << "\n\n\t***********************2.��������****************************";
    cout << "\n\n\t***********************3.����������Ϣ************************";
    cout << "\n\n\t***********************4.��ʾ����������Ϣ********************";
    cout << "\n\n\t***********************5.ɾ��������Ϣ************************";
    cout << "\n\n\t***********************6.���������۸�����********************";
    cout << "\n\n\t***********************7.�˳�ϵͳ****************************";


    do{
        cout << "\n\n\t����������Ҫ�ķ����ţ�";
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



void Controller::addCar()          //�������
{
    string name, color, num;
    double price;
    int Size;
    showCopy();

    cout << "\n\n\t�����������������֣�";
    cin >> name;

    cout << "\n\n\t�������������ļ۸�";
    cin >> price;

    cout << "\n\n\t����������������ɫ��";
    cin >> color;

    cout << "\n\n\t�������������ı�ţ�";
    cin >> num;

    cout << "\n\n\t��������������������";
    cin >> Size;

    Car car = Car(name, price, color, num, Size);
    int result = MessageBox(NULL,"��ȷ��Ҫ��Ӵ���Ϣ��","�������",MB_YESNO | MB_ICONQUESTION);
    if(result == 6)
    {
        if( car.save() )
        {
            cars.push_back(car);
            cout << "\n\n\t��������Ϣ��ӳɹ���"<<endl;
            cout << "\n\n\t����������Ϣ���£�";
            car.show();
        }
        else cout << "\n\n\t��������Ϣ���ʧ�ܣ�"<<endl;
    }
    system("pause");

}



void Controller::findCar()         //����������Ϣ
{
    showCopy();
    string name;
    cout << "\n\n\t��������Ҫ���ҳ������ֻ���:";
    cin >> name;
    int i=0;
    for( ; i < cars.size(); i++)
    {
        if(cars[i].getname() == name || cars[i].getnum() == name)
        {
            cout << "\n\n\t����Ҫ���ҵĳ�����Ϣ���£�";
            cars[i].show();
            break;
        }

    }
    if(i>=cars.size()) cout << "\n\n\t���޴˳�����Ϣ...";
    cout<<"\n\t";
    system("pause");
}

void Controller::deleteCar()       //ɾ��������Ϣ
{
    showCopy();
    string num;
    //cout<<"************************* ɾ �� *************************";
    cout << "\n\n\t������Ҫɾ��������ţ�";
    cin >> num;
    int i = 0, len=cars.size();
    for(;i<len;i++)
    {
        if(cars[i].getnum() == num)
        {
            cout<<"\n\n\t��Ҫɾ����������Ϣ���£�";
            cars[i].show();
            break;
        }
    }
    if(i>=len)
    {
        cout<<"\n\n\t������������...";
        system("pause");
        return;
    }

    int result=MessageBox(NULL,"��ȷ��Ҫɾ������������Ϣ��","ȷ����ʾ",MB_YESNO | MB_ICONQUESTION);
    if(result == 6)
    {
        cars.erase(cars.begin()+i);
        cout<<"\n\n\tɾ���ɹ�..."<<endl;

        system("pause");
    }
    else cout<<"\n\n\tɾ��ʧ��...";
    rewrite();

    return;

}


void Controller::showInfo()        //��ʾ����������Ϣ
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

void Controller::changeInfo()      //����������Ϣ
{
    showCopy();
    int option=0,count;
    string name;
    cout << "\n\n\t����������Ҫ�޸ĵĳ������ֻ���:";
    cin >> name;
    int i=0;
    for( ; i < cars.size(); i++)
    {
        if(cars[i].getname() == name || cars[i].getnum() == name)
        {
            cout << "\n\n\t����Ҫ�޸ĵĳ�����Ϣ���£�";
            cars[i].show();
            count=i;
            break;
        }

    }
    if(i>=cars.size()) cout << "\n\n\t���޴˳�����Ϣ...";
    cout<<"\n\t";
    do{

        cout << "\n\n\t��ѡ����Ҫ�޸ĵ���Ϣ...";
        cout << "\n\n\t1.������\n"<< "\n\n\t2.�۸�\n"<< "\n\n\t3.��ɫ\n"<< "\n\n\t4.���\n"<< "\n\n\t5.��������\n"<<"6.������һ��";
        cout <<"\n\n";
        cout << "��ѡ������Ҫ�Ĳ�����";
        cin  >> option;
        if(option == 1)
        {
            showCopy();
            string name;
            cout<< "\n\n\t�������µĳ�����";
            cin>> name;
            cars[count].setname(name);
            cout << "\n\n\t��������Ϣ���£�";
            cars[count].show();
        }

        if(option == 2)
        {
            showCopy();
            double price;
            cout<< "\n\n\t�������µĳ��ۣ�";
            cin>> price;
            cars[count].setprice(price);
            cout << "\n\n\t��������Ϣ���£�";
            cars[count].show();
        }

        if(option == 3)
        {
            showCopy();
            string color;
            cout<< "\n\n\t�������µĳ�ɫ��";
            cin>> color;
            cars[count].setcolor(color);
            cout << "\n\n\t��������Ϣ���£�";
            cars[count].show();
        }

        if(option == 4)
        {
            showCopy();
            string num;
            cout<< "\n\n\t�������µĳ��ţ�";
            cin>> num;
            cars[count].setnum(num);
            cout << "\n\n\t��������Ϣ���£�";
            cars[count].show();
        }

        if(option == 5)
        {
            showCopy();
            int Size;
            cout<< "\n\n\t�������µĳ��أ�";
            cin>> Size;
            cars[count].setSize(Size);
            cout << "\n\n\t��������Ϣ���£�";
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
void Controller::sortCar()         //����
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

void Controller::rewrite()         //��д
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
