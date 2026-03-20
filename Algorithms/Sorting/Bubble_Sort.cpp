#include <bits/stdc++.h>
#define int long long
using namespace std;

void Bubble_Sort(vector<int>& a){
    // Worst Case Time Complexity: O(n^2)
    int n = a.size();
    for(int i=0; i<n; ++i){
        for(int j=0; j<(n - 1); ++j){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}
 
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;

    cout << "Bubble Sort in Action" << endl;

    cout << "Before Sorting: ";
    for(auto i : a) cout << i << " ";
    cout << endl;

    auto s = chrono::high_resolution_clock::now();
    Bubble_Sort(a);
    auto e = chrono::high_resolution_clock::now();

    cout << "After Sorting: ";
    for(auto i : a) cout << i << " ";
    cout << endl;

    auto d = chrono::duration_cast<chrono::microseconds>(e - s);
    cout << "Time taken: " << d.count() << " microseconds." << endl;
}
 
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int t = 1;
    // cin >> t;
 
    while(t--) solve();
 
    return 0;
}