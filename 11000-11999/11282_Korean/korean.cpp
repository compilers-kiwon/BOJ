#include <iostream>
#include <string>

using namespace std;

string char32_to_utf8(char32_t c) {
    string s;
    
    if (c <= 0x7F) {
        s.push_back(static_cast<char>(c));
    } else if (c <= 0x7FF) {
        s.push_back(static_cast<char>(0xC0 | (c >> 6)));
        s.push_back(static_cast<char>(0x80 | (c & 0x3F)));
    } else if (c <= 0xFFFF) {
        s.push_back(static_cast<char>(0xE0 | (c >> 12)));
        s.push_back(static_cast<char>(0x80 | ((c >> 6) & 0x3F)));
        s.push_back(static_cast<char>(0x80 | (c & 0x3F)));
    } else {
        s.push_back(static_cast<char>(0xF0 | (c >> 18)));
        s.push_back(static_cast<char>(0x80 | ((c >> 12) & 0x3F)));
        s.push_back(static_cast<char>(0x80 | ((c >> 6) & 0x3F)));
        s.push_back(static_cast<char>(0x80 | (c & 0x3F)));
    }

    return s;
}

int main() {
    int N;

    cin >> N;

    char32_t c = N - 1 + 44032;
    std::string s = char32_to_utf8(c);
    std::cout << s << '\n';

    return 0;
}