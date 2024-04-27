-- 코드를 입력하세요
SELECT o.flavor
    FROM first_half AS o
    WHERE o.flavor IN (
        SELECT p.flavor
        FROM icecream_info AS p
        WHERE p.ingredient_type = 'fruit_based')
        AND o.total_order > 3000
    ORDER BY o.total_order DESC;