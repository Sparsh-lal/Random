/*
    Problem:
        Given a function 'ok(int x)' which returns for some integer 'k'
            false, when x < k 
            true, when x >= k
    Input:
        The value 'k'
    Output:
        Return the value of 'k' after computation

    Corollary:
        Here the Input as well as Output are same which seem counter-intuitive
        But, this is because I am custom implementing the 'ok(int x)' fucntion here
        In the actual problem, we'd be given the 'ok(int x)' function already, so the input and output would be different
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

// custom implementation of the 'ok(int x)' function
int k;
bool ok(int x){
    return x >= k;
}
 
void solve(){
    // Taking the value of 'k' as input
    cin >> k;

    // assuming initial jump length 'z' is large enough
    int z = 6; // hardcoding the value of z, which we can change later on, based on real constraints
    
    int x = -1;
    for(int i = z; i>=1; i/=2) while(!ok(x + i)) x += i;

    int ans = x + 1;
    cout << ans;
}
 
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int t = 1;
    // cin >> t;

    while(t--) solve();
 
    return 0;
}