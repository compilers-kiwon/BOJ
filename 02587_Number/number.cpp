#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n[5];
    int sum;
    
    sum = 0;
    for(int i=0;i<5;i++)
    {
        cin>>n[i];
        sum += n[i];
    }
    
    sort(&n[0],&n[5]);
    
    cout<<sum/5<<endl<<n[2]<<endl;
    
    return 0;
}
