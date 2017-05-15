# 182. Duplicate Emails
select Email from Person group by Email having count(*) > 1