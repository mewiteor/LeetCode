/*
 * Copyright (C) 2016  Mewiteor <mewiteor@hotmail.com>
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/*
 * Given an array of integers and an integer k, find out whether there
 * are two distinct indices i and j in the array such that nums[i] =
 * nums[j] and the difference between i and j is at most k.
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()<2)
            return false;
        map<int,int> mp;
        for(int i=nums.size();i>0;--i) {
            auto ret = mp.insert(make_pair(nums[i-1],i));
            if(!ret.second)
                if(ret.first->second-i<=k)
                    return true;
                else
                    ret.first->second=i;
        }
        return false;
    }
};
