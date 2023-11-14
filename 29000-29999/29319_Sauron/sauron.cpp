#include    <iostream>

using namespace std;

int input(int& max_num)
{
    int n,sum;

    cin>>n;
    max_num = sum = 0;

    for (int i=1;i<=n;i++) {
        int a;
        cin>>a;

        max_num = max(max_num,a);
        sum += a;
    }

    return  sum;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum,max_num;
    sum = input(max_num);

    cout<<sum-max_num<<'\n';
    return  0;
}