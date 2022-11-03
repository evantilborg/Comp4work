/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template
 **********************************************************************/

Name: Erik van Tilborg
Hours to complete assignment: ~ 7-8 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

the assignment was to create a universe of different celestial bodies 
in an sfml winodw and have them be scaled accordingly to the sfml winodw
size based on their real distances from the sun.

i was able to accomplish this and had a result that was similar to that 
of the supplied assignment pdf. the only change that i made was to center
the celestial bodies based on their center instead of the top left corner
of the sprite that is default in sfml.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

the parts that were essential to this assignment was having a data
structure that held all of the celestial bodies within the universe, having
an overload for the insertion operator used in the universe class for getting
input in from a file containing the key values for the celestila bodies.
numerous getters were used to make accessing private information needed for
calculations and setters were used to put those calculations and initial 
values in place.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/

the workings of my implementation are relatively quite simple. the brunt 
of everything is housed within the insertion (>>) operator overload within
the universe class and the CelestialBody constructor. everything else are
either getter or setter functions that aid one another, mostly for calculating
the viewport coordinates in relation to the positions passed in by the file.

i used the smart pointers in 3 places, 1, the universe object consists of
a vector of shared pointers of CelestialBody.

std::vector<std::shared_ptr<CelestialBody>> universeContents;

2. inside the >> overload i used shared pointers to pass the data from the universe
to the celestial bodies, in a while loop for as many number of celestial bodies 
specified by the input file.

	while(i < uni.numCelestialBodies){
		in >> x >> y >> xVelo >> yVelo >> mass >> planetName;
		auto temp = std::make_shared<CelestialBody>(x, y, xVelo, yVelo, mass, planetName);
		temp->setRadius(uni.uniRadius);
		uni.universeContents.push_back(temp);
		i++;
	}

3. i used them again in my getPlanet function that returns the shared pointers of  
the celestial body at the index location to access the data that it holds.

std::shared_ptr<CelestialBody> getPlanet(int x){
		return universeContents[x];
	}


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

i received some help, albeit not directly asked for, from the class discord server
some of the methods that Dr. Daly and some of the students were talking about
helped me think of ways in which i could tackle my own problems that i had.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

at one point i encountered an issue where my sprites only would print in
the top left corner of the sfml window. upon inspection of my code, i 
realized that i never set the positions of the sprites for the adjusted 
coordinates. once i realized this i made the neccessary fix and the sprites
printed to the sfml window in their correct spots based on the scale calculations.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

no further commemts
