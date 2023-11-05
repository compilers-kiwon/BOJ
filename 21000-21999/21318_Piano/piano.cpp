#include    <iostream>

using namespace std;

const static int MAX_SIZE = 100000+1;

static int N,Q;
static int difficulty[MAX_SIZE];
static int sum_of_mistakes[MAX_SIZE];

static inline int make_mistake(int idx) {
    int cur_difficulty = difficulty[idx];
    int prev_difficulty = difficulty[idx-1];
    return  (prev_difficulty>cur_difficulty?1:0);
}

static inline int get_num_of_mistakes(int from,int to) {
    return  sum_of_mistakes[to]-sum_of_mistakes[from];
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for (int i=1;i<=N;i++) {
        cin>>difficulty[i];
        sum_of_mistakes[i] = 
            make_mistake(i)+sum_of_mistakes[i-1];
    }

    cin>>Q;

    for (int i=1;i<=Q;i++) {
        int x,y;

        cin>>x>>y;
        cout<<get_num_of_mistakes(x,y)<<'\n';
    }

    return  0;
}