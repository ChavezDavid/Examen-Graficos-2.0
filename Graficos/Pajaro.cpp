#include "stdafx.h"
#include "Pajaro.h"

Pajaro::Pajaro() {
	coordenadas = vec3(0.0f, 0.0f, 0.0f);
	transformaciones = mat4(1.0f);
}

void Pajaro::moverPajaro() {
	if(transformaciones[0][3] < 1.0f && transformaciones[0][3] > -1.0f)
		transformaciones = translate(transformaciones, vec3(1 * velocidad, 0.0f, 0.0f));
	if (transformaciones[0][3] > 1.0f)
		rotarPajaro();
}

void Pajaro::rotarPajaro() {
	transformaciones = rotate(transformaciones, 180.0f, 1.0f, 1.0f, 1.0f);
}