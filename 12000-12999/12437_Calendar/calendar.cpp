#include    <iostream>

using namespace std;

int make_calendar(int num_of_months,
        int days_per_month,int days_per_week)
{
    int row,col;

    row = 1;
    col = 0;

    for(int m=1;m<=num_of_months;m++)
    {
        row += (col!=0)?1:0;

        for(int d=1;d<=days_per_month;d++)
        {
            if( ++col == days_per_week )
            {
                col=0,row++;
            }
        }
    }

    row -= (col==0)?1:0;

    return  row;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int months_per_year,days_per_month,days_per_week;

        cin>>months_per_year>>days_per_month>>days_per_week;
        cout<<"Case #"<<i<<": "<<
            make_calendar(months_per_year,days_per_month,days_per_week)<<'\n';
    }

    return  0;
}