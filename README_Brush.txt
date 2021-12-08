 ____  ____  _   _ ____  _   _ 
| __ )|  _ \| | | / ___|| | | |
|  _ \| |_) | | | \___ \| |_| |
| |_) |  _ <| |_| |___) |  _  |
|____/|_| \_\\___/|____/|_| |_| README


Design Decisions: 
I used polymorphism to create the Brush's needed for this project by having a variable of type 
Brush and then assigning it to one of the types of Brushes that extend from the Brush class using a switch statement based on the settings configured in the UI. When the mouse_dragged method is called in the Canvas2D class, the brush_dragged method of the specific Brush being used will be called. For the 3 standard brushes, this method is the same, but the mask that was initialized when the Brush was created would be different, creating the varied effects. However, for the smudge brush, when brush_down is called, it picks up paint from the canvas, and when brush_dragged is called, it mixes that paint with whatever new paint is under it. As a result, I overrode the brush_dragged method in the SmudgeBrush subclass.

Known Bugs: No known bugs :)
                               