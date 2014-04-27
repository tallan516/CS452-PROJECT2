GLfloat platform_normals[]
{
	-20*norm, -norm, -20*norm,
	-20*norm, -norm, 20*norm,
	20*norm, -norm, 20*norm,
	20*norm, -norm, -20*norm
};

GLfloat platform_vertices[]
{
	-20.0f,-size,-20.0f,	//0 Platform: Back, Left
	-20.0f,-size,20.0f,	//1 Platform: Front, Left
	20.0f,-size,20.0f,	//2 Platform: Front, Right
	20.0f,-size,-20.0f	//3 Platform: Back, Right
};

GLfloat platform_colors[]
{
	1.0f,1.0f,1.0f,1.0f,		//0 Platform: White
	1.0f,1.0f,1.0f,1.0f,		//1 Platform: White
	1.0f,1.0f,1.0f,1.0f,		//2 Platform: White
	1.0f,1.0f,1.0f,1.0f,		//3 Platform: White
};

GLubyte platform_elems[]
{
	0,1,2,0,3,2
};
