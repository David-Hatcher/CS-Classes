from collections import OrderedDict

class TeamDB:
    def __init__(self):
        self.DB = list()

    def createTeam(self,teamData):
        team = OrderedDict()
        team["TEAM_ID"] = teamData[0]
        team["LOCATION"] = teamData[1]
        team["NAME"] = teamData[2]
        team["LEAGUE"] = teamData[3]
        return team

    def stringifyTeam(self,team):
        return "".join(value.ljust(12) for value in team.values())

    def stringifyHeader(self):
        return "".join(key.ljust(12) for key in self.DB[0].keys())

    def doesTeamMatch(self,team,fields,params):
            #helper function, tests if a coach matches the given parameters
        isMatch = True
        for field,param in zip(fields,params):
            if field in team:
                if team[field] != param:
                    isMatch = False
            else:
                isMatch = False
        return isMatch

    def load_teams(self, fileName):
        #Loads teams
        s = ""
        try:
            self.fileName = fileName[0]
            f = open(self.fileName,'r')
            line = f.readline().rstrip() # Removing header
            for line in f:
                x = line.split(',')
                x = list(map(lambda val: val.strip(),x))
                temp = self.add_team(x)
                if temp != "[Team added!]\n":
                    s += "Error on line " + line + "\n" + temp
            f.close()
            return "[Teams Loaded!]\n" + s
        except:
            return "[File not found!]\n"

    def print_teams(self):
        #print teams to the console
        if len(self.DB) == 0:
            return "[No teams in DB]\n"
        s = self.stringifyHeader() + '\n'
        for team in self.DB:
            s += self.stringifyTeam(team)  + '\n'
        return s

    def add_team(self,teamData):
        #Add a team with specified values
        if len(teamData) != 4:
            return "Invalid input, must have all 4 fields\n"
        else:
            errorString = ''
            errorFlag = False
            if not teamData[0].isalnum() or teamData[0].upper() != teamData[0]:
                errorFlag = True
                errorString += 'team_id invalid'
            if len(teamData[3]) != 1 or not teamData[3].isalpha() or teamData[3].upper() != teamData[3]:
                errorFlag = True
                errorString += 'league is invalid'
            if not errorFlag:
                self.DB.append(self.createTeam(teamData))
                return "[Team added!]\n"
            else:
                errorString += '\nInput Data has the following constraints:\n\nteam_ID : capital letters and/or digits\nLocation : American City name, one or two English word(s)\nName : team name, any reasonable English word\nLeague : one capital letter\n'
                return errorString

    def remove_team(self,fields,params):
        #Remove a Team from the DB
        removalList = []
        for i in range(0,len(self.DB)):
            team = self.DB[i]
            if self.doesTeamMatch(team,fields,params) == True:
                removalList.append(i)
        if len(removalList):
            removalList.sort()
            removalList.reverse()
            for index in removalList:
                self.DB.pop(index)
            return "[Team(s) Removed!]\n"
        return "[No Teams Found!]\n"

    def teams_by_city_league(self,params):
        #print teams by city and league
        fields = ["LOCATION","LEAGUE"]
        s = ""
        for team in self.DB:
            if self.doesTeamMatch(team,fields,params):
                s += self.stringifyTeam(team) + '\n'
        return s