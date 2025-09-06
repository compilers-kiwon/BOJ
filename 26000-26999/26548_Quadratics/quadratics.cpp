#include <iostream>
#include <cmath>

using namespace std;

double solve_positive(double a, double b, double c) {
    return ((-b + sqrt((b * b) - (4 * a * c))) / (2 * a));
}

double solve_negative(double a, double b, double c) {
    return ((-b - sqrt((b * b) - (4 * a * c))) / (2 * a));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cout << fixed;
    cout.precision(3);

    int n;

    for (cin >> n; n > 0; n--) {
        double a, b, c;
        cin >> a >> b >> c;
        cout << solve_positive(a, b, c) << ", "
                << solve_negative(a, b, c) << '\n';
    }

    return 0;
}