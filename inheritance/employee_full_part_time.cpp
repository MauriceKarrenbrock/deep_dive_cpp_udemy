// make Emplyee base class
// and then FullTimeEmployee and PartTimeEmployee
#include<iostream>
#include<cstring>
#include<string>

// ################################################
// Employee

class Employee
{
private:
    std::string name;
    std::string departement;
    std::string role;

public:
    Employee(std::string name, std::string departement, std::string role);

    // setters
    int setName(std::string name);
    int setDepartement(std::string departement);
    int setRole(std::string role);

    //getter
    std::string getName();
    std::string getDepartement();
    std::string getRole();
};


Employee::Employee(std::string name="name surname",
    std::string departement="undefined",
    std::string role="undefined")
{
    if (setName(name))
        std::cout<<"Invalid name";

    if (setDepartement(departement))
        std::cout<<"Invalid departement";

    if (setRole(role))
        std::cout<<"Invalid role";
}

// setters
// They return 0 if everything is OK
// another number otherwise
int Employee::setName(std::string name)
{
    if (name.empty())
    {
        this->name = "INVALID";
        
        return -1;
    }

    this->name = name;

    return 0;
}

int Employee::setDepartement(std::string departement)
{
    if (departement.empty())
    {
        this->departement = "INVALID";
        
        return -1;
    }

    this->departement = departement;

    return 0;
}

int Employee::setRole(std::string role)
{
    if (role.empty())
    {
        this->role = "INVALID";
        
        return -1;
    }

    this->role = role;

    return 0;
}


//getter
std::string Employee::getName()
{
    return name;
}

std::string Employee::getDepartement()
{
    return departement;
}

std::string Employee::getRole()
{
    return role;
}

// End Employee
// ####################################

// ####################################
// FullTimeEmployee

class FullTimeEmployee: public Employee
{
private:
    float monthly_salary;

public:
    FullTimeEmployee(
        std::string name, std::string departement, std::string role, float montly_salary
        );

    int setMonthlySalary(float monthly_salary);
    float getMonthlySalary();
};

FullTimeEmployee::FullTimeEmployee(std::string name="name surname",
    std::string departement="undefined",
    std::string role="undefined",
    float montly_salary=0.f):Employee(name, departement, role)
{
    if(setMonthlySalary(monthly_salary))
        std::cout<<"Invalid wage value";
}

int FullTimeEmployee::setMonthlySalary(float monthly_salary)
{
    if (monthly_salary < 0.f)
    {
        this->monthly_salary = 0.f;

        return -1;
    }

    this->monthly_salary = monthly_salary;

    return 0;
}

float FullTimeEmployee::getMonthlySalary()
{
    return monthly_salary;
}

// End FullTimeEmployee
// ######################################

// ########################################
// PartTimeEmployee

class PartTimeEmployee: public Employee
{
private:
    float daily_wage;

public:
    PartTimeEmployee(
        std::string name, std::string departement, std::string role, float daily_wage
        );

    int setDailyWage(float daily_wage);
    float getDailyWage();
};

PartTimeEmployee::PartTimeEmployee(std::string name="name surname",
    std::string departement="undefined",
    std::string role="undefined",
    float daily_wage=0.f):Employee(name, departement, role)
{
    if(setDailyWage(daily_wage))
        std::cout<<"Invalid wage value";
}

int PartTimeEmployee::setDailyWage(float daily_wage)
{
    if (daily_wage < 0.f)
    {
        this->daily_wage = 0.f;

        return -1;
    }

    this->daily_wage = daily_wage;

    return 0;
}

float PartTimeEmployee::getDailyWage()
{
    return daily_wage;
}

// End PartTimeEmployee
// ######################################

int main()
{
    FullTimeEmployee full("John Snow", "Marketing", "Project manager", 5000);
    PartTimeEmployee part("Mr Bean", "Front Office", "Junior front office", 100);

    std::cout<<"Employee "<<full.getName()<<" has a montly salary of "<<full.getMonthlySalary()<<std::endl;

    std::cout<<"Employee "<<part.getName()<<" has a daily wage of "<<part.getDailyWage()<<std::endl;

    return 0;
}