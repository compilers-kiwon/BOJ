#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cout << fixed; cout.precision(6);

    int N;
    double V;
    
    for (cin >> N, V = 0.0; N > 0; --N) {
        double A;
        
        cin >> A;
        V = 1.0 - (1.0 - V) * (1.0 - A / 100.0);
        cout << V * 100.0 << '\n';
    }

    return 0;
}