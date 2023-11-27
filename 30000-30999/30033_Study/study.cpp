#include    <iostream>
#include    <vector>

using namespace std;

static inline void read_data(vector<int>& buf,int size) {
    for (int i=1;i<=size;i++) {
        int n;
        cin>>n;
        buf.push_back(n);
    }
}

static inline int compare(const vector<int>& plan,
                            const vector<int>& actual,int size) {
    int ret = 0;
    for (int i=0;i<size;i++) ret+=(plan[i]<=actual[i])?1:0;
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> A,B;

    cin>>N;
    read_data(A,N);
    read_data(B,N);

    cout<<compare(A,B,N)<<'\n';
    return  0;
}