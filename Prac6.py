def selection_sort(marks):
    for i in range(len(marks)-1):
        min = i
        for j in range(i+1,len(marks)):
            if(marks[min]>marks[j]):
                min = j
            
        marks[i],marks[min] = marks[min],marks[i]
    print("marks after selection sort are: ")
    for i in range(len(marks)):
        print(marks[i])
    ch = input("do you want to get top 5 (y/n): ")
    if ch == 'y':
        display_topfive(marks)
    

def display_topfive(perc):
    print("Top five percentages are : ")
    i = len(perc)-1
    count = 0
    while i>=0 and count!=5:
        print(perc[i])
        count+=1
        i-=1  

def bubble_sort(marks):
    for i in range(len(marks)-1):
        for j in range(len(marks)-i-1):
            if(marks[j]>marks[j+1]):
                marks[j],marks[j+1] = marks[j+1],marks[j]
    
    print("marks after bubble sort are : ")
    for i in range(len(marks)):
        print(marks[i])
    ch = input("do you want to get top 5 (y/n): ")
    if ch == 'y':
        display_topfive(marks)


marks = []

n = int(input("enter the total number of student: "))
for i in range(n):
    marks.append(float(input("enter marks of student : ")))

flag = 1
while flag==1:
    print("slect the operation you want to perform :")
    print("1.BUBBLE SORT")
    print("2.SELECTION SORT")
    print("3.exit")
    ch = int(input("enter your choice: "))

    if ch==1:
        bubble_sort(marks)
    elif ch==2:
        selection_sort(marks)
    elif ch==3:
        flag = 0
    else:
        print("enter a valid input")