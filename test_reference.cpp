//引用类型变量priceRef 获取了price的引用，可以直接通过操作priceRef来操作price这个变量

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
