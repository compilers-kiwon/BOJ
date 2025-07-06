#include <iostream>

using namespace std;

#define MAX_NUM (1000000)
#define is_even(n) (((n)%2)==0)

bool used[MAX_NUM + 1] = {false, };

void get_numbers(int& num_of_odds, int& num_of_evens) {
    int N;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        int num;

        cin>>num;
        used[num] = true;
        is_even(num)?++num_of_evens:++num_of_odds;
    }
}

int determine_number(int start) {
    int ret;
    for (ret = start; used[ret] == true; ret += 2);
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_odds, num_of_evens;

    num_of_odds = num_of_evens = 0;
    get_numbers(num_of_odds, num_of_evens);

    cout<<determine_number(num_of_odds>num_of_evens?1:2)<<'\n';
    return 0;
}