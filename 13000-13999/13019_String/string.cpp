#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    0x100

bool    can_be_same(const string& A,const string& B)
{
    int A_cnt[MAX_SIZE] = {0,};
    int B_cnt[MAX_SIZE] = {0,};

    for(int i=0;i<A.length();i++)
    {
        A_cnt[A[i]]++;B_cnt[B[i]]++;
    }

    for(char c='A';c<='Z';c++)
    {
        if( A_cnt[c] != B_cnt[c] )
        {
            return  false;
        }
    }

    return  true;
}

int main(void)
{
    string  A,B;

    cin>>A>>B;

    if( !can_be_same(A,B) )
    {
        cout<<"-1\n";
        return  0;
    }

    int cnt = 0;

    for(int A_pos=A.length()-1,B_pos=B.length()-1;A_pos>=0;A_pos--)
    {
        if( A[A_pos] == B[B_pos] )
        {
            B_pos--;
        }
        else
        {
            cnt++;
        }
    }

    cout<<cnt<<'\n';
    return  0;
}