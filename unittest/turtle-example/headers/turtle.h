#pragma once 

/* Interface for turtle */
class Turtle {
	public: 
		virtual ~Turtle () {}
		virtual void PenUp () = 0;
		virtual void PenDown () = 0;
		virtual void Foreward (int distance) = 0;
		virtual void Turn (int degrees) = 0;
		virtual void GoTo (int x, int y) = 0;
		virtual int GetX () const = 0;
		virtual int GetY () const = 0;
}; 