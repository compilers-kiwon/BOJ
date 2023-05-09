#include    <iostream>

using namespace std;

#define write_book(init_speed,day)  ((init_speed)<<(day))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int k,d,s;

    cin>>k>>d;
    s = 0;

    for(int i=0;;i++)
    {
        s += write_book(k,i);

        if( s > d )
        {
            cout<<i<<'\n';
            break;
        }
    }

    return  0;
}