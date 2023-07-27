#include    <iostream>

using namespace std;

#define MAX_SIZE    (300000+1)

#define YEAR    0
#define MONTH   1
#define DAY     2

static int  N,Y,M,D;
static int  date[MAX_SIZE][3];

const static int date_order[3][3] = 
    {{0,1,2},{2,1,0},{2,0,1}};

const static int days_of_month[12+1] =
    {0,31,28,31,30,31,30,31,31,30,31,30,31};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define is_leap_year(y)     ((y)%4==0)
#define is_valid_year(y)    IN_RANGE(0,(y),99)
#define is_valid_month(m)   IN_RANGE(1,(m),12)
#define is_valid_day(y,m,d) \
    IN_RANGE(1,(d),days_of_month[(m)]+((is_leap_year((y))&&(m)==2)?1:0))

#define FALSE   0
#define TRUE    1

int input(void)
{
    cin>>Y>>M>>D>>N;

    for(int i=1;i<=N;i++)
    {
        int&    A = date[i][0];
        int&    B = date[i][1];
        int&    C = date[i][2];

        cin>>A>>B>>C;
    }

    return  0;
}

int is_valid_date(int y,int m,int d)
{
    return (is_valid_year(y)&&is_valid_month(m)
                &&is_valid_day(y,m,d))?TRUE:FALSE;
}

int is_safe_date(int y,int m,int d)
{
    if( Y != y ) return (Y<y)?TRUE:FALSE;
    if( M != m ) return (M<m)?TRUE:FALSE;
    return  (D<=d)?TRUE:FALSE;
}

int simulate(void)
{
    for(int i=1;i<=N;i++)
    {
        int cnt_of_valid_date = 0;
        int cnt_of_safe_date = 0;

        for(int order=0;order<3;order++)
        {
            int year = date[i][date_order[order][YEAR]];
            int month = date[i][date_order[order][MONTH]];
            int day = date[i][date_order[order][DAY]];

            if( is_valid_date(year,month,day) == FALSE )
            {
                continue;
            }
            
            cnt_of_valid_date++;

            if( is_safe_date(year,month,day) == FALSE )
            {
                break;
            }

            cnt_of_safe_date++;
        }

        if( cnt_of_valid_date == 0 )
        {
            cout<<"invalid\n";
            continue;
        }

        if( cnt_of_valid_date != cnt_of_safe_date )
        {
            cout<<"unsafe\n";
            continue;
        }

        cout<<"safe\n";
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    input();
    simulate();

    return  0;
}