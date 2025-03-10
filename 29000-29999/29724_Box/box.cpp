#include <iostream>

using namespace std;

const static int APPLE_BOX_LEN = 12;
const static int APPLE_BOX_WEIGHT = 500;
const static int APPLE_BOX_PACK_WEIGHT = 1000;
const static int APPLE_PRICE = 4000;
const static int PEAR_BOX_WEIGH = 6000;

int get_apple_price(int num_of_apples) {
    return (APPLE_PRICE * num_of_apples);
}

int get_num_of_apples(int W, int H, int L) {
    return ((W/APPLE_BOX_LEN) * (H/APPLE_BOX_LEN) * (L/APPLE_BOX_LEN));
}

int get_apple_box_weight(int num_of_apples) {
    return (num_of_apples*APPLE_BOX_WEIGHT) + APPLE_BOX_PACK_WEIGHT;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, total_weight, total_apple_price;

    cin>>N;
    total_weight = total_apple_price = 0;

    for (int i = 1; i <= N; i++) {
        char T;
        int W, H, L;

        cin>>T>>W>>H>>L;

        if (T == 'B') {
            total_weight += PEAR_BOX_WEIGH;
        } else { // T == 'A'
            int num_of_apples = get_num_of_apples(W,H,L);
            total_weight += get_apple_box_weight(num_of_apples);
            total_apple_price += get_apple_price(num_of_apples);
        }
    }

    cout<<total_weight<<'\n'<<total_apple_price<<'\n';
    return 0;
}