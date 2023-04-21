#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

typedef long long int   int64;

const static int days_of_month[12+1] = 
        {0,
         0,
         31,
         31+28,
         31+28+31,
         31+28+31+30,
         31+28+31+30+31,
         31+28+31+30+31+30,
         31+28+31+30+31+30+31,
         31+28+31+30+31+30+31+31,
         31+28+31+30+31+30+31+31+30,
         31+28+31+30+31+30+31+31+30+31,
         31+28+31+30+31+30+31+31+30+31+30};

#define convert_days(M)         (days_of_month[(M)])
#define convert_minutes(D,H,M)  (((D)-1)*24*60+(H)*60+(M))

static int  N,L,F;
static map<string,int64> penalty;
static map<string,map<string,int>> state;

int init(void)
{
    int d,h,m;

    scanf("%d %d/%d:%d %d",&N,&d,&h,&m,&F);
    L = convert_minutes(d+1,h,m);

    return  0;
}

int simulate(void)
{
    for(int i=1;i<=N;i++)
    {
        int     MM,DD,hh,mm,t;
        string  buf,P,M;

        cin>>buf;sscanf(buf.c_str(),"2021-%d-%d",&MM,&DD);
        cin>>buf;sscanf(buf.c_str(),"%d:%d",&hh,&mm);
        cin>>P>>M;

        t = convert_minutes(convert_days(MM)+DD,hh,mm);

        map<string,map<string,int>>::iterator   part = state.find(P);

        if( part!=state.end() && part->second.find(M)!=part->second.end() )
        {
            int rental_time = t-(part->second.find(M)->second);
            penalty[M] += (int64)(max(rental_time-L,0)*F);

            part->second.erase(M);
            if(part->second.empty()) state.erase(P);
        }
        else
        {
            state[P][M] = t;
        }
    }

    return  0;
}

int print(void)
{
    bool    printed = false;
    map<string,int64>::iterator it;

    for(it=penalty.begin();it!=penalty.end();it++)
    {
        if( it->second != 0 )
        {
            printed = true;
            cout<<it->first<<' '<<it->second<<'\n';
        }
    }

    if( printed == false )
    {
        cout<<"-1\n";
    }

    return  0;
}

int main(void)
{
    init();
    simulate();
    print();

    return  0;
}