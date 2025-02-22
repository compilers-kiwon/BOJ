#include <iostream>
#include <queue>
#include <cstdint>

using namespace std;

typedef pair<int64_t,int64_t> Book;

priority_queue<Book> happy, unhappy;

void input(void) {
    int N;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        int64_t a, b;

        cin>>a>>b;

        if (a <= b) {
            happy.push({-a, b});
        } else {
            unhappy.push({b, -a});
        }
    }
}

int read_books(void) {
    int64_t cur_state = 0;

    for (; !happy.empty(); happy.pop()) {
        int64_t required = -happy.top().first;
        int64_t taken = happy.top().second;

        if ((cur_state-=required) < 0) {
            break;
        }

        cur_state += taken;
    }

    if (!happy.empty()) {
        return 0;
    }

    for (; !unhappy.empty(); unhappy.pop()) {
        int64_t required = -unhappy.top().second;
        int64_t taken = unhappy.top().first;

        if ((cur_state-=required) < 0) {
            break;
        }

        cur_state += taken;
    }

    if (!unhappy.empty()) {
        return 0;
    }

    return 1;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    input();
    cout<<read_books()<<'\n';

    return 0;
}