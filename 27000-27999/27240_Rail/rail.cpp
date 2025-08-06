#include <iostream>

using namespace std;

#define IN_RANGE(area,st) ((area).first<=(st)&&(st)<=(area).second)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, a, b, s, t;
    pair<int, int> outside1, city, outside2;

    cin >> n >> a >> b >> s >> t;
    
    outside1.first = 1, outside1.second = a;
    city.first = a + 1, city.second = b - 1;
    outside2.first = b, outside2.second = n;

    if (IN_RANGE(city, s) && IN_RANGE(city, t)) {
        cout << "City\n";
    } else if ((IN_RANGE(outside1, s) && IN_RANGE(outside1, t))
                || (IN_RANGE(outside2, s) && IN_RANGE(outside2, t))) {
        cout << "Outside\n";    
    } else {
        cout << "Full\n";
    }

    return 0;
}