#include    <iostream>
#include    <string>

using namespace std;

int costToSwap(const string& w1,const string& w2)
{
    int ret = 0;

    for(int i=0;i<w1.length();i++)
    {
        ret += (int)w1[i]-(int)w2[i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  w1,w2;
        int     cost;

        cin>>w1>>w2;
        cost = costToSwap(w1,w2);

        if( cost == 0 )
        {
            cout<<"Swapping letters to make "<<w1<<" look like "<<w2<<" was FREE.\n";
        }
        else
        {
            if( cost < 0 )
            {
                cout<<"Swapping letters to make "<<w1<<" look like "<<w2<<" cost "<<-cost<<" coins.\n";
            }
            else
            {
                cout<<"Swapping letters to make "<<w1<<" look like "<<w2<<" earned "<<cost<<" coins.\n";
            }
        }
    }

    return  0;
}