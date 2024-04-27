-- 코드를 입력하세요
SELECT p.product_code, SUM(p.price * s.sales_amount) AS sales
    FROM product AS p
    INNER JOIN offline_sale AS s ON p.product_id = s.product_id
    GROUP BY p.product_code
    ORDER BY sales DESC, p.product_code ASC