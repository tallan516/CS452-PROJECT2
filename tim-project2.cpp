#include "timShader.h"
#include "shape.h"
#include "cube.h"
#include "platform.h"

#include "SDL2/SDL.h"

using namespace std;

GLuint abuffer;
GLuint buffer[3];
GLuint ebuffer;
GLuint program;

glm::vec3 translate_vec;

GLfloat pit = 1;
GLfloat yaw = 1;

//GLfloat xAccel = 0;
//GLfloat zAccel = 0;

Shape *platform;
Shape *cube;


//Declare functions
void init();
void display(SDL_Window* window);
void input(SDL_Window* window);


int main(int argc, char **argv)
{
	//Main method stuff
	SDL_Window *window;	//SDL window
	if(SDL_Init(SDL_INIT_VIDEO) < 0)	//Tries to intitiate SDL
	{
		cerr << "Error, cannot initialize SDL." << endl;
		SDL_Quit();	//Close out of SDL
		exit(0);	//End program
	}

	//Create window
	window = SDL_CreateWindow("CS452-PROJECT2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_OPENGL);

	//Check window creation
	if(window == NULL)
	{
		cerr << "Error, cannot create window." << endl;
	}

	SDL_GLContext glcontext = SDL_GL_CreateContext(window);	//Creates opengl context associated with the window
	glewInit();	//Initializes glew
	
	init();	//Calls function to initialize the shaders and set up buffers
	
	//Keep looping through to make sure
	while(true)
	{
		input(window);	//Check keyboard input
		display(window);	//Render
	}

	//Close out of SDL stuff
	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

void display(SDL_Window* window)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);	//Clears the frame buffer
	
	platform->bind_buffers();
	platform->draw(program);
	cube->bind_buffers();
	cube->draw(program);
	
	glFlush();	//Makes sure all data is rendered as soon as possible
	SDL_GL_SwapWindow(window);	//Updates the window
}

void input(SDL_Window* window)
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
			cube->input2(window);
			platform->input2(window);
		}
	}
}

void init()
{
      glEnable(GL_DEPTH_TEST);
      glEnable(GL_COLOR_MATERIAL);
      //glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
      
      program = glCreateProgram();	//Creates program
	initShaders(program);	//Calls the initialize shader function in the header file
      
      platform = new Shape(platform_normals, platform_vertices, platform_colors, platform_elems,
      	sizeof(platform_normals), sizeof(platform_vertices), sizeof(platform_colors), sizeof(platform_elems));
      cube = new Shape(cube_normals, cube_vertices, cube_colors, cube_elems,
      	sizeof(cube_normals), sizeof(cube_vertices), sizeof(cube_colors), sizeof(cube_elems));
      
}








