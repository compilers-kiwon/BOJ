    #include    <iostream>

    using namespace std;

    #define is_divisible(a,b)   ((a)%(b)==0)

    int main(void)
    {
        cin.tie(NULL);
        cin.sync_with_stdio(false);

        int     p,q,s;
        bool    found = false;

        cin>>p>>q>>s;

        for(int i=1;i<=s;i++)
        {
            if( is_divisible(i,p) && is_divisible(i,q) )
            {
                found = true;
                break;
            }
        }

        cout<<(found?"yes":"no")<<'\n';

        return  0;
    }