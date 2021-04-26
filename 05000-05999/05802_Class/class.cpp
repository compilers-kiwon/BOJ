#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define PRESENT                             0
#define NEED_TO_STUDY_AT_HOME               1
#define NEED_TO_REMEDIAL_WORK_AFTER_SCHOOL  2
#define ABSENT                              3
#define MAX_TYPE                            4

const string    str[MAX_TYPE] = {"Present","Needs to study at home",
                                 "Needs remedial work after school","Absent"};

void    parse(string& input,vector<string>& result)
{
    string  w;

    input.push_back(' ');

    for(int i=0;i<input.length();i++)
    {
        char&   c = input[i];

        if( c == ' ' )
        {
            result.push_back(w);
            w.clear();
        }
        else
        {
            w.push_back(c);
        }
    }
}

int     get_report(const vector<string>& result)
{
    if( result.size() == 1 )
    {
        return  ABSENT;
    }

    if( result.size() == 2 )
    {
        return  PRESENT;
    }

    if( result.size()<6 || (result.back()=="yes" || result.back()=="y") )
    {
        return  NEED_TO_STUDY_AT_HOME;
    }

    return  NEED_TO_REMEDIAL_WORK_AFTER_SCHOOL;
}

int     main(void)
{
    int K;

    cin>>K;

    for(int k=1;k<=K;k++)
    {
        int N,cnt[MAX_TYPE];

        cin>>N;getchar();
        fill(&cnt[0],&cnt[MAX_TYPE],0);

        for(int n=1;n<=N;n++)
        {
            string          assessment;
            vector<string>  p;

            getline(cin,assessment);
            parse(assessment,p);

            cnt[get_report(p)]++;
        }

        cout<<"Roll-call: "<<k<<'\n';

        for(int i=0;i<MAX_TYPE;i++)
        {
            cout<<str[i]<<": "<<cnt[i]<<" out of "<<N<<'\n';
        }
    }

    return  0;
}