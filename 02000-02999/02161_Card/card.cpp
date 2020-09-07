#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> card_q;
vector<int> removed_card;

int main(void)
{
    int N;
    
    cin>>N;
    
    for(int i=1;i<=N;i++)
    {
        card_q.push(i);
    }
    
    while( card_q.size() != 1 )
    {
        removed_card.push_back(card_q.front());
        card_q.pop();
        
        card_q.push(card_q.front());
        card_q.pop();
    }
    removed_card.push_back(card_q.front());
    
    for(int i=0;i<N;i++)
    {
        cout<<removed_card[i]<<' ';
    }
    cout<<endl;
    
    return 0;
}       
