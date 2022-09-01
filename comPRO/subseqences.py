def printSubSeqRec(str, n, index=0, curr=""):

  # base case
    #  if (index == n):
    #    return
    if (len(curr) > 0):
        print(curr)
    if (index == n):
        return

    i = index

    while(i < n):
        curr = curr + str[i]
        printSubSeqRec(str, n, i+1, curr)
        curr = curr[0:-1]
        i = i + 1

#  Generates power set in lexicographic order.
#  function


def printSubSeq(str):
    printSubSeqRec(str, len(str))


# // Driver code
str = "cab"
printSubSeq(str)
