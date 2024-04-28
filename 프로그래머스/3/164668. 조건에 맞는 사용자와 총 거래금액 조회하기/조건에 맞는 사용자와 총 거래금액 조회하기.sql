-- 코드를 입력하세요
SELECT member.user_id, member.nickname, SUM(article.price) AS total_sales
    FROM used_goods_user AS member
    JOIN used_goods_board AS article
    ON member.user_id = article.writer_id
    WHERE article.status = 'done'
    GROUP BY member.user_id
    HAVING total_sales >= 700000
    ORDER BY total_sales ASC;