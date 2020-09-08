#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string word;
    int cnt,i;
    
    cin>>word;
    
    for(i=cnt=0;i<word.length();i++)
    {
        char c = word[i];
        
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
        
    return 0;
}
