#include <iostream>
#include <vector>
using namespace std;

class BasePizza {
    public: 
        virtual int cost() = 0;
};

class ToppingsDecorator : public BasePizza {
    public: 
    virtual int cost() = 0;
};

class Margherita : public BasePizza {
    public: 
    int cost(){
        return 100;
    };
};

class FarmHouse : public BasePizza {
    public: 
    int cost(){
        return 110;
    };
};

class VegDelight : public BasePizza {
    public: 
    int cost(){
        return 150;
    };
};

class ExtraCheese : public ToppingsDecorator {
    private:
    BasePizza* basePizza;

    public: 
    ExtraCheese(BasePizza *basePizza){
        this->basePizza = basePizza;
    }

    int cost() {
        return basePizza->cost() + 10;
    };
};

class Mushroom : public ToppingsDecorator {
    private:
    BasePizza* basePizza;

    public: 
    Mushroom(BasePizza *basePizza){
        this->basePizza = basePizza;
    }
    int cost() {
        return basePizza->cost() + 15;
    };
};

int main() {
    BasePizza *obj = new Mushroom(new ExtraCheese(new Margherita()));

    cout<< obj->cost() <<endl;
    return 0;
}