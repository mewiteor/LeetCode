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
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice
 * in the array, and it should return false if every element is distinct.
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<=1)return false;
        set<int> st;
        for(const auto x:nums)
            if(!st.insert(x).second)
                return true;
        return false;
    }
};
