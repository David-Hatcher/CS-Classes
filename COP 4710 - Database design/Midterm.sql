SELECT R.name, R.address
FROM Readers R,
WHERE R.age > 30;


SELECT B.title, B.publisher
FROM LibraryBranch LB, BookLoan BL, Reader R, Book B
WHERE   BL.lid = LB.lid AND
        LB.bname = 'Capestown' AND
        BL.rid = R.rid AND
        R.name = 'John Doe' AND
        BL.bid = B.bid;

SELECT R.name
FROM LibraryBranch LB, BookLoan BL, Readers R
WHERE   BL.lid = LB.lid AND
        BL.rid = R.rid  AND
        LB.bname = 'Capestown' AND
        R.rid NOT IN (  SELECT R.rid
                        FROM LibraryBranch LB, BookLoan BL, Readers R
                        WHERE   BL.lid = LB.lid AND
                                BL.rid = R.rid  AND
                                LB.bname = 'Sharptown')

SELECT B.title, B.publisher
FROM BookLoan BL, Reader R, Book B
WHERE   BL.bid = B.bid AND
        BL.rid = R.rid AND
        B.publisher = R.name;

SELECT B.name, AVG(R.age)
FROM Book B, BookLoan BL, Reader R
WHERE   B.bid = BL.bid AND
        BL.rid = R.rid
GROUP BY B.bid
HAVING COUNT(BL.rid) > 5

SELECT T.title
FROM    (SELECT B.title as title, COUNT(DISTINCT BL.lid) as cnt
        FROM BookLoan BL, Book B
        WHERE BL.bid = B.bid
        GROUP BY B.title) T
WHERE T.cnt in  (SELECT COUNT(DISTINCT lid)
                FROM LibraryBranch LB)

