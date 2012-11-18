#include <iostream>
#include <string>
using namespace std;
class System {
        public:
                System();
                System(int year);
                void start(int method);
                void work(int howlong);
                static string& get_xcode();
                int get_made_year();
                static int get_durable();
                ~System();
        private:
                static string xcode;
                int made_year;
                static const int durable = 40000;
        public:
                static const string name;
};


using namespace std;
const string System::name("X00125 AUTOSYS");
string System::xcode("J862009-X007");
System::System() {}
System::System(int year) : made_year(year) {}

void System::start(int method)
{
    switch(method)
    {
    case 1:
        cout<<"Hot Start!!!"<<endl;
        break;
    case 2:
        cout<<"Freeze Start!!!"<<endl;
        break;
    default:
        cout<<"Stop!!!"<<endl;
    }
}

void System::work(int howlong)
{
    cout<<"It has been worked for "<<howlong<<" hours."<<endl;
}

string& System::get_xcode()
{
    return xcode;
}

int System::get_made_year()
{
    return made_year;
}

int System::get_durable()
{
    return durable;
}

System::~System() {}




int main()
{
    cout<<System::name<<endl;
    cout<<System::get_xcode()<<endl;
    cout<<System::get_durable()<<endl;
    int year = 2009;
    System *system = new System(year);
    system->start(1);
    system->work(1788);
    cout<<system->get_made_year()<<endl;
    delete system;
    return 0;
}
