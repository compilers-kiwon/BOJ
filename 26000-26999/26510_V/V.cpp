#include    <iostream>
#include    <string>

using namespace std;

int print(int size)
{
    for(int left_space=0,mid_space=2*size-3;
            left_space<size;left_space++,mid_space-=2)
    {
        cout<<string(left_space,' ')<<'*'<<
            string(max(mid_space,0),' ')<<(mid_space>0?"*\n":"\n");
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int n;cin>>n;print(n));
    return  0;
}