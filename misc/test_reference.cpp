//�������ͱ���priceRef ��ȡ��price�����ã�����ֱ��ͨ������priceRef������price�������

#include <iostream>

using namespace std;

int main()
{
    float price = 12.56;

    float &priceRef = price;

    cout<<priceRef<<endl;

    priceRef = 100.34;

    cout<<priceRef<<endl;

    return 0;

}
