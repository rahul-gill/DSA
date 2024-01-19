#include<bits/stdc++.h>
using namespace std;
int main(){
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);
	set<int> sss;
	for(int i=1;i<=20;i++) {
		sss.insert(i);
		sss.insert(i*2);
		sss.insert(i*3);
	}
	sss.insert(50);
	vector<int> ss;
	ss.push_back(0);
	for(auto x:sss) ss.push_back(x);
	int s;
	while(cin>>s,s>0){
		set<set<int>> themain;
		for(int i=0;i<ss.size() && ss[i]<=s;i++)
			for(int j=0;j<ss.size() && ss[j]<=s-ss[i];j++)
				for(int k=0;k<ss.size() && ss[k]<=s-ss[i]-ss[j];k++)
					if(ss[i]+ss[j]+ss[k] == s) 
						{	set<int> temp;
							temp.insert(i);temp.insert(j);temp.insert(k);
							themain.insert(temp);
						}

		int perms = 0,combs=themain.size();
		for(auto x:themain){
			if(x.size() == 1) perms++;
			else if(x.size() == 2) perms+=3;
			else if(x.size() == 3) perms+=6;
		}
		if(perms == 0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",s);
		else printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",s,combs,s,perms);
		for(int i=0;i<70;i++) cout<<'*';cout<<'\n';

	}
	printf("END OF OUTPUT\n");

} 

