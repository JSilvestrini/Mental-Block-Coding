if __name__ == "__main__":
    userInput = input("Give me a simple mathematical phrase,\nIt should be _number_ _operation_ _number_\n>\t")
    math = userInput.split(" ")
    i = 0
    while len(math) > 1:
        while (math.count('*') > 0) or (math.count('/') > 0):
            if math[i] == '*':
                math[i-1] = float(math[i-1]) * float(math[i+1])
                math.pop(i)
                math.pop(i)
                i = 0
            elif math[i] == '/':
                math[i-1] = float(math[i-1]) / float(math[i+1])
                math.pop(i)
                math.pop(i)
                i = 0
            i += 1
        if len(math) <= 1:
            break
        if math[i] == '+':
            math[i-1] = float(math[i-1]) + float(math[i+1])
            math.pop(i)
            math.pop(i)
            i = 0
        if math[i] == '-':
            math[i-1] = float(math[i-1]) - float(math[i+1])
            math.pop(i)
            math.pop(i)
            i = 0
        i += 1

    print(f"{math[0]}")