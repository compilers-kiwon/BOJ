#include    <iostream>

using namespace std;

typedef struct{int y,m,d;}  Date;

#define get_num_of_days(n)  ((((n).y-1)*12+(n).m-1)*30+(n).d)

#define MAX_MONTHLY 36

#define NUM_OF_DAYS_PER_MONTH   30
#define NUM_OF_MONTHS_PER_YEAR  12

#define get_annual_of_this_year(y)  (max(0,((y)-1))/2+15)

int simulate(const Date& from,const Date& to,int& annual,int& monthly)
{
    int start = get_num_of_days(from);
    int end = get_num_of_days(to);

    for(int i=start+NUM_OF_DAYS_PER_MONTH,m_cnt=1,y_cnt=0;
        i<=end;
        i+=NUM_OF_DAYS_PER_MONTH,m_cnt++)
    {
        if( m_cnt == NUM_OF_MONTHS_PER_YEAR )
        {
            m_cnt = 0;
            y_cnt++;
            annual += get_annual_of_this_year(y_cnt);
        }

        monthly++;
    }

    return  end-start;
}

int input(Date& from,Date& to)
{
    cin>>from.y>>from.m>>from.d;
    cin>>to.y>>to.m>>to.d;

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Date    from,to;
    int     annual,monthly,num_of_working_days;

    input(from,to);
    
    annual = monthly = 0;
    num_of_working_days = simulate(from,to,annual,monthly);

    cout<<annual<<' '<<min(monthly,MAX_MONTHLY)<<'\n';
    cout<<num_of_working_days<<"days\n";

    return  0;
}