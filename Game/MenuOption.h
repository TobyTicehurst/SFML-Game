#pragma once
#include "SFML\Graphics.hpp"
#include <functional>

class MenuOption
{
public:
	MenuOption(std::string text, std::function<void(void)> function);
	

	void callFunction();

	std::string m_text;
	std::function<void(void)> m_function = []() {};
};

