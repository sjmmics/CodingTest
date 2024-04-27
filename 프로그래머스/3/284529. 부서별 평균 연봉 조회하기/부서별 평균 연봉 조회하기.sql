-- 코드를 작성해주세요
SELECT hr.dept_id, dp.dept_name_en, ROUND(AVG(hr.sal)) AS avg_sal
    FROM hr_employees AS hr INNER JOIN hr_department AS dp ON hr.dept_id = dp.dept_id 
    GROUP BY hr.dept_id
    ORDER BY avg_sal DESC;