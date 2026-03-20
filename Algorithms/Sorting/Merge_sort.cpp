#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> Merge_Sort(vector<int> a){
    // Worst Case Time Complexity: O(nlogn)

    int n = a.size();

    if(n == 1) return a;

    int k = n / 2;

    vector<int> b, c, res;
    for(int i=0; i<n; ++i) i < k ? b.push_back(a[i]) : c.push_back(a[i]);

    b = Merge_Sort(b);
    c = Merge_Sort(c);

    int i = 0, j = 0;
    while(i < b.size() && j < c.size()) b[i] < c[j] ? res.push_back(b[i++]) : res.push_back(c[j++]);
    while(i < b.size()) res.push_back(b[i++]);
    while(j < c.size()) res.push_back(c[j++]);

    return res;
}
 
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;

    cout << "Merge Sort in Action" << endl;

    cout << "Before Sorting: ";
    for(auto i : a) cout << i << " ";
    cout << endl;

    auto s = chrono::high_resolution_clock::now();
    a = Merge_Sort(a);
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