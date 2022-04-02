#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"

#include "Defs.h"
#include "Log.h"
#include "ModuleFonts.h"
#include <stdio.h>

Scene::Scene() : Module()
{
	name.Create("scene");
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene::Start()
{
	char lookupTable1[] = { "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[£]çç€!ççç%&'()*+,-.^0123456789:;<=>?/abcdefghijklmnopqrstuvwxyz ççççççç" };
	font1 = app->fonts->Load("Assets/Textures/UI/font1_white_2.png", lookupTable1, 6);
	font2 = app->fonts->Load("Assets/Textures/UI/font1_black_3.png", lookupTable1, 6);
	font3 = app->fonts->Load("Assets/Textures/UI/font1_white_1.png", lookupTable1, 6);
	img = app->tex->Load("Assets/Textures/test.png");

	////////////////////////////
	example = 1;

	//EXAMPLE 1
	bg = app->tex->Load("Assets/Textures/example1_bg.png");
	letters = app->tex->Load("Assets/Textures/example1_letters.png");
	slider = app->tex->Load("Assets/Textures/example1_slider.png");

	example1Tween.smoothness = 5;
	example1Tween.Set();


	totalTweenings = 0;
	tweeningTime = 100;
	tweeningEasingType = 0;

	//EXAMPLE 2
	map = app->tex->Load("Assets/Textures/map.png");
	sign = app->tex->Load("Assets/Textures/sign.png");
	tree = app->tex->Load("Assets/Textures/tree.png");

	cameraTween.Set();
	cameraTween.AddTween(100, 200, BACK_IN_OUT);

	player1.x = 300;
	player1.y = 300;
	player1.speed = 4;

	UIelements = app->tex->Load("Assets/Textures/UI/UI_elements.png");
	panel = { 0, 312, 672, 432 };
	button1 = { 320, 116, 132, 48 };
	button2 = { 180, 116, 132, 48 };
	button_small = { 412, 60, 48, 48 };

	UI_panelTween.Set();
	UI_panelTween.AddTween(100, 150, BACK_OUT);

	UI_button1Tween.Set();
	UI_button1Tween.Wait(30);
	UI_button1Tween.AddTween(100, 100, BOUNCE_OUT);

	UI_button2Tween.Set();
	UI_button2Tween.AddTween(100, 100, BOUNCE_OUT);


	UI_button3Tween.Set();
	UI_button3Tween.Wait(50);
	UI_button3Tween.AddTween(100, 100, BACK_OUT);


	menuOpen = false;

	return true;
}

// Called each loop iteration
bool Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene::Update(float dt)
{
	

	if (app->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		example = 1;
	}
	if (app->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		example = 2;
	}

	switch (example)
	{
	case 0:
	{
		

	}
	break;

	case 1:
	{

		if (app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		{
			tweeningEasingType++;
			
			
		}

		if (app->input->GetKey(SDL_SCANCODE_X) == KEY_DOWN)
		{
			tweeningEasingType--;

		}


		char *easingType = "";

		switch (tweeningEasingType)
		{
		case -1:
		{
			tweeningEasingType = 31;
		}
		break;
		case 32:
		{
			tweeningEasingType = 0;
		}
		break;

		case 0:
		{
			example1Tween.SetEasing(DEF);
			 easingType = "DEFAULT";
		}	
			break;
		case 1:
		{
			example1Tween.SetEasing(LINEAR);
			easingType = "Linear";
		}
		break;
		case 2:
		{
			example1Tween.SetEasing(STEPPED);
			easingType = "Stepped";
		}
		break;
		case 3:
		{
			example1Tween.SetEasing(QUADRATIC_IN);
			easingType = "Quadratic In";
		}
		break;
		case 4:
		{
			example1Tween.SetEasing(QUADRATIC_OUT);
			easingType = "Quadratic Out";
		}
		break;
		case 5:
		{
			example1Tween.SetEasing(QUADRATIC_IN_OUT);
			easingType = "Quadratic In Out";
		}
		break;
		case 6:
		{
			example1Tween.SetEasing(CUBIC_IN);
			easingType = "Cubic In";
		}
		break;
		case 7:
		{
			example1Tween.SetEasing(CUBIC_OUT);
			easingType = "Cubic Out";
		}
		break;
		case 8:
		{
			example1Tween.SetEasing(CUBIC_IN_OUT);
			easingType = "Cubic In Out";
		}
		break;
		case 9:
		{
			example1Tween.SetEasing(QUARTIC_IN);
			easingType = "Quartic In";
		}
		break;
		case 10:
		{
			example1Tween.SetEasing(QUARTIC_OUT);
			easingType = "Quartic Out";
		}
		break;
		case 11:
		{
			example1Tween.SetEasing(QUARTIC_IN_OUT);
			easingType = "Quartic In Out";
		}
		break;
		case 12:
		{
			example1Tween.SetEasing(QUINTIC_IN);
			easingType = "Quintic In";
		}
		break;
		case 13:
		{
			example1Tween.SetEasing(QUINTIC_OUT);
			easingType = "Quintic Out";
		}
		break;
		case 14:
		{
			example1Tween.SetEasing(QUINTIC_IN_OUT);
			easingType = "Quintic In Out";
		}
		break;
		case 15:
		{
			example1Tween.SetEasing(SINUSOIDAL_IN);
			easingType = "Sinusoidal In";
		}
		break;
		case 16:
		{
			example1Tween.SetEasing(SINUSOIDAL_OUT);
			easingType = "Sinusoidal Out";
		}
		break;
		case 17:
		{
			example1Tween.SetEasing(SINUSOIDAL_IN_OUT);
			easingType = "Sinusoidal In Out";
		}
		break;
		case 18:
		{
			example1Tween.SetEasing(EXPONENTIAL_IN);
			easingType = "Exponential In";
		}
		break;
		case 19:
		{
			example1Tween.SetEasing(EXPONENTIAL_OUT);
			easingType = "Exponential Out";
		}
		break;
		case 20:
		{
			example1Tween.SetEasing(EXPONENTIAL_IN_OUT);
			easingType = "Exponential In Out";
		}
		break;
		case 21:
		{
			example1Tween.SetEasing(CIRCULAR_IN);
			easingType = "Circular In";
		}
		break;
		case 22:
		{
			example1Tween.SetEasing(CIRCULAR_OUT);
			easingType = "Circular In Out";
		}
		break;
		case 23:
		{
			example1Tween.SetEasing(BOUNCE_IN);
			easingType = "Bounce In";
		}
		break;
		case 24:
		{
			example1Tween.SetEasing(BOUNCE_OUT);
			easingType = "Bounce Out";
		}
		break;
		case 25:
		{
			example1Tween.SetEasing(BOUNCE_IN_OUT);
			easingType = "Bounce In Out";
		}
		break;
		case 26:
		{
			example1Tween.SetEasing(ELASTIC_IN);
			easingType = "Elastic In";
		}
		break;
		case 27:
		{
			example1Tween.SetEasing(ELASTIC_OUT);
			easingType = "Elastic Out";
		}
		break;
		case 28:
		{
			example1Tween.SetEasing(ELASTIC_IN_OUT);
			easingType = "Elastic In Out";
		}
		break;
		case 29:
		{
			example1Tween.SetEasing(BACK_IN);
			easingType = "Back In";
		}
		break;
		case 30:
		{
			example1Tween.SetEasing(BACK_OUT);
			easingType = "Back Out";
		}
		break;
		case 31:
		{
			example1Tween.SetEasing(BACK_IN_OUT);
			easingType = "Back In Out";
		}
		break;

		default:
			example1Tween.SetEasing(DEF);
			easingType = "DEFAULT";
			break;
		}

		if (app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN)
		{
			if (totalTweenings < 4)
			{
				totalTweenings++;
				example1Tween.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);
			}
			

		}

		if (app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN)
		{
			if (totalTweenings > 0)
			{
				totalTweenings--;
				example1Tween.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);
			}

		}

		if (app->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
		{
			totalTweenings = 0;
			example1Tween.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);

		}
		if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
		{
			totalTweenings = 1;
			example1Tween.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);

		}
		if (app->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
		{
			totalTweenings = 2;
			example1Tween.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);

		}
		if (app->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
		{
			totalTweenings = 3;
			example1Tween.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);

		}
		if (app->input->GetKey(SDL_SCANCODE_T) == KEY_DOWN)
		{
			totalTweenings = 4;
			example1Tween.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);

		}

		if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
		{
			tweeningTime += 10;

		}

		if (app->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN)
		{
			tweeningTime -= 10;

		}

		

		example1Tween.Step(2, false);

		float point = example1Tween.GetPoint();

		float prog = example1Tween.Main().progress();
		float dur = example1Tween.Main().duration();

		/*LOG("progress %f", prog);
		LOG("duration %f", dur);
		LOG("point %f", point);*/
		app->render->DrawTexture(bg, point * -1280, 0);
		app->render->DrawTexture(slider, 1280 / 2 - 506 / 2 + point * 100, 50);
		app->render->DrawTexture(slider, 1280 / 2 - 506 / 2 + point * 100, 180);
		app->render->DrawTexture(letters, 1280 / 2 - 506 / 2, 50);

		char tweeningT[16];
		sprintf_s(tweeningT, "%i", tweeningTime);
		

		app->fonts->DrawText(20, 300, font3, "Use [Arrows] to move horizontally.");
		app->fonts->DrawText(20, 330, font3, "Use A and Z to change the Tweening Time.");
		app->fonts->DrawText(20, 360, font3, "Use S and X to change the Easing Mode.");

		app->fonts->DrawText(20, 540, font1, "Easing Mode:");
		app->fonts->DrawText(20, 580, font1, easingType);

		app->fonts->DrawText(20, 640, font1, "Tweening Time:");
		app->fonts->DrawText(20, 680, font1, tweeningT);

		app->fonts->DrawText(1280 / 2 - 506 / 2 - 50, 75, font2, "<");
		app->fonts->DrawText(1280 / 2 + 506 / 2 + 10, 75, font2, ">");
	}
	break;
	
	case 2:
	{
		
		if (!menuOpen)
		{

			if (app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
			{
				player1.x += player1.speed;
			}
			if (app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
			{
				player1.x -= player1.speed;

			}
			if (app->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
			{
				player1.y -= player1.speed;

			}
			if (app->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
			{
				player1.y += player1.speed;

			}
		}

		cameraTween.Step(1, false);
		
		if ((player1.x > 500 && player1.x < 580) &&
			(player1.y > 400 && player1.y < 480))
		{
			cameraTween.Foward();
		}
		else 
		{
			cameraTween.Backward();
		}

		app->render->DrawTexture(map, 0, 80);
		app->render->DrawTexture(sign, 500, 400);
		app->render->DrawTexture(tree, 1000, 100);
		SDL_Rect playerRect = { player1.x - 20,player1.y - 60,40,60 + 20 };
		app->render->DrawRectangle(playerRect, 255, 255, 255, 180);
		app->render->DrawCircle(player1.x + app->render->camera.x, player1.y, 3, 255, 255, 255, 180,false);

		float prog = cameraTween.Main().progress();
		float dur = cameraTween.Main().duration();
		float point = cameraTween.GetPoint();

		LOG("progress %f", prog);
		LOG("duration %f", dur);
		LOG("point %f", point);

		app->render->camera.x = -point * 300;

		

		if (app->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN)
		{
			menuOpen = !menuOpen;

		}

		if (menuOpen)
		{
			UI_panelTween.Foward();
			UI_button1Tween.Foward();
			UI_button2Tween.Foward();
			UI_button3Tween.Foward();

		}
		else 
		{
			UI_panelTween.Backward();
			UI_button1Tween.Backward();
			UI_button2Tween.Backward();
			UI_button3Tween.Backward();

		}

		UI_panelTween.Step(1, false);
		UI_button1Tween.Step(1, false);
		UI_button2Tween.Step(1, false);
		UI_button3Tween.Step(1, false);

		int offset = 500;

		point = UI_panelTween.GetPoint();
		app->render->DrawTexture(UIelements, 1280 / 2 - 672 / 2,  -offset + point * (100 + offset), 1, 1, 255, &panel, 0);
		app->fonts->DrawText(1280 / 2 - (16 + 8) * 5, -offset + point * (120 + offset), font2, "Pause");

		point = UI_button1Tween.GetPoint();
		app->render->DrawTexture(UIelements, 1280 / 2 - 132 - 20, -offset + point * (450 + offset), 1, 1, 255, &button1, 0);

		point = UI_button2Tween.GetPoint();
		app->render->DrawTexture(UIelements, 1280 / 2 + 20, -offset + point * (450 + offset), 1, 1, 255, &button2, 0);

		point = UI_button3Tween.GetPoint();
		app->render->DrawTexture(UIelements, 1280 / 2 + 672 / 2 - 150, -offset + point * (150 + offset), 1, 1, 255, &button_small, 0);


	}
	default:
		break;
	}







	return true;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;

	if(app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
