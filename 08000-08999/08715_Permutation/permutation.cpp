#include    <iostream>

using namespace std;

#define MAX_NUM (1000000+1)

static bool counted[MAX_NUM];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int main(void)
{
    int n,a;

    cin>>n;

    for (int i=1;i<=n;i++) {
        cin>>a;

        if (!IN_RANGE(1,a,n) || counted[a]) {
            cout<<"NIE\n";
            return  0;
        }

        counted[a] = true;
    }

    cout<<"TAK\n";
    return  0;
}