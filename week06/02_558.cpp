#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int, pair<int, int> > edge;

int main(){
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> d(n, 0);
		vector<edge> e(m);

		for (int i=0; i<m; i++) {
			cin >> e[i].second.first >> e[i].second.second >> e[i].first;
		}

		bool f;
		for(int i=0; i<n; i++){
			f = false;
			for(int j=0; j<m; j++){
				int from = e[j].second.first,
					to = e[j].second.second,
					cost = e[j].first,
					new_dist = d[from] + cost;

				if(new_dist < d[to]){
					d[to] = new_dist;
					f = true;
				}
			}
			if (!f) {
				cout << "not possible" << endl;
				break;
			}
		}

		if (f) cout << "possible" << endl;
	}

	return 0;
}
