-- 코드를 작성해주세요

SELECT a.item_id, a.item_name
    FROM item_info AS a
    INNER JOIN item_tree AS b
    ON a.item_id = b.item_id
    WHERE b.parent_item_id IS NULL
    ORDER BY a.item_id ASC;