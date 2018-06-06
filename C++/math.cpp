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

long long fibo_1(int n){
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    return fibo_1(n - 1) + fibo_1(n - 2);
}

long long fibo_2(int n){
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        b = a + b;
        a = b - a;
    }
    return a;
}

void math_problem2(){
    int n;
    clock_t begin_t;

    cout << "input the number of fibonacci serie you want:";
    cin >> n;
    cout << "the first approach" << endl;
    begin_t = clock();
    cout << "the number of " << n << "th is " << fibo_1(n) << endl;
    cout << "it takes " << float(clock() - begin_t) / CLOCKS_PER_SEC << "seconds" << endl;
    cout << "the second approach" << endl;
    begin_t = clock();
    cout << "the number of " << n << "th is " << fibo_2(n) << endl;
    cout << "it takes " << float(clock() - begin_t) / CLOCKS_PER_SEC << "seconds" << endl;
}

int main(){
    math_problem2();
}