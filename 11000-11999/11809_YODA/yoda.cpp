#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

#define remove_leading_zero(s) \
    {for(;(s).length()>1;(s).pop_back())if((s).back()!='0')break;}

#define fill_if_empty(s,f)  ((s)+=(s).empty()?(f):"")

int collide(string& N,string& M,string& r1,string& r2)
{
    for(;!N.empty()&&!M.empty();N.pop_back(),M.pop_back())
    {
        if( N.back() == M.back() )
        {
            r1.push_back(N.back());
            r2.push_back(M.back());
        }
        else
        {
            (N.back()>M.back())?
                r1.push_back(N.back()):r2.push_back(M.back());
        }
    }

    remove_leading_zero(r1);
    remove_leading_zero(r2);

    reverse(r1.begin(),r1.end());
    reverse(r2.begin(),r2.end());

    r1.insert(0,N.c_str());
    r2.insert(0,M.c_str());

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  N,M,r1,r2;

    cin>>N>>M;
    collide(N,M,r1,r2);

    fill_if_empty(r1,"YODA");
    fill_if_empty(r2,"YODA");

    cout<<r1<<'\n'<<r2<<'\n';
    return  0;
}