#include "GL/glew.h"
#include "GL/freeglut.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "SDL2/SDL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

GLfloat norm = 1.0f / sqrt(3.0f);
GLfloat size = 1.0f;

class Shape
{
	GLuint vaoID, vboID[3], eboID;
	GLfloat *vertices;
	GLfloat *colors;
	GLfloat *normals;
	GLubyte *elements;
	int vsize;
	int csize;
	int nsize;
	int esize;
	GLfloat pit=0, yaw=0;
	glm::vec3 translate_vec;
	public:
		Shape(GLfloat* n, GLfloat* v, GLfloat* c, GLubyte* e, int nsize, int vsize, int csize, int esize);
	~Shape();
	void bind_buffers();
	void draw(GLuint program);
	void input2(SDL_Window* window);
};

Shape::Shape(GLfloat* n, GLfloat* v, GLfloat* c, GLubyte* e, int nsiz, int vsiz, int csiz, int esiz)
{
	vertices = v;
	colors = c;
	normals = n;
	elements = e;
	nsize = nsiz;
	vsize = vsiz;
	csize = csiz;
	esize = esiz;
}

Shape::~Shape()
{
	delete[] vertices;
	delete[] colors;
	delete[] normals;
	delete[] elements;
}

void Shape::bind_buffers()
{
	glGenVertexArrays(1,&vaoID);
	glGenBuffers(3,vboID);
	glGenBuffers(1,&eboID);
	
	glBindVertexArray(vaoID);
	
	glBindBuffer(GL_ARRAY_BUFFER, vboID[0]);
	glBufferData(GL_ARRAY_BUFFER, vsize, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, esize, elements, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vboID[1]);
	glBufferData(GL_ARRAY_BUFFER, csize, colors, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, vboID[2]);
	glBufferData(GL_ARRAY_BUFFER, nsize, normals, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
}

void Shape::draw(GLuint program)
{
	glm::mat4 trans;
	trans=glm::translate(trans, translate_vec);
	trans=glm::rotate(trans,pit,glm::vec3(1, 0, 0));
	trans=glm::rotate(trans,yaw,glm::vec3(0, 0, 1));

	GLint tempLoc = glGetUniformLocation(program,"modelMatrix");//Matrix that handle the transformations
	glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans[0][0]);
	
	cout << esize << endl;
	
	glDrawElements(GL_TRIANGLES, esize, GL_UNSIGNED_BYTE, NULL);
}

void Shape::input2(SDL_Window* window)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))	//Handling the keyboard
	{
		if(event.type == SDL_QUIT)
		{
			exit(0);
		}
		else if(event.type == SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
				case SDLK_ESCAPE: exit(0);
				case SDLK_i: pit+=2; break;
				case SDLK_k: pit-=2; break;
				case SDLK_j: yaw+=2; break;
				case SDLK_l: yaw-=2; break;
				
				case SDLK_w: translate_vec.y+=2; break;
				case SDLK_s: translate_vec.y-=2; break;
				case SDLK_a: translate_vec.x-=2; break;
				case SDLK_d: translate_vec.x+=2; break;
			}
		}
	}
}







