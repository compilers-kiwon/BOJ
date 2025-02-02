#include <iostream>

using namespace std;

int get_num_of_ways(int d1, int d2, int sum) {
    int ret = 0;

    for (int i = 1; i <= d1 && i < sum; i++) {
        ret += ((sum - i) <= d2)?1:0;
    }

    return ret;
}

int main(void) {
    const int TARGET = 10;
    int m, n, w;

    cin>>m>>n;
    w = get_num_of_ways(m, n, TARGET);

    if (w == 1) {
        cout<<"There is 1 way to get the sum "<<TARGET<<".\n";
    } else {
        cout<<"There are "<<w<<" ways to get the sum "<<TARGET<<".\n";
    }

    return 0;
}