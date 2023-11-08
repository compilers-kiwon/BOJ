#include    <iostream>
#include    <algorithm>

using namespace std;

const static int MAX_SIZE = 4000000+1;

static int N,M,K;
static int num[MAX_SIZE],parent[MAX_SIZE];

int find_parent(int n)
{
    int& ret = parent[n];
    if (ret != n) ret=find_parent(ret);
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>K;

    for (int i=1;i<=M;i++) {
        cin>>num[i];
        parent[i] = i;
    }

    sort(&num[1],&num[M+1]);

    for (int i=1;i<=K;i++) {
        int n;
        cin>>n;

        int upper_number_idx =
            upper_bound(&num[1],&num[M+1],n)-&num[1]+1;
        int parent_idx = find_parent(upper_number_idx);

        cout<<num[parent_idx]<<'\n';
        parent[parent_idx] = parent_idx+1;
    }

    return  0;
}