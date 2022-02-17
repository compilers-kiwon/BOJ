#include    <iostream>
#include    <string>

using namespace std;

#define is_even(n1,n2)  ((n1)%2==0||(n2)%2==0)

#define BLACK       0
#define WHITE       1
#define EQUAL       2
#define MAX_COLOR   EQUAL

const string    str[EQUAL+1] = {"black","white","equal"};

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int m,n,i,j,c;

    cin>>m>>n>>i>>j>>c;
    c = (c+abs(i-j))%MAX_COLOR; //  get color at (1,1)

    if( is_even(m,n) == true )
    {
        c = EQUAL;
    }

    cout<<str[c]<<'\n';

    return  0;
}