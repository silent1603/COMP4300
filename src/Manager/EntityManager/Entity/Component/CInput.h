#ifndef CINPUT_H
#define CINPUT_H
#include "Math/Vector.h"
#include "Component.h"
class CInput : public Component
{
	enum class InputType : int
	{
		NONE = 0,
		UP,
		LEFT,
		RIGHT,
		DOWN,
		SHOOT,
		SIZE
	};
public:
	Vector<int, (int)(InputType::SIZE)> inputs; 
	CInput(){ }
};
#endif