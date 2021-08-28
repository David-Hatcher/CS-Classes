DROP FUNCTION harmonic(integer);
CREATE OR REPLACE FUNCTION Harmonic (n integer) RETURNS float AS $$
DECLARE
-- put your local variables here
    tempValue integer := 1;
    harmonicValue float := 0;
BEGIN
    IF n > 1000000 OR n < 1 then
        RETURN -1;
    ELSE
        LOOP
            IF tempValue > n then
                RETURN harmonicValue;
            ELSE
                harmonicValue := harmonicValue + tempValue^(-1);
                tempValue := tempValue + 1;
            END IF;
        END LOOP;
    END IF;
-- here you can fill in the function body
END;
$$ LANGUAGE plpgsql;
-- select * from Harmonic(1);
-- select * from Harmonic(2);
-- select * from Harmonic(3);
-- select * from Harmonic(10);
-- select * from Harmonic(100000);
-- select * from Harmonic(999900000);
-- select * from Harmonic(-1);
-- select * from Harmonic(0);


DROP FUNCTION player_height_rank(integer,integer);
CREATE OR REPLACE FUNCTION player_height_rank (a integer, b integer) RETURNS INTEGER AS $$
DECLARE
-- put your local variables here
    rank INTEGER := 0;
    offs INTEGER := 0;
    tempValue FLOAT := NULL;
    r record;
    count INTEGER := 0;
BEGIN
    IF a < 1 OR a > b then
        RETURN 0;
    END IF;
    FOR r IN SELECT P.firstname,P.lastname, ((P.h_feet * 12 * 2.54) + (P.h_inches * 2.54)) as h_cm
            FROM players p
            ORDER BY h_cm DESC
        LOOP

        IF r.h_cm = tempValue then
            offs := offs + 1;
        ELSE
            rank := rank + offs + 1;
            offs := 0;
            tempValue := r.h_cm;
        END IF;

        IF rank >= a AND rank <= b then
            RAISE NOTICE '% % %',r.firstname,r.lastname,r.h_cm;
            count := count + 1;
        END IF;
        IF rank > b then
            RETURN count;
        END IF;
        END LOOP;
    RETURN count;
END;
$$ LANGUAGE plpgsql;
-- select * from player_height_rank (1,2);
-- select * from player_height_rank (2,2);
-- select * from player_height_rank (2,5);
-- select * from player_height_rank (3500,5000);
-- select * from player_height_rank (12,50);
-- select * from player_height_rank (30,20);
-- select * from player_height_rank (-1,20);
-- select * from player_height_rank (0,20);
