#include    <iostream>
#include    <string>
#include    <queue>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    double m;
    priority_queue<double> drinks;

    cin>>N;

    for (int i=1;i<=N;i++) {
        double x;
        cin>>x;
        drinks.push(x);
    }

    for (m=drinks.top()/2.0;!drinks.empty();drinks.pop()) {
        m += drinks.top()/2.0;
    }

    cout.precision(5);cout<<fixed;
    cout<<m<<'\n';

    return  0;
}