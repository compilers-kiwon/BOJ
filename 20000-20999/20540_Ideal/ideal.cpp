#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define add_ideal_type(t,n,m)   ((t)[(n)]=(m),(t)[(m)]=(n))

string  get_ideal_type(const string& me,
                        map<char,char>& ideal)
{
    string  ret;

    for(int i=0;i<me.size();i++)
    {
        ret.push_back(ideal[me[i]]);
    }

    return  ret;
}

void    init(map<char,char>& table)
{
    add_ideal_type(table,'E','I');
    add_ideal_type(table,'S','N');
    add_ideal_type(table,'T','F');
    add_ideal_type(table,'J','P');
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  me;
    map<char,char>  ideal;

    init(ideal);

    cin>>me;
    cout<<get_ideal_type(me,ideal)<<'\n';

    return  0;
}