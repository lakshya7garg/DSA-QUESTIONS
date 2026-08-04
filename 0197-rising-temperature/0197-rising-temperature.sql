# Write your MySQL query statement below
select id from(
select *,
    lag(temperature) over(order by recordDate) prevdatetemp,
    lag(recordDate) over(order by recordDate) prevdate
from Weather 
) t
where temperature>prevdatetemp
and datediff(recordDate,prevdate)=1;