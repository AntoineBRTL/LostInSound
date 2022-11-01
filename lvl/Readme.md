# Create custom levels

## Create a lvl file ##
1) Create a file name like this : `x.lvl` where `x` is its location in the game.
2) Write these informations in this file : 
    - The number of portal(s) in the lvl - `(int)`.
    - The winner instrument - note that this is the instrument which play the key - has to be its index - `(int)`.
    - The winner key - has to be its index - `(int) from 0 to 11`.
    - The instrument played at the center - note that this is the instrument which play the key - has to be its index - `(int)`.
    - The key played at the center - has to be its index - `(int) from 0 to 11` - `-1` means that no sound will be played at the center.
    - The rule - see [here](#Rules) - `(int)`.

## Rules ##
See all the different rules:
1) The player has to find the portal which plays the same key as he played.
2) The player has to find the portal which plays the lowest key.
3) The player has to find the portal which plays the highest key.