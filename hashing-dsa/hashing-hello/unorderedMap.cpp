#include <bits/stdc++.h>
 using namespace std;
#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string ,int>umap;
    umap["prince"]=44;
    umap["gfg"]=56;
    umap["hello world"]=90;

    // for(auto x:umap){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    for(auto itr=umap.begin();itr!=umap.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    string key="prince";
    if(umap.find(key)!=umap.end()){
        cout<<"key found"<<endl;

    }else{
        cout<<"key not found"<<endl;
    }

    if(umap.find(key)!=umap.end()){
        auto temp =umap.find(key);
        cout<<"key is : "<<temp->first<<endl;
        cout<<"value is "<<temp->second<<endl;
    }

    umap.insert({"mobile",17000});
       for(auto itr=umap.begin();itr!=umap.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }

    cout<<umap.size()<<endl;

    int arr[]={1,1,2,3,5,6,0,0,0,7,3,3,9,9};
    unordered_map<int ,int>umaped;
    for(int i=0;i<15;i++){
        int key=arr[i];
        umaped[key++];
    }

    for(auto itr=umaped.begin(); itr!=umaped.end();itr++){
        cout<<itr->first <<" "<<itr->second<<endl;
    }
}
