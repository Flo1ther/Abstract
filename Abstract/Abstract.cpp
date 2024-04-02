#include <iostream>
#include <cmath>
#include <Windows.h>
class Equation {
public:
    virtual void calculateRoots() const = 0;

    virtual ~Equation() {}
};

class LinearEquation : public Equation {
private:
    double a, b;

public:
    LinearEquation(double a_val, double b_val) : a(a_val), b(b_val) {}

    void calculateRoots() const override {
        if (a == 0) {
            if (b == 0)
                std::cout << "Рівняння має безліч коренів\n";
            else
                std::cout << "Рівняння не має коренів\n";
        }
        else {
            double root = -b / a;
            std::cout << "Корінь рівняння: " << root << std::endl;
        }
    }
};
class QuadraticEquation : public Equation {
private:
    double a, b, c;

public:
    QuadraticEquation(double a_val, double b_val, double c_val) : a(a_val), b(b_val), c(c_val) {}

    void calculateRoots() const override {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "Перший корінь рівняння: " << root1 << std::endl;
            std::cout << "Другий корінь рівняння: " << root2 << std::endl;
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            std::cout << "Рівняння має один корінь: " << root << std::endl;
        }
        else {
            std::cout << "Рівняння не має дійсних коренів\n";
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    LinearEquation linear(2, 3);
    QuadraticEquation quadratic(1, -5, 6);

    std::cout << "Лінійне рівняння:\n";
    linear.calculateRoots();

    std::cout << "\nКвадратне рівняння:\n";
    quadratic.calculateRoots();

    return 0;
}
