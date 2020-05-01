module Questions_01_Lists
    ( someFunc
    , myLast
    )
where

someFunc :: IO ()
someFunc = putStrLn "someFunc"


-- 001: Find the last element of a list.
myLast :: [x] -> x
myLast [x]        = x
myLast []         = error "empty list"
myLast (_ : tail) = myLast tail
