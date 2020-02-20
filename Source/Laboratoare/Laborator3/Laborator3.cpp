#include "Laborator3.h"

#include <vector>
#include <iostream>

#include "Transform2D.h"
#include "Object2D.h"

#include <Core/Engine.h>


using namespace std;


Laborator3::Laborator3()
{
}

Laborator3::~Laborator3()
{
}

void Laborator3::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	glm::vec3 corner = glm::vec3(0, 0, 0);
	float squareSide = 100;

	g = 10;
	vit = 0;

	// compute coordinates of square center
	float cx = corner.x + squareSide / 2;
	float cy = corner.y + squareSide / 2;
	
	// initialize tx and ty (the translation steps)
	translateX = 200;
	translateY = 250; // h la care e pasarea
	translateX1 = 1200;
	translateX2 = 1800;
	translateX3 = 2400;

	score = 1;

	// initialize sx and sy (the scale factors)
	scaleX = 1;
	scaleY = 1;
	
	// initialize angularStep
	angularStep = 0;
	

	Mesh* square1 = Object2D::CreateSquare("square1", corner, squareSide, glm::vec3(1, 1, 0), true);
	AddMeshToList(square1);

	Mesh* rectangle1 = Object2D::CreateRectangle("rectangle1", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(rectangle1);

	Mesh* rectangle2 = Object2D::CreateRectangle("rectangle2", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(rectangle2);

	Mesh* rectangle3 = Object2D::CreateRectangle("rectangle3", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(rectangle3);

	Mesh* squareE = Object2D::CreateSquare("squareE", corner, squareSide, glm::vec3(0, 1, 0), true);
	AddMeshToList(squareE);
	/////////
	Mesh* rectangle4 = Object2D::CreateRectangle("rectangle4", corner, squareSide, glm::vec3(0, 1, 0));
	AddMeshToList(rectangle4);

	Mesh* rectangle5 = Object2D::CreateRectangle("rectangle5", corner, squareSide, glm::vec3(0, 1, 0));
	AddMeshToList(rectangle5);

	Mesh* rectangle6 = Object2D::CreateRectangle("rectangle6", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(rectangle6);
	
	Mesh* rectangle7 = Object2D::CreateRectangle("rectangle7", corner, squareSide, glm::vec3(1, 1, 0));
	AddMeshToList(rectangle7);

	BlocksPos squareColBLOCK = { 0.0f, 0.0f, 0.0f, 100 };
	Mesh* squareCol = Object2D::CreateSquare("squareCol", corner, squareSide, glm::vec3(1, 0, 1), true);
	blocks.insert({ "squareCol", squareColBLOCK });
	AddMeshToList(squareCol);

	Mesh* block1 = Object2D::CreateSquare("block1", corner, squareSide, glm::vec3(0, 0, 0), true);
	AddMeshToList(block1);

	BlocksPos block_2 = {0.0f, 0.0f, 0.0f, 100};
	Mesh* block2 = Object2D::CreateSquare("block2", corner, squareSide, glm::vec3(1, 0, 1), true);
	blocks.insert({ "block2", block_2 });
	AddMeshToList(block2);

	Mesh* block3 = Object2D::CreateSquare("block3", corner, squareSide, glm::vec3(1  , 0, 1), true);
	AddMeshToList(block3);

	BlocksPos block_4 = {0.0f, 0.0f, 0.0f, 100};
	Mesh* block4 = Object2D::CreateSquare("block4", corner, squareSide, glm::vec3(0, 0, 0), true);
	blocks.insert({ "block4", block_4 });
	AddMeshToList(block4);
	
	Mesh* block5 = Object2D::CreateSquare("block5", corner, squareSide, glm::vec3(1, 0, 1), true);
	AddMeshToList(block5);

	BlocksPos block_6 = {0.0f, 0.0f, 0.0f, 100};
	Mesh* block6 = Object2D::CreateSquare("block6", corner, squareSide, glm::vec3(0, 0, 0), true);
	blocks.insert({ "block6", block_6 });
	AddMeshToList(block6);

	/*Mesh* block7 = Object2D::CreateSquare("block7", corner, squareSide, glm::vec3(1, 0, 1), true);
	AddMeshToList(block7);

	BlocksPos block_8 = { 0.0f, 0.0f, 0.0f, 100 };
	Mesh* block8 = Object2D::CreateSquare("block8", corner, squareSide, glm::vec3(0, 0, 0), true);
	blocks.insert({ "block8", block_8 });
	AddMeshToList(block8);

	Mesh* block9 = Object2D::CreateSquare("block9", corner, squareSide, glm::vec3(1, 0, 1), true);
	AddMeshToList(block9);

	BlocksPos block_10 = { 0.0f, 0.0f, 0.0f, 100 };
	Mesh* block10 = Object2D::CreateSquare("block10", corner, squareSide, glm::vec3(0, 0, 0), true);
	blocks.insert({ "block10", block_10 });
	AddMeshToList(block10);

	Mesh* block11 = Object2D::CreateSquare("block11", corner, squareSide, glm::vec3(1, 0, 1), true);
	AddMeshToList(block11);

	BlocksPos block_12 = { 0.0f, 0.0f, 0.0f, 100 };
	Mesh* block12 = Object2D::CreateSquare("block12", corner, squareSide, glm::vec3(0, 0, 0), true);
	blocks.insert({ "block12", block_12 });
	AddMeshToList(block12);

	Mesh* block13 = Object2D::CreateSquare("block13", corner, squareSide, glm::vec3(1, 0, 1), true);
	AddMeshToList(block13);

	BlocksPos block_14 = { 0.0f, 0.0f, 0.0f, 100 };
	Mesh* block14 = Object2D::CreateSquare("block14", corner, squareSide, glm::vec3(0, 0, 0), true);
	blocks.insert({ "block14", block_14 });
	AddMeshToList(block14);*/

}

void Laborator3::print(const BlocksPos& rect) {
	std::cout << rect.posX1 << " " << rect.posX2 << " " << rect.posY1 << " " << rect.posY2 << std::endl;
}

bool Laborator3::collision(const BlocksPos& bird, const BlocksPos& rectangle) {
	if ((rectangle.posX1 <= bird.posX2 && bird.posX1 <= rectangle.posX2) && 
		((rectangle.posY1 >= bird.posY1) || (rectangle.posY2 <= bird.posY2))) 
		return 1;
	return false;
}


bool Laborator3::die(const BlocksPos& fish) {
	for (auto it = blocks.begin(); it != blocks.end(); it++) {
		if (collision(fish, it->second)) {
			return true;
		}
	}
	return false;
}

void Laborator3::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(2, 0, 3, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
}
   
void Laborator3::Update(float deltaTimeSeconds)
{

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(250, 275 + translateY);
	modelMatrix *= Transform2D::Rotate(angularStep);
	modelMatrix *= Transform2D::Translate(40, 5);
	modelMatrix *= Transform2D::Scale(0.09f, 0.09f);
	RenderMesh2D(meshes["squareE"], shaders["VertexColor"], modelMatrix);
	
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(250, 275 + translateY);
	modelMatrix *= Transform2D::Rotate(angularStep);
	modelMatrix *= Transform2D::Translate(0, -25);
	modelMatrix *= Transform2D::Rotate(0.75f);
	modelMatrix *= Transform2D::Scale(0.5f, 0.5f);
	RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(250, 275 + translateY);
	modelMatrix *= Transform2D::Rotate(angularStep);
	modelMatrix *= Transform2D::Translate(35, -60);
	modelMatrix *= Transform2D::Scale(0.7f, 0.7f);
	modelMatrix *= Transform2D::Rotate(1.55f);
	RenderMesh2D(meshes["rectangle1"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(250, 275 + translateY);
	modelMatrix *= Transform2D::Rotate(angularStep);
	modelMatrix *= Transform2D::Translate(40, 75);
	modelMatrix *= Transform2D::Scale(0.7f, 0.7f);
	modelMatrix *= Transform2D::Rotate(3.10f);
	RenderMesh2D(meshes["rectangle2"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(250, 275 + translateY);
	modelMatrix *= Transform2D::Rotate(angularStep);
	modelMatrix *= Transform2D::Translate(70, 5);
	modelMatrix *= Transform2D::Scale(0.5f, 0.5f);
	modelMatrix *= Transform2D::Rotate(2.3f);
	RenderMesh2D(meshes["rectangle3"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(250, 275 + translateY);
	modelMatrix *= Transform2D::Rotate(angularStep);
	modelMatrix *= Transform2D::Translate(-60, 10);
	modelMatrix *= Transform2D::Scale(0.3f, 0.3f);
	RenderMesh2D(meshes["rectangle4"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(250, 275 + translateY);
	modelMatrix *= Transform2D::Rotate(angularStep);
	modelMatrix *= Transform2D::Translate(-60, 15);
	modelMatrix *= Transform2D::Scale(0.3f, 0.3f);
	modelMatrix *= Transform2D::Rotate(4.7f);
	RenderMesh2D(meshes["rectangle5"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(250, 275 + translateY);
	modelMatrix *= Transform2D::Rotate(angularStep);
	modelMatrix *= Transform2D::Translate(-60, -15);
	modelMatrix *= Transform2D::Scale(0.3f, 0.3f);
	modelMatrix *= Transform2D::Rotate(1.58f);
	RenderMesh2D(meshes["rectangle6"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(250, 275 + translateY);
	modelMatrix *= Transform2D::Rotate(angularStep);
	modelMatrix *= Transform2D::Translate(-60, 39);
	modelMatrix *= Transform2D::Scale(0.3f, 0.3f);
	modelMatrix *= Transform2D::Rotate(3.2f);
	RenderMesh2D(meshes["rectangle7"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(155, 213 + translateY);
	modelMatrix *= Transform2D::Scale(1.7f, 1.4f);
	RenderMesh2D(meshes["squareCol"], shaders["VertexColor"], modelMatrix);
	fish = { 155 , 1.4f * (213 + translateY), 1.7f * 255, 1.4f * (313 + translateY) };
	//print(fish);

	///////////////////////////////////////////////
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(translateX1, 150);
	modelMatrix *= Transform2D::Scale(3.0f, 4.0f);
	RenderMesh2D(meshes["block2"], shaders["VertexColor"], modelMatrix);
	blocks["block2"].posX1 = 100 + translateX1;
	blocks["block2"].posY1 = 150;
	blocks["block2"].posX2 = (translateX1 + 150) * 3;
	blocks["block2"].posY2 = 720;
	//print(blocks["block2"]);
	//cout << blocks["block2"].posX << endl;
	
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(translateX1, 0);
	modelMatrix *= Transform2D::Scale(3.0f, 750.0f);
	RenderMesh2D(meshes["block1"], shaders["VertexColor"], modelMatrix);


	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(translateX2, 50);
	modelMatrix *= Transform2D::Scale(3.0f, 6.0f);
	RenderMesh2D(meshes["block3"], shaders["VertexColor"], modelMatrix);
	blocks["block3"].posX1 = 100 + translateX2;
	blocks["block3"].posY1 = 50;//50 * 6.0
	blocks["block3"].posX2 = (150 + translateX2) * 3;
	blocks["block3"].posY2 = 900;//150*6

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(translateX2, 0);
	modelMatrix *= Transform2D::Scale(3.0f, 750.0f);
	RenderMesh2D(meshes["block4"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(translateX3, 50);
	modelMatrix *= Transform2D::Scale(3.0f, 3.0f);
	RenderMesh2D(meshes["block5"], shaders["VertexColor"], modelMatrix);
	blocks["block5"].posX1 = 100 + translateX3;
	blocks["block5"].posY1 = 50;
	blocks["block5"].posX2 = (150 + translateX3) * 3;
	blocks["block5"].posY2 = 450;

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(translateX3 , 0);
	modelMatrix *= Transform2D::Scale(3.0f, 750.0f);
	RenderMesh2D(meshes["block6"], shaders["VertexColor"], modelMatrix);

	if (translateY > -450) {
		translateY += vit / 2;
		vit -= g * deltaTimeSeconds;
	}

	else {
		translateY = -400;
	}
	
	if (translateX1 > -500) {
		translateX1 -= 2;
	}

	else {
		translateX1 = 1300;
		score++;
	}

	if (translateX2 > -500) {
		translateX2 -= 2;
	}

	else {
		translateX2 = 1300;
		score++;
	}

	if (translateX3 > -500) {
		translateX3 -= 2;
	}

	else {
		translateX3 = 1300;
		score++;
	}

	if (angularStep > -1) {
		angularStep -= g / 10 * deltaTimeSeconds;
	}

	if (die(fish)) {
		cout << "YOUR SCORE: " << score << endl;
		cout << "GAME OVER";
		exit(0);
	}
	
}

void Laborator3::FrameEnd()
{

}

void Laborator3::OnInputUpdate(float deltaTime, int mods)
{
	
}

void Laborator3::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_SPACE) {
		angularStep = 0.75; 
		vit = 5;
	}
	// add key press event
}

void Laborator3::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Laborator3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Laborator3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Laborator3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Laborator3::OnWindowResize(int width, int height)
{
}
