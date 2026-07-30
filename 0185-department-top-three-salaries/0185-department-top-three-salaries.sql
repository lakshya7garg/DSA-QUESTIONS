SELECT 
    Department ,
    Employee ,
    Salary
FROM
(
SELECT 
    d.name as Department ,
    e.name as Employee ,
    e.salary as Salary,
    DENSE_RANK() OVER (PARTITION BY d.id ORDER BY e.salary DESC) rnk 
FROM Employee e
JOIN Department d
ON e.departmentId=d.id
) T 
WHERE rnk<=3;