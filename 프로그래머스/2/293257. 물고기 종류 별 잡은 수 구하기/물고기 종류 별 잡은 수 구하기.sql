-- 코드를 작성해주세요
SELECT COUNT(*) AS fish_count, n.fish_name
    FROM fish_name_info AS n
    INNER JOIN fish_info AS f
    ON f.fish_type = n.fish_type
    GROUP BY n.fish_name
    ORDER BY fish_count DESC;