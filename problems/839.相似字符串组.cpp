// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem839.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */

// @lc code=start
#include<vector>
#include<string>
#include<queue>
#include<functional>
using namespace std;
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> visited(n,0);
        queue<int> q;
        function<void(int)> bfs = [&](int idx){
            q.push(idx);
            visited[idx] = 1;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(int i = 0;i < n;i++){
                    if(i!=front && !visited[i] && isSimilar(strs[front],strs[i])){
                        q.push(i);
                        visited[i] = 1;
                    }  
                }
            }
        };
        int res = 0;
        for(int i = 0;i < n;i++){
            if(visited[i] == 0){
                bfs(i);
                res++;
            }
        }
        return res;
    }

private:
    bool isSimilar(string str1,string str2){
        int num = 0;
        if(str1 == str2) return true;
        if(str1.size() == str2.size()){
            for(int j = 0;j < str1.size();j++){
                if(str1[j]!=str2[j]){
                    num++;
                }
            }
        }
        return num == 2 ? true : false;
    }
};
// @lc code=end

//题目
/**
 * 
 * 如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。
 * 
 * 例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似。
 * 
 * 总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。
 * 
 * 给定一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个 字母异位词 。请问 strs 中有多少个相似字符串组？
 * 
 * 
 * 字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。
 * 
 * 示例 1：
 * 输入：strs = ["tars","rats","arts","star"]
 * 输出：2
 * 
 * 
 * 
 * 
 * 
 * 
*/