#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){
    vector<string> words = {"bella", "umbrella", "Izabella"};
    map<char,int> fmap;
        string str1 = words[0];
        vector<string> ans;

        for(int i=0; i<str1.length(); i++){
            fmap[str1[i]] += 1;
        }

        for(int i=0; i<words.size(); i++){
            map<char,int> tmap;
            string str = words[i];

            for(int j=0; j<str.length(); j++){
                tmap[str[j]] += 1;
            }
            for(auto i:fmap){
                if(i.second != tmap[i.first]){
                    fmap[i.first] = min(tmap[i.first], fmap[i.first]);
                }
            }
        }

        for(auto i:fmap){
            int a = i.second;
            
            if(a > 0){
                for(int j=0; j<a; j++){
                    string s(1, i.first);
                    ans.push_back(s);
                }
            }
        }

        for(int x=0; x<ans.size(); x++){
            cout<<ans[x]<<" ";
        }
}