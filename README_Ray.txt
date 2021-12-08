____
|  _ \ __ _ _   _
| |_) / _` | | | |
|  _ < (_| | |_| |
|_| \_\__,_|\__, |  README :)
           |____/

*** You can modify depth of recursive reflection raytracing on line 64 of
RayScene.cpp. It is the last argument to traceRay(), and it is currently set
to 4 ***

Design Decisions:
- I decided to make each shape in charge of mapping an xyz point on the shape
to a uv point on a unit square. I made this decision because each shape does
it slightly differently, and delegating this responsibility to each shape class
better utilizes the Object-Oriented nature of my program and also allows me
to easily call the necessary method in a switch statement.
- I utilize the same traceRay method for normal raytracing, recursive reflection
raytracing and for checking for shadows. This decision required me to add two
parameters to the traceRay method, one to signify whether its currently being
used to check for shadows, and one to signify depth level of recursion. I made
this decision because the underlying logic for all 3 tasks was the same and
I wanted to reuse this large amount of code.

Known Bugs: No Known Bugs :)
