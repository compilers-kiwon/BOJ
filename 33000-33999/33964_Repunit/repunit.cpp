#include <iostream>

using namespace std;

int build_num(int num_of_digits) {
    int ret = 0;

    for (int i = 1; i <= num_of_digits; i++) {
        ret = (ret * 10) + 1;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X, Y;

    cin>>X>>Y;
    cout<<build_num(X) + build_num(Y)<<'\n';

    return 0;
}