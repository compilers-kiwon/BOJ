#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,fixed_raise,cnt_of_fixed,cnt_of_double;

    cin>>n>>fixed_raise;
    cnt_of_fixed = cnt_of_double = 0;

    for(int i=1;i<=n;i++)
    {
        int salary;

        cin>>salary;
        if (salary == fixed_raise) continue;

        if (salary < fixed_raise) cnt_of_fixed++;
        else cnt_of_double++;
    }

    cout<<((cnt_of_fixed==cnt_of_double)?0:
                (cnt_of_fixed>cnt_of_double)?1:2)<<'\n';

    return  0;
}