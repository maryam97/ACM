num = []
imm = True
set = 0
while True:
    try:
        a = input()

        if a == "9":
            set += 1
            for i in range(len(num)):
                for j in range(len(num)):
                    if i!=j:
                        #print(str(num[i]), str(num[j]))
                        if str(num[i]).startswith(str(num[j])):
                            #print("hmm")
                            imm = False
                            break
                #print(imm)
                if not imm:
                    break
            if imm:
                print("Set %d is immediately decodable" %(set))
            else:
                print("Set %d is not immediately decodable" %(set))
            del num[:]
            imm = True
            continue

        num.append(str(a))
    except EOFError:
        break
