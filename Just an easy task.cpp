#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define FOR(i,a,n) for(int i =a; i < n; i++)
#define FORd(i,a) for (int i = (a)-1; i >= 0; i--)
#define pb push_back
#define fi first
#define se second
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int unsigned lli;
typedef long long int llim;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

vector<int> primes;
vector<bool> isPrime;
vector<int> primeFactors;
vector<int> lowestPrime;

void factorizar(int n){
	while(n>1){
		int p = lowestPrime[n];
		while(n%p==0){
			primeFactors.pb(p);
			n/=p;
		}
	}
}

void lowestPrimeSieve(int n){
	lowestPrime.resize(n + 1, 1);
	lowestPrime[0] = lowestPrime[1] = 0;
	for(int i = 2; i <= n; ++i) lowestPrime[i] = (i & 1 ? i : 2);
	int limit = sqrt(n);
	for(int i = 3; i <= limit; i += 2)
		if(lowestPrime[i] == i)
			for(int j = i * i; j <= n; j += 2 * i)
				if(lowestPrime[j] == j) lowestPrime[j] = i;
}


void primesSieve(int n){
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	primes.push_back(2);
	for(int i = 4; i <= n; i += 2) isPrime[i] = false;
	int limit = sqrt(n);
	for(int i = 3; i <= n; i += 2){
		if(isPrime[i]){
			primes.push_back(i);
			if(i <= limit)
				for(int j = i * i; j <= n; j += 2 * i)
					isPrime[j] = false;
		}
	}
}

int main(){__
	int n;
	cin>>n;
	if(n==1){
		cout<<1<<"\n";
		exit(0);
	}
	primesSieve(n);
	lowestPrimeSieve(n);
	factorizar(n);
	vi v(n, 1);
	int ant = 1, pfs, tam = primeFactors[0];
	forn(i, primeFactors.size()){
		pfs = primeFactors[i];
		vector<int> cop(v);
		if(pfs==ant){
			v[0] = pfs*(v[0]+pfs-1);
			int mul;
			forn(j, pfs){
				mul=j==0?2*pfs-1:pfs-1;
				forn(l, tam){
					v[j+l*pfs] = cop[(l*pfs+j)%tam]*mul;
				}
			}
		} else{
			int mul;
			forn(j, pfs){
				mul=j==0?2*pfs-1:pfs-1;
				forn(l, tam){
					v[j+l*pfs] = cop[(l*pfs+j)%tam]*mul;
				}
			}
		}
		tam=i==0?tam:tam*pfs;
		ant=pfs;
	}

	forn(i, tam)
		cout<<v[i]<<" ";
	cout<<"\n";
	return 0;
}

int main(){__
	int n;
	cin>>n;
	llim s;
	c[0]+=2*n-1;
	for(llim i=1; i<n; i++)
		for(llim j=1; j<=i; j++){
			s = ((i%n)*(j%n))%n;
			if(i==j)	
				c[s]++;
			else
				c[s]+=2;
		}
	forn(i, n)
		cout<<c[i]<<" ";
	cout<<"\n";

}
