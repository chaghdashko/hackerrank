actualDate = input().split()
expectedDate = input().split()

actualDay = int(actualDate[0])
actualMonth = int(actualDate[1])
actualYear = int(actualDate[2])

expectedDay = int(expectedDate[0])
expectedMonth = int(expectedDate[1])
expectedYear = int(expectedDate[2])

fine = 0

if expectedYear > actualYear:
    fine = 0
else:
    if expectedYear == actualYear:
        if expectedMonth > actualMonth:
            fine = 0
        else:
            if expectedMonth == actualMonth:
                if expectedDay >= actualDay:
                    fine = 0
                else:
                    fine = 15 * (actualDay - expectedDay)
            else:
                fine = 500 * (actualMonth - expectedMonth)
    else:
        fine = 10000
    
print(fine)
