#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

typedef long long int int64;

static inline int64 extend_digits(int64 cur_num,int64 new_digit) {
    return  (cur_num*10LL+new_digit);
}

void build_number(int64 cur,int64 upper,
                        vector<int64>& nums)
{
    int64 n;

    if ((n=extend_digits(cur,4LL)) <= upper) {
        nums.push_back(n);
        build_number(n,upper,nums);
    }

    if ((n=extend_digits(cur,7LL)) <= upper) {
        nums.push_back(n);
        build_number(n,upper,nums);
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 A,B;
    vector<int64> nums;

    cin>>A>>B;
    build_number(0LL,B,nums);
    
    sort(nums.begin(),nums.end());
    nums.push_back(B+1);

    cout<<upper_bound(nums.begin(),nums.end(),B)
            -lower_bound(nums.begin(),nums.end(),A)<<'\n';
    return  0;
}