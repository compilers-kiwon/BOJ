#include    <iostream>

using namespace std;

const static int MAX_SIZE = 200000+1;
const static int TURN_ON = 1;
const static int TOGGLE = 2;

typedef long long int int64;

static int64 flow[MAX_SIZE];
static bool locked[MAX_SIZE];

int64 input(void)
{
    int N;
    int64 ret;

    cin>>N;
    ret = 0;

    for (int i=1;i<=N;i++) {
        cin>>flow[i];
        ret += flow[i];
    }

    return  ret;
}

void simulate(int64 cur)
{
    int Q;

    cout<<cur<<'\n';
    cin>>Q;

    for (int q=1;q<=Q;q++) {
        int op,i;
        int64 x;

        cin>>op>>i;

        switch (op) {
            case TURN_ON :
                cin>>x;
                cur += (locked[i]?0:x-flow[i]);
                flow[i] = x;
                break;
            case TOGGLE :
                locked[i] = !locked[i];
                cur += (locked[i]?-flow[i]:flow[i]);
                break;
            default :
                /*do nothing*/
                break;
        }

        cout<<cur<<'\n';
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 total;

    total = input();
    simulate(total);

    return  0;
}