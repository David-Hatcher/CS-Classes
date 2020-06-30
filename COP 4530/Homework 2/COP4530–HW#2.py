songsCount = 0
class Song:
    def __init__(self,name,next = None, prev = None):
        self.name = name
        self.next = next
        self.prev = prev
        global songsCount
        songsCount += 1

class Album:
    def __init__(self,name,head = None, tail = None):
        self.name = name
        self.head = head
        self.tail = tail
        self.songList = []
        self.songOrderList = []
    def addSong(self,song):
        self.songList.append(Song(song))
    def buildList(self):
        for i in range(0,len(self.songOrderList)):
            for j in range(0,len(self.songList)):
                if(self.songList[j].name == self.songOrderList[i]):
                    if(i == 0):
                        self.head = self.songList[j]
                    else:
                        if(self.tail == None):
                            self.tail = self.songList[j]
                            self.songList[j].prev = self.head
                            self.head.next = self.songList[j]
                        else:
                            self.tail.next = self.songList[j]
                            self.songList[j].prev = self.tail
                            self.tail = self.songList[j]
                    break
                    
class MusicPlayer:
    def __init__(self,albums):
        self.albums = albums
        self.currentAlbum = None
        self.currentSong = None
        self.playNextTrackCount = 0
    def playNextTrack(self):
        if(self.currentSong.next != None):
            self.currentSong = self.currentSong.next
            return "Now Playing: " + self.currentSong.name
        else:
            return "No next song."
    def skipBack(self):
        if(self.currentSong.prev != None):
            self.currentSong = self.currentSong.prev
            return "Now at: " + self.currentSong.name
        else:
            return "No previous song."
        pass
    def skipForward(self):
        if(self.currentSong.next != None):
            self.currentSong = self.currentSong.next
            return "Now at: " + self.currentSong.name
        else:
            return "No next song."
    def gotoBeginning(self):
        while(self.currentSong.prev != None):
            self.currentSong = currentSong.prev
        return "Now at: " + self.currentSong.name
        pass
    def gotoEnd(self):
        while(self.currentSong.next != None):
            self.currentSong = self.currentSong.next
        return "Now at " + self.currentSong.name
    def changeAlbum(self,albumName):
        for i in range(0,len(albums)):
            if(self.albums[i].name == albumName):
                self.currentAlbum = self.albums[i]
        return "Changed to Album " + self.currentAlbum.name

songsFile = "C:\\Users\\salla\\Desktop\\CS-Classes\\COP 4530\\Homework 2\\HW2Songs.txt"
albumsFile = "C:\\Users\\salla\\Desktop\\CS-Classes\\COP 4530\\Homework 2\\HW2Albums.txt"
commandsFile = "HW2Commands.txt"


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

def buildAlbumLinkedLists(albumCase):
    for album in albumCase:
        album.buildList()

albumCase = []

buildAlbums(albumCase,songsFile)
buildAlbumOrderList(albumCase,albumsFile)
buildAlbumLinkedLists(albumCase)




#Traversing testing Delete once finished#########################
# first = None
# for album in albumCase:
#     print(album.name,"Double Linked list Order")
#     print()
#     first = album.head
#     while(first.next != None):
#         print(first.name)
#         first = first.next
#     print(first.name)
#     print()
#     print("Reversing List")
#     print()
#     while(first.prev != None):
#         print(first.name)
#         first = first.prev

#     print(first.name)
#     print()

# print(songsCount)