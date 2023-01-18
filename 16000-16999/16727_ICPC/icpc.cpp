#include    <iostream>

using namespace std;

#define get_winner(p_score,s_score) \
    (((p_score)>(s_score))?"Persepolis\n":"Esteghlal\n")

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int p1,s1,p2,s2,p,s;

    cin>>p1>>s1>>s2>>p2;

    p = p1+p2;
    s = s1+s2;

    if( p!=s || p2!=s1 )
    {
        if( p != s )
        {
            cout<<get_winner(p,s);
        }
        else
        {
            cout<<get_winner(p2,s1);
        }
    }
    else
    {
        cout<<"Penalty\n";
    }

    return  0;
}