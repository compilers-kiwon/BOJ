#include <iostream>

using namespace std;

#define MAX_ROUND (20)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int n, r, num_of_required_lower_ranks[MAX_ROUND+1];

    cin>>n>>r;
    
    for (int i = 1; i <= n; i++) {
        num_of_required_lower_ranks[i] = (1 << (i - 1)) - 1;
    }

    int highest_round, num_of_lower_ranks;

    highest_round = 1, num_of_lower_ranks = (1 << n) - r;

    for (; highest_round < n; highest_round++) {
        if (num_of_lower_ranks >= num_of_required_lower_ranks[highest_round]
                && num_of_lower_ranks < num_of_required_lower_ranks[highest_round+1]) {
            break;
        }
    }

    cout<<highest_round<<'\n';
    return 0;
}