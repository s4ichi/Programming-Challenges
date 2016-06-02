#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cmath>

#define mp make_pair

using namespace std;

typedef pair<double, double> pdd;

struct UF {
	vector<int> p;
	UF(){} UF(int n):p(n,-1){}

	int find(int x){return p[x]<0 ? x : p[x]=find(p[x]);}
	int same(int a, int b){return find(a)==find(b);}
	int size(int x){return p.size();}

	void unit(int x,int y)
	{
		x=find(x);y=find(y);
		if(x==y)return;
		if(p[x]<p[y])swap(x,y);
		p[y]+=p[x];
		p[x]=y;
	}
};

double dist(pdd a, pdd b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) +
				(a.second - b.second) * (a.second - b.second));

}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n; cin >> n;
		vector<pdd> v(n);

		for (int i=0; i<n; i++) {
			cin >> v[i].first >> v[i].second;
		}

		vector<pair<double, pair<int, int> > > edge;

		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (i == j) continue;
				edge.push_back(mp(dist(v[i], v[j]), mp(i, j)));
			}
		}

		sort(edge.begin(), edge.end());

		UF uf(n);

		double ans = 0;
		for (int i=0; i<edge.size(); i++) {
			int a = edge[i].second.first, b = edge[i].second.second;
			double dist = edge[i].first;

			if (!uf.same(a, b)) {
				ans += dist;
				uf.unit(a, b);
			}
		}

		printf("%.2lf\n", ans);
		if (t > 0) cout << endl;
	}

	return 0;
}
