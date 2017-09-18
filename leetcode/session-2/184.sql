# 184. Department Highest Salary
select D.Name as Department, E.name as Employee, E.Salary
from Employee E, Department D where E.DepartmentId = D.id
and (DepartmentId, Salary) in (select DepartmentId, max(Salary) as max from Employee group by DepartmentId)