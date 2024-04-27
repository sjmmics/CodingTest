-- 코드를 입력하세요
SELECT ins.animal_id, ins.animal_type, ins.name
    FROM animal_ins AS ins
    LEFT JOIN animal_outs AS outs ON ins.animal_id = outs.animal_id
    WHERE ins.sex_upon_intake like '%intact%' AND 
        (outs.sex_upon_outcome LIKE '%spayed%' OR outs.sex_upon_outcome LIKE '%neutered%')
    ORDER BY ins.animal_id