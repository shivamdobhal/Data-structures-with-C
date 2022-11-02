unordered
key value pair
time complexity-0(1)
as a form of table

example-1]intersection of two arrays
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
  solution======================================================================
 vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> map;
            vector<int> ans;
            
            for(int i =0;i<nums1.size();i++)
            {
                 map[nums1[i]]++;        //  insert in form of table //count increases
            }
            
            for(int i=0;i<nums2.size();i++)
            {
                    if(map.find(nums2[i])!=map.end() && map[nums2[i]]!=0) //searching
                    {
                            map[nums2[i]]--;           //count decreases
                            ans.push_back(nums2[i]);
                    }
            }
            return ans;
    }
