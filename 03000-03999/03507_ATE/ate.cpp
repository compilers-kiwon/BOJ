#include    <iostream>

using namespace std;

#define MIN_NUM 0
#define MAX_NUM 99

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,lucky;

    cin>>n;
    lucky = 0;

    for(int mid=MIN_NUM;mid<=MAX_NUM;mid++)
    {
        for(int tail=MIN_NUM;tail<=MAX_NUM;tail++)
        {
            lucky += ((n-mid-tail)==0?1:0);
        }
    }

    cout<<lucky<<'\n';

    return  0;
}