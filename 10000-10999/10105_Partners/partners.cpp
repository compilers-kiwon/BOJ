#include    <iostream>
#include    <string>
#include    <vector>
#include    <map>

using namespace std;

#define read_names(size,list) \
    {for(int i=0;i<(size);i++){\
        string name;cin>>name;(list).push_back(name);}}

#define GOOD    1
#define BAD     0

#define is_included(m,i)    ((i)!=(m).end())

int input(vector<string>& s1,vector<string>& s2)
{
    int N;

    cin>>N;
    read_names(N,s1);read_names(N,s2);

    return  0;
}

int simulate(vector<string>& s1,vector<string>& s2)
{
    map<string,string>  assigned;

    for (int i=0;i<s1.size();i++) {
        string  n1 = s1[i];
        string  n2 = s2[i];

        if (n1 == n2) return BAD;

        map<string,string>::iterator    it1,it2;

        it1 = assigned.find(n1);
        it2 = assigned.find(n2);

        if (!is_included(assigned,it1) && !is_included(assigned,it2)) {
            assigned[n1] = n2;
            assigned[n2] = n1;
            continue;
        }

        if (is_included(assigned,it1) && it1->second==n2
                && is_included(assigned,it2) && it2->second==n1) {
            continue;
        }

        return  BAD; 
    }

    return  GOOD;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string>  s1,s2;

    input(s1,s2);
    cout<<(simulate(s1,s2)==GOOD?"good":"bad")<<'\n';

    return  0;
}