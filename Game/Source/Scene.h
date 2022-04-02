#ifndef __SCENE_H__
#define __SCENE_H__

#include "Module.h"
#include "Tweening.h"

struct SDL_Texture;

class BasicPlayer
{
public:
	BasicPlayer()
	{
		x = 0, y = 0;
	}
	~BasicPlayer() {}
	int x, y;
	float speed;
private:
	
};

class Scene : public Module
{
public:

	Scene();

	// Destructor
	virtual ~Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

private:
	SDL_Texture* img;
	

	int example;

	//EXAMPLE 1
	SDL_Texture* bg;
	SDL_Texture* letters;
	SDL_Texture* slider;
	Tween example1Tween;
	int totalTweenings;
	int tweeningTime;
	int tweeningEasingType;

	int font1;
	int font2;
	int font3;

	//EXAMPLE 2
	SDL_Texture* map;
	SDL_Texture* sign;
	SDL_Texture* tree;
	SDL_Texture* UIelements;
	SDL_Rect panel;
	SDL_Rect button1;
	SDL_Rect button2;
	SDL_Rect button_small;

	Tween cameraTween;
	Tween UI_panelTween;
	Tween UI_button1Tween;
	Tween UI_button2Tween;
	Tween UI_button3Tween;

	BasicPlayer player1;

	bool menuOpen;
	//Example 3
	Tween tweenHammer;
	Tween tweenGhost;
	Tween tweenJaws;


};




#endif // __SCENE_H__