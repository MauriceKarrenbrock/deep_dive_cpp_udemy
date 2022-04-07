#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

int main()
{
    std::string palindrome_sting="ANNA", not_palindrome_string="NOT";
    std::string helper_string;

    std::cout<<palindrome_sting<<" is ";

    helper_string = palindrome_sting;

    std::reverse(helper_string.begin(), helper_string.end());
    
    bool is_palindrome=true;

    for (int i=0; helper_string[i]!='\0'; i++)
    {
        if (helper_string[i] != palindrome_sting[i])
        {    is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) std::cout<<" palindrome\n";
    else std::cout<<" not palindrome\n";


    std::cout<<not_palindrome_string<<" is ";

    helper_string = not_palindrome_string;

    std::reverse(helper_string.begin(), helper_string.end());
    
    is_palindrome=true;

    for (int i=0; helper_string[i]!='\0'; i++)
    {
        if (helper_string[i] != not_palindrome_string[i])
        {    is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) std::cout<<" palindrome\n";
    else std::cout<<" not palindrome\n";


    return 0;
}