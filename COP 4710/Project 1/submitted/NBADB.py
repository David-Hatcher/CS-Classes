from coaches import CoachDB
from teams import TeamDB


class NBADBApp:
    def __init__(self):
        self.c = CoachDB()
        self.t = TeamDB()

    def getInput(self):
        return input()

    def splitInput(self,input):
        inputArr = input.split()
        return inputArr

    def getCommand(self,inputArr):
        return inputArr[0]

    def getParams(self,inputArr):
        return inputArr[1:]

    def splitFields(self,paramsArray):
        fields = list()
        params = list()
        for val in paramsArray:
            arr = val.split("=")
            fields.append(arr[0].upper())
            params.append(arr[1].replace("+"," "))
        return (fields,params)

    def runCommand(self,inputArr):
        command = self.getCommand(inputArr)
        propsList = self.getParams(inputArr)
        if command == "add_coach":
            print(self.c.add_coach(propsList))
        elif command == "add_team":
            print(self.t.add_team(list(map(lambda x: x.replace("+"," "),propsList))))
        elif command == "load_coaches":
            print(self.c.load_coaches(propsList))
        elif command == "remove_coach":
            fields,params = self.splitFields(propsList)
            print(self.c.remove_coach(fields,params))
        elif command == "load_teams":
            print(self.t.load_teams(propsList))
        elif command == "remove_team":
            fields,params = self.splitFields(propsList)
            print(self.t.remove_team(fields,params))
        elif command == "print_coaches":
            print(self.c.print_coaches())
        elif command == "print_teams":
            print(self.t.print_teams())
        elif command == "coaches_by_name":
            print(self.c.coaches_by_name(propsList))
        elif command == "teams_by_city_league":
            print(self.t.teams_by_city_league(list(map(lambda x: x.replace("+"," "),propsList))))
        elif command == "best_coach":
            print(self.c.best_coach(propsList))
        elif command == "search_coaches":
            fields,params = self.splitFields(propsList)
            print(self.c.search_coaches(fields,params))
        elif command == "help":
            self.doHelp()
        else:
            print("Invalid Command please try again!")

    def doHelp(self):
        print("add_coach ID SEASON FIRST_NAME LAST_NAME SEASON_WIN")
        print("SEASON_LOSS PLAYOFF_WIN PLAYOFF_LOSS TEAM - add new coach data")
        print("add_team ID LOCATION NAME LEAGUE - add a new team")
        print("print_coaches - print a listing of all coaches")
        print("print_teams - print a listing of all teams")
        print("remove_coach coach_ID - remove an existing record in coaches by ID")
        print("remove_team team_ID - remove an existing record in teams by ID")
        print("coaches_by_name NAME - list info of coaches with the specified name")
        print("teams_by_city CITY - list the teams in the specified city")
        print("load_coach FILENAME - bulk load of coach info from a file")
        print("load_team FILENAME - bulk load of team info from a file")
        print("best_coach SEASON - print the name of the coach with the most netwins in a specified season")
        print("search_coaches field=VALUE - print the name of the coach satisfying the specified conditions")
        print("exit - quit the program\n")

    def doIntro(self):
        print("The mini-DB of NBA coaches and teams")
        print("Please enter a command.  Enter 'help' for a list of commands.\n")

def main():
    n = NBADBApp()
    n.doIntro()
    while(True):
        print(">",end="")
        userInput = n.getInput()
        print("-"*(len(userInput)+1) + '\n')
        if userInput == "exit":
            break
        elif userInput == "":
            print("Please enter a command")
            continue
        inputArr = n.splitInput(userInput)
        n.runCommand(inputArr)

main()