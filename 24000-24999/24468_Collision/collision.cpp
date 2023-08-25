#include    <iostream>
#include    <vector>

using namespace std;

typedef pair<int,char>  Ball;   // first: pos, second: dir

#define MAX_SIZE    (1000+1)
#define LEFT        'L'
#define RIGHT       'R'
#define NONE        0

#define get_offset(d)   ((d)==LEFT?-1:1)
#define reverse_dir(d)  ((d)=((d)==LEFT?RIGHT:LEFT))

static int  L,N,T;
static int  state[MAX_SIZE][MAX_SIZE];  // [time][pos]
static Ball b[MAX_SIZE];

int input(void)
{
    cin>>L>>N>>T;

    for (int i=1;i<=N;i++) {
        cin>>b[i].first>>b[i].second;
    }

    return  0;
}

int simulate(void)
{
    int ret = 0;

    for (int t=1;t<=T;t++) {
        for (int i=1;i<=N;i++) {
            int&    pos = b[i].first;
            char&   d = b[i].second;

            pos += get_offset(d);

            if (state[t][pos] == NONE) {
                if(pos==0 || pos==L) reverse_dir(d);
                state[t][pos] = i;
            } else {
                int against = state[t][pos];
                reverse_dir(b[against].second);reverse_dir(d);
                ret++;
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}