#include <iostream>
#include <string>

using namespace std;

void do_button1(string& s, int n) {
    for (int i = 1; i <= n; ++i) {
        s.push_back(s.front());
        s.erase(0, 1);
    }
}

void do_button2(string& s, int n) {
    for (int i = 1; i <= n; ++i) {
        s.insert(s.begin(), s.back());
        s.pop_back();
    }
}

void do_button3(string& s, int n) {
    for (int i = 1; i <= n; ++i) {
        swap(s[0], s[1]);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s = "ABCDE";

    for (bool stop = false;!stop;) {
        int b, n;
        
        cin >> b >> n;

        switch (b) {
            case 1: do_button1(s, n); break;
            case 2: do_button2(s, n); break;
            case 3: do_button3(s, n); break;
            case 4: stop = true; break;
            default: /* do nothing*/; break;
        }
    }

    for (int i = 0; i < s.length(); ++i) {
        cout << s[i] << ' ';
    }

    return 0;
}