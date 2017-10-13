import os
import argparse

def reverse_str(s):
    if not isinstance(s, str):
        return None
    res = ""
    for i in range(len(s)):
        res = res + s[len(s) - i - 1]
    return res


VOWEL_LETTERS=('a','e','i','o','u')


def pig(s):
    if not isinstance(s, str):
        return None
    res = ""
    for i in range(len(s)):
        res = res + s[len(s) - i - 1]
    return res

if __name__ == "__main__":
    s = input("Please input a string: \n")
    print(reverse_str(s))