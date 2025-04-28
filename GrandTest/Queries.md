/* 1) Write a SQL query to calculate the total revenue per customer, excluding cancelled orders, 
 for those with at least two orders between October 10 and October 15, 2024.
 
 Expected Output Columns:
 ------------------------
 +----------------+--------------+
 | Name           | TotalRevenue |
 +----------------+--------------+
 
 Note: 
 -----
 Database name: customer_orders
 
 Tables in customer_orders:  Customers                                                                       
 OrderItems                                                                      
 Orders                                                                          
 Products
 
 */
use customer_orders;
/* 2) Write a SQL query to find the customer with the highest average order cost, 
 excluding cancelled orders.
 
 Expected Output Columns:
 ------------------------
 +--------------+-------------+
 | Name         | AvgCost     |
 +--------------+-------------+
 
 Note: 
 -----
 Database name: customer_orders
 
 Tables in customer_orders:  Customers                                                                       
 OrderItems                                                                      
 Orders                                                                          
 Products
 
 */
use customer_orders;
/*3) Write a SQL query to find the customer who ordered the most keyboards, 
 using pattern matching and aggregate functions.
 
 Expected Output Columns:
 ------------------------
 +---------------+---------------+
 | Name          | KeyboardCount |
 +---------------+---------------+
 
 Note: 
 -----
 Database name: customer_orders
 
 Tables in customer_orders:  Customers                                                                       
 OrderItems                                                                      
 Orders                                                                          
 Products
 
 */
use customer_orders;
/* 4)Write a SQL query to list products ordered in both 'Shipped' and 'Processing' statuses 
 but not 'Cancelled'.
 
 Expected Output Columns:
 ------------------------
 +------------+
 | Name       |
 +------------+
 
 Note: 
 -----
 Database name: customer_orders
 
 Tables in customer_orders:  Customers                                                                       
 OrderItems                                                                      
 Orders                                                                          
 Products
 
 */
use customer_orders;
/* 5) Write a SQL query to find the top 3 most expensive products never ordered.
 
 Expected Output Columns:
 ------------------------
 +------------+--------+
 | Name       | Price  |
 +------------+--------+
 
 Note: 
 -----
 Database name: customer_orders
 
 Tables in customer_orders:  Customers                                                                       
 OrderItems                                                                      
 Orders                                                                          
 Products
 
 */
use customer_orders;
/* 6) Write a SQL Query Using a Correlated Subquery to Get the Latest Order for Each Customer
 
 Expected Output Columns:
 ------------------------
 +---------+------------+------------+-----------+
 | OrderID | CustomerID | OrderDate  | TotalCost |
 +---------+------------+------------+-----------+
 
 Note: 
 -----
 Database name: customer_orders
 
 Tables in customer_orders:  Customers                                                                       
 OrderItems                                                                      
 Orders                                                                          
 Products
 
 */
use customer_orders;
/* 7) Write a SQL Query to Find the Most Frequently Ordered Product.
 
 Expected Output Columns:
 ------------------------
 +-------+---------------+
 | Name  | TotalQuantity |
 +-------+---------------+
 
 Note: 
 -----
 Database name: customer_orders
 
 Tables in customer_orders:  Customers                                                                       
 OrderItems                                                                      
 Orders                                                                          
 Products
 
 */
use customer_orders;


/* 8) Write a SQL Query to Find orders that were placed on weekends.

Expected Output Columns:
------------------------
+---------+------------+------------+
| OrderID | CustomerID | OrderDate  |
+---------+------------+------------+

Note: 
-----
Database name: customer_orders

Tables in customer_orders:  Customers                                                                       
                            OrderItems                                                                      
                            Orders                                                                          
                            Products

*/
use customer_orders;


Perfect! Here's the **full set of SQL queries** to solve your tasks cleanly and correctly, assuming your database `customer_orders` and the mentioned tables have typical columns like `CustomerID`, `OrderID`, `OrderDate`, `Status`, `Quantity`, `Price`, etc.

---

# 1. **Total Revenue per Customer (Min 2 Orders, Exclude Cancelled Orders)**

```sql
USE customer_orders;

SELECT c.Name, SUM(oi.Quantity * p.Price) AS TotalRevenue
FROM Customers c
JOIN Orders o ON c.CustomerID = o.CustomerID
JOIN OrderItems oi ON o.OrderID = oi.OrderID
JOIN Products p ON oi.ProductID = p.ProductID
WHERE o.Status != 'Cancelled'
  AND o.OrderDate BETWEEN '2024-10-10' AND '2024-10-15'
GROUP BY c.CustomerID, c.Name
HAVING COUNT(DISTINCT o.OrderID) >= 2;
```

---

# 2. **Customer with the Highest Average Order Cost**

```sql
USE customer_orders;

SELECT c.Name, AVG(oi.Quantity * p.Price) AS AvgCost
FROM Customers c
JOIN Orders o ON c.CustomerID = o.CustomerID
JOIN OrderItems oi ON o.OrderID = oi.OrderID
JOIN Products p ON oi.ProductID = p.ProductID
WHERE o.Status != 'Cancelled'
GROUP BY c.CustomerID, c.Name
ORDER BY AvgCost DESC
LIMIT 1;
```

---

# 3. **Customer Who Ordered the Most Keyboards**

```sql
USE customer_orders;

SELECT c.Name, SUM(oi.Quantity) AS KeyboardCount
FROM Customers c
JOIN Orders o ON c.CustomerID = o.CustomerID
JOIN OrderItems oi ON o.OrderID = oi.OrderID
JOIN Products p ON oi.ProductID = p.ProductID
WHERE p.Name LIKE '%keyboard%'
GROUP BY c.CustomerID, c.Name
ORDER BY KeyboardCount DESC
LIMIT 1;
```

---

# 4. **Products Ordered in Both 'Shipped' and 'Processing' but not 'Cancelled'**

```sql
USE customer_orders;

SELECT DISTINCT p.Name
FROM Products p
JOIN OrderItems oi ON p.ProductID = oi.ProductID
JOIN Orders o ON oi.OrderID = o.OrderID
WHERE o.Status IN ('Shipped', 'Processing')
  AND p.ProductID NOT IN (
    SELECT DISTINCT p2.ProductID
    FROM Products p2
    JOIN OrderItems oi2 ON p2.ProductID = oi2.ProductID
    JOIN Orders o2 ON oi2.OrderID = o2.OrderID
    WHERE o2.Status = 'Cancelled'
)
GROUP BY p.ProductID, p.Name
HAVING COUNT(DISTINCT o.Status) = 2;
```

---

# 5. **Top 3 Most Expensive Products Never Ordered**

```sql
USE customer_orders;

SELECT p.Name, p.Price
FROM Products p
LEFT JOIN OrderItems oi ON p.ProductID = oi.ProductID
WHERE oi.ProductID IS NULL
ORDER BY p.Price DESC
LIMIT 3;
```

---

# 6. **Latest Order for Each Customer (Correlated Subquery)**

```sql
USE customer_orders;

SELECT o1.OrderID, o1.CustomerID, o1.OrderDate,
       (SELECT SUM(oi.Quantity * p.Price)
        FROM OrderItems oi
        JOIN Products p ON oi.ProductID = p.ProductID
        WHERE oi.OrderID = o1.OrderID) AS TotalCost
FROM Orders o1
WHERE o1.OrderDate = (
    SELECT MAX(o2.OrderDate)
    FROM Orders o2
    WHERE o2.CustomerID = o1.CustomerID
);
```

---

# 7. **Most Frequently Ordered Product**

```sql
USE customer_orders;

SELECT p.Name, SUM(oi.Quantity) AS TotalQuantity
FROM Products p
JOIN OrderItems oi ON p.ProductID = oi.ProductID
GROUP BY p.ProductID, p.Name
ORDER BY TotalQuantity DESC
LIMIT 1;
```

---

# 8. **Orders Placed on Weekends**

```sql
USE customer_orders;

SELECT OrderID, CustomerID, OrderDate
FROM Orders
WHERE DAYOFWEEK(OrderDate) IN (1, 7);
```

> 🔥 **Note:** In SQL `DAYOFWEEK()`:
> 
> - `1` = Sunday
>     
> - `7` = Saturday
>     

---

# ✅ All Done!

Each query matches **your requested output columns and conditions**.

---

# 🚀 Quick Summary

|Task|Query Provided|
|---|---|
|Revenue per customer (2+ orders)|✅|
|Highest average order cost|✅|
|Most keyboards ordered|✅|
|Products in Shipped & Processing but not Cancelled|✅|
|Top 3 expensive never-ordered products|✅|
|Latest order per customer (correlated)|✅|
|Most frequently ordered product|✅|
|Orders placed on weekends|✅|

---

Would you also like me to give you a **diagram of table relationships** 📊?  
(Helpful if you want a clean Entity-Relationship visual to fully understand joins!)  
Just say **"Show ER Diagram"**! 🚀