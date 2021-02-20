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
	fstream result;
	
	string name;
	cout << "파일 이름을 입력해 주세요.(.txt 제외) : " ;
	cin >> name;
	
	fin.open(name+".txt");
	
	if(!fin){
		cout << "해당 파일이 없습니다.\n";
		return 0; 
	}
	result.open(name+"_result.txt");
	
	cout << "조금만 기다려 주세요\n";
	string tmp;
	while(!fin.eof() && fin >> tmp){
		if(check(tmp)) {
			vector<string> s = split(tmp);
			low(s);
			push_data(s);
		}
	}
	vector<pair<string,int>> rv;
	
	sort(v.begin(), v.end());
	
	int len = v.size();
	rv.push_back({v[0], 1});
	for(int i=1;i<len;i++){
		if(v[i] == v[i-1]){
			rv.back().second++;
		}
		else{
			rv.push_back({v[i], 1});
		}
	}
	
	len = rv.size();
	for(int i=0;i<len;i++){
		result << rv[i].first << " " << rv[i].second << endl;
	}
	
	fin.close();
	result.close();
	
	cout << "완료되었습니다.\n";
}
