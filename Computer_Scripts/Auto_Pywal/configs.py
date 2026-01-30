from header import *

def cmd_indexing(i):
    return i

def pws_indexing(i):
    # Powershell uses dark cyan as it's background, instead of black
    # We swap these to keep uniformity with cmd (and some others)

    pws_indexes = [
        1, #0
        5, #1
        2, #2
        3, #3
        7, #4
        0, #5
        6, #6
        4  #7
    ]

    if(i >= 8):
        return pws_indexes[i-8] + 8
    return pws_indexes[i]

    # From cyan to black
    if(i == 5):
        #print("TURNING BLACK",i,i-3)
        return 0

    # From black to cyan
    if(i == 0):
        #print("TURNING CYAN",i,i+3)
        return 5
    
    return i