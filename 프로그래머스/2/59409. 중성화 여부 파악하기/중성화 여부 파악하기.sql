-- 코드를 입력하세요
SELECT animal_id, name, 
    CASE 
    WHEN sex_upon_intake LIKE "%neutered%" OR sex_upon_intake LIKE "%spayed%"
    THEN "O"
    ELSE "X"
    END AS "중성화"
    FROM animal_ins
    ORDER BY animal_id;
    