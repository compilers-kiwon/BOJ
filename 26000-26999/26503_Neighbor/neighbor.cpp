#include <iostream>
#include <cmath>

using namespace std;

typedef struct {
    int numerator, denominator;
} Fraction;

void input(Fraction& f1, Fraction& f2) {
    cin >> f1.numerator >> f1.denominator;
    cin >> f2.numerator >> f2.denominator;
}

void make_common(Fraction& f1, Fraction& f2) {
    Fraction t1, t2;
    
    t1 = {f1.numerator * f2.denominator, f1.denominator * f2.denominator};
    t2 = {f2.numerator * f1.denominator, f2.denominator * f1.denominator};

    f1 = t1, f2 = t2;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        Fraction f1, f2, sub;

        input(f1, f2);
        make_common(f1, f2);
        
        sub = {abs(f1.numerator - f2.numerator), f1.denominator};
        
        if (sub.numerator != 0 && (sub.denominator % sub.numerator) == 0) {
            cout << "1/" << (sub.denominator / sub.numerator) << '\n';
        } else {
            cout << "NOT NEIGHBORS\n";
        }
    }

    return 0;
}