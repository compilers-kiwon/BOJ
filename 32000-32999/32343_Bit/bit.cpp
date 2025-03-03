#include <iostream>

using namespace std;

int get_num_of_ones(int num) {
    int ret = 0;

    for (int pos = 0; (1<<pos) <= num; pos++) {
        if ((num & (1<<pos)) != 0) {
            ret++;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int N, a, b, max_xor, max_num;

    cin>>N>>a>>b;
    max_xor = 0;
    max_num = (1<<N) - 1;

    for (int x = 0; x <= max_num; x++) {
        int num_of_ones_in_x = get_num_of_ones(x);

        for (int y = 0; y <= max_num; y++) {
            int num_of_ones_in_y = get_num_of_ones(y);

            if ((num_of_ones_in_x == a) && (num_of_ones_in_y == b)) {
                max_xor = max(max_xor, x^y);
            }
        }
    }

    cout<<max_xor<<'\n';

    return 0;
}