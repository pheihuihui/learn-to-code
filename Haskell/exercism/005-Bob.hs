module Bob (responseFor) where

responseFor :: String -> String
-- responseFor xs = error "You need to implement this function."
responseFor xs
  | length xs == 0 || ((length $ trim xs) == 0) = "Fine. Be that way!"
  | last' xs == '?' && (not $ isAllCapital xs) = "Sure."
  | isAllCapital xs && (last' xs /= '?') = "Whoa, chill out!"
  | isAllCapital xs = "Calm down, I know what I'm doing!"
  | isNothing xs = "Fine. Be that way!"
  | otherwise = "Whatever."

isAllCapital :: String -> Bool
isAllCapital xs =
  let bool1 = not $ elem True $ map (\x -> elem x ['a' .. 'z']) xs
      bool2 = elem True $ map (\x -> elem x ['A' .. 'Z']) xs
   in bool1 && bool2

isNothing :: String -> Bool
isNothing xs = not $ elem True $ map (\x -> elem x (['a' .. 'z'] ++ ['A' .. 'Z'] ++ ['0' .. '9'])) xs

last' :: String -> Char
last' xs = last $ reverse $ trim $ reverse xs

trim :: String -> String
trim "" = ""
trim (x : xs)
  | x == ' ' = trim xs
  | otherwise = x : xs