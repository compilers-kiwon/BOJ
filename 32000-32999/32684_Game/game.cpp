#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define NUM_OF_PIECES (6)

typedef struct {
    string name;
    int score;
} Player;

const int table[NUM_OF_PIECES] = {130, 70, 50, 30, 30, 20};
const int EXTRA_POINT = 15;

void input(Player& p, string s, int extra) {
    p.name = s;
    p.score = extra;

    for (int i = 0; i < NUM_OF_PIECES; i++) {
        int n;
        cin>>n;
        p.score += n*table[i];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Player c, e;

    input(c, "cocjr0208", 0);
    input(e, "ekwoo", EXTRA_POINT);

    cout<<((c.score>e.score)?c.name:e.name)<<'\n';
    return 0;
}