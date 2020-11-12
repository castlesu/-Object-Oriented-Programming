#include <iostream>
#include <string>

class Beverage
{
public:

    Beverage() {
        description = "Unknown Beverage";
    }

    virtual std::string getDescription() {
        return description;
    }

    virtual double cost() = 0;

protected:
    std::string description;

};

class CondimentDecorator : public Beverage
{
public:
    CondimentDecorator(Beverage* beverage) {

        this->_beverage = beverage;
    }

    std::string getDescription()
    {
        return this->_beverage->getDescription();
    }

    double cost()
    {
        return this->_beverage->cost();
    }

private:
    Beverage* _beverage;
};

class DarkRoast : public Beverage
{
public:
    DarkRoast() {
        description = "Dark Roast Coffee";
    }

    double cost() {
        return 0.99;
    }
};

class Decaf : public Beverage
{
public:
    Decaf() {
        description = "Decaf Coffee";
    }

    double cost() {
        return 1.05;
    }
};

class Espresso : public Beverage
{
public:
    Espresso() {
        description = "Espresso";
    }

    double cost() {
        return 1.99;
    }
};

class HouseBlend : public Beverage
{
public:
    HouseBlend() {
        description = "House Blend Coffee";
    }

    double cost() {
        return 0.89;
    }
};

class Soy : public CondimentDecorator
{
public:

    Soy(Beverage* beverage) : CondimentDecorator(beverage) {}

    std::string getDescription()
    {
        return CondimentDecorator::getDescription() + ", Soy ";
    }

    double cost()
    {
        return (0.15 + CondimentDecorator::cost());
    }
};



class Mocha : public CondimentDecorator
{
public:

    Mocha(Beverage* beverage) : CondimentDecorator(beverage) {}

    std::string getDescription()
    {
        return CondimentDecorator::getDescription() + ", Mocha ";
    }

    double cost()
    {
        return (0.20 + CondimentDecorator::cost());
    }
};

class Whip : public CondimentDecorator
{
public:

    Whip(Beverage* beverage) : CondimentDecorator(beverage) {}

    std::string getDescription()
    {
        return CondimentDecorator::getDescription() + ", Whip ";
    }

    double cost()
    {
        return (0.10 + CondimentDecorator::cost());
    }
};

class Milk : public CondimentDecorator
{
public:

    Milk(Beverage* beverage) : CondimentDecorator(beverage) {}

    std::string getDescription()
    {
        return CondimentDecorator::getDescription() + ", Milk ";
    }

    double cost()
    {
        return (0.10 + CondimentDecorator::cost());
    }
};

int main()
{

    Beverage* beverage = new Espresso();
    std::cout << beverage->getDescription() + "  :" << beverage->cost() << std::endl;

    Beverage* beverage2 = new DarkRoast();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Milk(beverage2);
    beverage2 = new Whip(beverage2);
    std::cout << beverage2->getDescription() + "  :" << beverage2->cost() << std::endl;


    Beverage* beverage3 = new HouseBlend();
    beverage3 = new Soy(beverage3);
    beverage3 = new Milk(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    std::cout << beverage3->getDescription() + "  :" << beverage3->cost() << std::endl;

}