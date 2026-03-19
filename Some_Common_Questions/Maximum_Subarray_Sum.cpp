#include <bits/stdc++.h>
#define int long long
using namespace std;

void Brute_Force(vector<int>& a){
    int n = a.size(), ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=i; j<n; ++j){
            int sum = 0;
            for(int k=i; k<j; ++k) sum += a[k];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}

void Better_Approach(vector<int>& a){
    int n = a.size(), ans = 0;
    for(int i=0; i<n; ++i){
        int sum = 0;
        for(int j=i; j<n; ++j){
            sum += a[j];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}

void Most_Efficient(vector<int>& a){
    int n = a.size(), ans = 0, sum = 0;
    for(int i=0; i<n; ++i){
        sum = max(a[i], sum + a[i]);
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
 
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    // Brute Force Approach: O(n^3)
    auto s1 = chrono::high_resolution_clock::now();
    cout << "Brute force approach: ";
    Brute_Force(a);
    auto e1 = chrono::high_resolution_clock::now();
    auto d1 = chrono::duration_cast<chrono::microseconds>(e1 - s1);
    cout << "Time taken: " << d1.count() << " microseconds.\n" << endl;

    // Slightly Better Approach: O(n^2)
    auto s2 = chrono::high_resolution_clock::now();
    cout << "Slightly better approach: ";
    Better_Approach(a);
    auto e2 = chrono::high_resolution_clock::now();
    auto d2 = chrono::duration_cast<chrono::microseconds>(e2 - s2);
    cout << "Time taken: " << d2.count() << " microseconds.\n" << endl;

    // Most efficient Approach: O(n)
    auto s3 = chrono::high_resolution_clock::now();
    cout << "Most efficient approach: ";
    Most_Efficient(a);
    auto e3 = chrono::high_resolution_clock::now();
    auto d3 = chrono::duration_cast<chrono::microseconds>(e3 - s3);
    cout << "Time taken: " << d3.count() << " microseconds.\n" << endl;
}
 
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int t = 1;
    // cin >> t;
 
    while(t--) solve();
 
    return 0;
}