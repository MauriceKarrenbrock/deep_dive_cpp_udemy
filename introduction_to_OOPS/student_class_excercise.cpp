// Make a class called studen
#include<iostream>
#include<cstring>
#include<string>

class Student
{
private:
    int grade1;
    int grade2;
    int grade3;
    int rollNum;
    std::string name;

    bool checkGrade(int grade);

public:
    // Constructor
    Student(int grade1,
            int grade2,
            int grade3,
            int rollNum,
            std::string name);

    // Getters
    int getGrade1(){return grade1;};
    int getGrade2(){return grade2;};
    int getGrade3(){return grade3;};
    int getRollNum(){return rollNum;};
    std::string getName(){return name;};

    // Setters
    void setGrade1(int grade);
    void setGrade2(int grade);
    void setGrade3(int grade);
    void setRollNum(int n);
    void setName(std::string name);

    // Others
    int getTotal();
    float getAverage();
};

int main()
{   
    int grade1, grade2, grade3, rollnum;
    std::string name;

    std::cout<<"Input a name\n";

    std::getline(std::cin, name);

    std::cout<<"Input Roll number\n";

    std::cin>>rollnum;
    std::cin.ignore();


    std::cout<<"Input grade 1\n";

    std::cin>>grade1;
    std::cin.ignore();

    std::cout<<"Input grade 2\n";

    std::cin>>grade2;
    std::cin.ignore();

    std::cout<<"Input grade 3\n";

    std::cin>>grade3;
    std::cin.ignore();

    Student student(
        grade1,
        grade2,
        grade3,
        rollnum,
        name);

    std::cout<<"Total score "<<student.getTotal()<<std::endl;

    std::cout<<"Average score "<<student.getAverage()<<std::endl;

    return 0;
}

// Implementation of Student class

bool Student::checkGrade(int grade)
{
    if (grade < 0)
    {
        std::cout<<"Grade must be positive but you gave "<<grade<<std::endl;

        return false;
    }

    return true;
}

Student::Student(int grade1=0,
        int grade2=0,
        int grade3=0,
        int rollNum=0,
        std::string name="")
{
    setGrade1(grade1);
    setGrade2(grade2);
    setGrade3(grade3);
    setRollNum(rollNum);
    setName(name);
}

// Setters
void Student::setGrade1(int grade)
{
    if (checkGrade(grade))
        grade1 = grade;
    else
        grade1 = -1000; //dummy value
}

void Student::setGrade2(int grade)
{
    if (checkGrade(grade))
        grade2 = grade;
    else
        grade2 = -1000; //dummy value
}

void Student::setGrade3(int grade)
{
    if (checkGrade(grade))
        grade3 = grade;
    else
        grade3 = -1000; //dummy value
}

void Student::setRollNum(int n)
{
    rollNum = n;
}

void Student::setName(std::string name)
{
    name = name;
}

// Others
int Student::getTotal()
{
    return grade1 + grade2 + grade3;
}

float Student::getAverage()
{
    return getTotal() / 3.0f;
}
