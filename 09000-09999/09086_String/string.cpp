#include <iostream>
#include <string>

using namespace std;

int main()
{
  int T;
    
  cin>>T;
    
  for(int i=1;i<=T;i++)
  {
      string str;
      
      cin>>str;
      cout<<str[0]<<str[str.length()-1]<<endl;
  }
  return 0;        
}
