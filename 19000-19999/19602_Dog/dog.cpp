#include    <iostream>

using namespace std;

#define SMALL   1
#define MIDDLE  2
#define LARGE   3
#define HAPPY   10

#define get_score(S,M,L)    ((S)*SMALL+(M)*MIDDLE+(L)*LARGE)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int S,M,L;

    cin>>S>>M>>L;

    if( get_score(S,M,L) >= HAPPY )
    {
        cout<<"happy\n";
    }
    else
    {
        cout<<"sad\n";
    }

    return  0;
}