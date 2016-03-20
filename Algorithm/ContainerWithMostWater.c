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
 * Given n non-negative integers a1, a2, ..., an, where each represents
 * a point at coordinate (i, ai). n vertical lines are drawn such that
 * the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
 * which together with x-axis forms a container, such that the container
 * contains the most water.
 *
 * Note: You may not slant the container.
 */

int maxArea(int* height, int heightSize) {
    int max=0,min;
	while(heightSize>1) {
		min=height[0]<height[heightSize-1]?height[0]:height[heightSize-1];
		if(max<min*(heightSize-1))max=min*(heightSize-1);
		if(height[0]<height[heightSize-1])++height;
		--heightSize;
	}
	return max;

}
