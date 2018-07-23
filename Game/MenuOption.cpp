#include "MenuOption.h"
#include <string>


MenuOption::MenuOption(std::string text, std::function<void(void)> function)
{
	m_text = text;
	m_function = function;
	
}

void MenuOption::callFunction() {
	m_function();
}