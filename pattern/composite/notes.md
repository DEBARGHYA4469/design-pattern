#### Composite Pattern is a structural design pattern that lets you compose objects into tree like structures and then work with this structures as if they were individual objects. 

- Say you have a products and boxes. A box can contain several products as well as number of boxes. 
- When you create an ordering system that uses this classes, how do you determine the final price of a box? 
- One way trying to solve this unwrap all boxes, find the products, if its box unwrap again. But in this case you have to know the classes of Boxes and Products to unwrap and calculate the prices. 
- Solution : Use "composite" pattern. Have a high-level abstract class defining the interface. 

Example: 

Say you have GUI objects : dot, circle, square. You should be able to move each of them. Create a interface MoveableGraphics and let the objects derive from them. This interface is like the lowest common denominator of all operations permitted on the individual objects.


```
MovableGUIObject
	   |
	   v
      Dot
  |			|
  v 		v 
 Square	  Circle


class GraphicComposite 
	- array: 
		MovableGUIObject
	- method: 
		add objects
	- method: 
		remove objects
	- method: 
		move objects. 
```