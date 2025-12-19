#pragma once

#include <string>

namespace constants
{
    // Constants
   	constexpr int gScreenWidth     { 1920 };
   	constexpr int gScreenHeight    { 1080 };
   	// PATH TO YOUR RESOURCE FOLDER 'resources', 'gResPath'
   	const std::string gResPath { "./resources/" };
	// PATH'S TO ALL YOUR EXTERNAL RESOURCES using 'gResPath'
	const std::string bg_str  { gResPath + "images/bg.jpg" };
    const std::string sample_str { gResPath + "sounds/sample.wav"};

	const std::string earthTexture { gResPath + "earth/textures/earth.png"};
	const std::string playerShipTexture { gResPath + "player/textures/playership.png" };
	const std::string enemyShipTexture { gResPath + "enemy/textures/enemyship.png"};
	const std::string backgroundTexture { gResPath + "world/textures/background.png"};
}
