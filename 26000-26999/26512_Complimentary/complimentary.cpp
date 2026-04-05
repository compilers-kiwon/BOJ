#include <iostream>
#include <string>

using namespace std;

string get_bits(char num) {
    string ret;

    for (int i = 7; i >= 0; --i) {
        char d = num & (((char)1) << i);
        ret.push_back((d==0)?'0':'1');
    }

    return ret;
}

void simulate(char n1, char n2) {
    cout << (int)n1 << " = " << get_bits(n1) << '\n';
    cout << (int)n2 << " = " << get_bits(n2) << '\n';

    cout << '-' << (int)n1 << " = " << get_bits(n1 * ((char)-1)) << '\n';
    cout << '-' << (int)n2 << " = " << get_bits(n2 * ((char)-1)) << '\n';

    cout << (int)n1 - (int)n2 << " = " << get_bits(n1 - n2) << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int n1, n2;

        cin >> n1 >> n2;

        if (n1 == 0 && n2 == 0) {
            break;
        }

        simulate((char)n1, (char)n2);
        cout << '\n';
    }

    return 0;
}