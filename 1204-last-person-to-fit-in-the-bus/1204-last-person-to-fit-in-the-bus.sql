SELECT person_name FROM
(
SELECT person_name,
    SUM(weight) OVER(ORDER BY turn ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) as Total_Weight
FROM Queue
) T
WHERE Total_Weight<=1000
ORDER BY Total_Weight DESC
LIMIT 1;