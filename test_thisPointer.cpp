#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Filter
{
public:
    Filter();
    Filter(int slen_lower, int slen_upper);

    /** declare the filter
    *   @param *filter() */
    Filter *filter(
        vector<string>& container,
        const char some_char,
        const int lower_limit,
        const int upper_limit,
        bool *need_check);
    ~Filter();
private:
    int scan(string& s, const char some_char);
    bool check(string& s);
private:
    int slen_lower;
    int slen_upper;
    static const int def_slen_lower = 1;
    static const int def_slen_upper = 100; // int is comparible
    bool *need_check;
};



using namespace std;
Filter::Filter() : need_check(NULL) {}

Filter::Filter(int lower, int upper) : slen_lower(lower), slen_upper(upper), need_check(NULL) {}

Filter *Filter::filter(
        vector<string>& container,
        const char some_char,
        const int lower_limit,
        const int upper_limit,
        bool *need_check) {
        vector<string> v;
        vector<string>::iterator it = container.begin();

        if(this->need_check == NULL) {
                this->need_check = need_check; // 因为传入形参名与类的成员need_check相同，这里必须显式使用this指针为成员need_check赋值
        }

        while(it!=container.end()) {
                int count = scan(*it, some_char);
                if(count>=lower_limit && count<=upper_limit) {
                        v.push_back(*it);
                }
                it++;
        }

        container = v;
        return this; // 执行一次过滤后，返回当前的Filter类对象指针this，以便进一步执行过滤
}


int Filter::scan(string& s, const char some_char) {
        if(*need_check == true) {
                if(!check(s)) {
                        return -1;
                }
        }
        string::size_type size = s.size();
        int count = 0;
        string::size_type pos = s.find(some_char, 0);
        while(pos != string::npos) {
                count++;
                if(pos == size-1) {
                        break;
                }
                else {
                        pos = s.find(some_char, pos+1);
                }
        }
        return count;
}
bool Filter::check(string& s) {
        if(slen_lower <= 0 || slen_upper <= 0) {
                slen_lower = def_slen_lower;
                slen_upper = def_slen_upper;
        }
        if(s.size()>=slen_lower &&s.size()<=slen_upper ) {
                return true;
        }
        return false;
}
Filter::~Filter() {}




#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
        vector<string> vtr;
        vtr.push_back("123455897000032847754524"); // 0:4 1:1 5:4
        vtr.push_back("55555555555555517"); // 0:0 1:1 5:17
        vtr.push_back("0055123510"); // 0:3 1:2 5:2
        vtr.push_back("12348934229912344320"); // 0:1 1:2 5:0
        vtr.push_back("0000055005500020"); // 0:11 1:0 5:4
        vtr.push_back("88456455532518"); // 0:0 1:1 5:5
        vtr.push_back("55223408"); // 0:1 1:0 5:2
        vtr.push_back("5504"); // 0:1 1:0 5:2
        vtr.push_back("00456455530518"); // 0:2 1:1 5:5
        vtr.push_back("01236455515"); // 0:1 1:2 5:4
        vtr.push_back("88456455532518"); // 0:0 1:1 5:5
        cout<<vtr.size()<<endl;
        int slen_lo = 2;
        int slen_up = 20;
        bool check_status = true;
        bool *need_check = &check_status;
        Filter *pfilter = new Filter(slen_lo, slen_up);

        //因为定义过滤行为，也就是filter方法的时候，使用了this指针，能够执行连续过滤的行为，在使用的时候，这样可以执行连续操作：
        pfilter->filter(vtr, '5', 2, 5, need_check)
                        -> filter(vtr, '0', 1, 3, need_check)
                        ->filter(vtr, '1', 0, 0, need_check);
        cout<<vtr.size()<<endl;
        vector<string>::iterator it;
        for(it=vtr.begin(); it!=vtr.end(); it++) {
                cout<<*it<<endl;
        }
        delete pfilter;
        return 0;
}
