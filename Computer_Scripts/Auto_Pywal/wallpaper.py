from configs import *

# Function that gets all wallpapers (images) in a given directory and returns them
def getWallpapers(directoryPath):

    # A list of strings, the names of the wallpaper files
    wallpapers = []

    # Looping over all files in the directory
    for file in os.listdir(os.fsencode(directoryPath)):
        # Getting file name
        filename = os.fsdecode(file)

        # Filtering out all filetypes we don't want
        if(isValidType(filename)):
            wallpapers.append(filename)

    # returning the list of wallpaper names
    return wallpapers

# Function that displays all wallpaper names in a given list
def displayWallpapers(wallpapers,wrapNum = 5):

    numWallpapers = len(wallpapers)
    numCols = int((numWallpapers - (numWallpapers%wrapNum))/wrapNum) + 1
    numRows = wrapNum

    # We assume the entire grid exists, and then we simply skip nonexistant elements
    # We print each row at a time
    for r in range(0,numRows):

        # initializing empty string
        s = " "

        for c in range(0,numCols):
            # Getting the index of the current wallpaper
            i = c * numRows + r

            # Skipping nonexistant elements
            if i >= numWallpapers:
                continue

            # Populating the string with the next wallpaper
            s += f"{i:2}] {strippedFileName(wallpapers[i]):20}  "
        
        # Ignoring empty strings
        if s != " ":
            print(s)

def setWallpaper(imageName, indexing = cmd_indexing):

    # Saving the two different image paths
    imagePathA = wallpaperDirectoryA + imageName
    imagePathB = wallpaperDirectoryB + imageName

    # Getting the image
    image = pywal.image.get(imagePathA)

    # Getting the colors from the image
    colors = pywal.colors.get(image, backend="colorz")
    # Exporting the colors (caching colors)
    pywal.export.every(colors)
    # Setting the wallpaper
    pywal.wallpaper.change(image)

    # Reading from default.ini as a template
    schemeLines = []
    with open(schemeDirectory + "default.ini","r") as file:
        schemeLines.append(file.readline()) # Appending the first line
        for l in file:
            schemeLines.append(l.split("=")[0] + "= ")
    
    # Creating and building the wal.ini colortool scheme file
    with open(schemeDirectory + "wal.ini","w") as file:
        file.write(schemeLines[0]) # Writing the header
        schemeLines.remove(schemeLines[0])

        for i in range(0,len(schemeLines)):
            # Every remaining line in schemeLines corresponds to a color.
            # There are 16 of these, and 16 colors from pywal. 
            # We simply map each one to another
        
            trueIndex = indexing(i)
            hexColor  = list(colors["colors"].values())[trueIndex]
            RGBColor  = hexToRGB(hexColor)
            if(i == 0):
                print(RGBColor,trueIndex)

            file.write(schemeLines[i] + RGBColor + "\n")

    # Using ColorTool and our newly created scheme to color CMD
    p = subprocess.Popen(
                [currentDirectory + "ColorTool.exe", # Specifying application
                "-b",             # Saving config to defaults
                "-q",             # Stopping Colortool from printing
                schemeDirectory + "wal.ini"],       # Specifying scheme

                stdout=sys.stdout)
    p.communicate()

    print("\nWallpaper set!\n")

    os.system("wal --preview")