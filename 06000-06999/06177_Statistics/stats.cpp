#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define is_even(n)          ((n)%2==0)
#define get_mean(sum,size)  ((float)sum/(float)size)

int input(vector<float>& num)
{
    int N,ret;

    cin>>N;
    ret = 0;
    
    for(int i=1;i<=N;i++)
    {
        int X;

        cin>>X;
        num.push_back((float)X);
        ret += X;
    }

    return  ret;
}

float   get_median(const vector<float>& num)
{
    float   sum = num[num.size()/2];

    sum += is_even(num.size())?
        num[(num.size()-1)/2]:num[num.size()/2];
    
    return  sum/2.0;
}

int main(void)
{
    int sum;
    vector<float> X;

    sum = input(X);
    sort(X.begin(),X.end());

    printf("%.06f\n",get_mean(sum,X.size()));
    printf("%.06f\n",get_median(X));
    
    return  0;
}