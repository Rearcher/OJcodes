#181. Employees Earning More Than Their Managers
select Name as Employee from Employee e1 where Salary > (select Salary from Employee e2 where Id = e1.ManagerId)
