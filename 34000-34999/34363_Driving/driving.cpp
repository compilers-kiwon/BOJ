#include <iostream>

using namespace std;

double get_feets_per_sec(double miles_per_hour) {
    return (miles_per_hour * 5280.0f / 3600.0f);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double S, D, T;

    cin >> S >> D >> T;
    cout << (((get_feets_per_sec(S)*T)>=D)?
                "MADE IT":"FAILED TEST") << '\n';
    return 0;
}