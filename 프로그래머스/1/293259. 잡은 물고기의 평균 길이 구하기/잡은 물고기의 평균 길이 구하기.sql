SELECT ROUND(SUM(IFNULL(length, 10)) / COUNT(*), 2) AS 'average_length'
    FROM fish_info;
