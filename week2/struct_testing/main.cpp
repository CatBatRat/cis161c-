#include <iostream>

using namespace std;

struct values{
        int days;
        string name;
        string response;
};

values HelloToo(){
    values liz{5,"Larry","Stop sounding so happy!"};
    return liz;
}

int main(){
    cout << "Hello world!" << endl;
    values liz = HelloToo();
    cout << "\n" << liz.name << "! " << liz.response << endl;
    return 0;
}

