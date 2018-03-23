// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include "glm\gtx\transform.hpp"
#include "glm\glm.hpp"

#include <iostream>

#include "Vertice.h"
#include "Shader.h"
#include "Modelo.h"
#include "Pajaro.h"

#include <math.h>

using namespace std;

GLfloat red;
GLfloat green = 0.2f;
GLfloat blue = 0.4f;

GLuint posicionID;
GLuint colorID;
GLuint transformacionesID;

Pajaro *pajaro;
Modelo *cuadrado;
Modelo *piso;
Modelo *techo;
Modelo *puerta;
Modelo *ventana;

Shader *shader;

//Declaración de Ventana
GLFWwindow *window;

void actualizar()
{
	pajaro->moverPajaro();
	/*int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		nave->moverNave();
	}*/

	/*int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		nave->transformaciones = translate(nave->transformaciones, vec3(0.0f, 0.001f, 0.0f));
	}
	int estadoAbajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAbajo == GLFW_PRESS) {
		nave->transformaciones = translate(nave->transformaciones, vec3(0.0f, -0.001f, 0.0f));
	}
	int estadoX = glfwGetKey(window, GLFW_KEY_X);
	if (estadoX == GLFW_PRESS) {
		nave->transformaciones = scale(nave->transformaciones, vec3(1.001f, 1.001f, 1.001f));
	}
	int estadoZ = glfwGetKey(window, GLFW_KEY_Z);
	if (estadoZ == GLFW_PRESS) {
		nave->transformaciones = scale(nave->transformaciones, vec3(0.999f, 0.999f, 0.999f));
	}
	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		nave->transformaciones = rotate(nave->transformaciones, 0.005f, vec3(0.0f, 0.0f, -1.0f));
	}
	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		nave->transformaciones = rotate(nave->transformaciones, 0.005f, vec3(0.0f, 0.0f, 1.0f));
	}*/
}

void dibujar()
{
	//nave->dibujar(GL_POLYGON);
	cuadrado->dibujar(GL_POLYGON);
	piso->dibujar(GL_POLYGON);
	techo->dibujar(GL_POLYGON);
	puerta->dibujar(GL_POLYGON);
	ventana->dibujar(GL_POLYGON);
	pajaro->dibujar(GL_POLYGON);
}

void inicializarPajaro()
{
	pajaro = new Pajaro();
	Vertice v1 = { vec4(-0.8f, 0.7f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) };
	Vertice v2 = { vec4(-0.7f, 0.8f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) };
	Vertice v3 = { vec4(-0.6f, 0.7f, 0.0f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) };

	pajaro->vertices.push_back(v1);
	pajaro->vertices.push_back(v2);
	pajaro->vertices.push_back(v3);
}

void inicializarCuadrado(){
	cuadrado = new Modelo();
	Vertice v1 = { vec4(-0.5f, 0.2f, 0.0f, 1.0f), vec4(0.8f, 0.0f, 0.4f, 1.0f) };
	Vertice v2 = { vec4(0.5f, 0.2f, 0.0f, 1.0f), vec4(0.8f, 0.0f, 0.4f, 1.0f)};
	Vertice v3 = { vec4(0.5f, -0.8f, 0.0f, 1.0f), vec4(0.8f, 0.0f, 0.4f, 1.0f) };
	Vertice v4 = { vec4(-0.5f, -0.8f, 0.0f, 1.0f), vec4(0.8f, 0.0f, 0.4f, 1.0f) };

	cuadrado->vertices.push_back(v1);
	cuadrado->vertices.push_back(v2);
	cuadrado->vertices.push_back(v3);
	cuadrado->vertices.push_back(v4);
}

void inicializarPiso() {
	piso = new Modelo();
	Vertice v1 = { vec4(-1.0f, -0.7f, 0.0f, 1.0f), vec4(0.0f, 0.5f, 0.0f, 1.0f) };
	Vertice v2 = { vec4(1.0f, -0.7f, 0.0f, 1.0f), vec4(0.0f, 0.5f, 0.0f, 1.0f) };
	Vertice v3 = { vec4(1.0f, -1.0f, 0.0f, 1.0f), vec4(0.0f, 0.5f, 0.0f, 1.0f) };
	Vertice v4 = { vec4(-1.0f, -1.0f, 0.0f, 1.0f), vec4(0.0f, 0.5f, 0.0f, 1.0f) };

	piso->vertices.push_back(v1);
	piso->vertices.push_back(v2);
	piso->vertices.push_back(v3);
	piso->vertices.push_back(v4);
}

void inicializarTecho() {
	techo = new Modelo();
	Vertice v1 = { vec4(-0.6f, 0.2f, 0.0f, 1.0f), vec4(0.8f, 0.0f, 0.0f, 1.0f) };
	Vertice v2 = { vec4(0.0f, 0.8f, 0.0f, 1.0f), vec4(0.8f, 0.0f, 0.0f, 1.0f) };
	Vertice v3 = { vec4(0.6f, 0.2f, 0.0f, 1.0f), vec4(0.8f, 0.0f, 0.0f, 1.0f) };

	techo->vertices.push_back(v1);
	techo->vertices.push_back(v2);
	techo->vertices.push_back(v3);
}

void inicializarPuerta() {
	puerta = new Modelo();
	Vertice v1 = { vec4(-0.1f, -0.3f, 0.0f, 1.0f), vec4(0.8f, 0.4f, 0.0f, 1.0f) };
	Vertice v2 = { vec4(0.1f, -0.3f, 0.0f, 1.0f), vec4(0.8f, 0.4f, 0.0f, 1.0f) };
	Vertice v3 = { vec4(0.1f, -0.7f, 0.0f, 1.0f), vec4(0.8f, 0.4f, 0.0f, 1.0f) };
	Vertice v4 = { vec4(-0.1f, -0.7f, 0.0f, 1.0f), vec4(0.8f, 0.4f, 0.0f, 1.0f) };

	puerta->vertices.push_back(v1);
	puerta->vertices.push_back(v2);
	puerta->vertices.push_back(v3);
	puerta->vertices.push_back(v4);
}

void inicializarVentana() {
	ventana = new Modelo();
	Vertice v1 = { vec4(-0.4f, 0.0f, 0.0f, 1.0f), vec4(0.0f, 0.4f, 0.8f, 1.0f) };
	Vertice v2 = { vec4(-0.2f, 0.0f, 0.0f, 1.0f), vec4(0.0f, 0.4f, 0.8f, 1.0f) };
	Vertice v3 = { vec4(-0.2f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.4f, 0.8f, 1.0f) };
	Vertice v4 = { vec4(-0.4f, -0.2f, 0.0f, 1.0f), vec4(0.0f, 0.4f, 0.8f, 1.0f) };

	ventana->vertices.push_back(v1);
	ventana->vertices.push_back(v2);
	ventana->vertices.push_back(v3);
	ventana->vertices.push_back(v4);
}

int main()
{
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicialización de GLFW
	if (!glfwInit())
	{
		//Si no se inicia bien termina la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicialización de la ventana
	window = glfwCreateWindow(ancho, alto, "Gráficos", NULL, NULL);

	//Verificación de creación de ventana
	if (!window)
	{
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}

	//Establecer "windows" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;

	//Inicializar GLEW
	GLenum glewError = glewInit();

	//Verificar si GLEW se inicializo bien
	if (glewError != GLEW_OK)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL:" << version << endl;

	inicializarPajaro();
	inicializarCuadrado();
	inicializarPiso();
	inicializarTecho();
	inicializarPuerta();
	inicializarVentana();

	//Crear instancia del shader
	const char * rutaVertex = "vShaderSimple.shader";
	const char * rutaFragment = "fShaderSimple.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");
	transformacionesID = glGetUniformLocation(shader->getID(), "transformaciones");

	//Desenlazar shader
	shader->desenlazarShader();

	pajaro->shader = shader;
	pajaro->inicializarVertexArray(posicionID, colorID, transformacionesID);

	cuadrado->shader = shader;
	cuadrado->inicializarVertexArray(posicionID, colorID, transformacionesID);

	piso->shader = shader;
	piso->inicializarVertexArray(posicionID, colorID, transformacionesID);

	techo->shader = shader;
	techo->inicializarVertexArray(posicionID, colorID, transformacionesID);

	puerta->shader = shader;
	puerta->inicializarVertexArray(posicionID, colorID, transformacionesID);

	ventana->shader = shader;
	ventana->inicializarVertexArray(posicionID, colorID, transformacionesID);

	//Ciclo de Dibujo
	while (!glfwWindowShouldClose(window))
	{
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia
		glClearColor(red, green, blue, 1);

		//Limpiar pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de Dibujo
		actualizar();
		dibujar();

		//Intercambio de Buffers
		glfwSwapBuffers(window);
		//Buscar nueva señal de entrada
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
    return 0;
}

