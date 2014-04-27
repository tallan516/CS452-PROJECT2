GLfloat cube_normals[]
{
	-norm,-norm,-norm,
	norm,-norm,-norm,
	norm,-norm,norm,
	-norm,-norm,norm,
	-norm,norm,-norm,
	norm,norm,-norm,
	norm,norm,norm,
	-norm,norm,norm
};

GLfloat cube_vertices[]
{
	-size,-size,-size,	//0 Left, Bottom, Far
	size,-size,-size,		//1 Right, Bottom, Far
	size,-size,size,		//2 Right, Bottom, Near
	-size,-size,size,		//3 Left, Bottom, Near
	-size,size,-size,		//4 Left, Top, Far
	size,size,-size,		//5 Right, Top, Far
	size,size,size,		//6 Right, Top, Near
	-size,size,size		//7 Left, Top, Near
};

GLfloat cube_colors[]
{
	0.0f,0.0f,1.0f,1.0f,		//0 Blue
	0.0f,0.0f,1.0f,1.0f,		//1 Blue
	0.0f,0.0f,1.0f,1.0f,		//2 Blue
	0.0f,0.0f,1.0f,1.0f,		//3 Blue
	0.0f,0.0f,1.0f,1.0f,		//4 Blue
	0.0f,0.0f,1.0f,1.0f,		//5 Blue
	0.0f,0.0f,1.0f,1.0f,		//6 Blue
	0.0f,0.0f,1.0f,1.0f		//7 Blue
};

GLubyte cube_elems[]
{
	2,3,0,1,2,0,		//Bottom
	5,4,7,6,5,7,		//Top
	6,7,3,2,6,3,		//Front
	4,5,1,0,4,1,		//Back
	7,4,0,3,7,0,		//Left
	5,6,2,1,5,2,		//Right
};
