#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        string  p1,p2;
        int     score1,score2,n;

        cin>>p1>>p2;
        score1 = score2 = 0;

        if( p1=="#" && p2=="#" )
        {
            break;
        }

        cin>>n;

        for(int i=1;i<=n;i++)
        {
            char    c1,c2;

            cin>>c1>>c2;
            (c1==c2)?score1++:score2++;
        }

        cout<<p1<<' '<<score1<<' '<<p2<<' '<<score2<<'\n';
    }

    return  0;
}