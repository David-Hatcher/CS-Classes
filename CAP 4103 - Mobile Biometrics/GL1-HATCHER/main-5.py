import numpy as np
from sys import exit

# Class for holding the Jenga tower and getting R values
class Jenga:
    def __init__(self):
        self.SP = 100
    def removeRFromSP(self,r):
        self.SP = self.SP - r
    def getSP(self):
        return self.SP
    def isTowerStanding(self):
        return (self.SP > 0)
    def getSPPercent(self):
        return "{}%".format(self.getSP())
    def getRPercent(self,r):
        return "{}%".format(int((r/10)*100))
    def getRandomIntBetween(self,min,max):
        return np.random.randint(min,max+1)
    def getR(self,choice):
        if choice.upper() == "H":
            return self.getRandomIntBetween(8,10)
        elif choice.upper() == "M":
            return self.getRandomIntBetween(4,7)
        elif choice.upper() == "L":
            return self.getRandomIntBetween(0,3)
        else:
            return self.getRandomIntBetween(0,10)

# Helper class for computer logic to determine what move to take
class Computer:
    def __init__(self):
        pass
    def chooseRisk(self,jenga):
        currentSP = jenga.getSP()
        if(currentSP > 75):
            return "H"
        elif(currentSP > 25):
            return "M"
        else:
            return "L"

# Helper class for IOStream to offload this duty from the Game object
class IOStream:
    def __init__(self):
        pass
    def output(self,string):
        print(string, end="")
    def getInput(self):
        return input()

# Class for the game itself
class Game:
    def __init__(self):
        self.jenga = Jenga()
        self.computer = Computer()
        self.io = IOStream()
        self.startGame()
    def startGame(self):
        self.io.output("Let's Play JENGA!\n\n")
        self.roundCount = 0
        self.runGame()
    def getRiskString(self,riskPercent):
        return "This move was {} risky!\n\n".format(riskPercent)
    def pullPiece(self):
        if self.currentPlayer == "C":
            self.io.output("Computer's turn...\n")
            riskChoice = self.computer.chooseRisk(self.jenga)
        elif self.currentPlayer == "P":
            self.io.output("Your turn. Enter L, M, or H: ")
            riskChoice = self.io.getInput()
        riskNum = self.jenga.getR(riskChoice)
        self.jenga.removeRFromSP(riskNum)
        self.io.output(self.getRiskString(self.jenga.getRPercent(riskNum)))
    def handleTurn(self):
        self.pullPiece()
        winnerFound = self.checkForWinner()
        self.switchCurrentPlayer()
        return winnerFound
    def runGame(self):
        self.currentPlayer = "C"
        while self.jenga.isTowerStanding():
            self.roundCount += 1
            self.showRoundHeader()
            for _ in range(2):
                gameOver = self.handleTurn()
                if gameOver:
                    break
    def showRoundHeader(self):
        self.io.output( "----------\n" +
                        "ROUND {0}: PROB OF TOWER STANDING: {1}\n".format(self.roundCount, self.jenga.getSPPercent()) +
                        "----------\n" )
    def switchCurrentPlayer(self):
        if self.currentPlayer == "C":
            self.currentPlayer = "P"
        elif self.currentPlayer == "P":
            self.currentPlayer = "C"
    def checkForWinner(self):
        if not self.jenga.isTowerStanding():
            if self.currentPlayer == "C":
                self.io.output("Fuck yeah! The computer's move caused the tower to fall! YOU WIN!\n\n")
            if self.currentPlayer == "P":
                self.io.output("OH NO! Your move caused the tower to fall! YOU LOSE!\n\n")
            return True
        return False

Game()