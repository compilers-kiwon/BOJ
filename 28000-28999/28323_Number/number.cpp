#include <iostream>
#include <vector>

using namespace std;

enum {
    EVEN = 0,
    ODD = 1,
    MAX_ATTR = 2
};

#define change_attr(cur) (((cur)+1)%MAX_ATTR)
#define get_attr(num) ((num)%MAX_ATTR)

int get_unstable_numbers(int expected_attr, const vector<int>& A) {
    int ret = 0;

    for (int i = 0; i < A.size(); i++) {
        if (get_attr(A[i]) == expected_attr) {
            ret++;
            expected_attr = change_attr(expected_attr);
        }
    }

    return ret;
}

int get_biggest_unstable_numbers(const vector<int>& A) {
    int ret = 1;
    ret = max(ret,
            max(get_unstable_numbers(EVEN, A),
                get_unstable_numbers(ODD, A)));
    return ret;
}

void input(vector<int>& A) {
    int N;
    
    cin>>N;

    for (int i = 0; i < N; i++) {
        int num;
        cin>>num;
        A.push_back(num);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> A;

    input(A);
    cout<<get_biggest_unstable_numbers(A)<<'\n';

    return 0;
}