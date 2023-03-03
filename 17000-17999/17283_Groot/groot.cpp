#include    <iostream>

using namespace std;

#define LOWER_BOUND 5
#define grow(t,r) ((t)=(t)*(r)/100)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int L,R,current,sum,num_of_branches;

    cin>>L>>R;

    sum = 0;
    current = L;
    num_of_branches = 1;

    do{
        sum += current*num_of_branches;
        grow(current,R);
        num_of_branches <<= 1;
    }while(current>LOWER_BOUND);

    cout<<sum-L<<'\n';

    return  0;
}