#include <iostream>
#include <string>

using namespace std;

const string abcd = "abcdefghijklmnopqrstuvwxyz ";
const string qwer = "qwertyuiopasdfghjklzxcvbnm ";

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string N, str, converted;

    getline(cin, N);
    getline(cin, str);

    for (size_t i = 0; i < str.length(); i++) {
        converted.push_back(qwer[abcd.find(str[i])]);
    }

    cout << converted << '\n';

    return 0;
}