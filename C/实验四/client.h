#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
class  CLIENT{//客户机类
public:
    CLIENT(int price);
    CLIENT(CLIENT &p1);
    ~CLIENT();
    static void ChangeServerName(char newServerName);
    static void showClientNum();
    static void showServerName();
    static float AVE_PRICE();
    void showPrice();
private:
    static char ServerName;//服务器名称
    static int ClientNum;//记录客户数量
    static  int AveNum;//总价格
    int price;//价格
};
#endif // CLIENT_H_INCLUDED
