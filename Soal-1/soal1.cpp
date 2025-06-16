#include <iostream>
#include <iomanip>

class Vector2D {
private:
    double x, y;

public:
    // Constructor
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Operator overloading untuk penjumlahan
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // Operator overloading untuk pengurangan
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // Operator overloading untuk perkalian dengan skalar
    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    // Operator overloading untuk pembagian dengan skalar
    Vector2D operator/(double scalar) const {
       if (scalar == 0) {
        throw std::runtime_error("Pembagian dengan nol!");
    }
        return Vector2D(x / scalar, y / scalar);    
    }

    // Operator overloading untuk perbandingan kesamaan
    bool operator==(const Vector2D& other) const {
       const double EPSILON = 1e-9;
        return (std::abs(x - other.x) < EPSILON) && (std::abs(y - other.y) < EPSILON);

    }

    // Friend function untuk output stream
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "Vector(" << std::fixed << std::setprecision(2) << v.x << ", " << v.y << ")";
        return os;
    }

    // Getter methods (jika diperlukan)
    double getX() const { return x; }
    double getY() const { return y; }
};

int main() {
    double x1, y1, x2, y2, scalar;
    
    // Input dua vektor dan scalar
    std::cin >> x1 >> y1 >> x2 >> y2 >> scalar;
    
    Vector2D v1(x1, y1);
    Vector2D v2(x2, y2);
    
    // Output hasil operasi
    std::cout << "Vektor 1: " << v1 << std::endl;
    std::cout << "Vektor 2: " << v2 << std::endl;
    std::cout << "Penjumlahan: " << v1 + v2 << std::endl;
    std::cout << "Pengurangan: " << v1 - v2 << std::endl;
    std::cout << "Perkalian dengan " << scalar << ": " << v1 * scalar << std::endl;
    std::cout << "Pembagian dengan " << scalar << ": " << v1 / scalar << std::endl;
    std::cout << "Apakah sama? " << (v1 == v2 ? "Ya" : "Tidak") << std::endl;

    return 0;
}
