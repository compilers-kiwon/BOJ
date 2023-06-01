#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    26

#define get_idx(c)      ((int)((c)-'A'))
#define shift(n,offset) (((n)+(offset))%MAX_SIZE)
#define get_char(idx)   ((char)(idx)+'A')
#define encrypt(P,K)    get_char(shift(get_idx((P)),get_idx((K))+1))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        string  key,plain,encrypted;

        cin>>key;
        
        if( key == "0" )
        {
            break;
        }
        else
        {
            cin>>plain;
        }

        for(int k=0,p=0;p<plain.length();
                    p++,k=(k+1)%key.length())
        {
            encrypted.push_back(encrypt(plain[p],key[k]));
        }

        cout<<encrypted<<'\n';
    }

    return  0;
}