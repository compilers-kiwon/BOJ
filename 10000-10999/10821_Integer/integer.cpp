#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string S;
    
    cin>>S;
    
    int cnt,i;
    
    for(cnt=1,i=0;i<S.length();i++)
    {
        if( S[i] == ',' )
        {
            ++cnt;
        }
    }
    cout<<cnt<<endl;
    
    return 0;
}
