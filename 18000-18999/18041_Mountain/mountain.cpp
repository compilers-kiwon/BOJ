#include    <iostream>
#include    <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         N,X,max_len;
    vector<int> cur_course;

    cin>>N>>X;
    max_len = 0;

    for (int i=1;i<=N;i++) {
        int A;

        cin>>A;

        if(!(cur_course.empty()
                || A-cur_course.back()<=X)) {
            max_len = max(max_len,(int)cur_course.size());
            cur_course.clear();
        }
        
        cur_course.push_back(A);
    }

    cout<<max(max_len,(int)cur_course.size())<<'\n';
    return  0;
}