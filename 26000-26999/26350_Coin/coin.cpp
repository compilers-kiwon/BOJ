#include    <iostream>
#include    <vector>

using namespace std;

#define TRUE    1
#define FALSE   0

#define GOOD_STR    "Good coin denominations!"
#define BAD_STR     "Bad coin denominations!"

#define print_coins(c) \
    {for(int i=0;i<(c).size();i++)cout<<' '<<(c)[i];}cout<<'\n';

int is_good(const vector<int>& coins)
{
    vector<int> buf;

    buf.push_back(0);

    for(int i=0;i<coins.size();i++)
    {
        if( coins[i] < buf.back()*2 )
        {
            return  FALSE;
        }

        buf.push_back(coins[i]);
    }

    return  TRUE;
}

int input(vector<int>& coins)
{
    int d;

    cin>>d;

    for(int i=1;i<=d;i++)
    {
        int c;

        cin>>c;
        coins.push_back(c);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for(cin>>n;n>0;n--)
    {
        vector<int> coins;

        input(coins);
        cout<<"Denominations:";

        print_coins(coins);
        cout<<(is_good(coins)?GOOD_STR:BAD_STR)<<"\n\n";
    }

    return  0;
}