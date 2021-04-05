----------------------- #1------------------------

CREATE OR REPLACE FUNCTION get_height (firstn VARCHAR, lastn VARCHAR) RETURNS float AS $$
DECLARE
   height float := 0.0;
BEGIN

select into height (P.h_feet *12*2.54 + P.h_inches *2.54) 
from players as P 
where P.firstname=$1 and P.lastname=$2;

--check for null result
IF height IS NULL
THEN
return 0.0;

ELSE
return height;

END IF;

END;
$$ LANGUAGE plpgsql;


---------------#2---------------


CREATE OR REPLACE FUNCTION get_coach_rank (year INTEGER,firstn VARCHAR, lastn VARCHAR) RETURNS INTEGER AS $$
DECLARE
   rank INTEGER := 0;
   offs INTEGER := 0;
   tempValue INTEGER := NULL;
   r record;
BEGIN

FOR r IN SELECT (CS.season_win + CS.playoff_win - CS.season_loss - CS.playoff_loss) as netWin,CS.firstname, CS.lastname , CS.year
	FROM coaches_season CS
	WHERE CS.year = $1
	ORDER BY netwin DESC
    LOOP
    
	IF r.netWin = tempValue then
		offs := offs +1;
	ELSE
		rank := rank + offs + 1;
		offs := 0;
		tempValue := r.netWin;
	END IF;

        IF r. lastname = $3 AND r.firstname = $2 THEN
		RETURN rank;
	END IF;
    END LOOP;

--not in DB    
RETURN -1;

END;
$$ LANGUAGE plpgsql;
