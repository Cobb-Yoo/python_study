#include <bits/stdc++.h>
#include <fstream>
using namespace std;

vector<pair<string,int>> v;

bool cmp(pair<string,int> a, pair<string,int> b){
	if(a.second == b.second) return a.first.size() < b.first.size();
	return a.second > b.second;
}

int main(){
	fstream fin, result;
	
	fin.open("data.txt");
	result.open("mergedData.txt");
	
	string tmp;
	int cnt;
	while(!fin.eof()) {
		fin >> tmp >> cnt;
		v.push_back({tmp, cnt});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto i : v){
		result << i.first << " " << i.second << endl;
	}
	
	fin.close();
	result.close();
}
