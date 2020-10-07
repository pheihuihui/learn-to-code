module CollatzConjecture (collatz) where

collatz :: Integer -> Maybe Integer
-- collatz = error "You need to implement this function."

collatz n
  | n <= 0 = Nothing
  | n == 1 = Just 0
  | n > 1 =
    if n `mod` 2 == 0
      then (+ 1) <$> collatz (div n 2)
      else (+ 1) <$> collatz (n * 3 + 1)