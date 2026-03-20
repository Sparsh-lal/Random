#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
Assumptions:
1. every element in the array to be sorted is between 0 and some integer 'c'
2. c = O(n), i.e. c <= *max_element(a.begin(), a.end())
*/

void Counting_Sort(vector<int>& a){
    // Worst Case Time Complexity: O(n) given the assumptions hold

    int c = *max_element(a.begin(), a.end());
    vector<int> freq(++c);
    for(auto i : a) freq[i]++;

    a.clear();
    for(int i=1; i<c; ++i) while(freq[i]--) a.push_back(i);
}
 
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto& i : a) cin >> i;

    cout << "Counting Sort in Action" << endl;

    cout << "Before Sorting: ";
    for(auto i : a) cout << i << " ";
    cout << endl;

    auto s = chrono::high_resolution_clock::now();
    Counting_Sort(a);
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