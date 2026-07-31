SELECT
    employee_id,
    department_id
FROM
(
SELECT *,
    COUNT(primary_flag) OVER(PARTITION BY Employee_id) as flags
FROM Employee
)t
WHERE flags=1 or primary_flag='Y';