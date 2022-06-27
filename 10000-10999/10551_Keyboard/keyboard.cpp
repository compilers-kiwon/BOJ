#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    8
#define MOST_LEFT   0

const string    letters[MAX_SIZE] = {
    "1QAZ","2WSX","3EDC","4RFV5TGB","6YHN7UJM","8IK,","9OL.","0P;/-[\'=]"
};

void    simulate(const string& str,int cnt[])
{
    for(int i=0;i<str.length();i++)
    {
        for(int j=MOST_LEFT;j<MAX_SIZE;j++)
        {
            if( letters[j].find(str[i]) != string::npos )
            {
                cnt[j]++;
                break;
            }
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     cnt[MAX_SIZE];
    string  str;

    cin>>str;
    fill(&cnt[0],&cnt[MAX_SIZE],0);

    simulate(str,cnt);

    for(int i=MOST_LEFT;i<MAX_SIZE;i++)
    {
        cout<<cnt[i]<<'\n';
    }

    return  0;
}