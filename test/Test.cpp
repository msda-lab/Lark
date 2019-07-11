#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

using namespace std;

class Device
{
    public:
        Device() {}
        ~Device() {}

        void load() {loadDC(); loadAC();}
        virtual void loadDC() = 0;
        virtual void loadAC() = 0;
};

class Resistor: public Device
{
    public:
        Resistor() {}
        ~Resistor() {}

        void loadDC() {cout << "Resistor loadDC" << endl;}
        void loadAC() {cout << "Resistor loadAC" << endl;}
};

void print(const string &str)
{
    cout << str << endl;
}

int main()
{
    //Device *d = new Resistor();
    //d->load();
    print("hello");
    return 0;
}
