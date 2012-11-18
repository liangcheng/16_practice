#include <iostream>
#include <vector>
#include <string>
using namespace std;
class TruncateString;
typedef void (TruncateString::*TSFP)(string&, int); // 重定义指向该类的成员函数的指针类型
class TruncateString {
        public:
                inline void get_from_first(string& s, int count) {      s = s.substr(0, count); }
                inline void get_from_last(string& s, int count) {       s = s.substr(s.size()-count);   }
                void print(int count, const TSFP tsfp, string& after_s);
        private:
                void print_message(int count, const char *fname, string& after_s);
};

//TruncateString类中没有定义数据成员。接着，TruncateString类的成员函数实现在TruncateString.cpp文件中，如下所示：
void TruncateString::print(int count, const TSFP tsfp, string& after_s) {
        if(tsfp == &TruncateString::get_from_first) {
                print_message(count, "TruncateString::get_from_first", after_s);
        }
        if(tsfp == &TruncateString::get_from_last) {
                print_message(count, "TruncateString::get_from_last", after_s);
        }
}
void TruncateString::print_message(int count, const char *fname, string& after_s) {
        cout<<"Recall function "<<fname<<"\t[count="<<count<<"]\t:\t"<<after_s<<endl;
}




#include <vector>
int main() {
        string s = "abcedfghijklmnopqrstuvwxyz9876543210";
        TruncateString *pts = new TruncateString;
        vector<TSFP> tsfp_vector;
        TSFP tsfpf1 = &TruncateString::get_from_first;
        tsfp_vector.push_back(tsfpf1);
        TSFP tsfpf2 = &TruncateString::get_from_first;
        tsfp_vector.push_back(tsfpf2);
        TSFP tsfpl1 = &TruncateString::get_from_last;
        tsfp_vector.push_back(tsfpl1);
        TSFP tsfpl2 = &TruncateString::get_from_last;
        tsfp_vector.push_back(tsfpl2);
        TSFP tsfpl3 = &TruncateString::get_from_last;
        tsfp_vector.push_back(tsfpl3);
        int count_array[] = {   30, 25, 15, 8, 1        };
        for(int i=0; i<5; i++) {
                TSFP tsfp = tsfp_vector.at(i);
                (pts->*tsfp)(s, count_array[i]);
                pts->print(count_array[i], tsfp, s);
        }
        delete pts;
        return 0;
}


