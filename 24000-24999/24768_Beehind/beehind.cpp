#include    <iostream>

using namespace std;

#define continue_if_true(cond,msg) \
        {if((cond)){cout<<(msg);continue;}}

#define break_if_true(cond,msg) \
        {if((cond)){cout<<(msg);break;}}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int x,y;cin>>x>>y;)
    {
        break_if_true(x+y==0,"");
        continue_if_true(x+y==13,"Never speak again.\n");
        continue_if_true(x==y,"Undecided.\n");
        continue_if_true(x>y,"To the convention.\n");
        continue_if_true(x<y,"Left beehind.\n");
    }

    return  0;
}