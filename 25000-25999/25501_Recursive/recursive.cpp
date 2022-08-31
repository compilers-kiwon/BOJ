#include    <iostream>
#include    <string>

using namespace std;

int recursion(const string& str,int left,int right,int& cnt)
{
    cnt++;

    if( left >= right )
    {
        return  1;
    }

    return  ((str[left]!=str[right])?0:recursion(str,left+1,right-1,cnt));  
}

int isPalindrome(const string& str,int& cnt)
{
    return  recursion(str,0,str.length()-1,cnt);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        string  str;
        int     cnt,ret;

        cin>>str;
        cnt = 0;

        ret = isPalindrome(str,cnt);
        cout<<ret<<' '<<cnt<<'\n';
    }

    return  0;
}