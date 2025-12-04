#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {
private:
    float* coeffs;  // Array for coefficients
    int degree;     // Highest power

public:
    // Default constructor - degree 5
    Polynomial() {
        degree = 5;
        coeffs = new float[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coeffs[i] = 0;
        }
        cout << "Created polynomial of degree 5" << endl;
    }
    
    // Constructor with specific degree
    Polynomial(int deg) {
        if (deg < 0) deg = 0;
        degree = deg;
        coeffs = new float[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coeffs[i] = 0;
        }
        cout << "Created polynomial of degree " << degree << endl;
    }
    
    // Destructor
    ~Polynomial() {
        delete[] coeffs;
    }
    
    // Set coefficient for x^power
    void setCoeff(int power, float value) {
        if (power >= 0 && power <= degree) {
            coeffs[power] = value;
            cout << "Set coefficient for x^" << power << " to " << value << endl;
        } else {
            cout << "Invalid power! Must be 0 to " << degree << endl;
        }
    }
    
    // Get coefficient
    float getCoeff(int power) {
        if (power >= 0 && power <= degree) {
            return coeffs[power];
        }
        return 0;
    }
    
    // Show polynomial
    void show() {
        cout << "Polynomial: ";
        bool first = true;
        
        for (int i = degree; i >= 0; i--) {
            if (coeffs[i] != 0) {
                if (!first && coeffs[i] > 0) cout << " + ";
                if (coeffs[i] < 0) cout << " - ";
                
                float val = abs(coeffs[i]);
                if (val != 1 || i == 0) cout << val;
                
                if (i > 0) {
                    cout << "x";
                    if (i > 1) cout << "^" << i;
                }
                first = false;
            }
        }
        
        if (first) cout << "0";
        cout << endl;
    }
    
    // Add two polynomials
    Polynomial add(Polynomial other) {
        int maxDegree = max(degree, other.degree);
        Polynomial result(maxDegree);
        
        for (int i = 0; i <= maxDegree; i++) {
            float c1 = (i <= degree) ? coeffs[i] : 0;
            float c2 = (i <= other.degree) ? other.coeffs[i] : 0;
            result.setCoeff(i, c1 + c2);
        }
        
        return result;
    }
    
    // Evaluate at x
    float evaluate(float x) {
        float result = 0;
        for (int i = degree; i >= 0; i--) {
            result = result * x + coeffs[i];
        }
        return result;
    }
    
    // Get derivative
    Polynomial derivative() {
        if (degree == 0) {
            Polynomial result(0);
            result.setCoeff(0, 0);
            return result;
        }
        
        Polynomial result(degree - 1);
        for (int i = 1; i <= degree; i++) {
            result.setCoeff(i - 1, coeffs[i] * i);
        }
        return result;
    }
};

int main() {
    cout << "=== POLYNOMIAL CALCULATOR ===" << endl;
    
    // Create first polynomial: 2x^3 - x^2 + 3x - 4
    cout << "\n1. Creating polynomial p1:" << endl;
    Polynomial p1(3);
    p1.setCoeff(3, 2);   // 2x^3
    p1.setCoeff(2, -1);  // -x^2
    p1.setCoeff(1, 3);   // 3x
    p1.setCoeff(0, -4);  // -4
    p1.show();
    
    // Create second polynomial: x^2 + 2x + 1
    cout << "\n2. Creating polynomial p2:" << endl;
    Polynomial p2(2);
    p2.setCoeff(2, 1);   // x^2
    p2.setCoeff(1, 2);   // 2x
    p2.setCoeff(0, 1);   // 1
    p2.show();
    
    // Add them
    cout << "\n3. Adding p1 and p2:" << endl;
    Polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.show();
    
    // Evaluate p1 at x=2
    cout << "\n4. Evaluating p1 at x=2:" << endl;
    float value = p1.evaluate(2);
    cout << "p1(2) = " << value << endl;
    
    // Get derivative of p1
    cout << "\n5. Derivative of p1:" << endl;
    Polynomial deriv = p1.derivative();
    deriv.show();
    
    // Evaluate derivative at x=1
    cout << "\n6. Evaluating derivative at x=1:" << endl;
    float derivValue = deriv.evaluate(1);
    cout << "p1'(1) = " << derivValue << endl;
    
    // Create polynomial from user input
    cout << "\n7. Create your own polynomial:" << endl;
    int deg;
    cout << "Enter degree: ";
    cin >> deg;
    
    Polynomial userPoly(deg);
    for (int i = deg; i >= 0; i--) {
        float coeff;
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> coeff;
        userPoly.setCoeff(i, coeff);
    }
    
    cout << "Your polynomial: ";
    userPoly.show();
    
    return 0;
}
