#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

#define MAX_SIZE    0x100

string      T,S;
set<string> shifted[MAX_SIZE];

void    find_all_shifted_str(void)
{
    for(int i=1;i<S.length();i++)
    {
        string  tail = S.substr(0,i);
        string  head = S.substr(i,S.length()-i);

        shifted[head.front()].insert(head+tail);
    }

    shifted[S.front()].insert(S);
}

bool    find_sub_str(void)
{
    for(int i=0;i<T.length()-S.length()+1;i++)
    {
        set<string>::iterator   it;

        for(it=shifted[T[i]].begin();it!=shifted[T[i]].end();it++)
        {
            if( *it == T.substr(i,S.length()) )
            {
                return  true;
            }
        }
    }

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>T>>S;
    find_all_shifted_str();

    if( find_sub_str() == true )
    {
        cout<<"yes\n";
    }
    else
    {
        cout<<"no\n";
    }

    return  0;
}
