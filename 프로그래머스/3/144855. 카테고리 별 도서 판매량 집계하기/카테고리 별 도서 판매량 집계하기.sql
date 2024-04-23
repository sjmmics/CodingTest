-- 코드를 입력하세요
SELECT category, SUM(sales) AS 'total_sales'
    FROM book
    INNER JOIN book_sales on book.book_id = book_sales.book_id
    WHERE sales_date LIKE '2022-01%'
    GROUP BY category
    ORDER BY category;
    
    