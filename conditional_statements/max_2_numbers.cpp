#include <iostream>

int main()
{
    int x, y, max;

    std::cout<<"Give 2 integers\n";

    std::cin>>x>>y;

    if (x>y)
    {
        max = x;
    }
    else
    {
        max = y;
    }

    std::cout<<"Max = "<<max<<std::endl;

    return 0;
}