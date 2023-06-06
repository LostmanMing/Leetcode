/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int ,int> map;   //有序map
        vector<int> res;
        for(auto & a : arr1)    map[a]++;     //将arr1中的元素及其出现次数记录在有序map中
        for(auto & a : arr2){
            while(map[a]--)     res.push_back(a);    //按照arr2中的出现顺序将对应元素按照map中记录的个数放入数组
            map.erase(a);   //放入后将此元素从map中删除，因为后续需要遍历map中剩下的元素将其放入
        } 
        for(auto & n : map){
            while(n.second--)   res.push_back(n.first);  //由于map有序，此时按顺序放入即为按大小排列
        }
        return res;
    }
};
// @lc code=end

//题目

/**
 * 
 * 给定两个数组，arr1 和 arr2，
 * arr2 中的元素各不相同
 * arr2 中的每个元素都出现在 arr1 中
 * 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
 * 示例：
 * 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * 输出：[2,2,2,1,4,3,3,9,6,7,19]
 * 
 * 
 * 
 */