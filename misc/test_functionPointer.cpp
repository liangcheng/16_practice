#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef void (*FP)(string&, int); // 重定义函数指针类型

inline void get_from_first(string& s, int count)
{
    s = s.substr(0, count);
}

inline void get_from_last(string& s, int count)
{
    s = s.substr(s.size()-count);
}

void print(int count, FP fp, string& after_s)
{
    if(fp == get_from_first)
    {
        print_message(count, "get_from_first", after_s);
    }
    if(fp == get_from_last)
    {
        print_message(count, "get_from_last", after_s);
    }
}

void print_message(int count, const char *fname, string& after_s)
{
    cout<<"Recall function "<<fname<<"\t[count="<<count<<"]\t:\t"<<after_s<<endl;
}

int main()
{
    string s = "abcedfghijklmnopqrstuvwxyz9876543210";

    vector<FP> fp_vector;

    FP pf1 = get_from_first;
    fp_vector.push_back(pf1);

    FP pf2 = get_from_first;
    fp_vector.push_back(pf2);

    FP pl1 = get_from_last;
    fp_vector.push_back(pl1);

    FP pl2 = get_from_last;
    fp_vector.push_back(pl2);

    FP pl3 = get_from_last;
    fp_vector.push_back(pl3);


    int count_array[] = {30, 25, 15, 8, 1};
    for(int i=0; i<5; i++)
    {
        FP fp = fp_vector.at(i);
        fp(s, count_array[i]);
        print(count_array[i], fp, s);
    }
    return 0;
}
