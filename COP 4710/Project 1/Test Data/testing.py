from coaches import CoachDB
from teams import TeamDB

# c = CoachDB("c.txt")
# c.load_coaches()
# s = c.print_coaches()
# print(s)
# c.add_coach(["KERR01","2015","Steve","Kerr","73","9","15","9","GSW"])
# s = c.print_coaches()
# print(s)
# c.add_coach(["KERR01","2016","Steve","Kerr","67","15","16","1","GSW"])
# s = c.print_coaches()
# print(s)
# rfields = ["COACH_ID","SEASON","FIRST_NAME"]
# rparams = ["BEGIN01","1993","John"]
# c.remove_coach(rfields,rparams)
# s = c.print_coaches()
# print("Print Coaches\n",s)
# s = c.coaches_by_name("Steve")
# print("Coaches by name Steve\n",s)
# s = c.coaches_by_name(["John"])
# print("Coaches by name John\n",s)
# s = c.best_coach(["1993"])
# print("best coach 1993\n",s)
# sfields = ["FIRST_NAME","SEASON_WIN"]
# sparams = ["Steve","73"]
# s = c.search_coaches(sfields,sparams)
# print("Search Coaches season=1993\n",s)

# t = TeamDB("t.txt")
# t.load_teams()
# print(t.print_teams())
# t.add_team(["TB1", "Tampa", "Bulls", "N"])
# s = t.print_teams()
# print(s)
# t.remove_team(["TEAM_ID"],["END"])
# s = t.print_teams()
# print(s)