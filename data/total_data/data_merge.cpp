#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;

vector<pair<string,int>> v;
vector<pair<string,int>> arr;

bool cmp(pair<string, int> a, pair<string, int> b){
	return a.second > b.second;
}

int main(){
	fstream fin;
	fstream result;

	fin.open("origin_data.txt");
	result.open("merge_data.txt");
	string tmp;
	int cnt;
	
	while(!fin.eof()) {
		fin >> tmp >> cnt;
		v.push_back({tmp, cnt});
	}
	
	sort(v.begin(), v.end());
	int len = v.size();
	
	arr.push_back({v[0].first, v[0].second});
	for(int i=1;i<len;i++){
		if(arr.back().first == v[i].first){
			arr.back().second += v[i].second;
		}
		else{
			arr.push_back(v[i]);
		}
	}
	
	sort(arr.begin(), arr.end(), cmp);
	
	len = arr.size();
	for(int i=0;i<len;i++) result << arr[i].first << " " << arr[i].second << "\n";
}
