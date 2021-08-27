#include    <iostream>
#include    <vector>
#include    <string>
#include    <map>

using namespace std;

map<string,int> point;

#define CONFISCATED 100

int    input(map<string,int>& records,vector<string>& students)
{
    int W,N;

    cin>>W>>N;

    for(int i=1;i<=N;i++)
    {
        string  name,code;

        cin>>name>>code;

        if( records.find(name) == records.end() )
        {
            students.push_back(name);
        }

        records[name] += point[code];
    }

    return  W;
}

void    find_confiscated_phone(map<string,int>& records,
                               vector<string>& students,
                               vector<string>& result)
{
    for(int i=0;i<students.size();i++)
    {
        if( records[students[i]] >= CONFISCATED )
        {
            result.push_back(students[i]);
        }
    }
}

void    print(int week,vector<string>& n)
{
    cout<<"Week "<<week<<' ';

    if( n.empty() )
    {
        cout<<"No phones confiscated";
    }
    else
    {
        for(int i=0;i<n.size();i++)
        {
            if( i != 0 )
            {
                cout<<',';
            }

            cout<<n[i];
        }
    }

    cout<<'\n';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    point["TT"] = 75;
    point["TX"] = 50;
    point["PR"] = 80;
    point["RT"] = 30;
    point["AP"] = 25;
    point["PX"] = 60;

    for(;;)
    {
        int             week;
        map<string,int> penalty;
        vector<string>  s,c;

        week = input(penalty,s);

        if( week == 0 )
        {
            break;
        }

        find_confiscated_phone(penalty,s,c);
        print(week,c);
    }

    return  0;
}