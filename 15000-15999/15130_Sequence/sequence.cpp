#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    10

#define SUCCESS 1
#define FAIL    -1

typedef pair<int,int>   Number; // first: idx, second: val

int get_constant(const vector<Number>& num)
{
    int offset = num.back().first-num.front().first;
    int diff = num.back().second-num.front().second;
    
    return  diff/offset;
}

int input(int arr[],vector<Number>& num)
{
    for (int i=1;i<=MAX_SIZE;i++) {
        cin>>arr[i];
        if (arr[i] != 0) num.push_back({i,arr[i]});
    }

    return  0;
}

int build_left_seq(int pos,int constant,int arr[])
{
    for (int left=pos-1;left>=1;left--) arr[left]=arr[left+1]-constant;
    return  SUCCESS;
}

int build_right_seq(int pos,int constant,int arr[])
{
    for (int right=pos+1;right<=MAX_SIZE;right++) {
        int expected = arr[right-1]+constant;

        if (arr[right]!=0 && arr[right]!=expected) return FAIL;
        arr[right] = expected;
    }

    return  SUCCESS;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int arr[MAX_SIZE+1],c;
    vector<Number> num;

    input(arr,num);
    c = get_constant(num);

    if (build_left_seq(num.front().first,c,arr)==SUCCESS
            && build_right_seq(num.front().first,c,arr)==SUCCESS) {
        for (int i=1;i<=MAX_SIZE;i++) cout<<arr[i]<<(i==MAX_SIZE?'\n':' ');
    } else {
        cout<<FAIL<<'\n';
    }

    return  0;
}