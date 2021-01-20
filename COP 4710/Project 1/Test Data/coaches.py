from collections import OrderedDict

class CoachDB:
    def __init__(self):
        self.fileName = ''
        self.DBInit = False
        self.DB = list()

    def getFileName(self):
        #Getter, not really needed
        return self.fileName

    def doesCoachMatch(self,coach,fields,params):
        #helper function, tests if a coach matches the given parameters
        isMatch = True
        for field,param in zip(fields,params):
            if field in coach:
                if coach[field] != param:
                    isMatch = False
        return isMatch

    def createCoach(self,coachData):
        #Helper function to create a coach from given data
        coach = OrderedDict()
        coach["COACH_ID"] = coachData[0]
        coach["SEASON"] = coachData[1]
        coach["FIRST_NAME"] = coachData[2]
        coach["LAST_NAME"] = coachData[3]
        coach["SEASON_WIN"] = coachData[4]
        coach["SEASON_LOSS"] = coachData[5]
        coach["PLAYOFF_WIN"] = coachData[6]
        coach["PLAYOFF_LOSS"] = coachData[7]
        coach["TEAM"] = coachData[8]
        return coach
    def stringifyCoach(self,coach):
        #Helper function: Return formatted string of coaches name
        return "".join(value.ljust(13) for value in coach.values())

    def getHeaders(self):
        #Helper function: Return formatted string of header values
        return "".join(key.ljust(13) for key in self.DB[0].keys())

    def calcCoachScore(self,coach):
        #Helper Function: Calculate the score of a single coach
        return (int(coach["SEASON_WIN"]) - int(coach["SEASON_LOSS"])) + (int(coach["PLAYOFF_WIN"]) - int(coach["PLAYOFF_LOSS"]))

    def load_coaches(self,fileName):
        try:
            self.fileName = fileName[0]
            #Load coaches from the text file specified on instansiation
            f = open(self.fileName,'r')
            line = f.readline().rstrip() # Removing header
            for line in f:
                x = line.split(',')
                x = list(map(lambda val: val.strip(),x))
                self.DB.append(self.createCoach(x))
            self.DBInit = True
            f.close()
        except:
            return "[File not found!]\n"
        return "[Coaches DB loaded!]\n"

    def print_coaches(self):
        if not self.DBInit:
            return "[DB not loaded!]\n"
        #Print list of all coaches
        s = self.getHeaders() + '\n'
        for coach in self.DB:
            s += self.stringifyCoach(coach) + '\n'
        return s

    def add_coach(self,coachData):
        if not self.DBInit:
            return "[DB not loaded!]\n"
        #Add a coach to the DB
        if(len(coachData) != 9):
            return "[Invalid input, must have all 9 fields]\n"
        else:
            self.DB.append(self.createCoach(coachData))
            return "[Coach Added!]\n"

    def remove_coach(self,fields,params):
        if not self.DBInit:
            return "[DB not loaded!]\n"
        #Remove a coach from the DB
        removalList = []
        for i in range(0,len(self.DB)):
            coach = self.DB[i]
            if self.doesCoachMatch(coach,fields,params) == True:
                removalList.append(i)
        if len(removalList):
            removalList.sort()
            removalList.reverse()
            for index in removalList:
                self.DB.pop(index)
            return "[Coach(es) removed!]\n"
        return "[No Coaches Found]\n"

    def coaches_by_name(self,name):
        if not self.DBInit:
            return "[DB not loaded!]\n"
        #Finds coaches who have a specified first name
        fields = ["FIRST_NAME"]
        params = [name[0]]
        s = ""
        for coach in self.DB:
            if self.doesCoachMatch(coach,fields,params):
                s += self.stringifyCoach(coach) + '\n'
        return s

    def best_coach(self,season):
        if not self.DBInit:
            return "[DB not loaded!]\n"
        fields = ["SEASON"]
        params = [season[0]]
        #Finds the coach with the best score
        bestCoach = self.createCoach(['Null','Null','Null','Null','-10000','10000','-10000','10000','Null'])
        bestCoachScore = self.calcCoachScore(bestCoach)
        for coach in self.DB:
            if self.doesCoachMatch(coach,fields,params) and self.calcCoachScore(coach) > bestCoachScore:
                bestCoach = coach
                bestCoachScore = self.calcCoachScore(bestCoach)
        return "".join(bestCoach["FIRST_NAME"] + " " + bestCoach["LAST_NAME"] + '\n')

    def search_coaches(self,params,fields):
        if not self.DBInit:
            return "[DB not loaded!]\n"
        s = ""
        for coach in self.DB:
            if self.doesCoachMatch(coach,params,fields):
                s += self.stringifyCoach(coach) + '\n'
        return s