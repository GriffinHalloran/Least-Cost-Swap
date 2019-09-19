#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000
int n,x,a[MAX],b[MAX],t[10001];

int solve(){
    int ans=0;
    bool v[MAX];
    for(int i=0;i<n;i++){
        b[i]=a[i];  v[i]=false;
    }
    sort(b,b+n);
    for(int i=0;i<n;i++) t[b[i]]=i;
    for(int i=0;i<n;i++){
        if(v[i])    continue;
        int current=i;
        int s=0;
        int m=10000;
        int count=0;
        while(1){
            v[current]=true;
            count++;
            m=min(m,a[current]);
            s+=a[current];
            current=t[a[current]];
            if(v[current])  break;
        }
        ans+=min(s+(count-2)*m,s+m+(count+1)*x);
    }
    return ans;
}


int main(){
    cin>>n;
    x=10000;
    for(int i=0;i<n;i++){
        cin>>a[i];
        x=min(x,a[i]);
    }
    cout<<solve()<<endl;
    return 0;
}