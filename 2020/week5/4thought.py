
operators = ['+', '-', '*', "//"]
def find(num):
    for i in range(4):
        for j in range(4):
            for k in range(4):
                equ = f"4{operators[i]}4{operators[j]}4{operators[k]}4"
                try:
                    answer = eval(equ)
                    if (answer == num):
                        output = ''
                        # turns // to 1 /
                        equ = equ.replace('//', '/')
                        for char in equ:
                            output += char + ' '
                        print(f"{output}= {answer}")
                        return
                except:
                    continue

    print("no solution\n")

def main():
    cases = int(input())

    for _ in range(cases):
        num = int(input())
        if (num > 256 or num < -60):
            print("no solution")
            continue
        
        find(num)

if __name__ == "__main__":
    main()
