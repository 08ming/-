#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
class  CLIENT{//�ͻ�����
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
    static char ServerName;//����������
    static int ClientNum;//��¼�ͻ�����
    static  int AveNum;//�ܼ۸�
    int price;//�۸�
};
#endif // CLIENT_H_INCLUDED
