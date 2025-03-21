SQL view queries 


### 1. Employee Department Summary

Write a SQL View to display empno, ename, job, sal, department name, the average salary in their department, and the number of employees in their department.


```
SELECT * FROM employee_dept_summary;
+-------+--------+----------+---------+------------+-----------------+---------------------+
| empno | ename  | job      | sal     | dname      | dept_avg_salary | dept_employee_count |
+-------+--------+----------+---------+------------+-----------------+---------------------+
```
  ---


### 2. Employee Grade Distribution

Write a SQL View to display empno, ename, job, sal, grade, and the total number of employees in each grade.


```
 SELECT * FROM employee_grade_distribution;
  
+-------+--------+----------+---------+-------+--------------------+
| empno | ename  | job      | sal     | grade | employees_in_grade |
+-------+--------+----------+---------+-------+--------------------+
 
```

---

### 3. Employee Manager Overview

Write a SQL View to display empno, ename, job, sal, manager’s name, department name, and the total salary of their department.

```
SELECT * FROM employee_manager_overview;

+-------+--------+----------+---------+--------------+------------+-------------------+
| empno | ename  | job      | sal     | manager_name | dname      | dept_total_salary |
+-------+--------+----------+---------+--------------+------------+-------------------+
```
