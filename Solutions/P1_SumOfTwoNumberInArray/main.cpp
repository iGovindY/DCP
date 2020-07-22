#include <iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

bool check(int arr[], int size, int k)
{
    unordered_set<int> s;
    for(int i =0; i < size ; i++)
    {
        auto a = s.find(k-arr[i]);
        if(a != s.end())
        {
            return true;
        }
        else
        {
            s.insert(arr[i]);
        }
    }
    return false;
}
vector<int> twoSum(int nums[], int size, int target)
{
    vector<int> result;
    unordered_map<int,int> s;
    for(int i =0; i < size ; i++)
    {
        auto a = s.find(target - nums[i]);
        if(a != s.end())
        {
            result.push_back(a->second);
            result.push_back(i);
            break;
        }
        else
        {
            s.insert(make_pair(nums[i],i));
        }
    }
    return result;
}
int main()
{
    /** input */
    int arr[]   = {8, 10, 15, 2, 11, 7};
    int size    = sizeof(arr)/sizeof(int);
    int k       = 10;
    cout << "Searching: " << k << ", arr size: "<< size << endl;

    cout << (check(arr, size, k) ? "Found" : "Not Found") << endl;
    vector<int> res = twoSum(arr, size, k);
        cout<< "[";
    for(int n : res)
    {
        cout<< n <<",";
    }
        cout<< "]";

}
