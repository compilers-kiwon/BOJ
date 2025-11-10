#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

unordered_map<int, string> table = {
    {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"},
    {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
    {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"},
    {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"},
    {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"}, {30, "thirty"},
    {40, "forty"}, {50, "fifty"}, {60, "sixty"}, {70, "seventy"},
    {80, "eighty"}, {90, "ninety"}
};

void translate_num_into_word(int num, vector<string>& w) {
    if (num >= 100) {
        w.push_back(table[num/100]);
        w.push_back("hundred");
    }

    num %= 100;

    if (num == 0) {
        return;
    }

    if (IN_RANGE(20, num, 99)) {
        w.push_back(table[(num/10)*10]);
        
        if ((num % 10) != 0) {
            w.back() += "-" + table[num%10];
        }
    } else {
        w.push_back(table[num]);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        int X;
        vector<string> words;

        cin >> X;

        if (X == 0) {
            cout << "zero\n";
            continue;
        }

        if (X < 0) {
            words.push_back("negative"), X *= -1;
        }

        if (X >= 1000000) {
            translate_num_into_word(X / 1000000, words);
            words.push_back("million");
        }

        X %= 1000000;

        if (X >= 1000) {
            translate_num_into_word(X / 1000, words);
            words.push_back("thousand");
        }

        translate_num_into_word(X % 1000, words);

        for (int i = 0; i < words.size(); i++) {
            cout << words[i] << ((i==words.size()-1)?'\n':' ');
        }
    }

    return 0;
}