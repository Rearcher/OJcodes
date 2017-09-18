# 262. Trips and Users
select Request_at as Day, round(count(if(Status != 'completed', TRUE, NULL)) / count(*), 2) as 'Cancellation Rate'
from Trips
where (Request_at between '2013-10-01' and '2013-10-03') and Client_id not in (select Users_Id from Users Where Banned = 'Yes')
group by Request_at;