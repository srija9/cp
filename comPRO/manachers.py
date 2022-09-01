def update_string(string):
    newString = ['#']
    for i in string:
        newString += [i, '#']
    return ''.join(newString)

def manacher(string):
    string = update_string(string)
    LPS = [0 for _ in range(len(string))]
    C=0
    R=0

    for i in range(len(string)):
        iMirror = 2*C - i
        if(R>i):
            LPS[i] = min(R-i, LPS[iMirror])
        else:
            LPS[i] = 0
        try:
            while(string[i+1+LPS[i]] == string[i-1-LPS[i]]):
                LPS[i] += 1
        except:
            pass

        if(i+LPS[i] > R):
            C = i
            R = i+LPS[i]

    r, c = max(LPS), LPS.index(max(LPS))
    print(string[c-r : c+r].replace("#", ""))
    return r
 

def main():
    s = input()
    print(manacher(s))


if __name__ == "__main__":
    main()