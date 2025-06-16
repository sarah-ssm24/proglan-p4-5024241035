#include <iostream>
#include <iomanip>
#include <cmath>

class ElementalDamage {
private:
    double baseDamage, elementalMultiplier;

public:
    // Constructor
    ElementalDamage(double base = 0, double multiplier = 0) : baseDamage(base), elementalMultiplier(multiplier) {}

    // Operator overloading untuk penjumlahan
    ElementalDamage operator+(const ElementalDamage& other) const {
        return ElementalDamage(baseDamage + other.baseDamage, elementalMultiplier + other.elementalMultiplier);
    }

    // Operator overloading untuk pengurangan
    ElementalDamage operator-(const ElementalDamage& other) const {
        return ElementalDamage(baseDamage - other.baseDamage, elementalMultiplier - other.elementalMultiplier);
    }

    // Operator overloading untuk perkalian
    ElementalDamage operator*(const ElementalDamage& other) const {
        // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
        double newBase = baseDamage * other.baseDamage - elementalMultiplier * other.elementalMultiplier;
        double newMultiplier = baseDamage * other.elementalMultiplier + elementalMultiplier * other.baseDamage;
        return ElementalDamage(newBase, newMultiplier);
    }

    // Operator overloading untuk pembagian
    ElementalDamage operator/(const ElementalDamage& other) const {
        // (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c² + d²)
        double denominator = other.baseDamage * other.baseDamage + other.elementalMultiplier * other.elementalMultiplier;
        if (denominator == 0) {
            std::cout << "Error: Division by zero!" << std::endl;
            return ElementalDamage(0, 0);
        }
        double newBase = (baseDamage * other.baseDamage + elementalMultiplier * other.elementalMultiplier) / denominator;
        double newMultiplier = (elementalMultiplier * other.baseDamage - baseDamage * other.elementalMultiplier) / denominator;
        return ElementalDamage(newBase, newMultiplier);
    }

    // Operator overloading untuk perbandingan kesamaan
    bool operator==(const ElementalDamage& other) const {
        const double EPSILON = 1e-9;
        return (std::abs(baseDamage - other.baseDamage) < EPSILON && 
                std::abs(elementalMultiplier - other.elementalMultiplier) < EPSILON);
    }

    // Friend function untuk input stream
    friend std::istream& operator>>(std::istream& is, ElementalDamage& damage) {
        is >> damage.baseDamage >> damage.elementalMultiplier;
        return is;
    }

    // Friend function untuk output stream
    friend std::ostream& operator<<(std::ostream& os, const ElementalDamage& damage) {
        if (damage.elementalMultiplier >= 0) {
            os << damage.baseDamage << " + " << damage.elementalMultiplier << "i";
        } else {
            os << damage.baseDamage << " - " << std::abs(damage.elementalMultiplier) << "i";
        }
        return os;
    }

    // Getter methods
    double getBaseDamage() const { return baseDamage; }
    double getElementalMultiplier() const { return elementalMultiplier; }
};

int main() {
    // TODO: Implementasikan main function
    // 1. Buat dua objek ElementalDamage
    // 2. Input damage dari user
    // 3. Lakukan operasi matematika menggunakan operator overloading
    // 4. Output hasil sesuai format yang diminta
    
    return 0;
}
