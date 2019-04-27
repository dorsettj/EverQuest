#include "AnimationTest.h"

#include "AnimationLoader.h"
#include "AnimatedSprite.h"
#include <iostream>

using std::cout;
using std::endl;


	void testAddFrames()
	{
		Animation a(.4f);
		sf::IntRect tRect(10, 10, 10, 10);
		a.addFrame(tRect);
		//tests if the frame successfully is added to frames vector
		if (a.getFrame(0) == tRect) cout << "the frame was successfully added" << endl;
		else cout << "frame failed to be added\n";

		//tests if an exception is thrown if index is out of bounds
		a.getFrame(2);


	}

	void testAnimatedSprite()
	{

		AnimationLoader aloader;
		AnimatedSprite as;
		aloader.loadAnimationsFromFile(as, "hero.txt");
		
		Animation a(.3);
		std::string key = "key";
		sf::IntRect rect(10, 10, 10, 10);

		a.getCurrentSquare();

		a.addFrame(rect);
		//test getters and setters
		as.setAnimation(key, a);

		if (as.getAnimation(key) == a) cout << "success" << endl; \
		else cout << "failed";

	}


	bool operator==(Animation lhs, Animation rhs)
	{

		if (lhs.getFrameCount() != rhs.getFrameCount()) return false;
		for (int i = 0; i < rhs.getFrameCount(); i++)
		{
			if (lhs.getFrame(i) != rhs.getFrame(i))return false;
		}
		return true;
	}