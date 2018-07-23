#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    if (nums.size() == 1) return 0;

    else if (nums.size() >= 2)
    {
        if (target < nums[0]) return 0;
        if (target > nums[nums.size()-1]) return nums.size();

        int begin = 0;
        int end = nums.size()-1;
        while (end > begin)
        {
            int center = int((end + begin)/2);
            if (nums[center] == target)
            {
                return center;
            }
            else if (nums[center] < target)
                begin = center + 1;
            else
                end = center - 1;
        }
        if (begin >= end)
            return begin;
    }
}


int main()
{
    vector <int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    int target = 2;
    int res = searchInsert(nums, target);
    cout << res << endl;
    return 0;
}
