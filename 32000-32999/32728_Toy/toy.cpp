#include <iostream>
#include <string>

using namespace std;

#define NUM_OF_BOXES (3)

int N, K;
string box[NUM_OF_BOXES];

inline int get_idx(char c) {
    const string order = "srp";
    return order.find(c);
}

inline bool is_full(int box_idx) {
    return (box[box_idx].length() == K);
}

void put_in_box(const char toy) {
    for (int i = get_idx(toy);;i = (i+1)%NUM_OF_BOXES) {
        if (is_full(i) == false) {
            box[i].push_back(toy);
            break;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string toy;

    cin>>N>>K;

    if (N == 0) {
        return 0;
    }

    cin>>toy;

    for (int i = 0; i < N; i++) {
        put_in_box(toy[i]);
    }

    for (int i = 0; i < NUM_OF_BOXES; i++) {
        cout<<box[i]<<'\n';
    }

    return 0;
}