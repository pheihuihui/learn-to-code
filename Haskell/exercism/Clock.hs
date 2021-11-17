module Clock (addDelta, fromHourMin, toString) where

data Clock = Clock Int
    deriving (Eq)

fromHourMin :: Int -> Int -> Clock
fromHourMin hour min = newClock (hour * 60 + min)

toString :: Clock -> String
toString (Clock n) = _show (show (n `div` 60 `mod` 24)) ++ ":" ++ _show (show (n `mod` 60))

addDelta :: Int -> Int -> Clock -> Clock
addDelta hour min (Clock n) = newClock (hour * 60 + min + n)

newClock :: Int -> Clock
newClock num = Clock (num `mod` (24 * 60))

_show :: String -> String
_show str
    | length str == 1 = "0" ++ str
    | otherwise = str