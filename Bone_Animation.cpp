#include "Bone_Animation.h"



Bone_Animation::Bone_Animation()
{
}


Bone_Animation::~Bone_Animation()
{
}

void Bone_Animation::init()
{
	root_position = { 2.0f,1.0f,2.0f };
	yellowMat = glm::mat4(1.0f);
	pinkMat = glm::mat4(1.0f);
	blueMat = glm::mat4(1.0f);

	x = { 1.0, 0.0, 0.0 };
	y = { 0.0, 1.0, 0.0 };
	z = { 0.0, 0.0, 1.0 };

	scale_vector =
	{
		{1.0f,1.0f,1.0f},			// base to yellow is 1
		{0.5f,4.0f,0.5f},			// yellow has length of 4
		{0.5f,3.0f,0.5f},			// pink has length of 3
		{0.5f,2.0f,0.5f}			// blue has length of 2
	};

	rotation_degree_vector = 
	{
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f}
	};

	colors = 
	{
		{0.7f,0.0f,0.0f,1.0f},
		{0.7f,0.7f,0.0f,1.0f},
		{0.7f,0.0f,0.7f,1.0f},
		{0.0f,0.7f,0.7f,1.0f}
	};

	yellowAngles = { 0.0f, 0.0f, 20.0f };
	pinkAngles =   { 0.0f, 0.0f, 25.0f };
	blueAngles =   { 0.0f, 0.0f, 25.0f };

}

void Bone_Animation::update(float delta_time) 
{

	glm::mat4 yellow = glm::mat4(1.0f);
	glm::mat4 pink = glm::mat4(1.0f);
	glm::mat4 blue = glm::mat4(1.0f);

	//yellow
	yellow = glm::translate(yellow, glm::vec3(2.0f, 1.0f, 2.0f));

	yellow = glm::rotate(yellow, glm::radians(yellowAngles.x), x);
	yellow = glm::rotate(yellow, glm::radians(yellowAngles.y), y);
	yellow = glm::rotate(yellow, glm::radians(yellowAngles.z), z);

	yellow = glm::translate(yellow, glm::vec3(0.0f, 2.0f, 0.0f));
	
	yellow = glm::scale(yellow, scale_vector[1]);
	

	//pink
	pink = glm::translate(pink, glm::vec3(2.0f, 1.0f, 2.0f));

	//rotate by yellows angles
	pink = glm::rotate(pink, glm::radians(yellowAngles.x), x);
	pink = glm::rotate(pink, glm::radians(yellowAngles.y), y);
	pink = glm::rotate(pink, glm::radians(yellowAngles.z), z);

	pink = glm::translate(pink, glm::vec3(0.0f, 2.0f, 0.0f));

	//and pinks
	pink = glm::rotate(pink, glm::radians(pinkAngles.x), x);
	pink = glm::rotate(pink, glm::radians(pinkAngles.y), y);
	pink = glm::rotate(pink, glm::radians(pinkAngles.z), z);

	pink = glm::translate(pink, glm::vec3(0.0f, 3.0f, 0.0f));

	pink = glm::scale(pink, scale_vector[2]);


	//blue
	blue = glm::translate(blue, glm::vec3(2.0f, 1.0f, 2.0f));
	
	//rotate by yellows then pinks then blues
	blue = glm::rotate(blue, glm::radians(yellowAngles.x), x);
	blue = glm::rotate(blue, glm::radians(yellowAngles.y), y);
	blue = glm::rotate(blue, glm::radians(yellowAngles.z), z);

	blue = glm::translate(blue, glm::vec3(0.0f, 2.0f, 0.0f));

	blue = glm::rotate(blue, glm::radians(pinkAngles.x), x);
	blue = glm::rotate(blue, glm::radians(pinkAngles.y), y);
	blue = glm::rotate(blue, glm::radians(pinkAngles.z), z);

	blue = glm::translate(blue, glm::vec3(0.0f, 3.0f, 0.0f));

	blue = glm::rotate(blue, glm::radians(blueAngles.x), x);
	blue = glm::rotate(blue, glm::radians(blueAngles.y), y);
	blue = glm::rotate(blue, glm::radians(blueAngles.z), z);

	blue = glm::translate(blue, glm::vec3(0.0f, 2.0f, 0.0f));

	blue = glm::scale(blue, scale_vector[3]);


	yellowMat = yellow;
	pinkMat = pink;
	blueMat = blue;


}

void Bone_Animation::reset()
{
}

