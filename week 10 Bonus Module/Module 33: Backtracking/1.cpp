#include<iostream>
#include<vector>
#include<map>
using namespace std;
int n;
vector<vector<int>>ans;

vector<int> get_candidatee(int id, vector<int>state)
{
    map<int, int>taken;
    for(auto x: state)
    {
        taken[x]=1;
    }
    

    vector<int>candidates;
    for(int i=1; i<=n; i++)
    {
        if (taken[i]==0)
        {
            candidates.push_back(i);
        }
        
    }

    return candidates;
}

bool find_solution(int id, vector<int>initial_state)
{
    if (n==id)
    {
        return true;
    }
    return false;
    
}

void backtrack(int id, vector<int>initial_state)
{
    if (find_solution(id, initial_state))
    {
        ans.push_back(initial_state);
        return;
    }

    vector<int>candidates= get_candidatee(id, initial_state);
    for(auto candidate: candidates)
    {
        initial_state[id]=candidate;
        backtrack(id+1, initial_state);
        initial_state[id]=0;
    }
    
}
int main()
{
    cin>>n;
    vector<int>initial_state(n);
    backtrack(0, initial_state);

    for(auto permutation:ans)
    {
        for(auto x:permutation)
        {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}