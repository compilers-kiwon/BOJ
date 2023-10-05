#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

static int  n,h[MAX_SIZE],v[MAX_SIZE];

bool    win(int power)
{
    for (int i=1;i<=n;i++) {
        if (h[i]+power != v[i]) {
            return  (h[i]+power)>v[i];
        }
    }

    return  true;
}

int     input(void)
{
    cin>>n;

    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) cin>>v[i];

    return  0;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for (int num_of_days=0;;num_of_days++) {
        if (win(num_of_days)) {
            cout<<num_of_days<<'\n';
            break;
        }
    }

    return  0;
}