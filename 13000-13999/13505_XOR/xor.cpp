#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MSB_POS (29)
#define LSB_POS (0)
#define MAX_LEN (MSB_POS+1)

void get_all_bits(const vector<int>& numbers, set<int> bits[]) {
    for (int i = 0; i < numbers.size(); ++i) {
        int bit_seq = 0;
        int n = numbers[i];

        for (int b = MSB_POS; b >= LSB_POS; --b) {
            bit_seq = bit_seq * 2 + (((n & (1 << b)) != 0)?1:0);
            bits[MAX_LEN-b].insert(bit_seq);
        }
    }
}

int simulate(const set<int> bits[],
                const vector<int>& numbers) {
    int max_xor_num = -1;

    for (int i = 0; i < numbers.size(); ++i) {
        int paired_num = 0;

        for (int b = MSB_POS; b >= LSB_POS; --b) {
            int tail = ((numbers[i] & (1 << b)) == 0)?1:0;
            paired_num = paired_num * 2 + tail;

            if (bits[MAX_LEN-b].find(paired_num) == bits[MAX_LEN-b].end()) {
                paired_num += (tail==0)?1:-1;
            }
        }
        
        max_xor_num = max(max_xor_num, numbers[i] ^ paired_num);
    }

    return max_xor_num;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> num;
    set<int> bits[MAX_LEN+1];

    for (cin >> N; N > 0; --N) {
        int A;
        cin >> A;
        num.push_back(A);
    }

    get_all_bits(num, bits);
    cout << simulate(bits, num) << '\n';

    return 0;
}