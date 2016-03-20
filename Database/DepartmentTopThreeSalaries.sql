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
 * The Employee table holds all employees. Every employee has an Id,
 * and there is also a column for the department Id.
 * 
 * +----+-------+--------+--------------+
 * | Id | Name  | Salary | DepartmentId |
 * +----+-------+--------+--------------+
 * | 1  | Joe   | 70000  | 1            |
 * | 2  | Henry | 80000  | 2            |
 * | 3  | Sam   | 60000  | 2            |
 * | 4  | Max   | 90000  | 1            |
 * | 5  | Janet | 69000  | 1            |
 * | 6  | Randy | 85000  | 1            |
 * +----+-------+--------+--------------+
 * The Department table holds all departments of the company.
 * 
 * +----+----------+
 * | Id | Name     |
 * +----+----------+
 * | 1  | IT       |
 * | 2  | Sales    |
 * +----+----------+
 * Write a SQL query to find employees who earn the top three salaries
 * in each of the department. For the above tables, your SQL query
 * should return the following rows.
 * 
 * +------------+----------+--------+
 * | Department | Employee | Salary |
 * +------------+----------+--------+
 * | IT         | Max      | 90000  |
 * | IT         | Randy    | 85000  |
 * | IT         | Joe      | 70000  |
 * | Sales      | Henry    | 80000  |
 * | Sales      | Sam      | 60000  |
 * +------------+----------+--------+
 */

-- Write your MySQL query statement below
select a.Name Department,b.Name Employee,b.Salary Salary from Department a inner join Employee b on a.Id=b.DepartmentId and (select count(distinct c.Salary) from Employee c where c.DepartmentId=a.Id and c.Salary>b.Salary) < 3 order by a.Id,b.Salary desc;
