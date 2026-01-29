import pywal

import sys
import os
import subprocess

wallpaperDirectoryA = "C:/Users/Bastian/Pictures/Wallpapers_A/"
wallpaperDirectoryB = "C:/Users/Bastian/Pictures/Wallpapers_B/"

imageTypes = [
    ".png",
    ".jpeg",
    ".jpg"
]

# Short helping function that determins if a file is of a certain type
def isValidType(filename):
    for type in imageTypes:
        if(filename.endswith(type)):
            return True
    return False

# Short helping function that returns a filename without the extension
def strippedFileName(filename):
    for type in imageTypes:
        if(filename.endswith(type)):
            return filename.strip(type)
    return filename

# Short helping function that turns a hex color (string) into an RGB color (string)
def hexToRGB(hex):
    hex = hex.strip("#") # Removing the hash
    R = int(hex[0:2],16)
    G = int(hex[2:4],16)
    B = int(hex[4:6],16)
    return f"{R},{G},{B}"

# Function that gets all wallpapers (images) in a given directory and returns them
def getWallpapers(directoryPath = wallpaperDirectoryA):

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

def setWallpaper(imageName):

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
    with open("schemes/default.ini","r") as file:
        schemeLines.append(file.readline()) # Appending the first line
        for l in file:
            schemeLines.append(l.split("=")[0] + "= ")
    
    # Creating and building the wal.ini colortool scheme file
    with open("schemes/wal.ini","w") as file:
        file.write(schemeLines[0]) # Writing the header
        schemeLines.remove(schemeLines[0])

        for i in range(0,len(schemeLines)):
            # Every remaining line in schemeLines corresponds to a color.
            # There are 16 of these, and 16 colors from pywal. 
            # We simply map each one to another
        
            file.write(schemeLines[i] + hexToRGB(list(colors["colors"].values())[i]) + "\n")

    # Using ColorTool and our newly created scheme to color CMD
    p = subprocess.Popen(
                ["ColorTool.exe", # Specifying application
                "-b",             # Saving config to defaults
                "-q",             # Stopping Colortool from printing
                "wal.ini"],       # Specifying scheme

                stdout=sys.stdout)
    p.communicate()

    print("\nWallpaper set!\n")

    os.system("wal --preview")

# Function that sets up autocomplete in terminal for a given list of wallpapers
def setupAutocomplete(wallpapers):

    # Creating list of stripped wallpapers
    strippedWallpapers = [strippedFileName(w) for w in wallpapers]

    # Ok so turns out the application i wanted to use doesn't exist on windows...
    # Ill reimplement this in the future i swear
    """
    # Code stolen from the web:

    # Creating a function that autocompletes text that has the beginning of a given word
    def completer(text, state):
        options = [i for i in strippedWallpapers if i.startswith(text)]
        if state < len(options):
            return options[state]
        else:
            return None

    # Adding completer
    readline.parse_and_bind("tab: complete")
    readline.set_completer(completer)
    """

    # Returning stripped wallpapers (we need these later)
    return strippedWallpapers


def main():
    
    # Getting the wallpapers
    wallpapers = getWallpapers()
    strippedWallpapers = setupAutocomplete(wallpapers)

    # Displaying wallpapers
    print("\nDisplaying avaliable wallpapers:\n")
    displayWallpapers(wallpapers)
    print(f"\nPlease select a wallpaper either by name, or number [0, {len(wallpapers)-1}]")
    
    # Collecting response from user
    response = input("> ")

    # User has two possible responses. Either it is a number:
    try:
        response = int(response)

        # Handling bounds issues
        if(response >= len(wallpapers) or response < 0):
            print(f"\nNumber must be within the range [0, {len(wallpapers)-1}]")
            return

        # Setting wallpaper
        setWallpaper(wallpapers[response])
        return
    except:
        pass

    # Or it's a name:
    if response in strippedWallpapers:
        setWallpaper(wallpapers[strippedWallpapers.index(response)])
        return

    # If we get here, somethings wrong...
    print(f"\nThe wallpaper {response} does not exist!!\n")

if __name__ == "__main__":
    main()
