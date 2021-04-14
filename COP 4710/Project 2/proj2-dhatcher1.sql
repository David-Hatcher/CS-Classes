\o proj2-dhatcher1.out
--QUESTION 1: Find all the coaches who have coached less than TWO teams. List their first names, last names and cids.

SELECT DISTINCT C2.firstname, C2.lastname, C2.cid
FROM    (SELECT C.cid AS cid, COUNT(DISTINCT C.tid) AS cnt
        FROM coaches_season C
        GROUP BY C.cid) C1, coaches_season C2
WHERE   C1.cid = C2.cid AND
        C1.cnt = 1
ORDER BY C2.lastname;


--Find all the players who played in a Miami N league team and a New York A league team (this does not have to happen in the same season). List their first names and ilkids.
SELECT P1.firstname
FROM    (SELECT P.firstname, P.lastname, P.tid
        FROM player_rs P, teams T
        WHERE   P.tid = T.tid AND
                T.location = 'New York' AND
                T.league = 'A'
        INTERSECT
        SELECT P.firstname, P.lastname, P.tid
        FROM player_rs P, teams T
        WHERE   P.tid = T.tid AND
                T.location = 'Miami' AND
                T.league = 'N'
        ) P1;

--Find those who happened to be a coach and a player in the same team in the same season. List their first names, last names, the team where this happened, and the year(s) when this happened.

SELECT C.firstname, C.lastname, T.name, C.year
FROM coaches_season C, player_rs P, teams T
WHERE   C.cid = P.ilkid AND
        C.year = P.year AND
        C.tid = P.tid AND
        T.tid = C.tid
ORDER BY (C.year,C.firstname);

--Find the average height (in centimeters) of each team in season 2002. Print the team name, the coach name and the average height value (in centimeters), and sort the results by the average height.

SELECT DISTINCT T.name, H.year, H.avgHeightCm AS avg_h
FROM coaches_season C,
    (SELECT PR.tid, AVG(P.h_feet * 12 + p.h_inches) * 2.54 AS avgHeightCm, PR.year
    FROM players P, player_rs PR
    WHERE   P.ilkid = PR.ilkid AND
            PR.year = 2002
    GROUP BY PR.tid, PR.year) H,
    teams T
WHERE   C.tid = H.tid AND
        H.tid = T.tid AND
        C.year = H.year
ORDER BY H.avgHeightCm DESC;

--Find the coach(es) (first name, last name, and cid) who have coached the largest number of players in year 2000.

SELECT C.firstname, C.lastname, C.cid
FROM coaches_season C
WHERE   C.year = 2000 AND
        C.cid NOT IN    (SELECT DISTINCT T1.cid
                        FROM    (SELECT C.cid, COUNT(PR.ilkid) as pCount
                                FROM coaches_season C, player_rs PR
                                WHERE   C.year = 2000 AND
                                        PR.year = C.year AND
                                        C.tid = PR.tid
                                GROUP BY C.cid) T1,
                                (SELECT C.cid, COUNT(PR.ilkid) as pCount
                                FROM coaches_season C, player_rs PR
                                WHERE   C.year = 2000 AND
                                        PR.year = C.year AND
                                        C.tid = PR.tid
                                GROUP BY C.cid) T2
                        WHERE T1.pcount < T2.pcount);

--Find the coaches who coached in ALL leagues. List their first names, last names and cids.

SELECT C1.firstname, C1.lastname, C1.cid
FROM    (SELECT C.cid, C.firstname, C.lastname, COUNT(DISTINCT T.league) AS lCount
        FROM coaches_season C, teams T
        WHERE   C.tid = T.tid
        GROUP BY C.cid, C.firstname, C.lastname) C1,
        (SELECT COUNT(l.league) AS lCount
        FROM    (SELECT DISTINCT league
                FROM teams) L) L1
WHERE   C1.lCount = L1.lCount
ORDER BY C1.firstname;

--Find those who happened to be a coach and a player in the same season, but in different teams. List their first names, last names, the season, and the teams this happened. Order the results by ascending season.

SELECT CT.firstname, CT.lastname, CT.year, PT.name, CT.name
FROM    (SELECT C.firstname, C.lastname, C.year, T.tid, T.name, C.cid
        FROM coaches_season C, teams T
        WHERE C.tid = T.tid) CT,
        (SELECT P.firstname, P.lastname, P.year, T.tid, T.name, P.ilkid
        FROM player_rs P, teams T
        WHERE P.tid = T.tid) PT
WHERE   CT.cid = PT.ilkid AND
        CT.year = PT.year AND
        CT.tid != PT.tid
ORDER BY CT.year ASC;

--Find the players who have scored more points than Michael Jordan did in a season. Print out the first name, last name, season, and how many more points they scored than Michael.

SELECT PR.firstname, PR.lastname, PR.year, PR.pts - J.pts as points_difference
FROM player_rs PR,
     (SELECT P.pts, P.year
     FROM player_rs P
     WHERE   P.ilkid = 'JORDAMI01') J
WHERE   PR.year = J.year AND
        PR.pts > J.pts;

--Find the third most successful coach in regular seasons in history, print his first name and last name, and his level of success, which is defined as season_win /(season_win + season_loss). Note that you have to count in all seasons a coach attended to calculate this value.

SELECT CS3.firstname, CS3.lastname, CS3.successLevel as success
FROM    (SELECT CS.firstname, CS.lastname, CS.sumWin::decimal/(CS.sumWin + CS.sumLoss) AS successLevel
        FROM    (SELECT C.cid, C.firstname, C.lastname, SUM(C.season_win) AS sumWin, SUM(C.season_loss) AS sumLoss
                FROM coaches_season C
                GROUP BY C.cid,C.firstname,C.lastname) CS
        ORDER BY successLevel DESC
        LIMIT 3) CS3
ORDER BY successLevel ASC
LIMIT 1;

--List the top 3 schools that sent the largest number of drafts to NBA. List the name of each school and the number of drafts sent. Order the results by number of drafts (hint: use "order by" to sort the results and 'limit xxx' to limit the number of rows returned)

SELECT draft_from, COUNT(DISTINCT ilkid)
FROM draft D
GROUP BY draft_from
ORDER BY COUNT(DISTINCT ilkid) DESC
LIMIT 3;

\o 
