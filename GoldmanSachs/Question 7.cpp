//Find the kid which gets tha damaged toy (Distributing M items in a circle of size N starting from K-th position)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    if(m <= n-k+1)
    cout << m+k-1;
    m -= (n - k + 1);
    if(m%n==0){
        cout <<n;
    }else
    cout << m%n;
    
}
