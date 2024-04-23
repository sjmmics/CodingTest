-- 코드를 입력하세요
SELECT HOUR(datetime) AS 'hour', COUNT(HOUR(datetime)) AS 'count'
    FROM animal_outs
    GROUP BY HOUR(datetime)
    HAVING hour >= 9 AND hour <= 19
    ORDER BY HOUR(datetime);
