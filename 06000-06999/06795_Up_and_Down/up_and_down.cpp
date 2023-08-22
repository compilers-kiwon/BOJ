#include    <iostream>

using namespace std;

#define FORWARD     0
#define BACKWARD    1
#define MAX_DIR     2
#define NEXT_DIR(d) (((d)+1)%MAX_DIR)

int get_final_pos(int f,int b,int s)
{
    int total,cur_dir,pos;

    total = pos = 0;
    cur_dir = FORWARD;

    for (;s-total>0;cur_dir=NEXT_DIR(cur_dir)) {
        int cur_step = min((cur_dir==FORWARD)?f:b,s-total);

        pos += ((cur_dir==FORWARD)?1:-1)*cur_step;
        total += cur_step;
    }
    
    return  pos;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a,b,c,d,s,nikky,byron;

    cin>>a>>b>>c>>d>>s;

    nikky = get_final_pos(a,b,s);
    byron = get_final_pos(c,d,s);

    cout<<(nikky>byron?"Nikky":
            (nikky<byron)?"Byron":"Tied")<<'\n';
    return  0;
}