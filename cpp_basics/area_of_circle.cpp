// Calculate area of a circle A = pi r**2
#include <iostream>

int main()
{
    const float pi=3.14;
    float radius, area;

    std::cout<<"Give the radius of the circle\n";

    std::cin>>radius;

    area = pi * radius * radius;

    std::cout<<"The area is = "<<area<<std::endl;

    return 0;
}