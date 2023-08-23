#include    <iostream>
#include    <string>

using namespace std;

#define ELIGIBLE        0
#define INELIGIBLE      1
#define COACH_PETITIONS 2

#define get_year(date)  (stoi((date).substr(0,4)))

const string state[] = {"eligible","ineligible","coach petitions"};

int get_state(const string& studies,
                const string& birth,int courses)
{
    if( get_year(studies)>=2010 || get_year(birth)>=1991 )
    {
        return  ELIGIBLE;
    }

    if( courses > 40 )
    {
        return  INELIGIBLE;
    }

    return  COACH_PETITIONS;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        string  name,studies,birth;
        int     courses;

        cin>>name>>studies>>birth>>courses;
        
        cout<<name<<' '<<
            state[get_state(studies,birth,courses)]<<'\n';
    }

    return  0;
}