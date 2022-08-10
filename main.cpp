#include <iostream>
#include <string>
#include <vector>

class Talent{
public:
    virtual void showTalent() = 0;
};

class Animal {
protected:
    std::string name;
    std::vector<Talent*> talents;
public:
    void addTalent(Talent* _talent) {
        talents.push_back(_talent);
    }
    void showTalents() {
        if (!talents.empty()) {
            std::cout << "This is " << name << " and it has some talents:" << std::endl;
            for (int i = 0; i < talents.size(); i++) {
                std::cout << "\t\tIt can \"";
                talents[i]->showTalent();
                std::cout << "\"" << std::endl;
            }
        } else {
            std::cout << "This is " << name << " and it has no talents." << std::endl;
        }
    }

};

class Swimming : virtual public Talent {
    void showTalent() override {
        std::cout << "Swim";
    }
};

class Dancing : virtual public Talent {
    void showTalent() override {
        std::cout << "Dance";
    }
};

class Counting : virtual public Talent {

    void showTalent() override {
        std::cout << "Count";
    }
};

class Cat: virtual public Animal {
public:
    Cat(const std::string& _name) {
        name = _name;
    }
};

class Dog: virtual public Animal {
public:
    Dog(const std::string& _name) {
        name = _name;
    }
};

int main() {
    std::string name;
    std::string talent;

    std::cout << "Enter name:" << std::endl;
    std::cin >> name;
    while (name.empty()) {
        std::cout << "Incorrect name. Enter name:" << std::endl;
        std::cin >> name;
    }
    Cat c(name);
    do {
        std::cout << "Enter talent (swimming, dancing, counting, end):" << std::endl;
        std::cin >> talent;
        if (talent == "swimming")
            c.addTalent(new Swimming());
        if (talent == "dancing")
            c.addTalent(new Dancing());
        if (talent == "counting")
            c.addTalent(new Counting());
    } while (talent != "end");
    c.showTalents();
    return 0;
}
