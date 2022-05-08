#pragma once
class GameItem {
public:
	virtual void start() = 0;
	virtual void draw() = 0;
	virtual void move() = 0;	
};

