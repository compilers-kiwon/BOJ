#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MAX_LEN     8
#define chr2int(c)  ((int)((c)-'0'))

void    shuffle(const string& n1,
                const string& n2,
                vector<int>& result)
{
    for(int i=0;i<MAX_LEN;i++)
    {
        result.push_back(chr2int(n1[i]));
        result.push_back(chr2int(n2[i]));
    }
}

void    calulate(vector<int>& n)
{
    for(;n.size()!=2;n.pop_back())
    {
        for(int i=0;i<n.size()-1;i++)
        {
            n[i] = (n[i]+n[i+1])%10;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    string      A,B;
    vector<int> buffer;

    cin>>A>>B;
    shuffle(A,B,buffer);

    calulate(buffer);
    cout<<buffer.front()<<buffer.back()<<'\n';

    return  0;
}