

---

### **1) Find the average salary and number of employees per department, ordered by average salary in descending order.**

#### **Expected Output Columns:**

```
+--------+-------------+----------+
| deptno | AVG(sal)    | COUNT(*) |
+--------+-------------+----------+
```

```sql
USE test;
SELECT deptno,
    AVG(sal),
    COUNT(*)
FROM emp
GROUP BY deptno
ORDER BY AVG(sal) DESC;
```

---

### **2) List the total salary and employee count per job, excluding clerks.**

#### **Expected Output Columns:**

```
+-----------+----------+----------+
| job       | SUM(sal) | COUNT(*) |
+-----------+----------+----------+
```

```sql
USE test;
SELECT job,
    SUM(sal),
    COUNT(*)
FROM emp
WHERE job <> "CLERK"
GROUP BY job;
```

---

### **3) Show the total salary per department where the total salary exceeds 5000, ordered by department number.**

#### **Expected Output Columns:**

```
+--------+----------+
| deptno | SUM(sal) |
+--------+----------+
```

```sql
USE test;
SELECT deptno,
    SUM(sal)
FROM emp
GROUP BY deptno
HAVING SUM(sal) > 5000
ORDER BY deptno;
```

---

### **4) Display the number of employees per job, sorted by job title alphabetically.**

#### **Expected Output Columns:**

```
+-----------+----------+
| job       | COUNT(*) |
+-----------+----------+
```

```sql
USE test;
SELECT job,
    COUNT(*)
FROM emp
GROUP BY job
ORDER BY job;
```

---

### **5) Find the minimum and maximum salaries per department, excluding department 20.**

#### **Expected Output Columns:**

```
+--------+----------+----------+
| deptno | MIN(sal) | MAX(sal) |
+--------+----------+----------+
```

```sql
USE test;
SELECT deptno,
    MIN(sal),
    MAX(sal)
FROM emp
WHERE deptno <> 20
GROUP BY deptno;
```

---

### **6) List departments with more than 3 employees, ordered by total salary descending.**

#### **Expected Output Columns:**

```
+--------+----------+----------+
| deptno | SUM(sal) | COUNT(*) |
+--------+----------+----------+
```

```sql
USE test;
SELECT deptno,
    SUM(sal),
    COUNT(*)
FROM emp
GROUP BY deptno
HAVING COUNT(*) > 3
ORDER BY SUM(sal) DESC;
```

---

### **7) Show the total commission and average salary per job for jobs with at least 2 employees.**

#### **Expected Output Columns:**

```
+----------+-----------+-------------+
| job      | SUM(comm) | AVG(sal)    |
+----------+-----------+-------------+
```

```sql
USE test;
SELECT job,
    SUM(comm),
    AVG(sal)
FROM emp
GROUP BY job
HAVING COUNT(ename) >= 2;
```

---

### **8) Retrieve employees ordered by hire date and salary in descending order.**

```sql
USE test;
SELECT *
FROM emp
ORDER BY hiredate,
    sal DESC;
```

---

### **9) Find the total salary per department and job combination, excluding the president job.**

#### **Expected Output Columns:**

```
+--------+----------+----------+
| deptno | job      | SUM(sal) |
+--------+----------+----------+
```

```sql
USE test;
SELECT deptno,
    job,
    SUM(sal)
FROM emp
WHERE job <> "PRESIDENT"
GROUP BY deptno,
    job;
```

---

### **10) List departments with an average salary above 2000, ordered by average salary.**

#### **Expected Output Columns:**

```
+--------+-------------+
| deptno | AVG(sal)    |
+--------+-------------+
```

```sql
USE test;
SELECT deptno,
    AVG(sal)
FROM emp
GROUP BY deptno
HAVING AVG(sal) > 2000;
```

---

### **11) Display the employee count and total salary per department for departments with total salary over 4000.**

```sql
USE test;
SELECT deptno,
    COUNT(*),
    SUM(sal)
FROM emp
GROUP BY deptno
HAVING SUM(sal) > 4000;
```

---

### **12) Show all employees sorted by department number and then by job title alphabetically.**

```sql
USE test;
SELECT *
FROM emp
ORDER BY deptno,
    job;
```

---

### **13) Find the average salary per job in departments other than 10, ordered by job.**

```sql
USE test;
SELECT job,
    AVG(sal)
FROM emp
WHERE deptno <> 10
GROUP BY job
ORDER BY job;
```

---

### **14) List the total salary and employee count per department, excluding employees named 'FORD'.**

```sql
USE test;
SELECT deptno,
    SUM(sal),
    COUNT(*)
FROM emp
WHERE ename <> "FORD"
GROUP BY deptno;
```

---

### **15) Retrieve the total salary per job where the total salary is less than 10000, ordered by total salary descending.**

```sql
USE test;
SELECT job,
    SUM(sal)
FROM emp
GROUP BY job
HAVING SUM(sal) < 10000
ORDER BY SUM(sal) DESC;
```

---

### **16) Show employees ordered by salary descending and then by employee name ascending.**

```sql
USE test;
SELECT *
FROM emp
ORDER BY sal DESC,
    ename;
```

---

### **17) Find the maximum salary and employee count per department for departments with more than 2 employees.**

```sql
USE test;
SELECT deptno,
    MAX(sal),
    COUNT(*)
FROM emp
GROUP BY deptno
HAVING COUNT(ename) > 2;
```

---

### **18) List the total commission per department, excluding department 40, ordered by total commission.**

```sql
USE test;
SELECT deptno,
    SUM(comm)
FROM emp
WHERE deptno <> 40
GROUP BY deptno
ORDER BY SUM(comm); 
```

---

### **19) Display the average salary and job count per department, sorted by department number and average salary descending.**

```sql
USE test;
SELECT deptno,
    AVG(sal),
    COUNT(job)
FROM emp
GROUP BY deptno
ORDER BY deptno,
    AVG(sal);
```

---

### **20) Find departments with a total salary greater than 3000, excluding salesmen, ordered by total salary.**

```sql
USE test;
SELECT deptno,
    SUM(sal)
FROM emp
WHERE job <> "SALESMAN"
GROUP BY deptno
HAVING SUM(sal) > 3000
ORDER BY SUM(sal);
```

---

