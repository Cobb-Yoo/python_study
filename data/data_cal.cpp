#include <bits/stdc++.h>
#include <fstream>
#include <vector>

using namespace std;
vector<string> v;

bool check(string s){
	if(('a' <= s[0] && s[0] <= 'z') || ('A' <= s[0] && s[0] <= 'Z')) return 1;
	return 0; 
}

vector<string> split(string aa){
	int len = aa.size();
	
	vector<string> tmp;
	string s="";
	for(int i=0;i<len;i++){
		if(('a' <= aa[i] && aa[i] <= 'z') || ('A' <= aa[i] && aa[i] <= 'Z')) s += aa[i];
		else{
			tmp.push_back(s);
			s = "";
		}
	}
	
	if(s != "") tmp.push_back(s);
	
	return tmp;
}

void low(vector<string> &s){
	int len = s.size();
	
	for(int i=0;i<len;i++){
		for(int j=0;j<s[i][j];j++){
			if(s[i][j] <= 'Z') s[i][j] = s[i][j]-'A'+'a';
		}
	}
}

void push_data(vector<string> s){
	for(int i=0;i<s.size();i++) v.push_back(s[i]);
}

int main(){
	fstream fin;
	
	fin.open("real_mo_data.txt");
	string tmp;
	int cnt = 0;
	while(!fin.eof() && fin >> tmp){
		if(check(tmp)) {
			vector<string> s = split(tmp);
			low(s);
			push_data(s);
		}
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()),v.end());

	for(int i=0;i<v.size();i++){
		if(v[i].size() <= 2) v.erase(v.begin()+i);
	}
	
	for(int i=0;i<v.size();i++){
		cout << v[i] << endl;
	}
}
