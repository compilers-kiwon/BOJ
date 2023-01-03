#include    <iostream>
#include    <set>

using namespace std;

#define get_value(I,V,X,L)  ((I)*1+(V)*5+(X)*10+(L)*50)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N;
    set<int>    num;

    cin>>N;

    for(int I=0;I<=N;I++)
    {
        for(int V=0;I+V<=N;V++)
        {
            for(int X=0;I+V+X<=N;X++)
            {
                int L = N-(I+V+X);

                num.insert(get_value(I,V,X,L));
            }
        }
    }

    cout<<num.size()<<'\n';

    return  0;
}