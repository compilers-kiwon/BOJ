#include <iostream>

using namespace std;

#define NUM_OF_STATIONS 10

int main(void)
{
    int max_num,current,i;
    
    for(i=1,max_num=current=0;i<=NUM_OF_STATIONS;i++)
    {
        int in,out;
        
        cin>>in>>out;
        current = current-in+out;
        max_num = max(max_num,current);
    }
    cout<<max_num<<endl;
    
    return 0;
}
