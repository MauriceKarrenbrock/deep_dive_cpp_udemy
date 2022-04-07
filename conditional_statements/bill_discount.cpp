#include <iostream>

int main()
{
    float bill;

    std::cout<<"Input your bill amunt\n";

    std::cin>>bill;

    if (bill >= 100. && bill < 500.)
    {
        bill *= 0.9;
    }
    else if (bill >= 500.)
    {
        bill *= 0.8;
    }

    std::cout<<"You have to pay "<<bill<<std::endl;

    return 0;
}