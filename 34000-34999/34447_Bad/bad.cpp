#include <iostream>
#include <string>

using namespace std;

#define chr2int(c) ((int)((c)-'0'))
#define int2chr(i) ((char)((i)+(int)'0'))

string decrypt(int key, const string& encrypted) {
    string ret;
    
    for (int i = 0; i < encrypted.length(); i++) {
        char c = encrypted[i];
        c = int2chr((chr2int(c) + key) % 10);
        ret.push_back(c);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        int k;
        string n;

        cin >> k >> n;
        cout << decrypt(k, n) << '\n';
    }

    return 0;
}