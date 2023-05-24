#include    <iostream>

using namespace std;

#define NUM_OF_DIGITS   10

const static int 
    num_of_highlighted_segs[NUM_OF_DIGITS] 
        = {6,2,5,5,4,5,6,3,7,6};

#define get_num_of_highlights(d)    (num_of_highlighted_segs[(d)])

#define simulate(d1,d2,d3,d4) \
    (get_num_of_highlights((d1))+get_num_of_highlights((d2))\
     +get_num_of_highlights((d3))+get_num_of_highlights((d4)))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int h1=0;h1<=2;h1++)
    {
        for(int h2=0;h2<=((h1==2)?3:9);h2++)
        {
            for(int m1=0;m1<=5;m1++)
            {
                for(int m2=0;m2<=9;m2++)
                {
                    if( simulate(h1,h2,m1,m2) == n )
                    {
                        cout<<h1<<h2<<':'<<m1<<m2<<'\n';
                        return  0;
                    }
                }
            }
        }
    }

    cout<<"Impossible\n";
    return  0;
}