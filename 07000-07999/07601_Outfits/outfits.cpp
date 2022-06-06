#include    <iostream>
#include    <vector>

using namespace std;

void    init(vector<int>& w,int size,bool from_right)
{
    w.push_back(0);

    for(int i=1;i<=size;i++)
    {
        w.push_back(i);
    }

    if( from_right == true )
    {
        for(int h=1,t=size;h<t;h++,t--)
        {
            swap(w[h],w[t]);
        }
    }
}

void    remove_outfit(vector<int>& w)
{
    int r;

    cin>>r;

    if( r != 0 )
    {
        w.erase(w.begin()+r);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int s=1;;s++)
    {
        int n,d,r;

        cin>>n>>d;

        if( n==0 && d==0 )
        {
            break;
        }

        cout<<"Scenario "<<s<<'\n';

        vector<int> Becs,Cas;

        init(Becs,n,false);
        init(Cas,n,true);

        remove_outfit(Becs);
        remove_outfit(Cas);

        for(int i=1;i<=d;i++)
        {
            int c1,c2;

            cin>>c1>>c2;
            cout<<"Day "<<i;

            if( Becs[c1] == Cas[c2] )
            {
                cout<<" ALERT\n";
            }
            else
            {
                cout<<" OK\n";
            }
        }
    }

    return  0;
}