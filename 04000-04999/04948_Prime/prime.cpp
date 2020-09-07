#include <iostream>

using namespace std;

#define MAX_NUM 123456

bool prime_table[MAX_NUM*2+1];

void init_table(int N){
    prime_table[1] = true;
    for(int i=2;i<=N*2;i++)
    {
        if( prime_table[i] == false )
        {
            for(int j=i+i;j<=N*2;j+=i)
            {
                prime_table[j] = true;
            }
        }
    }
}
int main(void)
{
    init_table(MAX_NUM);
    
    while(1)
    {
        int n;
        
        cin>>n;
        
        if( n==0 )
        {
            break;
        }
        
        int cnt,i;
        
        for(cnt=0,i=n+1;i<=2*n;i++)
        {
            if( prime_table[i] == false )
            {
                ++cnt;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
