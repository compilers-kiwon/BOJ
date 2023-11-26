#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

const static int MAX_NUM = 1000000;
const static int MAX_NUM_OF_PLAYERS = 100000;
const static int NONE = 0;

static int N,score[MAX_NUM_OF_PLAYERS+1],player[MAX_NUM+1];
static vector<int> used;

void input(void)
{
    cin>>N;

    for (int i=1;i<=N;i++) {
        int x;
        cin>>x;
        player[x] = i;
        used.push_back(x);
    }

    sort(used.begin(),used.end());
}

void simulate(void)
{
    for (int i=0;i<N;i++) {
        int cur_card = used[i];
        int cur_player = player[cur_card];

        for (int j=cur_card*2;j<=used.back();j+=cur_card) {
            int other_player = player[j];

            if (other_player != NONE) {
                score[cur_player]++;
                score[other_player]--;
            }
        }
    }
}

void print(void)
{
    for (int i=1;i<=N;i++) {
        cout<<score[i]<<(i==N?'\n':' ');
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();

    return  0;
}