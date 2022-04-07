#include<iostream>
#include<cstring>
#include<string>

bool is_space(char str)
{
    if (str==' '||str=='\n'||str=='\t')
        return true;
    return false;
}

bool is_vowel(char str)
{
    if (str=='a'||str=='e'||str=='i'||str=='o'||str=='u'||str=='A'||str=='E'||str=='I'||str=='O'||str=='U')
        return true;
    return false;
}

int main()
{
    int spaces=0, vowels=0, consonants=0;
    std::string my_string = "This is a string";

    for (std::string::iterator it=my_string.begin(); it!=my_string.end(); it ++)
    {
        if (is_space(*it)) spaces ++;
        else if (is_vowel(*it)) vowels ++;
        else consonants ++; 
    }

    std::cout<<"There are "<<(spaces + 1)<<" words "<<vowels<<" vowels and "<<consonants<<" consonants\n";

    return 0;
}