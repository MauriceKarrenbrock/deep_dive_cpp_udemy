// Get average of array
#include <iostream>

int main()
{
    int n;

    std::cout<<"How many numbers?\n";
    std::cin>>n;

    float array[n];

    std::cout<<"Imput the numbers one at the time\n";

    for (auto& i : array)
        std::cin>>i;

    float sum=0;

    for (auto i : array)
    {
        sum += i;
    }

    sum /= n;

    std::cout<<"The average is "<<sum<<"\n";

    return 0;
}