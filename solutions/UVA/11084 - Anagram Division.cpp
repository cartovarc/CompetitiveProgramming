#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;
string n;
long d, s;
long dp[1050][10005];
long dpfact[10];

long c(long b, long acu){
	int j = 0;
    for(long i=0; i<s; i++){
        long mask = 1 << i;
        if((mask&b)){
			j++;
        }
    }
    if(j==s){
        return acu%d==0;
    }
    
    if(dp[b][acu]!=-1){
    	return dp[b][acu];
    }
    
    long total = 0;
    for(long i=0; i<s; i++){
        long mask = 1 << i;
        if(!(mask&b)){
            long cb = b;
            cb = cb|mask;
            long aux = acu + (n[j]-'0')*pow(10, i);
            long nodo = c(cb, aux%d);
            total += nodo;
            if(j-1>=0){
            	dp[cb][aux%d] = nodo;	
            }
            
        }
    }
    dp[b][acu] = total;
    return total;
}

void initialize()
{
    long i;
    dpfact[0]=1;
    for(i=1;i<=11;i++)
    {
        dpfact[i]=dpfact[i-1]*i;
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    memset(dpfact, -1, sizeof(dpfact));
    initialize();
    long casos;
    cin >> casos;
    while(casos--){
        memset(dp, -1, sizeof(dp));
        cin >> n;
        cin >> d;
        s = n.length();
                
        long r[10];
        for(long i=0; i<10; i++){
            r[i] = 0;
        }
        
        for(long i=0; i<n.length(); i++){
            r[(n[i]-'0')]+=1;
        }
        long res = c(0, 0);
        
        for(long i=0; i<10; i++){
            if(r[i]>1){
                res/=dpfact[r[i]];
            }
        }
        
        cout << res << endl;

    }
    return 0;
}
