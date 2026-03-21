/*
Assumptions:
    1. The given array 'a', of length n, is already sorted
    2. We need to find the index of z, if it is present in 'a', otherwise return -1
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

int Traditional_Binary_Search(vector<int>& a, int z){
    int x = 0, y = (a.size() - 1);
    while(x <= y){
        int mid = (x + y) / 2;
        if(a[mid] == z) return mid;
        (a[mid] > z) ? y = mid - 1 : x = mid + 1;
    }
    return -1;
}

int Efficient_Binary_Search(vector<int>& a, int z){
    /*
        Idea is to make jumps and slow down when we get closer to the target element
        Search goes from l to r, initial jump length is n / 2, which is halved at each step
    */

    int n = a.size(), x = 0;
    for(int i=(n / 2); i>=1; i/=2){
        while(x + 1 < n && a[x + i] <= z) x += i;
    }
    return (a[x] == z) ? x : -1;
}

void solve(){
    // Taking Input
    int n, z; cin >> n >> z;
    vector<int> a(n);
    for(auto& i : a) cin >> i;

    // Method 1 --> Traditional Way
    auto s1 = chrono::high_resolution_clock::now();
    int ans_Traditional = Traditional_Binary_Search(a, z);
    auto e1 = chrono::high_resolution_clock::now();

    cout << "In Traditional way, ans: " << ans_Traditional;
    auto d1 = chrono::duration_cast<chrono::microseconds>(e1 - s1);
    cout << " in time: " << d1.count() << " ms." << endl;

    // Method 2 --> Efficient Way
    auto s2 = chrono::high_resolution_clock::now();
    int ans_Efficient = Efficient_Binary_Search(a, z);
    auto e2 = chrono::high_resolution_clock::now();

    cout << "In Efficient way, ans: " << ans_Efficient;
    auto d2 = chrono::duration_cast<chrono::microseconds>(e2 - s2);
    cout << " in time: " << d2.count() << " ms." << endl;
}
 
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int t = 1;
    // cin >> t;
 
    while(t--) solve();
 
    return 0;
}