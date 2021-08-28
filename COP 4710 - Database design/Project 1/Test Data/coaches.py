from collections import OrderedDict

class CoachDB:
    def __init__(self):
        self.fileName = ''
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
        try:
            seasonWin = int(coach["SEASON_WIN"])
        except:
            seasonWin = 0
        try:
            seasonLoss = int(coach["SEASON_LOSS"])
        except:
            seasonLoss = 0
        try:
            playoffWin = int(coach["PLAYOFF_WIN"])
        except:
            playoffWin = 0
        try:
            playoffLoss = int(coach["PLAYOFF_LOSS"])
        except:
            playoffLoss = 0
        return (seasonWin - seasonLoss) + (playoffWin - playoffLoss)

    def isScoreInvalid(self,score):
        if score == "":
            return False
        try:
            if int(score) < 0:
                return True
        except:
            return True
        return False

    def load_coaches(self,fileName):
        s = ""
        try:
            self.fileName = fileName[0]
            #Load coaches from the text file specified on instansiation
            f = open(self.fileName,'r')
            line = f.readline().rstrip() # Removing header
            for line in f:
                x = line.split(',')
                x = list(map(lambda val: val.strip(),x))
                temp = self.add_coach(x)
                if temp != "[Coach Added!]\n":
                    s += "Error on line" + line + "\n" + temp
            f.close()
        except:
            return "[File not found!]\n"
        return "[Coaches DB loaded!]\n" + s

    def print_coaches(self):
        #Print list of all coaches
        if len(self.DB) == 0:
            return "[No coaches in DB]\n"
        s = self.getHeaders() + '\n'
        for coach in self.DB:
            s += self.stringifyCoach(coach) + '\n'
        return s

    def add_coach(self,coachData):
        #Add a coach to the DB
        if(len(coachData) != 9):
            return "[Invalid input, must have all 9 fields]\n"
        else:
            errorString = ''
            errorFlag = False
            if(len(coachData[0]) > 9 or not coachData[0].isalnum() or coachData[0].upper() != coachData[0]):
                errorFlag = True
                errorString += "coach_id is invalid\n"
            if int(coachData[1]) < 1000 or int(coachData[1]) > 3000:
                errorFlag = True
                errorString += "season is invalid\n"
            if self.isScoreInvalid(coachData[4]) or self.isScoreInvalid(coachData[5]) or self.isScoreInvalid(coachData[6]) or self.isScoreInvalid(coachData[7]):
                errorFlag = True
                errorString += "one or more of the scores are invalid\n"
            if not coachData[8].isalnum() or coachData[8].upper() != coachData[8]:
                errorFlag = True
                errorString += "the team is invalid\n"
            if not errorFlag:
                self.DB.append(self.createCoach(coachData))
                return "[Coach Added!]\n"
            else:
                errorString += "\nInput Data has the following constraints:\n\nCoach_ID : consists of 7 or less capital letters and two digits\nseason : 4 digit year,first_name : any reasonable English name \nlast_name : any reasonable English name\nseason_win : non-negative integer\nseason_loss : non-negative integer\nplayoff_win : non-negative integer\nplayoff_loss : non-negative integer\nteam : capital letters and/or digits\n"
                return errorString

    def remove_coach(self,fields,params):
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
        #Finds coaches who have a specified first name
        fields = ["FIRST_NAME"]
        params = [name[0]]
        s = ""
        for coach in self.DB:
            if self.doesCoachMatch(coach,fields,params):
                s += self.stringifyCoach(coach) + '\n'
        return s

    def best_coach(self,season):
        fields = ["SEASON"]
        params = [season[0]]
        #Finds the coach with the best score
        bestCoach = self.createCoach(['Null','Null','No','Coaches Found!','-10000','10000','-10000','10000','Null'])
        bestCoachScore = self.calcCoachScore(bestCoach)
        for coach in self.DB:
            if self.doesCoachMatch(coach,fields,params) and self.calcCoachScore(coach) > bestCoachScore:
                bestCoach = coach
                bestCoachScore = self.calcCoachScore(bestCoach)
        return "".join(bestCoach["FIRST_NAME"] + " " + bestCoach["LAST_NAME"] + '\n')

    def search_coaches(self,params,fields):
        s = ""
        for coach in self.DB:
            if self.doesCoachMatch(coach,params,fields):
                s += self.stringifyCoach(coach) + '\n'
        return s

    def doesCoachMatch(self,coach,fields,params):
        #helper function, tests if a coach matches the given parameters
        isMatch = True
        for field,param in zip(fields,params):
            if field in coach:
                if coach[field] != param:
                    isMatch = False
        return isMatch