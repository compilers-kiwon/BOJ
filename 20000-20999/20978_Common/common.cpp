#include    <iostream>
#include    <set>

using namespace std;

int find_common_elements(const set<int>& A,const set<int>& B)
{
    set<int>::iterator  it1,it2;

    for(it1=A.begin(),it2=B.begin();it1!=A.end()&&it2!=B.end();)
    {
        if (*it1==*it2) {cout<<*it1<<'\n';it1++,it2++;}
        else {(*it1<*it2)?it1++:it2++;}
    }

    return  0;
}

int read_elements(int num_of_elements,set<int>& s)
{
    for(int i=1;i<=num_of_elements;i++)
    {
        int n;

        cin>>n;
        s.insert(n);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N,M;
    set<int>    A,B;

    cin>>N>>M;
    
    read_elements(N,A);
    read_elements(M,B);

    find_common_elements(A,B);
    return  0;
}