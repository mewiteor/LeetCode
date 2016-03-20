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
 * There are n bulbs that are initially off. You first turn on all
 * the bulbs. Then, you turn off every second bulb. On the third round,
 * you toggle every third bulb (turning on if it's off or turning off
 * if it's on). For the ith round, you toggle every i bulb. For the
 * nth round, you only toggle the last bulb. Find how many bulbs are
 * on after n rounds.
 *
 * Example:
 *
 * Given n = 3. 
 *
 * At first, the three bulbs are [off, off, off].
 * After first round, the three bulbs are [on, on, on].
 * After second round, the three bulbs are [on, off, on].
 * After third round, the three bulbs are [on, off, off]. 
 *
 * So you should return 1, because there is only one bulb is on.
 */

int bulbSwitch(int n) {
    return (int)sqrt(n);
}
