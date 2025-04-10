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