import time
#start timer
start = time.time()
#counter initializations
skipFCount = 0
skipBcount = 0
playNextCount = 0
appendCount = 0
beginningCount = 0
endCount = 0
songsCount = 0
import sys
if len(sys.argv) != 4:
    raise ValueError('Please provide three file names.')

sys.argv[0] = sys.argv[0][0:len(sys.argv[0]) - sys.argv[0][::-1].find('/')]
inputFile1 = sys.argv[0]+sys.argv[1] 
inputFile2 = sys.argv[0]+sys.argv[2] 
inputFile3 = sys.argv[0]+sys.argv[3] 
print("\nThe files that will be used for input are {0}, {1}, and {2}\n\n".format(sys.argv[1],sys.argv[2],sys.argv[3]))


#Song class is used for the individual nodes in the linked list
class Song:
    def __init__(self,name,next = None, prev = None):
        self.name = name
        self.next = next
        self.prev = prev
        global songsCount

# Album class is the actual linked list 
class Album:
    def __init__(self,name,head = None, tail = None):
        #name of the album
        self.name = name
        #first node in the album
        self.head = head
        #last node in the album
        self.tail = tail
        #list of song nodes
        self.songList = []
        #order of songs in album
        self.songOrderList = []
    #addSong is used to create the initial list of song nodes in no particular order
    def addSong(self,song):
        self.songList.append(Song(song))
    #buildList orders the nodes depending on the album list provided for each album
    def buildList(self):
        global appendCount,songsCount
        #looping through both the ordered song list and the list of song nodes to order the nodes
        for i in range(0,len(self.songOrderList)):
            for j in range(0,len(self.songList)):
                #if the songs match we will attach them in the nodelist
                if(self.songList[j].name == self.songOrderList[i]):
                    #increment append counter
                    appendCount += 1
                    #increment global variable every time a song is instansiated
                    songsCount += 1
                    #check if it's the first song
                    if(i == 0):
                        self.head = self.songList[j]
                    #if it's not the first song
                    else:
                        #checks if it's the second song so it can throw it on tail
                        if(self.tail == None):
                            self.tail = self.songList[j]
                            self.songList[j].prev = self.head
                            self.head.next = self.songList[j]
                        #all other songs will use this to add to tail giving the append function an O(1)
                        else:
                            self.tail.next = self.songList[j]
                            self.songList[j].prev = self.tail
                            self.tail = self.songList[j]
                    break
#this is the class used to make the playlist this assumes the playlist will always
#be last as the nodes next and prev will need to be changed
class Playlist:
    def __init__(self,name = "Playlist",head = None,tail = None):
        #name of the playlist
        self.name = name
        #first node in the playlist
        self.head = head
        #last node in the playlist
        self.tail = tail
    #append adds the node into the last position in the nodelist
    def append(self,song):
        #if the node is the first to be added
        if(self.head == None):
            self.head = song
        #all other nodes
        else:
            #if the node is the second node in the list
            if(self.tail == None):
                self.tail = song
                song.prev = self.head
                self.head.next = song
                self.tail.next = None
            #all other nodes 
            else:
                song.prev = self.tail
                self.tail.next = song
                self.tail = song
                self.tail.next = None
        
#MusicPlayer is used to store the albums and playlists
class MusicPlayer:
    def __init__(self,albums):
        #array of all albums
        self.albums = albums
        #current album being played
        self.currentAlbum = None
        #current song being played
        self.currentSong = None
    #playNextTrack will play the next track in the list as per instructions
    #if there are no more songs then it will return that information
    def playNextTrack(self):
        return "Now Playing: " + self.currentSong.name
    #skipBack skips backwards to the previous track, if no prev track it will return that info
    def skipBack(self):
        if(self.currentSong.prev != None):
            self.currentSong = self.currentSong.prev
            return "Now at: " + self.currentSong.name
        else:
            return "No previous song."
    #skipForward will skip to the next track, if no next track it will return that info
    def skipForward(self):
        if(self.currentSong.next != None):
            self.currentSong = self.currentSong.next
            return "Now at: " + self.currentSong.name
        else:
            return "No next song."
    #gotoBeginning goes to the beginning of the album O(1)
    def gotoBeginning(self):
        self.currentSong = self.currentAlbum.head
        return "Now at: " + self.currentSong.name
    #goToEnd goes to the end of the album O(1)
    def gotoEnd(self):
        self.currentSong = self.currentAlbum.tail
        return "Now at: " + self.currentSong.name
    #changeAlbum changes to a new album
    def changeAlbum(self,albumName):
        for i in range(0,len(self.albums)):
            if(self.albums[i].name == albumName.strip()):
                self.currentAlbum = self.albums[i]
                self.currentSong = self.currentAlbum.head
                break
        return "Changed to Album " + self.currentAlbum.name + '\n'
    #build playlist will build the playlist when it's called
    def buildPlayList(self,playList):
        self.playListAlbum = Playlist()
        for song in playList:
            albumNum = song[0] - 1
            songAlbum = self.albums[albumNum]
            index = songAlbum.songList
            for i in range(0,len(index)):
                if song[1] == index[i].name:
                    self.playListAlbum.append(index[i])
                    break
        self.albums.append(self.playListAlbum)
        return self.changeAlbum("Playlist")
    #getPlaylist gets the playlist information
    def getPlayList(self,fileName):
        readFile = open(fileName)
        playList = []
        playListFlag = False
        for line in readFile:
            if playListFlag == True:
                playList.append((int(line[0]),line[1:len(line)].strip('\n')))
            if "Playlist" in line:
                playListFlag = True
        readFile.close()
        return playList
    #processCommand will process each command it's given
    def processCommand(self,input):
        global beginningCount, endCount, skipFCount, playNextCount,skipBcount
        if("Beginning" in input):
            beginningCount += 1
            return self.gotoBeginning()
        elif("End" in input):
            endCount += 1
            return self.gotoEnd()
        elif("Skip Forward" in input):
            skipFCount += 1
            return self.skipForward()
        elif("Play Track" in input):
            playNextCount += 1
            return self.playNextTrack()
        elif("Skip Backward" in input):
            skipBcount += 1
            return self.skipBack()
        elif("Album" in input):
            return self.changeAlbum(input[7:len(input)])
        elif("Playlist" in input):
            return self.buildPlayList(self.getPlayList(songsFile))
        else:
            return '\n'
    
        
#creating file names from the runtime args
songsFile = str(sys.argv[1])
albumsFile = str(sys.argv[2])
commandsFile = str(sys.argv[3])

#buildAlbums will build the initial list of song nodes
def buildAlbums(albums,songsFileName):
    fileRead = open(songsFileName,'r')
    lines = []
    for line in fileRead:
        lines.append(line.strip('\n'))
    fileRead.close()
    currentAlbum = None
    for line in lines:
        if "Album:" in line:
            albumName = line[7:len(line)]
            currentAlbum = Album(albumName)
        elif "Playlist" not in line and line != '':
            currentAlbum.addSong(line)
        elif "Playlist" in line:
            break
        else:
            albums.append(currentAlbum)
#buildAlbumOrderList will build the list to use to order the nodes
def buildAlbumOrderList(albums,albumsFileName):
    fileRead = open(albumsFileName,'r')
    albumOrders = []
    for line in fileRead:
        albumOrders.append(line.strip('\n'))
    currentAlbum = None
    for orderedSong in albumOrders:
        if "Album:" in orderedSong:
            albumName = orderedSong[7:len(orderedSong)]
            for album in albums:
                if albumName == album.name:
                    currentAlbum = album
        else:
            if orderedSong != '':
                currentAlbum.songOrderList.append(orderedSong)

#buildAlbumLinkedLists will build all the linked lists out for each album
def buildAlbumLinkedLists(albumCase):
    for album in albumCase:
        album.buildList()

#getCommands will grab the commands list
def getCommands(commandsFile):
    readFile = open(commandsFile,'r')
    commands = []
    for line in readFile:
        commands.append(line)
    return commands

#stores the list of albums to be added into the musicplayer object
albumCase = []

#build the album node lists
buildAlbums(albumCase,songsFile)
buildAlbumOrderList(albumCase,albumsFile)
buildAlbumLinkedLists(albumCase)


#creating the MusicPlayer object loaded with albums
player = MusicPlayer(albumCase)

#get the commands
commands = getCommands(commandsFile)

#runs each command
for command in commands:
    print(player.processCommand(command))
end = time.time()
print('\n\n********************')
print('**** Statistics ****')
print('********************', end = '\n\n')

print("Total Songs Read: ",songsCount)
print("Number of Skip Forward Commands: ",skipFCount)
print("Number of Skip Backward Commands: ",skipBcount)
print("Number of Play Next Track Commands: ",playNextCount)
print("Number of Append Commands",appendCount)
print("Number of Beginning Forward Commands: ",beginningCount)
print("Number of End Forward Commands: ",endCount)
print("Total Time of Program: {:.8f} milliseconds".format(end-start))


