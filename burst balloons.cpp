//dfs and back track 
#include<bits/stdc++.h>
using namespace std;

int n, ar[20], visited[20], max_ans;

void fun(int shot, int ans) {
    if (shot == n) {
        max_ans = max(max_ans, ans);
        return;
    }

    int original_ans = ans;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;

            // Default neighbors are 1
            int left = 1, right = 1,lf=0,rf=0;

            // Find left unvisited
            for (int j = i - 1; j >= 0; j--) {
                if (!visited[j]) {
                    lf=1;
                    left = ar[j];
                    break;
                }
            }

            // Find right unvisited
            for (int j = i + 1; j < n; j++) {
                if (!visited[j]) {
                    rf=1;
                    right = ar[j];
                    break;
                }
            }
            if(!lf && !rf)ans+=ar[i];
            else ans += left * right;

            fun(shot + 1, ans);

            // Backtrack
            ans = original_ans;
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        visited[i] = 0;
    }
    max_ans = INT_MIN;
    fun(0, 0);
    cout << max_ans << endl;
    return 0;
}


//another solution but vul khuje passina 

/*
#include <bits/stdc++.h>
using namespace std;
int n,mxans;
vector<int>ar,dp;
int solve(int mask);
int main()
{
    cin>> n;
    ar.assign(n,0);
    for(int i=0;i<n;i++)cin>>ar[i];
    dp.assign(1<<n,-1);
    //mxans=INT_MIN;
    cout<<solve(0)<<endl;
    
    //cout<<mxans<<endl;
    return 0;
}
int  solve(int mask)
{
    if(mask==(1<<n) -1) return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ans=0;mxans=0;
    for(int i=0;i<n;i++)
    {
        if((mask & 1<<i)==0)
        {
            int left,right,lf,rf,ans =0;
            left=right=1;lf=rf=0;
            // find left neighbor
            for (int j = i - 1; j >= 0; j--) {
                if ((mask & (1 << j)) == 0) {
                    left = ar[j];lf=1;
                    break;
                }
            }

            // find right neighbor
            for (int j = i + 1; j < n; j++) {
                if ((mask & (1 << j)) == 0) {
                    right = ar[j];rf=1;
                    break;
                }
            }
            if(!lf && !rf ) ans=ar[i];
            else ans=left*right;
            int new_mask= mask |1<<i;
            mxans= max(mxans,ans+solve(new_mask));
        }
    }
    return dp[mask]=mxans;
}

*/
