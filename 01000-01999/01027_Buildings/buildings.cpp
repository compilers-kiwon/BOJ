#include    <iostream>

using namespace std;

const static int MAX_SIZE = 50+1;

typedef long long int   int64;

bool find_obstacle(int A,int B,int64 h[])
{
    int from = min(A,B);
    int to = max(A,B);
    int64 dx = to-from;
    int64 dy = h[to]-h[from];

    for (int i=1;from+i<to;i++) {
        if (dx*(h[from+i]-h[from]) >= dy*(int64)i) {
            return  true;
        }
    }

    return  false;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,max_val;
    int64 h[MAX_SIZE];

    cin>>N;
    for (int i=1;i<=N;i++) cin>>h[i];

    max_val = 0;

    for (int i=1;i<=N;i++) {
        int cnt = 0;

        for (int j=1;j<=N;j++) {
            if (i!=j && !find_obstacle(i,j,h)) cnt++; 
        }

        max_val = max(max_val,cnt);
    }

    cout<<max_val<<'\n';
    return  0;
}