Permutation = [0,17,34,51,48,1,18,35,32,49,2,19,16,33,50,3,4,21,38,55,52,5,22,39,36,53,6,23,20,37,54,7,8,25,42,59,56,9,26,43,40,57,10,27,24,41,58,11,12,29,46,63,60,13,30,47,44,61,14,31,28,45,62,15]
#Permutation = [0,3,5,7,2,4,6,1]
done_array = [0]*len(Permutation)
swap_array = []
i = 0
working_index = i
while ((i<len(Permutation)) and (sum(done_array)!=len(done_array))) :
    if (i==Permutation[i]):
        done_array[i]=1
        i = i+1
        working_index = i
        continue
    else:
        if(working_index != Permutation[i]):
        #if((done_array[i] == 0) and (working_index != Permutation[i])):
            swap_array.append((working_index,Permutation[i]))
            #print(swap_array)
            done_array[i] = 1
            #working_index = i
            i = Permutation[i]
        else:
            done_array[i] = 1
            i = done_array.index(0)
            working_index = i
print(swap_array)