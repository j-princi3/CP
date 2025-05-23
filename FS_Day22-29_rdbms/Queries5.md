Procedures 

 1. Write a SQL procedure to retrieve all employees with their department names.

```
+-------+--------+-----------+------------+
| empno | ename  | job       | dname      |
+-------+--------+-----------+------------+
```
---


 2. Write a SQL procedure to count employees in each department.

```
 +------------+-----------+
| dname      | emp_count |
+------------+-----------+
```

---

 3. Write a SQL procedure to list departments with no employees.
```
+---------+----------+
| dname   | location |
+---------+----------+
```
---

 4. Write a SQL procedure to find employees with duplicate names.
 
```
+-------+------------+
| ename | name_count |
+-------+------------+
```

---

 5. Write a SQL procedure to find employees earning above 2500 and return their count.
**Procedure:** (IN parameter: min_salary = 2500)
CALL GetHighEarners(@count); SELECT @count;
```
+-------+---------+--------+
| ename | sal     | deptno |
+-------+---------+--------+

+--------+
| @count |
+--------+
```
---

 6. Write a SQL procedure to list employees and their managers' names and count employees with no manager.
```
**Procedure:** (No IN parameters, only OUT)
+----------+-----------+---------+
| employee | job       | manager |
+----------+-----------+---------+

+---------+
| @no_mgr |
+---------+
```
---


 7. Write a SQL procedure to calculate the total salary expenditure by department and return the highest total.
```
**Procedure:** (No IN parameters, only OUT)
CALL TotalSalaryByDept(@max); SELECT @max;
+------------+--------------+
| dname      | total_salary |
+------------+--------------+

+----------+
| @max     |
+----------+
```

---


 8. Write a SQL procedure to find employees hired before '1995-01-01' and return their average salary.
```
**Procedure:** (IN parameter: cutoff_date = '1995-01-01')
**Execution Command:** CALL GetEmpByHireDate(@avg); SELECT @avg;

-- Result of SELECT in procedure:
+-------+-------+------------+
| empno | ename | hiredate   |
+-------+-------+------------+

-- Result of SELECT @avg:
+---------+
| @avg    |
+---------+
```

---

 9. Write a SQL procedure to assign salary grades to employees and return the highest grade assigned.
```
**Procedure:** (No IN parameters, only OUT)

**Execution Command:** CALL AssignSalaryGrades(@max); SELECT @max;

-- Result of SELECT in procedure:
+--------+---------+-------+
| ename  | sal     | grade |
+--------+---------+-------+
     
-- Result of SELECT @max:
+------+
| @max |
+------+
```
---

 10. Write a SQL procedure to find the highest-paid employee in each department and return the overall highest salary.
```
**Procedure:** (No IN parameters, only OUT)

**Execution Command:** CALL GetTopEarnerByDept(@top); SELECT @top;

-- Result of SELECT in procedure:
+------------+-------+------------+
| dname      | ename | max_salary |
+------------+-------+------------+

-- Result of SELECT @top:
+---------+
| @top    |
+---------+
```
---


 11. Write a SQL procedure to update employee commission to 1000 for 'SALESMAN' and track the number of updates.
```
**Procedure:** (IN parameters: job_type = 'SALESMAN', new_comm = 1000)

**Execution Command:** CALL UpdateCommByJob(@count); SELECT @count;

-- Result of SELECT in procedure:
+-------+--------+----------+---------+
| empno | ename  | job      | comm    |
+-------+--------+----------+---------+

-- Result of SELECT @count:
+--------+
| @count |
+--------+
```

---


 12. Write a SQL procedure to calculate average salary by job title and modify 'CLERK' average.
```
**Procedure:** (IN parameter: target_job = 'CLERK')

**Execution Command:** SET @avg = 0; CALL AvgSalaryByJob(@avg); SELECT @avg;

-- Result of SELECT in procedure:
+-----------+-------------+
| job       | avg_salary  |
+-----------+-------------+

-- Result of SELECT @avg:
+---------+
| @avg    |
+---------+
```
---


 13. Write a SQL procedure to increase salaries by 10% for department 20 and track the total increase.
```
**Procedure:** (IN parameters: dept_num = 20, pct = 10)

**Execution Command:** CALL IncreaseSalByDept(@increase); SELECT @increase;

-- Result of SELECT in procedure:
+-------+-------+---------+
| empno | ename | sal     |
+-------+-------+---------+

-- Result of SELECT @increase:
+-----------+
| @increase |
+-----------+
```

---

 14. Write a SQL procedure to find employees with no commission in grade 4 and count them.
```
**Procedure:** (IN parameter: grade_num = 4)
 **Execution Command:** CALL GetNoCommByGrade(@count); SELECT @count;

-- Result of SELECT in procedure:
+-------+---------+-------+
| ename | sal     | grade |
+-------+---------+-------+

-- Result of SELECT @count:
+--------+
| @count |
+--------+
```
---


 15. Write a SQL procedure to list employees reporting to manager 7698 and modify their count.
```
**Procedure:** (IN parameter: mgr_id = 7698)

**Execution Command:** SET @count = 0; CALL GetSubordinates(@count); SELECT @count;

-- Result of SELECT in procedure:
+-------+--------+----------+
| empno | ename  | job      |
+-------+--------+----------+

-- Result of SELECT @count:
+--------+
| @count |
+--------+
```

---


 16. Write a SQL procedure to find departments with above-average employee count and return the average.
```
**Procedure:** (No IN parameters, only OUT)

**Execution Command:** CALL AboveAvgEmpDepts(@avg); SELECT @avg;

-- Result of SELECT in procedure:
+------------+-----------+
| dname      | emp_count |
+------------+-----------+

-- Result of SELECT @avg:
+------+
| @avg |
+------+
```
---

 17. Write a SQL procedure to calculate total commission by department and return the maximum commission.
```
**Procedure:** (No IN parameters, only OUT)

**Execution Command:** CALL TotalCommByDept(@max); SELECT @max;

-- Result of SELECT in procedure:
+------------+------------+
| dname      | total_comm |
+------------+------------+
-- Result of SELECT @max:

+---------+
| @max    |
+---------+
```

---


 18. Write a SQL procedure to find employees hired in the same year as employee 7499 and count them.
```
**Procedure:** (IN parameter: emp_id = 7499)

**Execution Command:** CALL SameHireYear(@count); SELECT @count;

-- Result of SELECT in procedure:
+-------+--------+------------+
| empno | ename  | hiredate   |
+-------+--------+------------+

-- Result of SELECT @count:
+--------+
| @count |
+--------+
```
---


 19. Write a SQL procedure to rank employees by salary within their department and return the highest rank count.
```
**Procedure:** (No IN parameters, only OUT)

**Execution Command:** CALL RankEmpBySalary(@max); SELECT @max;

-- Result of SELECT in procedure:
+--------+---------+------------+-------------+
| ename  | sal     | dname      | salary_rank |
+--------+---------+------------+-------------+

-- Result of SELECT @max:
+------+
| @max |
+------+
```
---


 20. Write a SQL procedure to transfer employees from dept 30 to dept 40, increase salaries by 500, and track count.
```
**Procedure:** (IN parameters: old_dept = 30, new_dept = 40, sal_increase = 500)

**Execution Command:** CALL TransferAndUpdateSalary(@count); SELECT @count;

-- Result of SELECT in procedure:
+-------+--------+---------+--------+
| empno | ename  | sal     | deptno |
+-------+--------+---------+--------+

-- Result of SELECT @count:
+--------+
| @count |
+--------+
```



