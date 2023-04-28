#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A,B;

    cin>>A>>B;

    for(;A!=B;)
    {
        int max_num = max(A,B);
        int min_num = min(A,B);

        A = max_num-min_num;
        B = min_num;
    }

    cout<<B<<'\n';

    return  0;
}