#include    <iostream>
#include    <queue>

using namespace std;

typedef long long int   int64;

const static int64  ITEM = -1;
const static int    SUCCESS = 1;
const static int    FAIL = 0;

bool    clear_out_enemy(int64& soldier,int num_of_items,
                                priority_queue<int64>& enemy)
{
    for(;!enemy.empty();) {
        int64   cur_enemy = -enemy.top();

        if (cur_enemy <= soldier) {
            soldier += cur_enemy;
            enemy.pop();
        } else {
            if (num_of_items == 0) return false;
            for (;num_of_items!=0&&cur_enemy>soldier;
                  soldier<<=1,num_of_items--);
        }
    }

    for (;num_of_items>0;soldier<<=1,num_of_items--);
    return  true;
}

void    input(int& num_of_items,int num_of_floors,
                        priority_queue<int64>& enemy)
{
    for (int i=1;i<=num_of_floors;i++) {
        int64   s;

        cin>>s;

        if (s == ITEM) num_of_items++;
        else enemy.push(-s);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,M,result;
    int64   P;

    cin>>N>>M>>P;
    result = SUCCESS;

    for (int i=1;i<=N;i++) {
        priority_queue<int64>   enemy;
        int num_of_items = 0;

        input(num_of_items,M,enemy);

        if (!clear_out_enemy(P,num_of_items,enemy)) {
            result = FAIL;
            break;
        }
    }

    cout<<result<<'\n';
    return  0;
}