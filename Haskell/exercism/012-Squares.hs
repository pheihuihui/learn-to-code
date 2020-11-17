module Squares (difference, squareOfSum, sumOfSquares) where

difference :: Integral a => a -> a
-- difference n = error "You need to implement this function."
difference n = squareOfSum n - sumOfSquares n

squareOfSum :: Integral a => a -> a
-- squareOfSum n = error "You need to implement this function."
squareOfSum n = ((n + 1) * n `div` 2) ^ 2

sumOfSquares :: Integral a => a -> a
-- sumOfSquares n = error "You need to implement this function."
sumOfSquares 0 = 0
sumOfSquares n = n ^ 2 + sumOfSquares (n - 1)