#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

static int N,M;
static vector<int> A,D;

static inline void get_numbers(int size,vector<int>& numbers) {
    for (int i=1;i<=size;i++) {
        int n;
        cin>>n;
        numbers.push_back(n);
    }
}

void input(void)
{
    cin>>N>>M;
    get_numbers(N,A);
    get_numbers(M,D);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int>& B = A;

    input();
    sort(B.begin(),B.end());

    for (int i=0;i<M;i++) {
        vector<int>::iterator it =
            lower_bound(B.begin(),B.end(),D[i]);

        if (it==B.end() || *it!=D[i]) cout<<"-1\n";
        else cout<<it-B.begin()<<'\n';
    }

    return  0;
}