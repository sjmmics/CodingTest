-- 코드를 입력하세요
SELECT category, price AS max_price, product_name
    FROM food_product
    WHERE category in ('과자', '국', '김치', '식용유') AND
        price IN (SELECT MAX(price) FROM food_product GROUP BY category)
    ORDER BY max_price DESC;