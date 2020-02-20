#pragma once

#include <Component/SimpleScene.h>
#include <unordered_map>
#include <string>
#include <Core/Engine.h>

struct BlocksPos {
	float posX1;
	float posY1;
	float posX2;
	float posY2;
};

class Laborator3 : public SimpleScene
{
	public:
		Laborator3();
		~Laborator3();

		void Init() override;
		bool die(const BlocksPos& bird);
		bool collision(const BlocksPos& bird, const BlocksPos& rectangle);
		void print(const BlocksPos& rect);

	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

	protected:
		float g;
		float vit;
		glm::mat3 modelMatrix;
		float translateX, translateY, translateX1, translateX2, translateX3;
		float scaleX, scaleY;
		int score;
		float angularStep;
		
	public:
		std::unordered_map<std::string, BlocksPos> blocks;
		BlocksPos fish;
};
