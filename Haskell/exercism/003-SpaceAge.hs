module SpaceAge (Planet (..), ageOn) where

data Planet
  = Mercury
  | Venus
  | Earth
  | Mars
  | Jupiter
  | Saturn
  | Uranus
  | Neptune

ageOn :: Planet -> Float -> Float
-- ageOn planet seconds = error "You need to implement this function."

ageOn planet seconds =
  case planet of
    Earth -> seconds / 31557600
    Mercury -> ageOn Earth seconds / 0.2408467
    Venus -> ageOn Earth seconds / 0.61519726
    Mars -> ageOn Earth seconds / 1.8808158
    Jupiter -> ageOn Earth seconds / 11.862615
    Saturn -> ageOn Earth seconds / 29.447498
    Uranus -> ageOn Earth seconds / 84.016846
    Neptune -> ageOn Earth seconds / 164.79132