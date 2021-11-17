module LeapYear (isLeapYear) where

isLeapYear :: Integer -> Bool
isLeapYear year
    | year `rem` 4 /= 0 = False
    | year `rem` 100 == 0 && year `rem` 400 /= 0 = False
    | otherwise = True