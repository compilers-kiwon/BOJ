#include    <iostream>

using namespace std;

#define PHI 1.61803399
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define LOWER   (PHI*0.99)
#define UPPER   (PHI*1.01)
#define is_golden(n)    IN_RANGE(LOWER,n,UPPER)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        double  n1,n2;

        cin>>n1>>n2;
        cout<<(is_golden(n1/n2)?
                "golden":"not")<<'\n';
    }

    return  0;
}