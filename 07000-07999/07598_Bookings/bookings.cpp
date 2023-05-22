#include    <iostream>
#include    <string>

using namespace std;

#define is_valid(n) (0<=(n)&&(n)<=68)

int simulate(int n)
{
    for(;;)
    {
        char    c;
        int     num;

        cin>>c>>num;
        if(c=='X'&&num==0) break;

        num *= (c=='B')?1:-1;
        n = is_valid(n+num)?n+num:n;
    }

    return  n;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int     n;
        string  flight;

        cin>>flight>>n;
        if(flight=="#"&&n==0) break;

        n = simulate(n);
        cout<<flight<<' '<<n<<'\n';
    }

    return  0;
}