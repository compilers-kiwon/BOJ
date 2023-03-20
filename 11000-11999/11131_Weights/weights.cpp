#include    <iostream>
#include    <cmath>

using namespace std;

#define get_sign(n) (((n)==0)?0:(n)/abs((n)))

#define get_dir(n)  (get_sign((n))==0?"Equilibrium":\
                     get_sign((n))==1?"Right":"Left")

int get_sum_of_weight(void)
{
    int N,ret;

    cin>>N;
    ret = 0;
    
    for(int i=1;i<=N;i++)
    {
        int W;

        cin>>W;
        ret += W;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int w = get_sum_of_weight();

        cout<<get_dir(w)<<'\n';
    }

    return  0;
}