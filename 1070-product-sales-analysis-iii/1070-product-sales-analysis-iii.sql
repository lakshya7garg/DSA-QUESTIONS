# Write your MySQL query statement below
SELECT 
    product_id,
    year as first_year,
    quantity,
    price
FROM (
SELECT product_id,
    year,
    RANK() OVER(Partition by product_id ORDER BY year ASC) rnk,
    quantity,
    price
FROM Sales
)T 
where rnk=1;