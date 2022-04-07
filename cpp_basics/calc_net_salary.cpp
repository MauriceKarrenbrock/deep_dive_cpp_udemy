// net_salary = basic_salary + basic_salary * percentage_allowances - basic_salary * percentage_deductions
#include <iostream>

int main()
{
    float basic_salary, percentage_allowances, percentage_deductions;
    float net_salary;

    std::cout<<"Give in order: basic salary, percentage of allowances and percentage of deductions\n";

    std::cin>>basic_salary>>percentage_allowances>>percentage_deductions;

    percentage_allowances/=100.f;
    percentage_deductions/=100.f;

    net_salary = basic_salary + basic_salary * percentage_allowances - basic_salary * percentage_deductions;

    std::cout<<"Net salary = "<<net_salary<<std::endl;

    return 0;
}