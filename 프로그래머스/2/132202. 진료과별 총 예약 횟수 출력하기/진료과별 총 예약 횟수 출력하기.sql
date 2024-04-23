-- 코드를 입력하세요
SELECT mcdp_cd AS '진료과코드', COUNT(mcdp_cd) AS '5월예약건수'
    FROM appointment
    WHERE apnt_ymd LIKE '2022-05%'
    GROUP BY mcdp_cd
    ORDER BY COUNT(mcdp_cd) ASC, mcdp_cd ASC;
    
    