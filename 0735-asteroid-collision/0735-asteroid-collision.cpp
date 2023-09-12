class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int> v;
        for(int x:asteroids){
            if(x>0){
                st.push(x);
            }
            else{
                if(st.empty() || st.top()<0){
                    st.push(x);
                }else{
                    while(!st.empty() && st.top()>0 && (st.top()+x)<0){
                        st.pop();
                    }
                    if(st.empty() || st.top()<0){
                        st.push(x);
                    }
                    else if(st.top()>0 && (st.top()+x)==0){
                        st.pop();
                    }
                }  
            }
        }
        while(!st.empty()){ 
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};