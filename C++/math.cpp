#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;

void math_problem1(){
    int a = 1, b = 2;
    double s = 0.0;
    clock_t begin_t;

    for (int j = 10; j <= 100000;j*=10){
        s = 0.0;
        a = 1;
        b = 2;
        begin_t = clock();
        for (int i = 0; i < j;i++){
            s += 1.0 / a;
            a += b;
            b++;
        }
        cout << "add to " << j << " numbers, the result is " << s << " the final number is " << a << endl;
        cout << "it takes " << float(clock() - begin_t) / CLOCKS_PER_SEC << "secodes" << endl;
    }
}

int main(){
    math_problem1();
}