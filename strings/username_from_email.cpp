#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

int main()
{
    std::string email="username@gmail.com";
    std::string at="@";

    auto at_index = std::find_first_of(email.begin(), email.end(), at.begin(), at.end());

    auto user_name = email.substr(0, at_index - email.begin());

    std::cout<<"Username = "<<user_name<<std::endl;

    return 0;
}