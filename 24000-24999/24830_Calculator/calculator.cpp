#include    <iostream>

using namespace std;

typedef long long int   int64;

int64   calculate(int64 n1,char op,
            int64 n2,int64 prev_result)
{
    int64   ret = 0;

    switch(op)
    {
        case '+':ret=(n1+n2)-prev_result;break;
        case '-':ret=prev_result*(n1-n2);break;
        case '*':ret=(n1*n2)*(n1*n2);break;
        case '/':ret=(n1+1)/2;break;
        default:/*do nothing*/;break;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    int64 num;

    cin>>n;
    num = 1;

    for(int i=1;i<=n;i++)
    {
        int64   n1,n2;
        char    op;

        cin>>n1>>op>>n2;
        num = calculate(n1,op,n2,num);

        cout<<num<<'\n';
    }

    return  0;
}