#include <iostream>
#include <deque>
#include <unordered_map>
#include <cstdint>

using namespace std;

int N;
uint64_t start_num;
deque<uint64_t> A;
unordered_map<uint64_t,int> B;

void input(void) {
    cin>>N>>start_num;

    for (int i = 2; i <= N; i++) {
        uint64_t num;
        cin>>num;
        B[num]++;
    }
}

bool check_head(int& num_of_numbers) {
    uint64_t head_num = A.front();

    if (B[head_num*3] != 0) {
        num_of_numbers--;
        B[head_num*3]--;

        A.push_front(head_num*3);
        return true;
    }

    if (head_num%2 == 0 && B[head_num/2] != 0) {
        num_of_numbers--;
        B[head_num/2]--;

        A.push_front(head_num/2);
        return true;
    }

    return false;
}

bool check_tail(int& num_of_numbers) {
    uint64_t tail_num = A.back();

    if (tail_num%3 == 0 && B[tail_num/3] != 0) {
        num_of_numbers--;
        B[tail_num/3]--;

        A.push_back(tail_num/3);
        return true;
    }

    if (B[tail_num*2] != 0) {
        num_of_numbers--;
        B[tail_num*2]--;

        A.push_back(tail_num*2);
        return true;
    }

    return false;
}

void build_sequence(void) {
    A.push_back(start_num);
    N--;

    for (; N > 0;) {
        if (check_head(N) == false) {
            check_tail(N);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    input();
    build_sequence();

    for (; !A.empty(); A.pop_front()) {
        cout<<A.front()<<' ';
    }

    return 0;
}