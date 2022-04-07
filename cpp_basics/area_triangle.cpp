#include <iostream>

int main()
{
    int b, h, a;

    std::cout<<"Give Base and Height\n";

    std::cin>>b>>h;

    a = (b * h) / 2.;

    std::cout<<"Area = "<<a;

    return 0;
}