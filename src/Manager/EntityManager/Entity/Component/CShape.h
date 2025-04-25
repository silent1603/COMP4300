#ifndef CSHAPE_H
#define CSHAPE_H
#include "Math/Vector.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "Component.h"
class CShape : public Component
{
public:
	sf::CircleShape circle;
	CShape() {}
	CShape(float radius,size_t points,const sf::Color& fill,const sf::Color& outline,float thickness,Vector<float,2> pos):circle(radius,points)
	{
		circle.setFillColor(fill);
		circle.setOutlineColor(outline);
		circle.setOutlineThickness(thickness);
		circle.setOrigin({pos.data[0],pos.data[1]});
	}
};
#endif