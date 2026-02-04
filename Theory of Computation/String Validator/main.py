n = int(input("Enter number of transitions: "))

delta = {}

for i in range(n):
    f = input("Enter from state: ")
    t = input("Enter to state: ")
    s = int(input("Enter symbol: "))
    print()
    
    delta[(f, s)] = t


curr_state = input("Enter the initial state: ")
final_state = input("Enter the final state: ")
string = input("Enter the string to validate: ")

flag = True


for ch in string: 
    if (curr_state, int(ch)) not in delta :
        flag = False
        break
    
    curr_state = delta[(curr_state, int(ch))]

if curr_state == final_state and flag :
    print("String accepted")
else : 
    print("String rejected")