#include "Time.h"
#include <iostream>

Time::Time()
{
	time = 0;
	deltaTime = 0;
	currentTime = std::chrono::high_resolution_clock::now();
}

void Time::Update()
{
	deltaCount = std::chrono::high_resolution_clock::now() - currentTime;
	deltaTime = deltaCount.count();
	//std::cout << "fps: " << 1 / deltaTime << std::endl;
	currentTime = std::chrono::high_resolution_clock::now();
}
