#include "KeyMap.h"
#include <GLFW/glfw3.h>

int ToGlfwKey(Key key)
{
	switch (key)
	{
		case Key::F9:
			return GLFW_KEY_F9;
		case Key::F11:
			return GLFW_KEY_F11;
		case Key::Escape:
			return GLFW_KEY_ESCAPE;
		default: 
			return GLFW_KEY_UNKNOWN;
	}
}