#include    <iostream>
#include    <cmath>

using namespace std;

#define NUM_OF_DATA 10

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    float  data[NUM_OF_DATA+1],sum,avg,diff,s;

    sum = diff = 0.0;

    for(int i=1;i<=NUM_OF_DATA;i++)
    {
        cin>>data[i];
        sum += data[i];
    }

    avg = sum/(float)NUM_OF_DATA;

    for(int i=1;i<=NUM_OF_DATA;i++)
    {
        diff += (data[i]-avg)*(data[i]-avg);
    }

    s = sqrt(diff/(float)(NUM_OF_DATA-1));
    cout<<((s<=1.0)?"COMFY":"NOT COMFY")<<'\n';

    return  0;
}