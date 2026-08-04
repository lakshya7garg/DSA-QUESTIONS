# Write your MySQL query statement below
SELECT machine_id,
    ROUND(avg(COALESCE(diff,0)),3) as processing_time
FROM(
select *,
    ROUND(MAX(timestamp) OVER(PARTITION BY machine_id,process_id) - 
    MIN(timestamp) OVER(PARTITION BY machine_id,process_id),3) as diff
from Activity
)t
group by machine_id;