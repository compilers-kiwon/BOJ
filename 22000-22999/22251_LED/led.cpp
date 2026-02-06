#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM (1000000)

vector<int> led_num[MAX_NUM];

int get_num_of_leds_to_be_flipped(int src, int dst) {
    const int led[10] = {0x7E, 0x30,0x6D, 0x79, 0x33,
                            0x5B, 0x5F, 0x70, 0x7F, 0x7B};
    return __builtin_popcount(led[src] ^ led[dst]);
}

void disassemble(int num, vector<int>& digits, int size) {
    for (; num > 0; num /= 10) {
        digits.push_back(num % 10);
    }

    for (; digits.size() < size;) {
        digits.push_back(0);
    }
}

void init(int max_num, int num_of_digits) {
    for (int i = 1; i <= max_num; ++i) {
        disassemble(i, led_num[i], num_of_digits);
    }
}

int flip(const vector<int>& src, int dst_num, int num_of_digits) {
    int ret = 0;
    
    for (int i = 0; i < num_of_digits; ++i) {
        ret += get_num_of_leds_to_be_flipped(src[i], led_num[dst_num][i]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> d;
    int N, K, P, X, cnt;

    cin >> N >> K >> P >> X, cnt = 0;    
    init(N, K), disassemble(X, d, K);

    for (int i = 1; i <= N; ++i) {
        int n = flip(d, i, K);
        cnt += (n<=P)?1:0;
    }

    cout << cnt - 1 << '\n';

    return 0;
}