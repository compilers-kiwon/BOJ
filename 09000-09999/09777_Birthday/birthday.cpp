#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    int     n;
    int     cnt[12+1] = {0,};
    string  buf;

    getline(cin,buf);
    n = stoi(buf);

    for (int i=1;i<=n;i++) {
        int id,dd,mm,yy;

        getline(cin,buf);
        sscanf(buf.c_str(),"%d %d/%d/%d",&id,&dd,&mm,&yy);
        cnt[mm]++;
    }

    for(int i=1;i<=12;i++) cout<<i<<' '<<cnt[i]<<'\n';
    return  0;
}