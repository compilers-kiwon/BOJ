#include    <iostream>

using namespace std;

enum{
    APPROVED = 1,
    REJECTED = -1,
    INVALID = 0
};

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,approved,rejected,invalid;

    cin>>N;
    approved = rejected = invalid = 0;

    for(int i=1;i<=N;i++)
    {
        int v;

        cin>>v;

        switch(v)
        {
            case APPROVED : approved++;break;
            case REJECTED : rejected++;break;
            case INVALID : invalid++;break;
            default : break;
        }
    }

    if( invalid*2 >= N )
    {
        cout<<"INVALID\n";
    }
    else
    {
        cout<<((rejected>=approved)?
                "REJECTED":"APPROVED")<<'\n';
    }

    return  0;
}