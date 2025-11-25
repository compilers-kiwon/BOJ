#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_SIZE (100000+1)

enum {
    START = 0,
    END = 1,
};

typedef tuple<int, int, int> Event; // <-time, attr, idx>

int N, placed[MAX_SIZE];

int simulate(priority_queue<Event>& pq) {
    int num_of_rooms = 0;
    queue<int> avaiable;

    for (; !pq.empty(); pq.pop()) {
        int attr = get<1>(pq.top());
        int idx = get<2>(pq.top());
        
        if (attr == END) {
            avaiable.push(placed[idx]);
        } else {
            if (avaiable.empty()) {
                avaiable.push(++num_of_rooms);
            }

            int cur_room = avaiable.front();

            avaiable.pop();
            placed[idx] = cur_room;
        }
    }

    return num_of_rooms;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<Event> pq;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int s, e, n;
        cin >> n >> s >> e;
        pq.push({-s, START, n}), pq.push({-e, END, n});
    }

    cout << simulate(pq) << '\n';

    for (int i = 1; i <= N; i++) {
        cout << placed[i] << '\n';
    }

    return 0;
}