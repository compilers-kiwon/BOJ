#include    <iostream>
#include    <vector>
#include    <cmath>

using namespace std;

#define MAX_SIZE    2
#define NEXT_ARR(p) (((p)+1)%MAX_SIZE)

int build_seq(vector<int> arr[],int src,int dst)
{
    for (int i=0;i<arr[src].size()-1;i++) {
        arr[dst].push_back(
            abs(arr[src][i]-arr[src][i+1]));
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,src,dst;
    vector<int> A[MAX_SIZE];

    cin>>N;
    src = 0;
    
    for (int i=0;i<N;i++) {
        int a;
        cin>>a;A[src].push_back(a);
    }

    for (;A[src].size()!=1;src=dst) {
        dst = NEXT_ARR(src);
        build_seq(A,src,dst);
        A[src].clear();
    }

    cout<<A[src].front()<<'\n';
    return  0;
}