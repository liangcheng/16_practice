#include <iostream>
#include <string.h>

using namespace std;

int Str_to_int(char str[])
{
    int i=0, num=0;
    int len = strlen(str);
    bool is_neg = false;

    if(str[0] = '-')
    {
        is_neg = true;
        i = 1;
    }

    while(i<len)
    {
        num *= 10.;
        num += (str[i++] - '0');
    }

    if(is_neg) num = -num;

    return num;
};

int main()
{
    char str[] = "-572903";
    cout<<"Input: "<< str <<"\n";
    cout<< Str_to_int(str)<<"\n";
}
