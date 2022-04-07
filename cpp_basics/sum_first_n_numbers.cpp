#include <iostream>

int main()
{
    int n, sum;

    std::cout<<"I will print the sum of the first N natural numbers\nInsert N\n";

    std::cin>>n;

    sum = n * (n + 1) / 2.;

    std::cout<<"The sum is = "<<sum<<"\n";

    return 0;
}