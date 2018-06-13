#include <iostream>


void pauses(){
    std::cout << "Press enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return;
}

int main(){
    int j = 0;
    int max = 0;

    std::cout << "please input a number: ";
    
    std::cin >> max;

    if(max > 1)
    {
        //for(int i = 0; i < max; j += ++i)
        for(int i = 0; i <= max; j += i++)
            continue;

        std::cout << "The sum of 1 to " << max  << " is: " << j << std::endl;

        pauses();
    }

    return 0;
}
