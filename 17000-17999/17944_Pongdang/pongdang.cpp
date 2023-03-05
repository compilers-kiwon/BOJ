#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,T,num_of_hands;

    cin>>N>>T;
    num_of_hands = 1;

    for(int i=1,offset=1;;
            i++,num_of_hands+=offset)
    {
        if( i == T )
        {
            break;
        }

        if( num_of_hands == 2*N )
        {
            offset = -1;
        }

        if( num_of_hands == 1 )
        {
            offset = 1;
        }
    }

    cout<<num_of_hands<<'\n';

    return  0;
}