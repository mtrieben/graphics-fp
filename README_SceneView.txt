 ____                    __     ___               
/ ___|  ___ ___ _ __   __\ \   / (_) _____      __
\___ \ / __/ _ \ '_ \ / _ \ \ / /| |/ _ \ \ /\ / /
 ___) | (_|  __/ | | |  __/\ V / | |  __/\ V  V / 
|____/ \___\___|_| |_|\___| \_/  |_|\___| \_/\_/   README :)


Design Decisions:
SceneView was pretty self-contained in one file, so the main design decision that I made is storing
The m_vertexData vector associated with each primitive so I don't have to re-tesselate the shapes 
Every time the camera moves. I stored one shape in a member variable m_shape, and I routinely update
This shapes m_vertexData with the m_vertexData of the shape to be rendered. I made a struct PrimShape
That stores the vector with vertices associated with each shape. If a setting is changed that
Requires re-tesselation, I update the vector stored in the PrimShape for that Shape.

Known Bugs: I'm not sure if this is a bug, but when a new scene is loaded after a scene has already been loaded, you need to switch any setting (ie, uncheck and recheck the use scene view button, change a shape tessellation parameter, etc).