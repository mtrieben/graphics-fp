 ____  _                           
/ ___|| |__   __ _ _ __   ___  ___ 
\___ \| '_ \ / _` | '_ \ / _ \/ __|
 ___) | | | | (_| | |_) |  __/\__ \
|____/|_| |_|\__,_| .__/ \___||___/   README :)
                  |_|           


Design Choices:
The main design choices that I made in Shapes pertain to how I structured the objects in the 
program. I had an overarching Shape superclass that contains the method required to add a vec3
To the actual m_vertexData vector. I also have a BaseShape class that is a subclass of Shape, and
It is the parent class to the Cylinder and Cone shapes. Because both of these shapes have a 
CircleBase that needs to be tessellated, I added that functionality to BaseShape. I then had a 
CircleBase class, and Spheres, Cylinders, and Cones contained instances of CircleBase. Finally,
Sphere and Cube were subclasses of the Shape superclass.

Known Bugs: No Known Bugs :)