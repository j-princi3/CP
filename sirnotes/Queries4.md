Below is the complete markdown file containing each query with its question, expected output columns, and the SQL code exactly as provided:

---

## SQL JOIN Queries

---

### 1) List employee names and department names for employees with a salary greater than 2000 using INNER JOIN.

**Question:**

```sql
/* Write a SQL query to list employee names and department names for employees with a salary greater than 2000 using INNER JOIN.
 
 
 +-------+------------+
 | ename | dname      |
 +-------+------------+
 */
```

**Query:**

```sql
USE test;
SELECT ename,
    dname
FROM emp
    JOIN dept ON emp.deptno = dept.deptno
WHERE emp.sal > 2000;
```

---

### 2) Retrieve all employees and their department locations, including those without departments, using LEFT JOIN.

**Question:**

```sql
/* Write a SQL query to retrieve all employees and their department locations, 
 including those without departments, using LEFT JOIN.
 
 +--------+----------+
 | ename  | location |
 +--------+----------+
 */
```

**Query:**

```sql
USE test;
SELECT ename,
    location
FROM emp
    LEFT JOIN dept ON emp.deptno = dept.deptno;
```

---

### 3) List all department numbers, department names and their employee counts, including departments with no employees, using RIGHT JOIN.

**Question:**

```sql
/* Write a SQL query to list all department numbers, department names and their 
 employee counts, including departments with no employees, using RIGHT JOIN.
 
 +--------+------------+-----------+
 | deptno | dname      | emp_count |
 +--------+------------+-----------+
 */
```

**Query:**

```sql
USE test;
SELECT dept.deptno,
    dept.dname,
    COUNT(emp.ename) AS emp_count
FROM emp
    RIGHT JOIN dept ON dept.deptno = emp.deptno
GROUP BY dept.deptno;
```

---

### 4) Simulate a FULL OUTER JOIN to list all employees and departments, including unmatched rows.

**Question:**

```sql
/* Write a SQL query to simulate a FULL OUTER JOIN to list all employees and 
 departments, including unmatched rows.
 
 +-------+--------+--------+------------+
 | empno | ename  | deptno | dname      |
 +-------+--------+--------+------------+
 */
```

**Query:**

```sql
USE test;
SELECT emp.empno,
    emp.ename,
    dept.deptno,
    dept.dname
FROM emp
    LEFT JOIN dept ON emp.deptno = dept.deptno
UNION
SELECT emp.empno,
    emp.ename,
    dept.deptno,
    dept.dname
FROM emp
    RIGHT JOIN dept ON emp.deptno = dept.deptno;
```

---

### 5) Find employees who are managers of other employees using a self-join (print names).

**Question:**

```sql
/* Write a SQL query to find employees who are managers of other employees using 
 a self-join.
 print names
 +---------+
 | manager |
 +---------+
 */
```

**Query:**

```sql
USE test;
SELECT e1.ename AS manager
FROM emp e1
    JOIN emp e2 ON e1.mgr = e2.empno;
```

---

### 6) Generate all possible employee-department combinations using CROSS JOIN.

**Question:**

```sql
/* Write a SQL query to generate all possible employee-department combinations 
 using CROSS JOIN.
 
 +--------+------------+
 | ename  | dname      |
 +--------+------------+
 */
```

**Query:**

```sql
USE test;
SELECT e1.ename,
    e1.ename
FROM emp e1
    CROSS JOIN emp e2 ON e1.deptno = e2.deptno;
```

---

### 7) List departments with employees earning more than 2500 using EXISTS.

**Question:**

```sql
/* Write a SQL query to list departments with employees earning more than 2500 
 using EXISTS.
 
 +--------+------------+
 | deptno | dname      |
 +--------+------------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 8) Find departments with number of employees earning less than 1000 using NOT EXISTS.

**Question:**

```sql
/* Write a SQL query to find departments with number of employees earning less 
 than 1000 using NOT EXISTS.
 
 +------------+--------+
 | dname      | deptno |
 +------------+--------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 9) Find managers and the number of employees they manage in departments located in 'New York', using the primary key and foreign key constraints.

**Question:**

```sql
/* Write a SQL query to find managers and the number of employees they manage in
 departments located in 'New York', using the primary key and foreign key 
 constraints.
 
 +--------------+-----------+
 | manager_name | emp_count |
 +--------------+-----------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 10) List all employees and departments, including those without matches, using a simulated FULL JOIN.

**Question:**

```sql
/* Write a SQL query to list all employees and departments, including those 
 without matches, using a simulated FULL JOIN.
 
 +-------+--------+--------+------------+----------+
 | empno | ename  | deptno | dname      | location |
 +-------+--------+--------+------------+----------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 11) List employee names and department names where the department is in 'Chicago' using INNER JOIN.

**Question:**

```sql
/* Write a SQL query to list employee names and department names where the 
 department is in 'Chicago' using INNER JOIN.
 
 +-------+-------+
 | ename | dname |
 +-------+-------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 12) Retrieve Department-wise Total Salary and Number of Employees (Using GROUP BY and JOIN).

**Question:**

```sql
/* 
 Retrieve Department-wise Total Salary and Number of Employees (Using GROUP BY and JOIN)
 
 +------------+---------------+--------------+
 | dname      | num_employees | total_salary |
 +------------+---------------+--------------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 13) List departments with no assigned employees using RIGHT JOIN.

**Question:**

```sql
/* Write a SQL query to list departments with no assigned employees using 
 RIGHT JOIN.
 
 +--------+---------+
 | deptno | dname   |
 +--------+---------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 14) Combine employee and department data with duplicates using UNION ALL.

**Question:**

```sql
/* Write a SQL query to combine employee and department data with duplicates 
 using UNION ALL.
 
 +--------+------------+
 | ename  | dname      |
 +--------+------------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 15) List employees and their managers’ names using a LEFT JOIN for employees without managers.

**Question:**

```sql
/* Write a SQL query to list employees and their managers’ names using a LEFT 
 JOIN for employees without managers.
 
 +----------+---------+
 | employee | manager |
 +----------+---------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 16) Retrieve average salaries per department using INNER JOIN and GROUP BY.

**Question:**

```sql
/* Write a SQL query to retrieve average salaries per department using INNER 
 JOIN and GROUP BY.
 
 +--------+------------+-------------+
 | deptno | dname      | avg_salary  |
 +--------+------------+-------------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 17) Find departments with more than 3 employees using INNER JOIN and HAVING.

**Question:**

```sql
/* Write a SQL query to find departments with more than 3 employees using 
 INNER JOIN and HAVING.
 
 +--------+----------+-----------+
 | deptno | dname    | emp_count |
 +--------+----------+-----------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 18) List employees and departments where the employee’s hire date is after 1980 using INNER JOIN.

**Question:**

```sql
/* Write a SQL query to list employees and departments where the employee’s 
 hire date is after 1980 using INNER JOIN.
 
 +--------+------------+------------+
 | ename  | dname      | hiredate   |
 +--------+------------+------------+
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 19) Find Departments Without Employees (Using LEFT JOIN and NULL Check).

**Question:**

```sql
/* 
 Find Departments Without Employees (Using LEFT JOIN and NULL Check)
 
 +------------+----------+
 | Department | Location |
 +------------+----------+
 
 */
```

**Query:**

```sql
USE test;
```

_(No additional SQL code provided)_

---

### 20) List employee names and department names using an implicit join, ordered by employee name.

**Question:**

```sql
/* Write a SQL query to list employee names and department names using an
 implicit join, ordered by employee name.

+--------+------------+
| ename  | dname      |
+--------+------------+
 */
```

**Query:**

```sql
USE test;
```



---
