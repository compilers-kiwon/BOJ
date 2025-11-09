#include <iostream>
#include <vector>

using namespace std;

typedef long long int int64;

void input(int64& total_time, vector<int64>& periods) {
    int N;

    for (cin >> N >> total_time; N > 0; N--) {
        int64 p;
        cin >> p;
        periods.push_back(p);
    }
}

int64 get_product(int64 bits, const vector<int64>& p, int64& num_of_bits) {
    int64 ret;
    
    ret = 1LL, num_of_bits = 0LL;
    
    for (int64 idx = 0; (1LL << idx) <= bits; idx++) {
        if ((bits & (1LL << idx)) == 0) {
            continue;
        }

        ret *= p[idx], num_of_bits++;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 T, total_num;
    vector<int64> p;

    input(T, p);
    total_num = 0;

    for (int64 selected = 1; selected < (1LL << p.size()); selected++) {
        int64 product, num_of_bits, cnt;

        product = get_product(selected, p, num_of_bits);
        cnt = T / product;
        total_num += ((num_of_bits%2)==1)?cnt:-cnt;
    }

    cout << total_num << '\n';
    return 0;
}