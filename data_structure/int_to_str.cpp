#include <iostream>
#include <string.h>
#define MAX_DIGITS 100

using namespace std;

char *Int_to_str(int num)
{
    char *str = new char[MAX_DIGITS+1];
    bool is_neg = false;
    int i = 0;

    if(num<0)
    {
        is_neg = true;
        num = -num;
    }

    while(num !=0)
    {
        str[i++] = (char)((num%10) + '0');
        num /=10;
    }
    if(is_neg)
    {
        str[i] = '-';
    }


    char *tmp;
    int j=0;
    while(i>0)
    {
        tmp[j++] =str[i--];
    }
    delete str;
    return tmp;
};


int main()
{
    int num = -123456789;
    cout<<Int_to_str(num)<<"\n";

    return 0;
}
