#include    <iostream>
#include    <string>

using namespace std;

#define MIN_LEN    6
#define MAX_LEN    9

#define IN_RANGE(MIN,n,MAX)    ((MIN)<=(n)&&(n)<=(MAX))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int N;
    
    cin>>N;
    
    for(int i=1;i<=N;i++)
    {
        string  str;
        
        cin>>str;
        cout<<(IN_RANGE(MIN_LEN,str.length(),MAX_LEN)?"yes\n":"no\n");
    }
    
    return    0;
}