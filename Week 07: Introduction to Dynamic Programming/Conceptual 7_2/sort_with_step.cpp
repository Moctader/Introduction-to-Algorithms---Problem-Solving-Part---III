#include<iostream>
#include<vector>
#include<map>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while (t--)
    {
       map<int, int>pos;
       int n, k; 
       cin>>n>>k;
       for(int i=1; i<=n; i++)
       {
            int in;
            cin>>in;
            pos[in]=i;
       }
       int count=0;
       
        for(auto value:pos)
        {
            int current_position, correct_position;
            current_position=value.second;
            correct_position=value.first;
            if (abs(current_position-correct_position)%k!=0)
            {
                count++;
            }
        }


        if (count==0)
        {
            cout<<0<<endl;
        }
        else if (count==2)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        
        
        
        

    }
    
    return 0;
}