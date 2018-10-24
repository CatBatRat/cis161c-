// vim:autochdir:

#include <iostream>

using namespace std;

int main() {
    int list[] {34, 12, 34, 19, 2, 200};
    int smaller = sizeof(list)*sizeof(list);
    int listlen = sizeof(list)/sizeof(list[0]);
    cout << smaller;

    for(int x;x<listlen;x++)
        smaller = (list[x]<smaller)?list[x]:smaller;

    cout << smaller;

    return 0;
}
