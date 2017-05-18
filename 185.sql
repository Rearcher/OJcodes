# 185. Department Top Three Salaries
select D.Name Department, E1.Name Employee, E1.Salary
from Employee E1 join Department D on E1.DepartmentId = D.id
where 3 > (select count(distinct(E2.Salary)) from Employee E2 where E2.Salary > E1.Salary and E2.DepartmentId = E1.DepartmentId)