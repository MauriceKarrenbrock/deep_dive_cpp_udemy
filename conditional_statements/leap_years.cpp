#include <iostream>

int main()
{
    int year;

    std::cout<<"Enter a year to know if it is a leap year"<<std::endl;

    std::cin>>year;

    bool leap=false;

    if ((year % 100) == 0)
    {
        if ((year % 400) == 0) leap = true;
    }
    else if ((year % 4) == 0)
    {
        leap = true;
    }

    if (leap) std::cout<<"Leap year\n";
    else std::cout<<"Not leap year\n";
    
    return 0;
}