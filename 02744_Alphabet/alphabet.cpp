#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string before,after;
    
    cin>>before;
    
    for(int i=0;i<before.length();i++)
    {
        char diff,from;
        
        if( before[i]>='a' && before[i]<='z' )
        {
            from = 'A';
            diff = before[i]-'a';
        }
        else
        {
            from = 'a';
            diff = before[i]-'A';
        }
        
        after.push_back(from+diff);
    }
    cout<<after<<endl;
        
    return 0;
}
