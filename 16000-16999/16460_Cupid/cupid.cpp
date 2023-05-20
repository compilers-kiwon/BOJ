#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

#define is_preferred_gender(p,g)    ((p).find((g))!=string::npos)
#define is_allowed_distance(d1,d2)  ((d1)>=(d2))

int see_who_like_me(pair<string,int> me,set<string>& matched)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  user;
        char    gender;
        int     dist;

        cin>>user>>gender>>dist;

        if( is_preferred_gender(me.first,gender)
                && is_allowed_distance(me.second,dist) )
        {
            matched.insert(user);
        }
    }

    if( matched.empty() )
    {
        matched.insert("No one yet");
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  user,preferred_gender;
    int     maximum_distance;
    
    set<string> matched;

    cin>>user>>preferred_gender>>maximum_distance;
    see_who_like_me({preferred_gender,maximum_distance},matched);

    for(set<string>::iterator it=matched.begin();it!=matched.end();it++)
    {
        cout<<*it<<'\n';
    }
    
    return  0;
}