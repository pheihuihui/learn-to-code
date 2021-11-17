module Anagram (anagramsFor) where

import Data.Char (toUpper)
import Data.List (sort)

anagramsFor :: String -> [String] -> [String]
anagramsFor xs = filter $ ana xs

ana :: String -> String -> Bool
ana xs ys
    | length xs /= length ys = False
    | fmap toUpper xs == fmap toUpper ys = False
    | sort (fmap toUpper xs) == sort (fmap toUpper ys) = True
    | otherwise = False