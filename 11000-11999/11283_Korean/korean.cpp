#include <iostream>
#include <string>

using namespace std;

char32_t to_char32(const string& s) {
    const unsigned char* p = (const unsigned char*)s.data();
    return (((p[0] & 0x0F) << 12) |
                ((p[1] & 0x3F) << 6) | (p[2] & 0x3F));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    getline(cin, s);
    
    int c = to_char32(s);
    cout << c - 44032 + 1 << '\n';

    return 0;
}