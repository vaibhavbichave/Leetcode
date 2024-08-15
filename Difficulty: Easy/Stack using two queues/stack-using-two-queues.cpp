//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    if(q1.empty()){
        q2.push(x);
    } else {
        q1.push(x);
    }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    int top = -1;
    if(!q1.empty()){
        for(int i=q1.size();i>1;i--){
            q2.push(q1.front());
            q1.pop();
        }
        top = q1.front();
        q1.pop();
    } else if(!q2.empty()){
        for(int i=q2.size();i>1;i--){
            q1.push(q2.front());
            q2.pop();
        }
        top = q2.front();
        q2.pop();
    }
    return top;
}
