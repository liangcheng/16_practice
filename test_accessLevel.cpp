#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Filter
{
public:
    Filter();
    Filter(const char some, const int lower, const int upper);
    void filter(vector<string>& container);
    ~Filter();

private:
    int scan(string& s);

private:
    char some_char; //some_char是指定的字符
    int lower_limit;
    int upper_limit;
};


Filter::Filter() : lower_limit(0), upper_limit(0)
{
}

Filter::Filter(const char some, const int lower, const int upper) : some_char(some), lower_limit(lower), upper_limit(upper)
{
}


void Filter::filter(vector<string>& container)
{
    vector<string> v;
    vector<string>::iterator it = container.begin();
    while(it!=container.end())
    {
        int count = scan(*it);
        if(count>=lower_limit && count<=upper_limit)
        {
            v.push_back(*it);
        }
        it++;
    }
    container = v;
}


int Filter::scan(string& s)
{
    string::size_type size = s.size();
    int count = 0;
    string::size_type pos = s.find(some_char, 0);
    while(pos != string::npos)
    {
        count++;
        if(pos == size-1)
        {
            break;
        }
        else
        {
            pos = s.find(some_char, pos+1);
        }
    }
    return count;
}


Filter::~Filter()
{
}




//在容器中放入6个数字字符串，统计每个字符串出现字符'5'的个数，预期结果是，过滤掉5的个数不在区间[5, 12]的字符串，最后应该只有2个满足区间要求。
int main()
{
    vector<string> vtr;
    vtr.push_back("123455897328455545"); // 5:6
    vtr.push_back("55555555555555555"); // 5:17
    vtr.push_back("000998766532245"); // 5:2
    vtr.push_back("1234998989893422"); // 5:0
    vtr.push_back("0000055005500000"); // 5:4
    vtr.push_back("888888436455532554"); // 5:5
    cout<<vtr.size()<<endl;
    char some = '5';
    int lower = 5;
    int upper = 12;
    Filter *pfilter = new Filter(some, lower, upper);
    pfilter->filter(vtr);
    cout<<vtr.size()<<endl;
    vector<string>::iterator it;
    for(it=vtr.begin(); it!=vtr.end(); it++)
    {
        cout<<*it<<endl;
    }
    delete pfilter;
    return 0;
}
