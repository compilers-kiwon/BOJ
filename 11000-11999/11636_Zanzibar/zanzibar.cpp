#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int z,inflow;

        z = 1;
        inflow = 0;

        do{
            int num;

            cin>>num;

            inflow += max(0,num-2*z);
            z = num;
        }while(z!=0);

        cout<<inflow<<'\n';
    }

    return  0;
}