#include <iostream>
using namespace std;

void pause(){
    cout << "Press enter to exit...";
    
    cin.get();

    return;
}

int main(){
    long a = 0, b = 1;
    int n = 2;

    while(a >= 0 && b >= 0 )
    {
        cout << a << "(" << n -1 << "), " << b << "(" << n << "), ";

        a = a + b;
        b = b + a;

        n += 2;
    }

    cout << a << "(" << n -1 << "), " << b << "(" << n << ")" << endl;

    cout << "max is " << n << endl;

    pause();

    return 0;
}