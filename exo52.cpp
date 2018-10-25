#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#include "texte.h"

bool isGreater( pair <string,int> a, pair <string, int> b){
	return (a.second > b.second);
}

int main(){
	string texte;
	texte = getText();

	map<string,int> dico;

	
	while (texte.size() > 4){

		if (texte.at(0) == ' ' ){
			texte.erase(0,1);
		}
		else{
			
			vector <unsigned int> v;
			v.push_back(texte.find(' '));
			v.push_back(texte.find(','));
			v.push_back(texte.find('.'));
			v.push_back(texte.find('\n'));
			v.push_back(texte.find('\''));
			v.push_back(texte.find('('));
			v.push_back(texte.find(')'));
			int found = *min_element(v.begin(),v.end());
			cout <<found <<" "; //<<"---->"<<texte<<endl;
			string word = texte.substr(0,found);
			//cout <<endl<<word <<"-" <<endl;
			if (found < 0)
				break;
			dico[word] ++;

			texte.erase(0,found+1);
			
		}
	

	}

// Test	
	vector < pair < string,int > > results;
	for (auto x : dico)
		results.push_back(x);
	sort(results.begin(),results.end(), isGreater);
	for (auto x:results){
		if (x.first.size() > 4)
			cout<<x.first<<" ---> "<<x.second<<endl;
	}
	/*
	
	vector <string> d;
	vector <int> e;
	for (auto it = dico.begin(); it != dico.end(); it ++){
		d.push_back(it->first);	
	}
	for (auto it = dico.begin(); it != dico.end(); it ++){
		e.push_back(it->second);	
	}
	
	//sort(d.begin(), d.end());
	for (int i =0; i<5; i++){
		max_element(

	}
	
			for (auto x : dico){
				cout << x.first  << ": " << x.second << '\n';
			}
*/	
}
