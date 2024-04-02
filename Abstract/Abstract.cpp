#include <iostream>
#include <fstream>
#include <vector>
class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(std::ofstream& file) const = 0;
    virtual void Load(std::ifstream& file) = 0;
    virtual ~Shape() {}
};

class Square : public Shape {
private:
    int x, y;
    int side;

public:
    Square(int x_val, int y_val, int side_val) : x(x_val), y(y_val), side(side_val) {}

    void Show() const override {
        std::cout << "Square: top left corner (" << x << ", " << y << "), side length: " << side << std::endl;
    }

    void Save(std::ofstream& file) const override {
        file << "Square " << x << " " << y << " " << side << std::endl;
    }

    void Load(std::ifstream& file) override {
        file >> x >> y >> side;
    }
};

class Rectangle : public Shape {
private:
    int x, y;
    int width, height;

public:
    Rectangle(int x_val, int y_val, int width_val, int height_val) : x(x_val), y(y_val), width(width_val), height(height_val) {}

    void Show() const override {
        std::cout << "Rectangle: top left corner (" << x << ", " << y << "), width: " << width << ", height: " << height << std::endl;
    }

    void Save(std::ofstream& file) const override {
        file << "Rectangle " << x << " " << y << " " << width << " " << height << std::endl;
    }

    void Load(std::ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

class Circle : public Shape {
private:
    int x, y;
    int radius;

public:
    Circle(int x_val, int y_val, int radius_val) : x(x_val), y(y_val), radius(radius_val) {}

    void Show() const override {
        std::cout << "Circle: center (" << x << ", " << y << "), radius: " << radius << std::endl;
    }

    void Save(std::ofstream& file) const override {
        file << "Circle " << x << " " << y << " " << radius << std::endl;
    }

    void Load(std::ifstream& file) override {
        file >> x >> y >> radius;
    }
};

class Ellipse : public Shape {
private:
    int x, y;
    int width, height;

public:
    Ellipse(int x_val, int y_val, int width_val, int height_val) : x(x_val), y(y_val), width(width_val), height(height_val) {}

    void Show() const override {
        std::cout << "Ellipse: top left corner of the bounding rectangle (" << x << ", " << y << "), width: " << width << ", height: " << height << std::endl;
    }

    void Save(std::ofstream& file) const override {
        file << "Ellipse " << x << " " << y << " " << width << " " << height << std::endl;
    }

    void Load(std::ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Square(0, 0, 5));
    shapes.push_back(new Rectangle(2, 3, 6, 4));
    shapes.push_back(new Circle(1, 1, 3));
    shapes.push_back(new Ellipse(4, 4, 5, 3));

    std::ofstream outFile("shapes.txt");
    if (outFile.is_open()) {
        for (const auto& shape : shapes) {
            shape->Save(outFile);
        }
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing\n";
        return 1;
    }

    std::ifstream inFile("shapes.txt");
    if (inFile.is_open()) {
        std::cout << "Shapes read from file:\n";
        while (!inFile.eof()) {
            std::string type;
            inFile >> type;

            if (type == "Square") {
                Square* square = new Square(0, 0, 0);
                square->Load(inFile);
                square->Show();
                delete square;
            }
            else if (type == "Rectangle") {
                Rectangle* rectangle = new Rectangle(0, 0, 0, 0);
                rectangle->Load(inFile);
                rectangle->Show();
                delete rectangle;
            }
            else if (type == "Circle") {
                Circle* circle = new Circle(0, 0, 0);
                circle->Load(inFile);
                circle->Show();
                delete circle;
            }
            else if (type == "Ellipse") {
                Ellipse* ellipse = new Ellipse(0, 0, 0, 0);
                ellipse->Load(inFile);
                ellipse->Show();
                delete ellipse;
            }
        }
        inFile.close();
    }
    else {
        std::cerr << "Unable to open file for reading\n";
        return 1;
    }

    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}
