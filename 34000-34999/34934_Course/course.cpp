#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, last;
    string course;

    for (cin >> N, last = 0; N > 0; N--) {
        string s;
        int year;

        cin >> s >> year;

        if (year > last) {
            last = year, course = s;
        }
    }

    cout << course << '\n';

    return 0;
}