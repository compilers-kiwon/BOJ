#include    <iostream>
#include    <stack>

using namespace std;

int main(void)
{
    int         N;
    stack<int>  s[3];

    scanf("%d",&N);

    for(int i=N;i>=1;i--)
    {
        s[0].push(i);
    }

    for(int C,D;scanf("%d %d",&C,&D)==2;)
    {
        stack<int>& from = s[C-1];
        stack<int>& to = s[C];

        for(int i=1;i<=D;i++)
        {
            to.push(from.top());
            from.pop();
        }
    }

    for(;!s[2].empty();s[2].pop())
    {
        printf("%d\n",s[2].top());
    }

    return  0;
}