#include "Shapes.hpp" 

TEST (ShapeTest, RenderCircleWithVector){
	VectorRenderer* vectorRenderer = new VectorRenderer();
	Circle* circle = new Circle (vectorRenderer);
	circle -> draw (); 
}

TEST (ShapeTest, RenderSquareWithVector){
	VectorRenderer* vectorRenderer = new VectorRenderer();
	Square* square = new Square(vectorRenderer); 
	square -> draw ();
}

TEST (ShapeTest, RenderCircleWithRaster){
	RasterRenderer* rasterRenderer = new RasterRenderer(); 
	Circle* circle = new Circle (rasterRenderer);
	circle -> draw ();
}

TEST (ShapeTest, RenderSquareWithRaster){
	RasterRenderer* rasterRenderer = new RasterRenderer(); 
	Square* square = new Square(rasterRenderer); 
	square -> draw ();
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}