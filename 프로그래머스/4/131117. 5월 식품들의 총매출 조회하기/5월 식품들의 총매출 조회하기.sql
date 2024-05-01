-- 코드를 입력하세요
SELECT food_order.product_id, food_product.product_name, 
        sum(food_product.price * food_order.amount) AS total_sales
    FROM food_order
    JOIN food_product ON food_order.product_id = food_product.product_id
    WHERE food_order.produce_date like '%2022-05%'
    GROUP BY food_order.product_id
    ORDER BY total_sales DESC, food_order.product_id ASC;