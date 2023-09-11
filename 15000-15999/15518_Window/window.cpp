#include    <iostream>

using namespace std;

#define MAX_WIDTH           (100)
#define MAX_NUM_OF_WINDOWS  (100+1)

static bool w[MAX_NUM_OF_WINDOWS*MAX_WIDTH];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,H,W;

    cin>>N>>H>>W;

    for (int i=1;i<=N;i++) {
        int start_pos = (i-1)*W+1;
        int slide;

        cin>>slide;
        start_pos += ((i%2==1)?1:-1)*slide;

        for (int p=0;p<W;p++) {
            w[start_pos+p] = true;
        }
    }

    int opened = 0;

    for (int i=1;i<=N*W;i++) {
        opened += (w[i]==false)?H:0;
    }

    cout<<opened<<'\n';
    return  0;
}