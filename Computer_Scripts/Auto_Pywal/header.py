# Packages we need
import pywal
import sys
import os
import subprocess

wallpaperDirectoryA = "C:/Users/Bastian/Pictures/Wallpapers_A/"
wallpaperDirectoryB = "C:/Users/Bastian/Pictures/Wallpapers_B/"
currentDirectory    = "C:/Users/Bastian/Documents/GitHub/Source_Code_Repository/Computer_Scripts/Auto_Pywal/"
schemeDirectory     = currentDirectory + "schemes/"

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
