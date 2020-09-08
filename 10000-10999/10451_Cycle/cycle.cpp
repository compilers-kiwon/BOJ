#include <cstdio>
#include <vector>

using namespace std;

void  find_cycle(vector<int>& n,vector<bool>& visited,int index)
{
    if( visited[index] != true )
    {
        visited[index] = true;
        find_cycle(n,visited,n[index]);
    }
}

int main(void)
{
    int T;
    
    scanf("%d",&T);
    
    while(T>0)
    {
        int N;
        
        scanf("%d",&N);
        
        vector<int> n(N+1);
        vector<bool> visited(N+1,false);
        
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&n[i]);
        }
        
        int cnt = 0;
        
        for(int i=1;i<=N;i++)
        {
            if( visited[i] == false)
            {
                ++cnt;
                visited[i] = true;
                find_cycle(n,visited,n[i]);
            }
        }
        printf("%d\n",cnt);
        
        T--;
    }
    return 0;
}
