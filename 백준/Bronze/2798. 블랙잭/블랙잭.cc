#include <iostream>
using namespace std;

int main(){
    int n, m, hap=0;
    int a[101];
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i]; 
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(a[i]+a[j]+a[k] <= m && a[i]+a[j]+a[k] > hap)
                  hap = a[i]+a[j]+a[k];
            }
        }
    }
    cout << hap << '\n';
    return 0;
}