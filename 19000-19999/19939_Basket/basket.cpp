#include    <iostream>

using namespace std;

const static int MAX_NUM_OF_BASKETS = 1000+1;

static int N,K,b[MAX_NUM_OF_BASKETS];

bool init(void) {
    if (K*(K+1)/2 > N) return false;
    for (int i=1;i<=K;i++) b[i]=i,N-=i;
    return  true;
}

void simulate(void)
{
    for (int ptr=K;N>0;ptr--,N--) {
        if (ptr == 0) ptr=K;
        b[ptr]++;
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>K;
    
    if (!init()) {
        b[K]=0,b[1]=1;
    } else {
        simulate();
    }

    cout<<b[K]-b[1]<<'\n';
    return  0;
}