#include    <iostream>
#include    <string>

using namespace std;

const string translation_table = "4bcd3fgh1jklmn0pqr5tuvwxyz";

#define get_idx(c)  ((int)((c)-'a'))

int translate(const string& str,string& result)
{
    for(int i=0;i<str.length();i++)
    {
        result.push_back(translation_table[get_idx(str[i])]);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str,result;

    cin>>str;
    translate(str,result);

    cout<<result<<'\n';
    return  0;
}