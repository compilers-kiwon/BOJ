#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 0x7FFFFFFF;

int get_size(int a, int b, int c) {
    return (2 * ((a * b) + (b * c) + (c * a)));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, size = INF;
    vector<int> lines;

    cin >> n;
    
    for (int a = 1; a <= 1000; a++) {
        for (int b = 1; b <= 1000; b++) {
            int c = n / (a * b);

            if ((a * b * c) == n) {
                int cur_size = get_size(a, b, c);

                if (cur_size < size) {
                    size = cur_size;
                    lines = {a, b , c};
                }
            }
        }
    }

    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << ((i==lines.size()-1)?'\n':' ');
    }
    
    return 0;
}