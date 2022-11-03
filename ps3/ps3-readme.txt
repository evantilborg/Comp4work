/**********************************************************************
 *  ps3-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Erik van Tilborg

Hours to complete assignment: 4 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

 the assignment was to create a recursive function, along with an appropriate 
 header and .cpp file to go along with it. this function would get the new
 positions of where the next triangles were to be displayed in the sfml window.
 this was done with command line arguments that specified the base length of the 
 starting triangle and how many recursions were to be performed.

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

 in the project, one of the most important parts of it was the custom made
 triangle class. in it there was a method of implementation that helped make 
 the assignment easier. my triangle class consists of shared pointers to a 
 vertex array that is a drawable object. the class also inherits from the 
 sf::Drawable public class. this allowed to make a virtual draw function within
 the triangle class which allowed the trianlges to be drawn.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

 the triangle object being of a shared pointer allowed me to pass in values to 
 the main objects directly by accessing the memory needed.

 std::shared_ptr<sf::VertexArray> verticies;
 
 having the triangle class inherit from sf::Drawable allows for the use of a 
 virtual draw function that will be called when wanting to draw the triangle 
 objects;

 virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {  //NOLINT
    target.draw(*verticies, states);
 }
 
 having chared pointers in the object directly helped set up the constructor 
 implementation that follows:

 Triangle::Triangle(double base, sf::Vector2<double> cPoint,
 sf::PrimitiveType type) {
     double Alt = base * (sqrt(3) / 2);
     verticies = std::make_shared<sf::VertexArray>(sf::LinesStrip, 4);

     (*verticies)[0].position =
     sf::Vector2f(cPoint.x - (base / 2.0), cPoint.y - (Alt / 2.0));

     (*verticies)[1].position =
     sf::Vector2f(cPoint.x + (base / 2.0), cPoint.y - (Alt / 2.0));

     (*verticies)[2].position =
     sf::Vector2f(cPoint.x, cPoint.y + (Alt / 2.0));

     (*verticies)[3] = (*verticies)[0];
 }

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/

 i learned how to use an sf::VertexArray and its associated methods, as well
 as more drawing tools like sf::LinesStrip and sf::PrimitiveType for the drawing
 type. also i learned that, what initially looked like a challenging assignment 
 was made easier by recursion. i dont normally use recursive methods because 
 iterative ones are usually faster, bt there are limits to them. this project would
 have been more difficult if we had to do it iteratively.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

 indirect help from the class discord server.

/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/

 no major problems

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/