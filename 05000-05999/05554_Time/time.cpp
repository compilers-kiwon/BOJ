#include <iostream>

using namespace std;

int main(void)
{
    int s1,s2,s3,s4,sum;
    
    cin>>s1>>s2>>s3>>s4;
    sum = s1+s2+s3+s4;
    cout<<sum/60<<endl<<sum%60<<endl;
    
    return 0;
}
