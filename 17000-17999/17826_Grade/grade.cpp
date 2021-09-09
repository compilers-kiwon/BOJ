#include    <iostream>
#include    <string>

using namespace std;

#define MAX_GRADE   7
#define MAX_SIZE    50

const string    g_str[MAX_GRADE] = {"A+","A0","B+","B0","C+","C0","F"};
const int       bound[MAX_GRADE] = {5,15,30,35,45,48,50};

int h,s[MAX_SIZE+1];

void    input(void)
{
    for(int i=1;i<=MAX_SIZE;i++)
    {
        cin>>s[i];
    }

    cin>>h;
}

int     get_grade(void)
{
    int ret;

    for(int i=0;i<MAX_GRADE;i++)
    {
        if( h >= s[bound[i]] )
        {
            ret = i;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<g_str[get_grade()]<<'\n';

    return  0;
}