
def getdata():
    perc = []
    number = int(input("Enter the number of stuent you want to store: "))
    for i in range(number):
        
        perc.append(float(input("Enter the percentage of student: ")))
    return perc

def display(perc):
    for i in range(len(perc)):
        print(perc[i]," ")
    print("\n")

def partition(perc,start,end):
    pivot = start
    left = start+1
    right = end
    while left<right:
        while left<=end and perc[left] <= perc[pivot]:
            left+=1
        while right >= 0 and perc[right] >= perc[pivot]:
            right-=1
        if left<right:
            perc[right],perc[left] = perc[left],perc[right]
    perc[pivot],perc[right] = perc[right],perc[pivot]
    return right

def quicksort(perc,start,end):
    if start<end:
        part = partition(perc,start,end)
        quicksort(perc,start,part-1)
        quicksort(perc,part+1,end)
    return perc

def display_topfive(perc):
    print("Top five percentages are : ")
    i = len(perc)-1
    count = 0
    while i>=0 and count!=5:
        print(perc[i])
        count+=1
        i-=1

unsorted_percentage = []
sorted_percentage = []
flag = 1

while flag == 1:
    print("\n--------------------MENU--------------------")
    print("1. Accept the Percentage of Students")
    print("2. Display the Percentages of Students")
    print("3. Perform Quick Sort on the Data")
    print("4. Exit")

    ch = int(input("Enter your choice (from 1 to 4) : "))

    if ch == 1:
        unsorted_percentage = getdata()

    elif ch == 2:
       display(unsorted_percentage)

    elif ch == 3:
        print("Percentages of Students after performing Quick Sort : ")
        sorted_percentage = quicksort(unsorted_percentage,0,len(unsorted_percentage)-1)
        display(sorted_percentage)
        a = input("Do you want to display the Top 5 Percentages of Students (yes/no) : ")
        if a == 'yes':
            display_topfive(sorted_percentage)

    elif ch == 4:
        print("Thanks for using this program!!")
        flag = 0

    else:
        print("Invalid Choice!!")

