_____ _ _ _
|  ___(_) | |_ ___ _ __
| |_  | | | __/ _ \ '__|
|  _| | | | ||  __/ |
|_|   |_|_|\__\___|_|  Readme :)

Design Decisions:
- The main design decision that I made in Filter is the choice to not use any sort of interface/inhertance relationship when designing my
class structure. Each type of filter (including the util filters such as grayscale, seperable convolution, and non-seperable convolution)
is in its own class, and the apply method for the filter is a static method. I chose this design because I would not gain anything from an
inhertance relationship. The shared functionality (the apply method) is executed very differently for each type of filter, and I call
the static apply method right away in the switch statement in Canvas2d.cpp, so it would not be beneficial in any way to store the filter
type in a superclass variable to then call a common method on (polymorphism).

Known Bugs: No known bugs :)
