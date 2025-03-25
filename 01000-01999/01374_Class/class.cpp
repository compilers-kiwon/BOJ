#include <iostream>
#include <queue>

using namespace std;

const int START = 0;
const int END = 1;

typedef pair<int,int> Event; // first: -time, second: event_type

priority_queue<Event> pq;

void input(void) {
    int N;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        int a, b, c;

        cin>>a>>b>>c;
        
        pq.push({-b, START});
        pq.push({-c, END});
    }
}

int simulate(void) {
    int ret = 0;
    int num_of_available_rooms = 0;

    for (; !pq.empty(); pq.pop()) {
        int event_type = -pq.top().second;

        if (event_type == START) {
            if (num_of_available_rooms == 0) {
                ret++; // allocate a new room
            } else {
                num_of_available_rooms--;
            }
        } else {
            num_of_available_rooms++;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return 0;
}