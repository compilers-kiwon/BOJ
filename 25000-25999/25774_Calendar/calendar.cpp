#include    <iostream>

using namespace std;

#define MAX_DAY     30
#define MAX_MONTH   12

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int from_d,from_m,from_y,n;
    int to_d,to_m,to_y;

    cin>>from_d>>from_m>>from_y
            >>n>>to_d>>to_m>>to_y;
    
    for(;!(from_d==to_d&&from_m==to_m&&from_y==to_y);n=(n==7)?1:n+1)
    {
        if( ++from_d > MAX_DAY )
        {
            from_d = 1;

            if ( ++from_m > MAX_MONTH )
            {
                from_m = 1;
                ++from_y;
            }
        }
    }

    cout<<n<<'\n';
    return  0;
}