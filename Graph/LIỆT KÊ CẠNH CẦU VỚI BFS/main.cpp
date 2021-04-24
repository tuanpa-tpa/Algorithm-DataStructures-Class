#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector < vector<int> > list(1005);
vector < pair<int, int> > res;
bool B[1005] = {false};
int v,e;

int BFS(int u) {
    queue <int> q;
    q.push(u);
    B[u] = true;
    int count = 0;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        count++;
        for (int i = 0; i< list[v].size(); i++) {
            if (!B[list[v][i]]) {
                q.push(list[v][i]);
                B[list[v][i]] = true;
            }
        }
    }    
    return count;
}

int demTPLT() {
	int tplt = 0;
	for (int i = 1; i <= v; i++) {
            if (!B[i]) {
                tplt++;
                BFS(i);
            }
    }
    return tplt;
}

void canhCau(int tmp,int c, vector < pair<int, int> > store) { // tmp la thanh phan lien thong ban dau
	for (int i = 0; i < store.size() ; i++) {
		if (i != c) {
			list[store[i].first].push_back(store[i].second);
			list[store[i].second].push_back(store[i].first);
		}
	}
	int dem = demTPLT();
	if (dem > tmp) {
		if (store[c].first < store[c].second) {
            pair <int, int> temp;
            temp.first = store[c].first;
            temp.second = store[c].second;
			res.push_back(temp);
		} else {
            pair <int, int> temp;
            temp.first = store[c].second;
            temp.second = store[c].first;
			res.push_back(temp);
		}
	}
}

void reB() {
	for (int i = 1; i <= v; i++) {
		list[i].clear();
	}
	for (int i = 1; i <= v; i++) {
    	B[i] = false;    	
	}
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> v >> e;
        res.clear();
        reB();
        vector < pair<int, int> > store; // luu canh
        for (int i = 1; i <= e; i++) {
            int d,c;
            cin >> d >> c;
            pair<int,int> temp;
            temp.first = d;
            temp.second = c;
            store.push_back(temp);
            list[d].push_back(c);
            list[c].push_back(d);
        }
 		int lt = demTPLT(); // thanh phan lien thong ban dau
 		
 		for (int i = 0; i < store.size(); i++) {
 			reB();
 			canhCau(lt,i,store);
		}
		sort(res.begin(),res.end());
		for (int i = 0; i < res.size(); i++) {
			cout << res[i].first << " " << res[i].second << " "; 
		}
		cout<< endl;
    }
    return 0;
}