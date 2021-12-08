 ___       _                          _   
|_ _|_ __ | |_ ___ _ __ ___  ___  ___| |_ 
 | || '_ \| __/ _ \ '__/ __|/ _ \/ __| __|
 | || | | | ||  __/ |  \__ \  __/ (__| |_ 
|___|_| |_|\__\___|_|  |___/\___|\___|\__|  README :)
                                          

Design Decisions:
- I decided to put pretty much all of my raytracing-specific logic into RayScene.cpp. I chose to
Not loop through pixels or do any logic in Canvas2D other than resizing and delegating to RayScene
Because I felt it made more sense for RayScene to be in charge of all of the logic.
- I chose to make a class to represent Rays. I knew I needed some way to store p and d for each Ray,
So I was deciding between a struct and a class. I ultimately chose class because I wanted to have
A method that applied a matrix transformation to a ray, as I do this multiple times in my program
- I chose to have each shape handle their own implicit equations/intersection methods. I made each
Shape have a static method that checked for intersection with a ray that is passed in as a parameter.
I chose to do this because I never had to make instances of the Shape subclasses. In addition,
I wanted to delegate to individual classes to make my program more object-oriented. Finally, this 
Allows me to use polymorphism and call the same method for any shape primitive type. I also had 
Some shared commonality that many shapes used, so I was able to put the equation to calculate the
Quadratic formula and the function where I did cap intersection in the Shape superclass and then
Call these functions from the individual Shape subclasses.
- Lastly, I used Structs to represent important pieces of data. For instance, my ShapeInfo struct
Holds the t-value, coordinate in object space, and normal vector in object space for a given 
Intersection. I return an instance of ShapeInfo when I find intersection points, and this allows me
To access all of the relevant information in RayScene when calculating lighting for an intersection.
I also made a TransformedPrimitive struct, which is how I store the transformation matrix associated
With each primitive in Scene.cpp. This easily allows me to access a primitive's transformation matrix
When I'm looping through the primitives in RayScene.

Known Bugs: No Known Bugs :)