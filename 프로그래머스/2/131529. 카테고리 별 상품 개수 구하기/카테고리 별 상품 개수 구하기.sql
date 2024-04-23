-- 코드를 입력하세요
SELECT LEFT(product_code, 2) AS category, COUNT(DISTINCT product_id) AS products
FROM product
GROUP BY category;
