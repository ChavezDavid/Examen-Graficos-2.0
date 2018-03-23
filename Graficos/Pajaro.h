#pragma once
#include "Modelo.h"

#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

class Pajaro : public Modelo {
public:
	Pajaro();
	vec3 coordenadas;
	float velocidad = 0.001f;
	void moverPajaro();
	void rotarPajaro();
};