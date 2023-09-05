#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

static int  N,T,R[MAX_SIZE];

int play(void)
{
    int ret,highest_rating;

    highest_rating = 0;

    for (int i=1;i<=N;i++) {
        if (R[i] > highest_rating) {
            ret = i;
            highest_rating = R[i];
        }
    }

    return  ret;
}

int distribute(int played)
{
    int base = R[played]/(N-1);
    int extra = R[played]%(N-1);

    for (int i=1;i<=N;i++) {
        if (i == played) {
            R[i] = 0;
        } else {
            R[i] += base+(extra>0?1:0);
            extra--;
        }
    }

    return  0;
}

bool    is_exception(int num_of_songs)
{
    if (num_of_songs == 1) {
        for (int i=1;i<=T;i++) cout<<"1\n";
        return  true;
    }

    return  false;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>T;
    for (int i=1;i<=N;i++) cin>>R[i];

    if (!is_exception(N)) {
        for (int i=1,p;i<=T;i++) {
            cout<<(p=play())<<'\n';
            distribute(p);
        }
    }

    return  0;
}