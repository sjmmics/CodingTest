-- 코드를 입력하세요
SELECT outs.animal_id, outs.name
    FROM animal_outs AS outs, animal_ins AS ins
    WHERE outs.animal_id = ins.animal_id 
    ORDER BY outs.datetime - ins.datetime DESC
    LIMIT 2;