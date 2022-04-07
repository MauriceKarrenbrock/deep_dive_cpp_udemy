#include<iostream>

// p/q
class Rational
{
private:
    int p;
    int q;

public:
    Rational(int p, int q);
    
    //setters
    void setP(int p);
    void setQ(int q);

    //getters
    int getP();
    int getQ();

    // Operator overloadings
    friend Rational operator + (Rational &r1, Rational &r2);
    
    friend std::ostream & operator << (std::ostream &o, Rational &r);
};

// Iplementation of Rational
Rational::Rational(int p=0, int q=1)
{
    setP(p);
    setQ(q);
}

//setters
void Rational::setP(int p)
{
    this->p = p;
}

void Rational::setQ(int q)
{
    if (q != 0)
        this->q = q;
    else
    {
        std::cout<<"q can not be zero!";
        this->q = 1;
    }
}

//getters
int Rational::getP(){return p;}
int Rational::getQ(){return q;}

// Operator overloadings
Rational operator + (Rational &r1, Rational &r2)
{
    Rational tmp;

    tmp.p = (r1.p * r2.q) + (r2.p * r1.q);

    tmp.q = r1.q * r2.q;

    return tmp;
}

std::ostream & operator << (std::ostream &o, Rational &r)
{
    o<<r.p<<"/"<<r.q;
    return o;
}

int main()
{
    Rational r1(3, 4), r2(2, 5), r3;

    r3 = r1 + r2;

    std::cout<<"Sum of "<<r1<<" and "<<r2<<" = "<<r3<<std::endl;

    return 0;
}