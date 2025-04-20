#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
const int N=1E3+5; 
ll a[N]; 
ll dp[N];//表示以第i位对手结尾的最长递增子序列长度 
int main() { 
    int n;
    cin>>n;
    //表示对手的个数 
    for(int i=1;i<=n;i++)
    cin>>a[i]; 
    for(int i=1;i<=n;i++)
     { 
        dp[i]=1; 
        for(int j=1;j<i;j++)
        //前面的所有对手 
        { 
            if(a[i]>a[j]) 
            { 
                dp[i]=max(dp[i],dp[j]+1); 
            } 
        } 
    } 
    ll ans=0; 
    for(int i=1;i<=n;i++) {

        ans=max(ans,dp[i]); 

    } 
    cout<<ans<<endl;
    
    return 0; 
}
