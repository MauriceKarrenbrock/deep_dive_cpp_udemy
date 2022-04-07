#include <iostream>

int main()
{
    float A[5][7], B[7][7];
    float C[5][20] = {0.f};

    // A is array of 2.0
    for (auto& i : A)
    {
        for (auto& j : i)
        {
            j = 2.f;
        }
    }

    // B = Identity
    for (int i=0; i<7; i++)
    {
        for (int j=0; j<7; j++)
        {
            if (i == j) B[i][j] = 1.f;
            else B[i][j] = 0.f;
        }
    }

    for (int i=0; i<5; i++)//A lines
    {
        for (int j=0; j<7; j++)//A columns
        {
            for (int k=0; k<7; k++)//B lines
            {
                C[i][j] += A[i][k] * B[k][j];
            }
            std::cout<<C[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}