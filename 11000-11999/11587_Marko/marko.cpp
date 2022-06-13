#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

char  keyboard[0x100];

void    init_keyboard(void)
{
    keyboard['a'] = keyboard['b'] = keyboard['c'] = '2';
    keyboard['d'] = keyboard['e'] = keyboard['f'] = '3';
    keyboard['g'] = keyboard['h'] = keyboard['i'] = '4';
    keyboard['j'] = keyboard['k'] = keyboard['l'] = '5';
    keyboard['m'] = keyboard['n'] = keyboard['o'] = '6';
    keyboard['p'] = keyboard['q'] = keyboard['r'] = keyboard['s'] = '7';
    keyboard['t'] = keyboard['u'] = keyboard['v'] = '8';
    keyboard['w'] = keyboard['x'] = keyboard['y'] = keyboard['z'] = '9';
}

void    get_input_seq(const string& w,string& k)
{
    for(int i=0;i<w.length();i++)
    {
        k.push_back(keyboard[w[i]]);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             N;
    map<string,int> cnt;

    cin>>N;
    init_keyboard();
    
    for(int i=1;i<=N;i++)
    {
        string  w,k;

        cin>>w;
        get_input_seq(w,k);

        cnt[k]++;
    }

    string  S;

    cin>>S;
    cout<<cnt[S]<<'\n';

    return  0;
}