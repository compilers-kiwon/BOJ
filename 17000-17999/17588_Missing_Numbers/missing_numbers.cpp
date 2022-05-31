#include    <iostream>

using namespace std;

#define MAX_NUM (200+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n,prev_num;
    bool    missed = false;

    cin>>n;
    prev_num = 0;

    for(int i=1;i<=n;i++)
    {
        int current_num;

        cin>>current_num;

        for(int j=prev_num+1;j<current_num;j++)
        {
            cout<<j<<'\n';
            missed= true;
        }

        prev_num = current_num;
    }

    if( missed == false )
    {
        cout<<"good job\n";
    }

    return  0;
}