#include    <iostream>
#include    <string>

using namespace std;

#define invert(c)   ((c)=='0'?'1':'0')

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for(cin>>t;t>0;t--)
    {
        int     n,cnt;
        string  s1,s2;

        cnt = 0;
        cin>>n>>s1>>s2;

        for(int i=0;i<n-1;i++)
        {
            if( s1[i] == s2[i] )
            {
                continue;
            }

            s1[i] = invert(s1[i]);
            s1[i+1] = invert(s1[i+1]);

            cnt++;
        }

        if( s1[n-1] == s2[n-1] )
        {
            cout<<cnt<<'\n';
        }
        else
        {
            cout<<"-1\n";
        }
    }

    return  0;
}