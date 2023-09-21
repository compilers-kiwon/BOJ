#include    <iostream>
#include    <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> A;

    cin>>N;

    for (int i=1;i<=N;i++) {
        int a;

        cin>>a;
        
        if (A.empty() || a>A.back()) {
            A.push_back(a);
        }
    }

    cout<<A.size()<<'\n';

    for (int i=0;i<A.size();i++) {
        cout<<A[i]<<(i==A.size()-1?'\n':' ');
    }

    return  0;
}