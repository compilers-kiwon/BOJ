#include    <iostream>
#include    <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,k;
    vector<int> notebook;

    cin>>n>>k;
    notebook.push_back(0);

    for (int i=1;i<=n;i++) {
        int a;

        cin>>a;

        if (notebook.back()+a <= k) {
            notebook.back() += a;
        } else {
            notebook.push_back(a);
        }
    }

    cout<<notebook.size()<<'\n';
    return  0;
}