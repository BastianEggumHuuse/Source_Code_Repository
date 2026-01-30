# Importing rest of program (unity build)
from wallpaper import *

def wallPaperSequence():
    
    # Getting the wallpapers
    wallpapers = getWallpapers(wallpaperDirectoryA)
    strippedWallpapers = [strippedFileName(w) for w in wallpapers]

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
        setWallpaper(wallpapers[response],pws_indexing)
        return
    except ValueError:
        pass

    # Or it's a name:
    if response in strippedWallpapers:
        setWallpaper(wallpapers[strippedWallpapers.index(response)],pws_indexing)
        return

    # If we get here, somethings wrong...
    print(f"\nThe wallpaper {response} does not exist!!\n")

def main(args):

    wallPaperSequence()