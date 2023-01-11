#include    <iostream>

using namespace std;

#define MAX_SIZE    (123456+1)
#define MAX_HP      0x7FFFFFFFFFFFFFFF

typedef long long int           int64;
typedef struct{int64 t,a,h;}    Dungeon;

int     N;
int64   H_ATK;
Dungeon d[MAX_SIZE];

#define get_tail(n,m)   ((((n)%2)&&((m)%2))?1:0)

void    input(void)
{
    cin>>N>>H_ATK;

    for(int i=1;i<=N;i++)
    {
        cin>>d[i].t>>d[i].a>>d[i].h;
    }
}

bool    battle(int64& s_hp,int64 s_atk,int64 m_hp,int64 m_atk)
{
    int64   num_of_attacks = (m_hp/s_atk)+((m_hp%s_atk)?1:0);

    s_hp -= m_atk*(num_of_attacks-1);
    return  (s_hp>0);
}

bool    simulate(int64 H_MAXHP)
{
    int64   current_hp,current_attack;

    current_hp = H_MAXHP;
    current_attack = H_ATK;

    for(int i=1;i<=N;i++)
    {
        if( d[i].t == 1 )
        {
            if( battle(current_hp,current_attack,d[i].h,d[i].a) == false )
            {
                return  false;
            }
        }
        else
        {
            current_hp = min(H_MAXHP,current_hp+d[i].h);
            current_attack += d[i].a;
        }
    }

    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   min_required_hp;

    input();

    for(int64 left=1,right=MAX_HP;left<=right;)
    {
        int64   mid = (left>>1)+(right>>1)+get_tail(left,right);

        if( simulate(mid) == true )
        {
            min_required_hp = mid;
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }

    cout<<min_required_hp<<'\n';

    return  0;
}