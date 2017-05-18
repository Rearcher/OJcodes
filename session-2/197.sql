# 197. Rising Temperature
select w1.Id from Weather w1, Weather w2 where w1.Temperature > w2.Temperature and to_days(w1.DATE) - to_days(w2.DATE) = 1