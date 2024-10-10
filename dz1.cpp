#include <iostream> 
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd_value = gcd(abs(numerator), abs(denominator));
        numerator /= gcd_value;
        denominator /= gcd_value;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            cout << "Error: denominator cannot be zero." << endl;
            denominator = 1;
        }
        simplify();
    }

    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Error: denominator cannot be zero." << endl;
            denominator = 1;
        }
        simplify();
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction add(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction subtract(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction divide(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        if (denom == 0) {
            cout << "Error: division by zero." << endl;
            denom = 1;
        }
        return Fraction(num, denom);
    }
};

int main() {
    Fraction fraction1, fraction2;
    cout << "Enter the first fraction:" << endl;
    fraction1.input();

    cout << "Enter the second fraction:" << endl;
    fraction2.input();

    cout << "Result of addition: ";
    Fraction result = fraction1.add(fraction2);
    result.display();

    cout << "Result of subtraction: ";
    result = fraction1.subtract(fraction2);
    result.display();

    cout << "Result of multiplication: ";
    result = fraction1.multiply(fraction2);
    result.display();

    cout << "Result of division: ";
    result = fraction1.divide(fraction2);
    result.display();

    return 0;
}