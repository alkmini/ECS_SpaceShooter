#pragma once
#include <chrono>

class Time
{
public:
	Time();

	inline static float time;

	inline static float deltaTime;

	void Update();

private:
	std::chrono::high_resolution_clock::time_point currentTime;
	std::chrono::duration<float> deltaCount;
 };

