#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

int main()
{
    std::string my_string = "STRING";
    std::string output_string = my_string;

    std::cout<<"Starting string is = "<<my_string<<std::endl;

    // with transform
    std::transform(output_string.begin(), output_string.end(), output_string.begin(), ::tolower);

    std::cout<<"With transform = "<<output_string<<std::endl;

    // With loop
    output_string = my_string;

    for (std::string::iterator it=output_string.begin(); it!=output_string.end(); it++)
    {
        *it = std::tolower(*it);
    }

    std::cout<<"With loop = "<<output_string<<std::endl;

    // With ASCII conversion
    output_string = my_string;

    for (std::string::iterator it=output_string.begin(); it!=output_string.end(); it++)
    {
        *it += 32;
    }

    std::cout<<"With ASCII conversion = "<<output_string<<std::endl;

    return 0;
}