{-# LANGUAGE OverloadedStrings #-}

module Acronym (abbreviate) where


import Data.Char       (isLetter, toUpper)
import Data.List.Split (wordsBy)

abbreviate :: String -> String
abbreviate = map (toUpper . head) . wordsBy (not . isLetter)