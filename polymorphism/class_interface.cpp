#include<iostream>

class Shape
{
    public:
        virtual float perimeter()=0;
        virtual float area()=0;
};

class Rectangle: public Shape
{
    private:
        float l1;
        float l2;
    
    public:
        Rectangle(float l1=0.f, float l2=0.f)
        {
            setL1(l1);
            setL2(l2);
        }

        void setL1(float l1)
        {
            this->l1 = l1;
        }
        void setL2(float l2)
        {
            this->l2 = l2;
        }

        float getL1()
        {
            return l1;
        }
        float getL2()
        {
            return l2;
        }

        float perimeter()
        {
            return (getL1() + getL2()) * 2.f;
        }

        float area()
        {
            return getL1() * getL2();
        }
};

class Circumference: public Shape
{
    private:
        float radius;
    
    public:
        Circumference(float r=0.f)
        {
            setRadius(r);
        }

        void setRadius(float r)
        {
            radius = r;
        }

        float getRadius()
        {
            return radius;
        }

        float perimeter()
        {
            return 2.f * 3.14f * getRadius();
        }

        float area()
        {
            return getRadius() * getRadius() * 3.14f;
        }
};

int main()
{
    Shape *r = new Rectangle(2.f, 3.f), *c = new Circumference(2.f);

    std::cout<<"Rectangle Area="<<r->area()<<" Perimeter="<<r->perimeter()<<std::endl;
    std::cout<<"Circumference Area="<<c->area()<<" Perimeter="<<c->perimeter()<<std::endl;

    return 0;
}