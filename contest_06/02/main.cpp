#include<cmath>

class Employee {
public:
    std::string name;
    std::string role;
    int money;
    Employee(std::string name, std::string role, int money) {
        this->name = name;
        this->role = role;
        this->money = money;
    }
    int bonus(double proc = 0) {
        double buf = this->money;
        if (this->role == "manager" and proc < 0.10) {
            buf = round(buf * 0.10);
        }
        else{
            buf = round(buf* proc);
        }
        return buf;
    }
    int salary() {
        return this->money + this->bonus(bonuses[this->role]);
    }

};

std::ostream& operator<<(std::ostream& out, Employee& per) {
    out << per.name <<" ("<< per.role <<"): " << per.salary();
    return out;
}

class Manager : public Employee {
public:
    Manager(std::string name, int money = 16242)
        :Employee(name, "manager", money) {
    }
};
