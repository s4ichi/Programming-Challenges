#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cmath>

#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

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

double dist(pii a, pii b)
{
	double a1 = (double)a.first, a2 = (double)a.second;
	double b1 = (double)b.first, b2 = (double)b.second;

	return sqrt((a1 - b1) * (a1 - b1) +
				(a2 - b2) * (a2 - b2));
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int s, p;
		cin >> s >> p;

		vector<pii> v(p+1);
		for (int i=0; i<p; i++) {
			cin >> v[i].first >> v[i].second;
		}

		vector<pair<double, pair<int, int> > > edge;

		for (int i=0; i<p; i++) {
			for (int j=i+1; j<p; j++) {
				edge.push_back(mp(dist(v[i], v[j]), mp(i, j)));
			}
		}

		sort(edge.begin(), edge.end());

		UF uf(p);


		vector<double> ans;
		for (int i=0; i<edge.size(); i++) {
			int a = edge[i].second.first, b = edge[i].second.second;
			double dist = edge[i].first;

			if (!uf.same(a, b)) {
				ans.push_back(dist);
				uf.unit(a, b);
			}
		}

		printf("%.2lf\n", ans[p-s-1]);
	}

	return 0;
}
