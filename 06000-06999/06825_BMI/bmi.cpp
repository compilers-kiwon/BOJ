#include <iostream>
#include <string>

using namespace std;

string calculate(double weight, double height) {
    string ret;
    double idx = weight / (height * height);

    if (idx > 25.0) {
        ret = "Overweight";
    } else if (idx < 18.5) {
        ret = "Underweight";
    } else {
        ret = "Normal weight";
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double height, weight;

    cin >> weight >> height;
    cout << calculate(weight, height) << '\n';

    return 0;
}