#include    <iostream>
#include    <string>

using namespace std;

#define print_ptr_idx(idx)  {if((idx)!=1)cout<<(idx);}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  p;

    cin>>N;
    cout<<"int a;\n";

    for(int i=1;i<=N;i++)
    {
        string  head = "int ";

        p.push_back('*');
        head += p+"ptr";

        cout<<head;
        print_ptr_idx(i);

        switch(i)
        {
            case 1:cout<<" = &a;\n";break;
            case 2:cout<<" = &ptr;\n";break;
            default:cout<<" = &ptr"<<i-1<<";\n";break;
        }
    }

    return  0;
}