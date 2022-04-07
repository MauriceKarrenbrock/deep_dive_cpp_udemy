#include <iostream>
#include <cmath>

int main()
{
    float a, b, c;
    float delta;
    float root1, root2;

    std::cout<<"Give a b c \nWhere ax^2 + bx + c = 0\n";

    std::cin>>a>>b>>c;

    delta = b * b - 4 * a * c;

    root1 = (-b + sqrt(delta)) / (2 * a);

    root2 = (-b - sqrt(delta)) / (2 * a);

    std::cout<<"X = "<<root1<<" or "<<root2;

    return 0;
}