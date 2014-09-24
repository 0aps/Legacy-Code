#include <iostream>
#include <queue>

using namespace std;

struct compare
{
  bool operator()(const int& l, const int& r)
  {
      return l > r;
  }
};
 
 
int main()
{
    //priority_queue<int,vector<int>, compare > pq;
    priority_queue<int,vector<int>, greater<int> > pq;
    priority_queue<int,vector<int> > npq;
    
    
    npq.push(3);
    npq.push(5);
    npq.push(1);
    npq.push(8);
    
    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(8);
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    while (!npq.empty())
    {
        cout << npq.top() << endl;
        npq.pop();
    }
    cin.get();
    return 0;
}
