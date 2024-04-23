-- 코드를 입력하세요
SELECT P.ingredient_type, SUM(O.total_order) AS total_order
    FROM first_half AS O, icecream_info AS P
    WHERE O.flavor = P.flavor
    GROUP BY P.ingredient_type
    ORDER BY total_order
    
    
