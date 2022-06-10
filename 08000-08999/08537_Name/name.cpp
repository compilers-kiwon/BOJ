#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

int get_num_of_each_other_chrs(const string& str)
{
    set<char>   s;

    for(int i=0;i<str.length();i++)
    {
        s.insert(str[i]);
    }

    return  s.size();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int i,max_num;

    cin>>i;
    
    for(max_num=0;i>0;i--)
    {
        string  s;

        cin>>s;
        max_num = max(max_num,get_num_of_each_other_chrs(s));
    }

    cout<<max_num<<'\n';

    return  0;
}