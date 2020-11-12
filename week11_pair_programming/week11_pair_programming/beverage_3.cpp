//#include <iostream>
//#include <string>
//
//
//class Beverage {
//
//protected:
//    std::string description;
//
//
//public:
//    int size;
//    Beverage() {
//        description = "unknown beverage";
//        size = -1;
//
//    }
//
//    virtual std::string getDescription() {
//        return description;
//    }
//
//    virtual double cost() = 0;
//
//
//};
//enum BeverageSize {
//    TALL,
//    GRANDE,
//    VENTI,
//};
//
//
//class CondimentDecorator : public Beverage {
//
//public:
//    CondimentDecorator(Beverage* beverage) {
//        this->_beverage = beverage;
//
//    }
//    std::string getDescription() {
//        return this->_beverage->getDescription();
//    }
//
//    double cost() {
//        return this->_beverage->cost();
//    }
//
//private: Beverage* _beverage;
//};
//
//class DarkRoast : public Beverage {
//public:
//    DarkRoast(BeverageSize SIZE) {
//        description = "Dark Roast Coffee";
//        size = SIZE;
//
//    }
//
//    double cost() {
//        return 0.99;
//    }
// 
//};
//
//class Decaf : public Beverage {
//public:
//    Decaf(BeverageSize SIZE) {
//        description = "Decaf Coffee";
//        size = SIZE;
//
//    }
//
//    double cost() {
//        return 1.05;
//
//    }
//   
//   
//};
//
//class Espresso : public Beverage {
//public:
//    Espresso(BeverageSize SIZE) {
//        description = "Espresso";
//        size = SIZE;
//    }
//
//    double cost() {
//        return 1.99;
//
//    }
//};
//
//class HouseBlend : public Beverage {
//public:
//    HouseBlend(BeverageSize SIZE) {
//        description = "House Blend Coffee";
//        size = SIZE;
//    }
//
//    double cost() {
//        return 0.89;
//
//    }
//};
//class Milk : public CondimentDecorator {
//public:
//    Milk(Beverage* beverage) : CondimentDecorator(beverage) {
//        size = beverage -> size;
//    }
//    std::string getDescription() {
//        return CondimentDecorator::getDescription() + ", Milk";
//    }
//
//    double cost() {
//        if (getSize() == TALL) {
//            return  CondimentDecorator::cost() + 0.10;
//        }
//        else if (getSize() == GRANDE) {
//            return CondimentDecorator::cost()+0.30;
//        }
//        else if (getSize() == VENTI) {
//            return CondimentDecorator::cost()+0.50;
//        }
//
//    }
//    BeverageSize getSize() {
//        if (size == TALL) { return TALL; }
//        else if (size == GRANDE) { return GRANDE; }
//        else if (size == VENTI) { return VENTI; }
//
//    }
//};
//
//class Soy : public CondimentDecorator {
//public:
//    Soy(Beverage* beverage) : CondimentDecorator(beverage) {
//        size = beverage->size;
//    }
//    std::string getDescription() {
//        return CondimentDecorator::getDescription() + ", Soy";
//    }
//
//    double cost() {
//        if(getSize()== TALL){
//            return 0.15 + CondimentDecorator::cost();
//		}
//        else if(getSize()==GRANDE){
//            return 0.35 + CondimentDecorator::cost();
//		}
//        else if(getSize()==VENTI){
//            return 0.55 + CondimentDecorator::cost();
//		}
//    }
//    BeverageSize getSize() {
//      if (size == TALL) { return TALL; }
//      else if (size == GRANDE) { return GRANDE; }
//      else if (size == VENTI) { return VENTI; }
//    }
//};
//
//class Mocha : public CondimentDecorator {
//public:
//    Mocha(Beverage* beverage) : CondimentDecorator(beverage) {
//        size = beverage->size;
//    }
//    std::string getDescription() {
//        return CondimentDecorator::getDescription() + ", Mocha";
//    }
//
//    double cost() {
//        if (getSize() == TALL) {
//            return 0.20 + CondimentDecorator::cost();
//        }
//        else if (getSize() == GRANDE) {
//            return 0.40 + CondimentDecorator::cost();
//        }
//        else if (getSize() == VENTI) {
//            return 0.60 + CondimentDecorator::cost();
//        }
//    }
//    BeverageSize getSize() {
//        if (size == TALL) { return TALL; }
//        else if (size == GRANDE) { return GRANDE; }
//        else if (size == VENTI) { return VENTI; }
//    }
//};
//
//class Whip : public CondimentDecorator {
//public:
//    Whip(Beverage* beverage) : CondimentDecorator(beverage) {
//        size = beverage->size;
//    }
//    std::string getDescription() {
//        return CondimentDecorator::getDescription() + ", Whip";
//    }
//
//    double cost() {
//        if (getSize() == TALL) {
//            return 0.10 + CondimentDecorator::cost();
//        }
//        else if (getSize() == GRANDE) {
//            return 0.30 + CondimentDecorator::cost();
//        }
//        else if (getSize() == VENTI) {
//            return 0.50 + CondimentDecorator::cost();
//        }
//    }
//
//    BeverageSize getSize() {
//      if (size == TALL) { return TALL; }
//      else if (size == GRANDE) { return GRANDE; }
//      else if (size == VENTI) { return VENTI; }
//    }
//};
//
//
//int main() {
//    Beverage* beverage2 = new DarkRoast(TALL);
//    beverage2 = new Mocha(beverage2);
//    beverage2 = new Milk(beverage2);
//    beverage2 = new Soy(beverage2);
//    beverage2 = new Whip(beverage2);
//    std::cout << beverage2->getDescription() + " : " << beverage2->cost() << std::endl;
//
//    Beverage* beverage1 = new DarkRoast(GRANDE);
//    beverage1 = new Mocha(beverage1);
//    beverage1 = new Milk(beverage1);
//    beverage1 = new Soy(beverage1);
//    beverage1 = new Whip(beverage1);
//    std::cout << beverage1->getDescription() + " : " << beverage1->cost() << std::endl;
//
//    Beverage* beverage3 = new HouseBlend(VENTI);
//    beverage2 = new Mocha(beverage3);
//    beverage2 = new Milk(beverage3);
//    beverage2 = new Soy(beverage3);
//    beverage2 = new Whip(beverage3);
//    std::cout << beverage3->getDescription() + " : " << beverage3->cost() << std::endl;
//
//}