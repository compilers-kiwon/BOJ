#include    <iostream>

using namespace std;

#define NUM_OF_MEMBERS  3
#define is_divisible(a) ((a%NUM_OF_MEMBERS)==0)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,sum;

    cin>>n;
    sum = 0;

    for(int i=1;i<=n;i++)
    {
        int w;

        cin>>w;
        sum += w;
    }

    cout<<(is_divisible(sum)?"yes":"no")<<'\n';

    return  0;
}