module LeapYear (isLeapYear) where

isLeapYear :: Integer -> Bool
-- isLeapYear year = error "You need to implement this function."
isLeapYear year = 
    if year `rem` 400  == 0
        then True
    else if year `rem` 100 == 0 && year `rem` 4 == 0
        then False
    else if year `rem` 4 == 0
        then True
    else False