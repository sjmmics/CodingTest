-- 코드를 입력하세요
SELECT b.board_id, b.writer_id, b.title, b.price, 
    CASE
        WHEN b.status = 'sale' THEN '판매중' 
        WHEN b.status = 'reserved' THEN '예약중'
        WHEN b.status = 'done' THEN '거래완료'
    END AS 'STATUS'
    FROM used_goods_board AS b
    WHERE b.created_date LIKE '%2022-10-05%'
    ORDER BY b.board_id DESC;