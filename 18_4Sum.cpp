#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    unordered_map<int, vector<pair<int,int>> > umap_source;
    sort(nums.begin(), nums.end());
    vector<vector<int> > result;
    
    int size = nums.size();
    if(size<4) return result;
    //initialization
    for(int i = 0; i<size; i++)
    {
        for(int j = i+1; j<size;j++){
            umap_source[nums[i]+nums[j]].push_back(make_pair(i,j)); 
        }
    }
    for(int i = 0; i<size; i++)
    {
        for(int j = i+1; j<size;j++)
        {
            int current = nums[i]+nums[j];
            if(umap_source.find(target - current)!=umap_source.end())
            {
                vector<pair<int,int> > ll = umap_source[target - current];
                auto it = ll.begin();
                for(;it!=ll.end(); it++)
                {
                    if(it->first <= j) continue;
                    result.push_back({nums[i], nums[j], nums[it->first], nums[it->second]});
                }
            }
        }
    }
    for(auto it = result.begin(); it!=result.end(); it++)
        {
            for(auto iiit = (*it).begin(); iiit!=(*it).end(); iiit++)
            {
                cout<<*iiit<<",";
            }
            cout<<endl;
        }
            cout<<"\n"<<"------------------------before sorting---------------------"<<endl;
    sort(result.begin(), result.end());
for(auto it = result.begin(); it!=result.end(); it++)
        {
            for(auto iiit = (*it).begin(); iiit!=(*it).end(); iiit++)
            {
                cout<<*iiit<<",";
            }
            cout<<endl;
        }
            cout<<"----------------------after soring---------------------------------"<<endl;
        auto aa = unique(result.begin(), result.end());
        for(auto it = result.begin(); it!=result.end(); it++)
        {
            for(auto iiit = (*it).begin(); iiit!=(*it).end(); iiit++)
            {
                cout<<*iiit<<",";
            }
            cout<<endl;
        }
            cout<<"----------------------after unique---------------------------------"<<endl;
    result.erase(aa, result.end());
    return result;
}

int main()
{
    //vector<int> a={-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
    vector<int> a = {-5,-5,-3,1};
    vector<int> b = {-5,-4,-4,11};
    vector<vector<int>> cc = {a,b};
    sort(cc.begin(), cc.end());
    cout<<cc[0][3]<<endl;
    //fourSum(a,0);
}