#include    <iostream>
#include    <vector>

using namespace std;

int input(vector<int>& h)
{
    int n,x;

    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>x;
        h.push_back(x);
    }

    return  0;
}

bool    is_fibo(const vector<int>& h)
{
    for (int i=2;i<h.size();i++) {
        if (h[i] != h[i-2]+h[i-1]) return false;
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for (int i=1;i<=n;i++) {
        vector<int> h;

        input(h);
        cout<<(is_fibo(h)?"YES":"NO")<<'\n';
    }

    return  0;
}