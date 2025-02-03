#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string number;
    unordered_set<char> digits;

    cin>>number;

    for (size_t i = 0; i < number.length(); i++) {
        if (isdigit(number[i])) {
            digits.insert(number[i]);
        }
    }

    cout<<digits.size()<<'\n';

    return 0;
}
