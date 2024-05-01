-- 코드를 입력하세요
SELECT m.user_id, m.nickname, 
        CONCAT(m.city, ' ', m.street_address1, ' ', m.street_address2) AS 전체주소,
        CONCAT(LEFT(m.tlno, 3), '-',
               MID(m.tlno, 4, 4), '-',
               RIGHT(tlno, 4)) AS 전화번호
    FROM used_goods_board AS s
    JOIN used_goods_user AS m ON s.writer_id = m.user_id
    GROUP BY m.user_id
    HAVING COUNT(board_id) >= 3
    ORDER BY s.writer_id DESC;