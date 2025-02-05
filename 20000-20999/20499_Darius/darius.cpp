#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define char2int(c) ((int)((c)-'0'))

const size_t K = 0;
const size_t D = 1;
const size_t A = 2;
const char DELIMITER = '/';

void get_numbers(const string& str, vector<int>& result) {
    int n = 0;

    for (size_t i = 0; i < str.length(); i++) {
        const char& c = str[i];

        if (c == DELIMITER) {
            result.push_back(n);
            n = 0;
        } else {
            n = n*10 + char2int(c);
        }
    }
}

int main(void) {
    string s;
    vector<int> num;

    cin>>s;
    s.push_back(DELIMITER);
    
    get_numbers(s, num);
    cout<<(((num[K]+num[A]<num[D])||(num[D]==0))?"hasu":"gosu")<<'\n';

    return 0;
}