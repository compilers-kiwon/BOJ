#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define get_idx(c)  ((int)(c-'a'))

typedef unsigned int uint32;

int N, M;
uint32 memorized;
vector<uint32> words;

uint32 get_bits_for_word(const string& word) {
    uint32 ret = 0;

    for (int i = 0; i < word.length(); i++) {
        ret |= 1 << get_idx(word[i]);
    }

    return ret;
}

int get_num_of_memorized_words(void) {
    int ret = 0;

    for (int i = 0; i < words.size(); i++) {
        ret += ((memorized&words[i])==words[i])?1:0;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> M;
    memorized = 0xFFFFFFFF;

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        words.push_back(get_bits_for_word(s));
    }

    for (int i = 1; i <= M; i++) {
        char o, x;

        cin >> o >> x;

        if (o == '1') {
            memorized -= 1 << get_idx(x);
        } else {
            memorized += 1 << get_idx(x);
        }

        cout << get_num_of_memorized_words() << '\n';
    }

    return 0;
}