#include<iostream>
#include<cstring>
#include<string>

int main()
{
    std::string my_string = "I am a string";

    // CPP string length
    std::cout<<"CPP length "<<my_string.length()<<std::endl;

    // With iterator
    int length=0;

    for (std::string::iterator it=my_string.begin(); it!=my_string.end(); it++)
    {
        length ++;
    }

    std::cout<<"Iterator length "<<length<<std::endl;

    // Old C stile
    length=0;

    while (my_string[length] != '\0')
        length ++;

    std::cout<<"Old C stile length "<<length<<std::endl;

    std::cout<<"True length 13"<<std::endl;

    return 0;
}