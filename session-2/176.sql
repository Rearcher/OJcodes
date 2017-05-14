# 176. Second Highest Salary

# Solution 1
select max(Salary) as SecondHighestSalary from Employee where Salary < (select max(Salary) from Employee)
# Solution 2
select max(Salary) as SecondHighestSalary from Employee where Salary not in (select max(Salary) from Employee)