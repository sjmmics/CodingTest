-- 코드를 입력하세요
SELECT YEAR(s.sales_date) AS 'year', 
       MONTH(s.sales_date) AS 'month', 
       m.gender, 
       COUNT(DISTINCT(s.user_id)) AS 'users'
    FROM user_info AS m
    JOIN online_sale AS s ON m.user_id = s.user_id
    WHERE m.gender IS NOT NULL
    GROUP BY YEAR(s.sales_date), MONTH(s.sales_date), m.gender
    ORDER BY YEAR(s.sales_date) ASC, MONTH(s.sales_date) ASC, m.gender ASC;