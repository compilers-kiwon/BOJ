#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define NUM_OF_MEMBERS  7
#define MAX_SIZE        12

const static pair<int,int>  start_date[MAX_SIZE] = {
    {1,20},{2,19},{3,21},{4,20},{5,21},{6,22},
    {7,23},{8,23},{9,23},{10,23},{11,23},{12,22}
};

#define MAX_MONTH   12
#define MAX_DAYS    31  // Assume that the number of days per each month is 31
                        // Because a date of a sign is not placed at a boundary of a month,
                        // we can simplify a calculation of a date.

static int  sign_table[MAX_MONTH+1][MAX_DAYS+1];
static bool occupied[MAX_SIZE];

int init(void)
{
    for(int i=0,sign_idx=1;i<MAX_SIZE-1;i++,sign_idx++)
    {
        int start_month = start_date[i].first;
        int start_day = start_date[i].second;

        int end_month = start_date[i+1].first;
        int end_day = start_date[i+1].second;

        for(int cur_month=start_month,cur_day=start_day;
                    !(cur_month==end_month&&cur_day==end_day);)
        {
            sign_table[cur_month][cur_day] = sign_idx;

            if( ++cur_day > MAX_DAYS )
            {
                cur_month++;
                cur_day = 1;
            }
        }
    }

    return  0;
}

int get_members_sign(void)
{
    for(int i=1;i<=NUM_OF_MEMBERS;i++)
    {
        int m,d;

        cin>>m>>d;
        occupied[sign_table[m][d]] = true;
    }

    return  0;
}

int simulate(void)
{
    int N,ret;
    vector<pair<int,int>>   birthdays;

    cin>>N;
    ret = 0;

    for(int i=1;i<=N;i++)
    {
        int m,d;

        cin>>m>>d;
        birthdays.push_back({m,d});
    }

    sort(birthdays.begin(),birthdays.end());

    for(int i=0;i<N;i++)
    {
        int&    m = birthdays[i].first;
        int&    d = birthdays[i].second;

        if( occupied[sign_table[m][d]] == false )
        {
            cout<<m<<' '<<d<<'\n';
            ret++;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    get_members_sign();

    cout<<(simulate()==0?"ALL FAILED":"")<<'\n';
    return  0;
}