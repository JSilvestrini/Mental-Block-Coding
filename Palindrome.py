def checkPalindrome(string):
    if string == string[::-1]:
        print(f"{string} is a palindrome!")
        return
    print(f"{string} is not a palindrome!")
    return

if __name__ == "__main__":
    checkThis = input("Palindrome checker, give me a word!\n>\t")
    checkPalindrome(checkThis)