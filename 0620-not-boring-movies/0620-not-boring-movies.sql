select * from Cinema 
where description!='boring' 
&& id%2<>0
order by rating desc;