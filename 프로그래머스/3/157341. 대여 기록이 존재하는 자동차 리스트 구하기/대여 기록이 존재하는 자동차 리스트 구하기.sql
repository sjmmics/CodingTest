-- 코드를 입력하세요
SELECT DISTINCT (cars.car_id)
    FROM car_rental_company_car AS cars
    WHERE cars.car_type like '%세단%' AND cars.car_id IN 
        (SELECT car_id
        FROM car_rental_company_rental_history
        WHERE MONTH(start_date) = '10')
    ORDER BY cars.car_id DESC;
    