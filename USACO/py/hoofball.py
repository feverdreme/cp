f= open('hoofball.in','r+')
cont = f.readlines()
f.close()
cont = [i.strip('\n').split() for i in cont]

"""
    this is what our algorithms is going to do :

    first we loop through max the max of cows
"""

#now create a function to keep looking through
