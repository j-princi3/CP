
---

## 1. Find employees who earn more than the average salary of all employees.

**Expected Output Columns:**

```
+-------+---------+
| ename | sal     |
+-------+---------+
```

```sql
USE test;

select ename,sal from emp where sal>(select avg(sal) from emp);
```

---

## 2. Find the name and salary of the highest-paid employee.

**Expected Output Columns:**

```
+-------+---------+
| ename | sal     |
+-------+---------+
```

```sql
USE test;

select ename,sal from emp where sal=(select max(sal) from emp);
```

---

## 3. Find employees who earn more than the highest-paid employee in department 10.

**Expected Output Columns:**

```
+-------+---------+--------+
| ename | sal     | deptno |
+-------+---------+--------+
```

```sql
USE test;

select ename,sal,deptno from emp where sal>(select max(sal) from emp where deptno=10);
```

---

## 4. Find employees whose salary is higher than the salary of ‘SCOTT’.

**Expected Output Columns:**

```
+-------+---------+
| ename | sal     |
+-------+---------+
```

```sql
USE test;

select ename,sal from emp where sal>(select sal from emp where ename='SCOTT');
```

---

## 5. Find employee who have the same job title as 'FORD'.

**Expected Output Columns:**

```
+-------+---------+
| ename | job     |
+-------+---------+
```

```sql
USE test;

select ename,job from emp where job in (select job from emp where ename='FORD');
```

---

## 6. Find departments that have at least one employee earning more than 3000.

**Expected Output Columns:**

```
+--------+------------+
| deptno | dname      |
+--------+------------+
```

```sql
USE test;

select deptno,dname from dept where deptno = (select deptno from emp where sal>3000);
```

---

## 7. Find employees who were hired before all employees in department 30.

**Expected Output Columns:**

```
+-------+------------+
| ename | hiredate   |
+-------+------------+
```

```sql
USE test;

select ename,hiredate from emp where hiredate<all(select hiredate from emp where deptno=30);
```

---

## 8. Find employees who belong to departments located in 'Dallas'.

**Expected Output Columns:**

```
+-------+--------+
| ename | deptno |
+-------+--------+
```

```sql
USE test;
select ename,deptno from emp where deptno = any(select deptno from dept where location ="Dallas");
```

---

## 9. Find the second highest salary from employees.

**Expected Output Columns:**

```
+-----------------------+
| second_highest_salary |
+-----------------------+
```

```sql
USE test;
SELECT MAX(sal) AS second_highest_salary
FROM emp
WHERE sal < (SELECT MAX(sal) FROM emp);
```

---

## 10. Find employees who have the same manager as ‘BLAKE’.

**Expected Output Columns:**

```
+-------+------+
| ename | mgr  |
+-------+------+
```

```sql
USE test;
select ename,mgr from emp where mgr =(select mgr from emp where ename='BLAKE') and ename!= 'BLAKE';
```

---

## 11. Find employees who belong to a department with no employees.

**Expected Output Columns:**

```
+---------+
| dname   |
+---------+
```

```sql
USE test;
select dname from dept where deptno not in (select deptno from emp);
```

---

## 12. Find the department that has the most employees.

**Expected Output Columns:**

```
+--------+----------------+
| deptno | employee_count |
+--------+----------------+
```

```sql
USE test;
SELECT deptno, COUNT(*) AS employee_count
FROM emp
GROUP BY deptno
HAVING COUNT(*) = 
(SELECT MAX(emp_count)
FROM (SELECT deptno, COUNT(*) AS emp_count
FROM emp
GROUP BY deptno) AS dept_counts);
```

---

## 13. Find the department name where ‘JONES’ works.

**Expected Output Columns:**

```
+----------+
| dname    |
+----------+
```

```sql
USE test;
select dname from dept where deptno = (select deptno from emp where ename='JONES');
```

---

## 14. Write a SQL query to find employees whose name contains ‘A’.

**Expected Output Columns:**

```
+--------+-------+
| ename  | empno |
+--------+-------+
```

```sql
USE test;
select ename,empno from emp where ename like '%A%';
```

---

## 15. Retrieve employees who have a commission greater than their salary.

**Expected Output Columns:**

```
+--------+-------+---------+---------+
| ename  | empno | sal     | comm    |
+--------+-------+---------+---------+
```

```sql
USE test;
select ename,empno,sal,comm from emp where comm>sal;
```

---

## 16. Write a SQL query to find all employees who do not receive a commission.

**Expected Output Columns:**

```
+-------+-------+------+
| ename | empno | comm |
+-------+-------+------+
```

```sql
USE test;
select ename,empno,comm from emp where comm =0 or comm is null;
```

---

## 17. Write a SQL query to count the number of employees who have a manager.

**Expected Output Columns:**

```
+------------------------+
| employees_with_manager |
+------------------------+
```

```sql
USE test;
select count(empno) as  employees_with_manager from emp where mgr is not null;
```

---

## 18. Write a SQL query to find the difference between the highest and second highest salary.

**Expected Output Columns:**

```
+-------------------+
| salary_difference |
+-------------------+
```

```sql
USE test;
SELECT 
    (SELECT MAX(sal) FROM emp) - 
    (SELECT MAX(sal) FROM emp WHERE sal < (SELECT MAX(sal) FROM emp)) 
    AS salary_difference;
```

---

## 19. Write a SQL query to calculate the total salary and total commission for all employees.

**Expected Output Columns:**

```
+--------------+------------------+
| Total Salary | Total Commission |
+--------------+------------------+
```

```sql
USE test;

select sum(sal) as "Total Salary", sum(comm) as  "Total Commission" from emp;
```

---

## 20. Write a SQL query to calculate the average salary and average commission of employees.

**Expected Output Columns:**

```
+----------------+--------------------+
| Average Salary | Average Commission |
+----------------+--------------------+
```

```sql
USE test;
select avg(sal) as "Average Salary", avg(comm) as "Average Commission" from emp; 
```

---

## 21. Write a SQL query to calculate the average salary of employees with a commission.

**Expected Output Columns:**

```
+----------------------+
| avg_salary_with_comm |
+----------------------+
```

```sql
USE test;
select avg(sal) as "avg_salary_with_comm" from emp where   comm is not null or comm !=0;
```

---

## 22. Write a SQL query to determine the minimum commission value, excluding NULLs.

**Expected Output Columns:**

```
+----------------+
| min_commission |
+----------------+
```

```sql
USE test;
select min(comm) as "min_commission" from emp where comm is not  null;
```

---

## 23. Write a SQL query to find the total commission paid to employees hired after 1995.

**Expected Output Columns:**

```
+----------------------+
| total_comm_post_1995 |
+----------------------+
```

```sql
USE test;
select sum(comm) as "total_comm_post_1995" from emp where hiredate>1995;
```

---

## 24. Write a SQL query to find the maximum hire date (latest hire) in the emp table.

**Expected Output Columns:**

```
+-------------+
| latest_hire |
+-------------+
```

```sql
USE test;
select max(hiredate) as "latest_hire" from emp ;
```

---

## 25. Write a SQL query to find the average commission for salesmen, excluding NULLs.

**Expected Output Columns:**

```
+-------------------+
| avg_salesman_comm |
+-------------------+
```

```sql
USE test;
select avg(comm) as "avg_salesman_comm" from emp where job = "SALESMAN";
```

---

## 26. Write a SQL query to determine the minimum salary for employees hired in the 1990s.

**Expected Output Columns:**

```
+----------------+
| min_salary_90s |
+----------------+
```

```sql
USE test;
select min(sal) as "min_salary_90s" from emp where year(hiredate) between 1990 and 1999;
```

---

## 27. Write a SQL query to find the total salary of employees whose names start with 'K'.

**Expected Output Columns:**

```
+----------------+
| total_salary_k |
+----------------+
```

```sql
USE test;
select sum(sal) as "total_salary_k" from emp where ename like "k%";
```

---

## 28. Write a SQL query to count the number of employees hired in each year.

**Expected Output Columns:**

```
+-----------+----------------+
| hire_year | hires_per_year |
+-----------+----------------+
```

```sql
USE test;
select year(hiredate) as "hire_year" , count(year(hiredate)) as "hires_per_year" from emp group by year(hiredate);
```

---

## 29. Write a SQL query to sum the commissions for employees with salaries below 1500.

**Expected Output Columns:**

```
+-----------------------+
| total_comm_low_salary |
+-----------------------+
```

```sql
USE test;
select sum(comm) as "total_comm_low_salary" from emp where sal<1500;
```

---

## 30. List employees who do not receive a commission but earn more than 2500.

**Expected Output Columns:**

```
+-------+---------+------+
| ename | sal     | comm |
+-------+---------+------+
```

```sql
USE test;
select ename,sal,comm from emp where (comm is null ) and sal>2500;
```

---

