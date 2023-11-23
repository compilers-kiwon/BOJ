#include    <iostream>
#include    <vector>

using namespace std;

static inline int get_number(int num,int prev) {
    int ret;

    for (int i=prev/num+1;;i++) {
        if ((ret=i*num) > prev) break;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    vector<int> arr,perfect;

    cin>>n;

    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    perfect.push_back(arr.front());

    for (int i=1;i<n;i++) {
        perfect.push_back(
            get_number(arr[i],perfect.back()));
    }

    for (int i=0;i<n;i++) {
        cout<<perfect[i]<<(i==n-1?'\n':' ');
    }

    return  0;
}