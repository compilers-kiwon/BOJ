#include    <iostream>
#include    <string>

using namespace std;

#define chr2int(c)  ((int)((c)-'0'))
#define get_num_of_always_stand_up(S)   (chr2int((S).front()))

int simulate(void)
{
    int S_max,ret,cur_num;
    string  S;

    cin>>S_max>>S;
    cur_num = get_num_of_always_stand_up(S);
    
    ret = 0;

    for(int shyness=1;shyness<=S_max;shyness++)
    {
        int required = shyness;
        int invited = max(0,required-cur_num);

        ret += invited;
        cur_num += invited+chr2int(S[shyness]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        cout<<"Case #"<<t<<": "<<simulate()<<'\n';
    }

    return  0;
}