#include    <iostream>

using namespace std;

#define NUM_OF_PREFERENCE   3
#define DO_NOT_CARE         '-'
#define PREF_LEN            10

static int  n,m,idx[0x100];
static int  cnt[NUM_OF_PREFERENCE+1]
               [NUM_OF_PREFERENCE+1]
               [NUM_OF_PREFERENCE+1];

int init(void)
{
    idx['-'] = 0;
    idx['k'] = idx['a'] = idx['r'] = 1;
    idx['e'] = idx['p'] = idx['b'] = 2;
    idx['m'] = idx['o'] = idx['g'] = 3;

    return  0;
}

int record_cnt(char s,char f,char c)
{
    cnt[idx[s]][idx[f]][idx[c]]++;
    cnt[idx[s]][idx[f]][idx[DO_NOT_CARE]]++;
    cnt[idx[s]][idx[DO_NOT_CARE]][idx[c]]++;
    cnt[idx[s]][idx[DO_NOT_CARE]][idx[DO_NOT_CARE]]++;
    cnt[idx[DO_NOT_CARE]][idx[f]][idx[c]]++;
    cnt[idx[DO_NOT_CARE]][idx[f]][idx[DO_NOT_CARE]]++;
    cnt[idx[DO_NOT_CARE]][idx[DO_NOT_CARE]][idx[c]]++;
    cnt[idx[DO_NOT_CARE]][idx[DO_NOT_CARE]][idx[DO_NOT_CARE]]++;

    return  0;
}

int input(void)
{
    scanf("%d %d",&n,&m);

    for (int i=1;i<=n;i++) {
        char    s[PREF_LEN],f[PREF_LEN],c[PREF_LEN];

        scanf("%s %s %s",s,f,c);
        record_cnt(s[0],f[0],c[0]);
    }

    return  0;
}

int main(void)
{
    init();
    input();

    for (int i=1;i<=m;i++) {
        char    s[PREF_LEN],f[PREF_LEN],c[PREF_LEN];

        scanf("%s %s %s",s,f,c);
        printf("%d\n",cnt[idx[s[0]]][idx[f[0]]][idx[c[0]]]);
    }

    return  0;
}