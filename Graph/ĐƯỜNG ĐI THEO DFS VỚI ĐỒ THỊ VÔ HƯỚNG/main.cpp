#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <ios>
using namespace std;

vector < vector<int> > list(1005);
vector < int > req(1005);
bool B[1005] = {false};
int v,e,f,s;

void BFS(int u) {
    stack <int> st;
    st.push(u);
    B[u] = true;
    while(!st.empty()) {
    	int s = st.top(); st.pop();
		for (int i = 0; i < list[s].size(); i++) {
			if (!B[list[s][i]]) {
				req[list[s][i]] = s; 
				B[list[s][i]] = true;
				st.push(s);
				st.push(list[s][i]);
				break;
			} 
		}	
	}
}
void reB() {
	for (int i = 1; i <= v; i++) {
    	B[i] = false;    	
	}
}

void duongDi() {
	BFS(f);
	if (!B[s]) {
		cout << "-1";
		return;
	}
	vector <int> temp;
	temp.push_back(s);
	int check = req[s]; 
	while(f != check) {
		temp.push_back(check);
		check = req[check];
	}
	temp.push_back(f);
	for (int i = temp.size()-1; i>= 0; i--) {
		cout << temp[i] << " ";
	}
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> v >> e >> f >> s;
        
        for (int i = 1; i <= v; i++) {
			list[i].clear();
		}
        req.clear(); reB();
        
        for (int i = 1; i <= e; i++) {
            int d,c;
            cin >> d >> c;
            list[d].push_back(c);
            list[c].push_back(d);
        }
        duongDi();
        cout << endl;
 	
    }
    return 0;
}