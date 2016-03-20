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
 * Given a Weather table, write a SQL query to find all dates' Ids
 * with higher temperature compared to its previous (yesterday's) dates.
 * 
 * +---------+------------+------------------+
 * | Id(INT) | Date(DATE) | Temperature(INT) |
 * +---------+------------+------------------+
 * |       1 | 2015-01-01 |               10 |
 * |       2 | 2015-01-02 |               25 |
 * |       3 | 2015-01-03 |               20 |
 * |       4 | 2015-01-04 |               30 |
 * +---------+------------+------------------+
 * For example, return the following Ids for the above Weather table:
 * +----+
 * | Id |
 * +----+
 * |  2 |
 * |  4 |
 * +----+
 */

-- Write your MySQL query statement below
select a.Id Id from Weather a inner join Weather b on datediff(a.Date,b.Date)=1 where a.Temperature>b.Temperature;
