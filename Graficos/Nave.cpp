#include "stdafx.h"
#include "Nave.h"

Nave::Nave() {
	angulo = 90.0f;
	coordenadas = vec3(0.0f, 0.0f, 0.0f);
	transformaciones = mat4(1.0f);
}

void Nave::rotarNave(int direccion) {
	float rotacion = velocidadAngular;
	if (direccion == 1) {
		rotacion = -rotacion;
	}
	transformaciones = rotate(transformaciones, rotacion, vec3(0.0f, 0.0f, 1.0f));
}

void Nave::moverNave() {
	transformaciones = translate(transformaciones, vec3(cos(angulo*3.14159f / 180.0f)*velocidad, sin(angulo*3.14159 / 180.0f)*velocidad, 0.0f));
}