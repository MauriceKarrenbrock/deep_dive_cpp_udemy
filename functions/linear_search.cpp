#include<iostream>
#include<iterator>

template <class T>

// If the element is not found it will return the length of the input array
int linear_search(T * array, int length, T key)
{
    int index;

    for (index=0; index <= length; index ++)
        if (array[index] == key) 
            break;

    return index;
}

int main()
{
    int A[]={1,2,3}, B[]={4,5,6};
    int key=2;
    int len_a = std::end(A) - std::begin(A), len_b = std::end(B) - std::begin(B);

    auto index = linear_search(A, len_a, key);

    if (index < len_a) std::cout<<key<<" is in A\n";
    else std::cout<<key<<" is not in A\n";

    index = linear_search(B, len_b, key);

    if (index < len_b) std::cout<<key<<" is in B\n";
    else std::cout<<key<<" is not in B\n";

    return 0;
}