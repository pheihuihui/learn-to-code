module Grains (square, total) where

square :: Integer -> Maybe Integer
-- square n = error "You need to implement this function."
square n
  | n <= 0 || n >= 65 = Nothing
  | otherwise = Just $ 2 ^ (n - 1)

total :: Integer
-- total = error "You need to implement this function."
total = 2 ^ (64 :: Integer) - 1
