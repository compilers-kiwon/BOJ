#include    <iostream>

using namespace std;

const static int NUM_OF_DAYS = 365;
const static int LIMIT_OF_DIRTINESS = 20;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,num_of_pushes,dirtiness,num_of_cleanups;
    bool push[NUM_OF_DAYS+1] = {false,};

    cin>>n;

    for (int i=1;i<=n;i++) {
        int d;

        cin>>d;
        push[d] = true;
    }

    num_of_pushes = dirtiness = num_of_cleanups = 0;

    for (int i=1;i<=NUM_OF_DAYS;i++) {
        dirtiness += num_of_pushes;

        if (dirtiness >= LIMIT_OF_DIRTINESS) {
            dirtiness = num_of_pushes = 0;
            num_of_cleanups++;
        }

        num_of_pushes += (push[i]?1:0);
    }

    cout<<num_of_cleanups+
            (num_of_pushes!=0?1:0)<<'\n';
    return  0;
}