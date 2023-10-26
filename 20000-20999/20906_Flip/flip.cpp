#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t,s,n,upper,lower,time_to_flow;

    cin>>t>>s>>n;
    upper=0,lower=s;
    time_to_flow = 0;

    for (int i=1;i<=n;i++) {
        int a,passed_time;

        cin>>a;
        passed_time = a-time_to_flow;

        int sand_to_flow = min(upper,passed_time);

        upper -= sand_to_flow;
        lower += sand_to_flow;

        swap(upper,lower);
        time_to_flow = a;
    }
    
    cout<<max(0,upper-(t-time_to_flow))<<'\n';
    return  0;
}