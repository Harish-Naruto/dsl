def getdata():
    roll = []
    n = int(input("enter the number of students: "))
    for i in range(n):
        roll.append(int(input("enter the roll number of student: ")))
    return roll


def display(roll):
    for i in range(len(roll)):
        print(roll[i])

def sort(roll):
    for i in range(len(roll)-1):
        min = i
        for j in range(i+1,len(roll)):
            if roll[min]>roll[j]:
                min = j
        roll[min],roll[i]=roll[i],roll[min]
    return roll

def ternary_search(arr,left,right,target):

    if left > right:
        return -1
        
   
    mid1 = left + (right - left) // 3
    mid2 = right - (right - left) // 3
    
   
    if arr[mid1] == target:
        return mid1
    if arr[mid2] == target:
        return mid2
        
    
    if target < arr[mid1]:
        return ternary_search(arr, left, mid1 - 1,target)
        
   
    elif target > arr[mid2]:
        return ternary_search(arr, mid2 + 1, right,target)
        
    
    else:
        return ternary_search(arr, mid1 + 1, mid2 - 1,target)



unsort_Roll = []
sort_Roll = []
flag = 1

while flag == 1:
        print("\n---------------------MENU---------------------")
        print("1. Accept Student Roll Numbers")
        print("2. Display the Roll Numbers of Student in sorted way")
        
        print("3. Perform Recursive Ternary Search")
        
        print("4. Exit\n")

        ch = int(input("Enter your choice (from 1 to 6) : "))

        if ch == 1:
             unsort_Roll = getdata()

        elif ch == 2:
            sort_Roll = sort(unsort_Roll)
            display(sort_Roll)

        elif ch == 3:
            find_roll = int(input("Enter the Roll Number to be searched : "))
            sort_Roll = sort(unsort_Roll)
            index = ternary_search(sort_Roll,0,len(sort_Roll),find_roll)
            if index != -1:
                 print("The Roll Number",find_roll,"is found at position",index+1)
            else:
                 print("Roll Number",find_roll,"nor found!!")

        elif ch == 4:
            print("Thanks for using this program!!")
            flag=0

        else:
            print("Wrong choice!!")
            flag = 0