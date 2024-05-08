-- 코드를 입력하세요
SELECT a.title, a.board_id, r.reply_id, r.writer_id, r.contents, DATE_FORMAT(r.created_date, "%Y-%m-%d") AS 'created_date'
    FROM used_goods_board AS a
    JOIN used_goods_reply AS r ON a.board_id = r.board_id
    WHERE a.created_date LIKE '%2022-10%'
    ORDER BY r.created_date ASC, a.title ASC;