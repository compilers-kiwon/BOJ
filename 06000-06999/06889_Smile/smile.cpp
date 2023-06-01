#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

int input_str(int num,vector<string>& buf)
{
    for(int i=0;i<num;i++)
    {
        string  str;

        cin>>str;
        buf.push_back(str);
    }

    return  0;
}

int print(vector<string>& head,vector<string>& tail)
{
    for(int i=0;i<head.size();i++)
    {
        for(int j=0;j<tail.size();j++)
        {
            cout<<head[i]<<" as "<<tail[j]<<'\n';
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,m;
    vector<string> adjectives,nouns;

    cin>>n>>m;

    input_str(n,adjectives);
    input_str(m,nouns);

    print(adjectives,nouns);
    return  0;
}