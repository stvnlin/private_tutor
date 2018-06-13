#include <iostream>

long long fibonacci(int n){
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void pause(){
    std::cout << "Press enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return;
}

int main(){
    int num = 1;

    while(num > 0){
        std::cout << "please input the number of serie of Fibonacci:";
        std::cin >> num;

        if(num > 0)
            std::cout << "the number is:" << fibonacci(num) << std::endl;    
    }

    pause();

    return 0;
}