def validate (prn) : 
    state = 0

    for ch in prn: 

        d = int(ch)

        if state == 0 and d == 2 : 
            state = 1
        elif state == 1 and d == 0 : 
            state = 2
        elif state == 2 and d == 2 : 
            state = 3
        elif state == 3 and d in range(2, 6) : 
            state = 4
        elif state == 4 and d == 0 : 
            state = 5
        elif state == 5 and d in range(1, 3) : 
            state = 6
        elif state == 6 and d == 0 : 
            state = 7
        elif state == 7 and d == 8 : 
            state = 8
        elif state == 8 and d in range(0, 2) : 
            state = 10
        elif state == 10 and d in range(0, 10) : 
            state = 11
        elif state == 11 and d in range(0, 10) : 
            state = 12
        elif state == 12: 
            print(f"PRN : {prn} is valid")
        else : 
            print("PRN is invalid")
            return
                
        
validate("202502080008")
validate("202401080002")
validate("202403070003")