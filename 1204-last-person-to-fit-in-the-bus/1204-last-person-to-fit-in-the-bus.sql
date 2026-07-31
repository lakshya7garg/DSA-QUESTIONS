SELECT Name as person_name FROM
(
SELECT turn as Turn,
    person_id as ID,
    person_name as Name,
    weight as Weight,
    SUM(weight) OVER(ORDER BY turn ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) as Total_Weight
FROM Queue
) T
WHERE Total_Weight<=1000
ORDER BY Total_Weight DESC
LIMIT 1;