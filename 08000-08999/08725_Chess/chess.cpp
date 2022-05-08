#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,sum;

    cin>>n;
    sum = 0;

    for(int row=1;row<=n;row++)
    {
        int max_num = 0;

        for(int col=1;col<=n;col++)
        {
            int num;

            cin>>num;
            max_num = max(max_num,num);
        }

        sum += max_num;
    }

    cout<<sum<<'\n';

    return  0;
}