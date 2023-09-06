#include    <iostream>
#include    <vector>
#include    <set>

using namespace std;

#define SIZE_OF_NEXT    5

#define END_OF_SEQUENCE "]"
#define MID_OF_SEQUENCE ", "

int get_next_numbers(int last,int offset,
                        vector<int>& next_numbers)
{
    for (next_numbers.push_back(last+offset);
         next_numbers.size()<SIZE_OF_NEXT;
         next_numbers.push_back(next_numbers.back()+offset));
    return  0;
}

bool    is_arithmetic_sequence(const vector<int>& s,int& offset)
{
    set<int>    diff;

    for (int i=1;i<s.size();i++) diff.insert(s[i]-s[i-1]);
    if (diff.size() != 1) return false;

    offset = *(diff.begin());
    return  true;
}

int input(vector<int>& s)
{
    int n,num;

    cin>>n;

    for (int i=1;i<=n;i++) {
        cin>>num;
        s.push_back(num);
    }

    return  0;
}

int print_sequence(const vector<int>& s)
{
    cout<<'[';

    for (int i=0;i<s.size();i++) {
        cout<<s[i]<<(i==s.size()-1?
                        END_OF_SEQUENCE:MID_OF_SEQUENCE);
    }

    return  0;
}

int print_arithmetic(const vector<int>& head,
                        const vector<int>& tail)
{
    cout<<"The next "<<SIZE_OF_NEXT<<" numbers after ";
    print_sequence(head);cout<<" are: ";
    print_sequence(tail);cout<<'\n';

    return  0;
}

int print_non_arithmetic(const vector<int>& head)
{
    cout<<"The sequence ";
    print_sequence(head);
    cout<<" is not an arithmetic sequence.\n";

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin>>t;t>0;t--) {
        int offset;
        vector<int> s;

        input(s);

        if (is_arithmetic_sequence(s,offset)) {
            vector<int> next;

            get_next_numbers(s.back(),offset,next);
            print_arithmetic(s,next);
        } else {
            print_non_arithmetic(s);
        }
    }

    return  0;
}