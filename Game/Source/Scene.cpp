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

	twExample.smoothness = 5;
	twExample.Set();


	totalTweenings = 0;
	tweeningTime = 100;
	tweeningEasingType = 0;

	//EXAMPLE 2
	map = app->tex->Load("Assets/Textures/map.png");
	sign = app->tex->Load("Assets/Textures/sign.png");
	tree = app->tex->Load("Assets/Textures/tree.png");
	inventory = app->tex->Load("Assets/Textures/UI/inventory.png");

	twCamera.Set();
	twCamera.AddTween(100, 200, BACK_IN_OUT);

	player1.x = 300;
	player1.y = 300;
	player1.speed = 4;

	UIelements = app->tex->Load("Assets/Textures/UI/UI_elements.png");
	panel = { 0, 312, 672, 432 };
	button1 = { 320, 116, 132, 48 };
	button2 = { 180, 116, 132, 48 };
	button_small = { 412, 60, 48, 48 };

	tw_UI_inventory.Set();
	tw_UI_inventory.smoothness = 4;
	tw_UI_inventory.AddTween(100, 50, EXPONENTIAL_OUT);

	tw_UI_panel.Set();
	tw_UI_panel.AddTween(100, 150, BACK_OUT);

	tw_UI_btn_Save.Set();
	tw_UI_btn_Save.Wait(30);
	tw_UI_btn_Save.AddTween(40, 80, Easings::SINUSOIDAL_IN);
	tw_UI_btn_Save.AddTween(100, 80, BOUNCE_OUT);

	tw_UI_btn_Load.Set();
	tw_UI_btn_Load.AddTween(40, 80, SINUSOIDAL_IN);
	tw_UI_btn_Load.AddTween(100, 80, BOUNCE_OUT);


	tw_UI_btn_Return.Set();
	tw_UI_btn_Return.Wait(50);
	tw_UI_btn_Return.AddTween(100, 100, BACK_OUT);


	menuOpen = false;
	inventoryOpen = false;


	//EXAMPLE 3
	trollface = app->tex->Load("Assets/Textures/UI/trollface.png");
	trollfacetweeningTime = 100;

	tw_size.Set();
	tw_size.smoothness = 4;

	tw_alpha.Set();
	tw_alpha.smoothness = 4;

	tw_angle.Set();
	tw_angle.smoothness = 4;

	tw_R.Set();
	tw_R.smoothness = 4;

	tw_G.Set();
	tw_G.smoothness = 4;

	tw_B.Set();
	tw_B.smoothness = 4;

	growing = true;
	rotating = true;
	opaque = true;
	R_ = true;
	G_ = true;
	B_ = true;
	activeGrow = true;
	activeRotation = true;
	activeAlpha = true;
	activeR = true;
	activeG = true;
	activeB = true;

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
	if (app->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		example = 3;
	}

	switch (example)
	{
	case 0:
	{
		

	}
	break;

	case 1:
	{
		app->render->camera.x = 0;

		app->fonts->DrawText(20, 10, font3, "Example 1/3");

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
			twExample.SetEasing(DEF);
			 easingType = "DEFAULT";
		}	
			break;
		case 1:
		{
			twExample.SetEasing(LINEAR);
			easingType = "Linear";
		}
		break;
		case 2:
		{
			twExample.SetEasing(STEPPED);
			easingType = "Stepped";
		}
		break;
		case 3:
		{
			twExample.SetEasing(QUADRATIC_IN);
			easingType = "Quadratic In";
		}
		break;
		case 4:
		{
			twExample.SetEasing(QUADRATIC_OUT);
			easingType = "Quadratic Out";
		}
		break;
		case 5:
		{
			twExample.SetEasing(QUADRATIC_IN_OUT);
			easingType = "Quadratic In Out";
		}
		break;
		case 6:
		{
			twExample.SetEasing(CUBIC_IN);
			easingType = "Cubic In";
		}
		break;
		case 7:
		{
			twExample.SetEasing(CUBIC_OUT);
			easingType = "Cubic Out";
		}
		break;
		case 8:
		{
			twExample.SetEasing(CUBIC_IN_OUT);
			easingType = "Cubic In Out";
		}
		break;
		case 9:
		{
			twExample.SetEasing(QUARTIC_IN);
			easingType = "Quartic In";
		}
		break;
		case 10:
		{
			twExample.SetEasing(QUARTIC_OUT);
			easingType = "Quartic Out";
		}
		break;
		case 11:
		{
			twExample.SetEasing(QUARTIC_IN_OUT);
			easingType = "Quartic In Out";
		}
		break;
		case 12:
		{
			twExample.SetEasing(QUINTIC_IN);
			easingType = "Quintic In";
		}
		break;
		case 13:
		{
			twExample.SetEasing(QUINTIC_OUT);
			easingType = "Quintic Out";
		}
		break;
		case 14:
		{
			twExample.SetEasing(QUINTIC_IN_OUT);
			easingType = "Quintic In Out";
		}
		break;
		case 15:
		{
			twExample.SetEasing(SINUSOIDAL_IN);
			easingType = "Sinusoidal In";
		}
		break;
		case 16:
		{
			twExample.SetEasing(SINUSOIDAL_OUT);
			easingType = "Sinusoidal Out";
		}
		break;
		case 17:
		{
			twExample.SetEasing(SINUSOIDAL_IN_OUT);
			easingType = "Sinusoidal In Out";
		}
		break;
		case 18:
		{
			twExample.SetEasing(EXPONENTIAL_IN);
			easingType = "Exponential In";
		}
		break;
		case 19:
		{
			twExample.SetEasing(EXPONENTIAL_OUT);
			easingType = "Exponential Out";
		}
		break;
		case 20:
		{
			twExample.SetEasing(EXPONENTIAL_IN_OUT);
			easingType = "Exponential In Out";
		}
		break;
		case 21:
		{
			twExample.SetEasing(CIRCULAR_IN);
			easingType = "Circular In";
		}
		break;
		case 22:
		{
			twExample.SetEasing(CIRCULAR_OUT);
			easingType = "Circular Out";
		}
		break;
		case 23:
		{
			twExample.SetEasing(BOUNCE_IN);
			easingType = "Bounce In";
		}
		break;
		case 24:
		{
			twExample.SetEasing(BOUNCE_OUT);
			easingType = "Bounce Out";
		}
		break;
		case 25:
		{
			twExample.SetEasing(BOUNCE_IN_OUT);
			easingType = "Bounce In Out";
		}
		break;
		case 26:
		{
			twExample.SetEasing(ELASTIC_IN);
			easingType = "Elastic In";
		}
		break;
		case 27:
		{
			twExample.SetEasing(ELASTIC_OUT);
			easingType = "Elastic Out";
		}
		break;
		case 28:
		{
			twExample.SetEasing(ELASTIC_IN_OUT);
			easingType = "Elastic In Out";
		}
		break;
		case 29:
		{
			twExample.SetEasing(BACK_IN);
			easingType = "Back In";
		}
		break;
		case 30:
		{
			twExample.SetEasing(BACK_OUT);
			easingType = "Back Out";
		}
		break;
		case 31:
		{
			twExample.SetEasing(BACK_IN_OUT);
			easingType = "Back In Out";
		}
		break;

		default:
			twExample.SetEasing(DEF);
			easingType = "DEFAULT";
			break;
		}

		if (app->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN)
		{
			if (totalTweenings < 4)
			{
				totalTweenings++;
				twExample.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);
			}
			

		}

		if (app->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN)
		{
			if (totalTweenings > 0)
			{
				totalTweenings--;
				twExample.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);
			}

		}

		if (app->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
		{
			totalTweenings = 0;
			twExample.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);

		}
		if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
		{
			totalTweenings = 1;
			twExample.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);

		}
		if (app->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
		{
			totalTweenings = 2;
			twExample.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);

		}
		if (app->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
		{
			totalTweenings = 3;
			twExample.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);

		}
		if (app->input->GetKey(SDL_SCANCODE_T) == KEY_DOWN)
		{
			totalTweenings = 4;
			twExample.AddTween(totalTweenings * 100, tweeningTime, BOUNCE_OUT);

		}

		if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
		{
			tweeningTime += 10;

		}

		if (app->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN)
		{
			tweeningTime -= 10;

		}

		

		twExample.Step(2, false);

		float point = twExample.GetPoint();

		float prog = twExample.Main().progress();
		float dur = twExample.Main().duration();

		/*LOG("progress %f", prog);
		LOG("duration %f", dur);
		LOG("point %f", point);*/
		app->render->DrawTexture(bg, point * -1280, 0);
		app->render->DrawTexture(slider, 1280 / 2 - 506 / 2 + point * 100, 50);
		app->render->DrawTexture(slider, 1280 / 2 - 506 / 2 + point * 100, 180);
		app->render->DrawTexture(letters, 1280 / 2 - 506 / 2, 50);
		app->fonts->DrawText(20, 10, font3, "Example 1/3");

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
		app->fonts->DrawText(20, 10, font3, "Example 2/3");

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

		if (!menuOpen) twCamera.Step(1, false);
		
		if ((player1.x > 500 && player1.x < 580) &&
			(player1.y > 400 && player1.y < 480))
		{
			twCamera.Foward();
		}
		else 
		{
			twCamera.Backward();
		}

		app->render->DrawTexture(map, 0, 80);
		app->render->DrawTexture(sign, 500, 400);
		app->render->DrawTexture(tree, 1000, 100);
		SDL_Rect playerRect = { player1.x - 20,player1.y - 60,40,60 + 20 };
		app->render->DrawRectangle(playerRect, 255, 255, 255, 180);
		app->render->DrawCircle(player1.x + app->render->camera.x, player1.y, 3, 255, 255, 255, 180,false);

		
		float point = twCamera.GetPoint();

		app->render->camera.x = -point * 300;

		

		if (app->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN)
		{
			menuOpen = !menuOpen;

		}

		if (menuOpen)
		{
			tw_UI_panel.Foward();
			tw_UI_btn_Save.Foward();
			tw_UI_btn_Load.Foward();
			tw_UI_btn_Return.Foward();
			

		}
		else 
		{
			tw_UI_panel.Backward();
			tw_UI_btn_Save.Backward();
			tw_UI_btn_Load.Backward();
			tw_UI_btn_Return.Backward();

			if (app->input->GetKey(SDL_SCANCODE_I) == KEY_DOWN)
			{
				inventoryOpen = !inventoryOpen;

			}
			
		}


		tw_UI_inventory.Step(1, false);

		if (inventoryOpen)
		{
			tw_UI_inventory.Foward();

		}
		else
		{
			tw_UI_inventory.Backward();

		}

		tw_UI_panel.Step(1, false);
		tw_UI_btn_Save.Step(1, false);
		tw_UI_btn_Load.Step(1, false);
		tw_UI_btn_Return.Step(1, false);

		
		
		int offset = 720;

		point = tw_UI_inventory.GetPoint();
		app->render->DrawTexture(inventory, 1280 / 2 - 528 / 2, offset + point * (400 - offset));


		offset = -500;

		app->fonts->DrawText(50, 40, font3, "Press [P] to Pause and [I] to open Inventory");
		app->fonts->DrawText(50, 40 + 32, font3, "Use [Arrows] to move the player");
		app->fonts->DrawText(50, 40 + 32 * 2, font3, "Move to the Sign to move camera");


		point = tw_UI_panel.GetPoint();
		app->render->DrawTexture(UIelements, 1280 / 2 - 672 / 2, offset + point * (100 - offset), 1, 1, 255, &panel, 0);
		app->fonts->DrawText(1280 / 2 - (16 + 8) * 5, offset + point * (120 + offset), font2, "Pause");

		point = tw_UI_btn_Save.GetPoint();
		app->render->DrawTexture(UIelements, 1280 / 2 - 132 - 20, offset + point * (450 - offset), 1, 1, 255, &button1, 0);

		point = tw_UI_btn_Load.GetPoint();
		app->render->DrawTexture(UIelements, 1280 / 2 + 20, offset + point * (450 - offset), 1, 1, 255, &button2, 0);

		point = tw_UI_btn_Return.GetPoint();
		app->render->DrawTexture(UIelements, 1280 / 2 + 672 / 2 - 150, offset + point * (150 - offset), 1, 1, 255, &button_small, 0);
	}
	break;
	case 3:
	{
		app->render->DrawTexture(bg, 0, 0);

		app->fonts->DrawText(20,10, font3, "Example 3/3");

		if (app->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
		{
			trollfaceTweeningType--;

		}

		if (app->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
		{
			trollfaceTweeningType++;

		}

		if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
		{
			if (trollfacetweeningTime > 0) trollfacetweeningTime -= 10;

		}

		if (app->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)
		{
			trollfacetweeningTime += 10;

		}

		if (app->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN)
		{
			activeGrow = !activeGrow;

		}

		if (app->input->GetKey(SDL_SCANCODE_X) == KEY_DOWN)
		{
			activeRotation = !activeRotation;

		}

		if (app->input->GetKey(SDL_SCANCODE_C) == KEY_DOWN)
		{
			activeAlpha = !activeAlpha;

		}

		if (app->input->GetKey(SDL_SCANCODE_V) == KEY_DOWN)
		{
			activeR = !activeR;

		}

		if (app->input->GetKey(SDL_SCANCODE_B) == KEY_DOWN)
		{
			activeG= !activeG;

		}

		if (app->input->GetKey(SDL_SCANCODE_N) == KEY_DOWN)
		{
			activeB = !activeB;

		}


		char* easingType = "";

		app->render->camera.x = 0;
		

		if (tw_size.Progress() == 1)
		{
			if (growing)
			{
				tw_size.AddTween(0, trollfacetweeningTime, DEF);
				growing = !growing;
			}
			else {
				tw_size.AddTween(100, trollfacetweeningTime, DEF);
				growing = !growing;

			}
		}

		if (tw_alpha.Progress() == 1)
		{
			if (opaque)
			{
				tw_alpha.AddTween(0, trollfacetweeningTime, DEF);
				opaque = !opaque;
			}
			else {
				tw_alpha.AddTween(100, trollfacetweeningTime, DEF);
				opaque = !opaque;

			}
		}

		if (tw_angle.Progress() == 1)
		{
			if (rotating)
			{
				tw_angle.AddTween(0, trollfacetweeningTime, DEF);
				rotating = !rotating;
			}
			else {
				tw_angle.AddTween(100, trollfacetweeningTime, DEF);
				rotating = !rotating;

			}
		}

		if (tw_R.Progress() == 1)
		{
			if (R_)
			{
				tw_R.AddTween(0, trollfacetweeningTime, DEF);
				R_ = !R_;
			}
			else {
				tw_R.AddTween(100, trollfacetweeningTime, DEF);
				R_ = !R_;

			}
		}

		if (tw_G.Progress() == 1)
		{
			if (G_)
			{
				tw_G.AddTween(0, trollfacetweeningTime, DEF);
				G_ = !G_;
			}
			else {
				tw_G.AddTween(100, trollfacetweeningTime, DEF);
				G_ = !G_;

			}
		}

		if (tw_B.Progress() == 1)
		{
			if (B_)
			{
				tw_B.AddTween(0, trollfacetweeningTime, DEF);
				B_ = !B_;
			}
			else {
				tw_B.AddTween(100, trollfacetweeningTime, DEF);
				B_ = !B_;

			}
		}

			/*
	tw_size.Set();
	tw_alpha.Set();
	tw_angle.Set();
	tw_R.Set();
	tw_G.Set();
	tw_B.Set();
	*/
		switch (trollfaceTweeningType)
		{
		case -1:
		{
			trollfaceTweeningType = 31;
		}
		break;
		case 32:
		{
			trollfaceTweeningType = 0;
		}
		break;

		case 0:
		{
			tw_size.SetEasing(DEF);
			tw_alpha.SetEasing(DEF);
			tw_angle.SetEasing(DEF);
			tw_R.SetEasing(DEF);
			tw_G.SetEasing(DEF);
			tw_B.SetEasing(DEF);
			easingType = "DEFAULT";
		}
		break;
		case 1:
		{
			tw_size.SetEasing(LINEAR);
			tw_alpha.SetEasing(LINEAR);
			tw_angle.SetEasing(LINEAR);
			tw_R.SetEasing(LINEAR);
			tw_G.SetEasing(LINEAR);
			tw_B.SetEasing(LINEAR);
			easingType = "Linear";
		}
		break;
		case 2:
		{
			twExample.SetEasing(STEPPED);
			tw_size.SetEasing(STEPPED);
			tw_alpha.SetEasing(STEPPED);
			tw_angle.SetEasing(STEPPED);
			tw_R.SetEasing(STEPPED);
			tw_G.SetEasing(STEPPED);
			tw_B.SetEasing(STEPPED);
			easingType = "Stepped";
		}
		break;
		case 3:
		{
			twExample.SetEasing(QUADRATIC_IN);
			tw_size.SetEasing(QUADRATIC_IN);
			tw_alpha.SetEasing(QUADRATIC_IN);
			tw_angle.SetEasing(QUADRATIC_IN);
			tw_R.SetEasing(QUADRATIC_IN);
			tw_G.SetEasing(QUADRATIC_IN);
			tw_B.SetEasing(QUADRATIC_IN);
			easingType = "Quadratic In";
		}
		break;
		case 4:
		{
			twExample.SetEasing(QUADRATIC_OUT);
			tw_size.SetEasing(QUADRATIC_OUT);
			tw_alpha.SetEasing(QUADRATIC_OUT);
			tw_angle.SetEasing(QUADRATIC_OUT);
			tw_R.SetEasing(QUADRATIC_OUT);
			tw_G.SetEasing(QUADRATIC_OUT);
			tw_B.SetEasing(QUADRATIC_OUT);
			easingType = "Quadratic Out";
		}
		break;
		case 5:
		{
			twExample.SetEasing(QUADRATIC_IN_OUT);
			tw_size.SetEasing(QUADRATIC_IN_OUT);
			tw_alpha.SetEasing(QUADRATIC_IN_OUT);
			tw_angle.SetEasing(QUADRATIC_IN_OUT);
			tw_R.SetEasing(QUADRATIC_IN_OUT);
			tw_G.SetEasing(QUADRATIC_IN_OUT);
			tw_B.SetEasing(QUADRATIC_IN_OUT);
			easingType = "Quadratic In Out";
		}
		break;
		case 6:
		{
			twExample.SetEasing(CUBIC_IN);
			tw_size.SetEasing(CUBIC_IN);
			tw_alpha.SetEasing(CUBIC_IN);
			tw_angle.SetEasing(CUBIC_IN);
			tw_R.SetEasing(CUBIC_IN);
			tw_G.SetEasing(CUBIC_IN);
			tw_B.SetEasing(CUBIC_IN);
			easingType = "Cubic In";
		}
		break;
		case 7:
		{
			twExample.SetEasing(CUBIC_OUT);
			tw_size.SetEasing(CUBIC_OUT);
			tw_alpha.SetEasing(CUBIC_OUT);
			tw_angle.SetEasing(CUBIC_OUT);
			tw_R.SetEasing(CUBIC_OUT);
			tw_G.SetEasing(CUBIC_OUT);
			tw_B.SetEasing(CUBIC_OUT);
			easingType = "Cubic Out";
		}
		break;
		case 8:
		{
			twExample.SetEasing(CUBIC_IN_OUT);
			tw_size.SetEasing(CUBIC_IN_OUT);
			tw_alpha.SetEasing(CUBIC_IN_OUT);
			tw_angle.SetEasing(CUBIC_IN_OUT);
			tw_R.SetEasing(CUBIC_IN_OUT);
			tw_G.SetEasing(CUBIC_IN_OUT);
			tw_B.SetEasing(CUBIC_IN_OUT);
			easingType = "Cubic In Out";
		}
		break;
		case 9:
		{
			twExample.SetEasing(QUARTIC_IN);
			tw_size.SetEasing(QUARTIC_IN);
			tw_alpha.SetEasing(QUARTIC_IN);
			tw_angle.SetEasing(QUARTIC_IN);
			tw_R.SetEasing(QUARTIC_IN);
			tw_G.SetEasing(QUARTIC_IN);
			tw_B.SetEasing(QUARTIC_IN);
			easingType = "Quartic In";
		}
		break;
		case 10:
		{
			twExample.SetEasing(QUARTIC_OUT);
			tw_size.SetEasing(QUARTIC_OUT);
			tw_alpha.SetEasing(QUARTIC_OUT);
			tw_angle.SetEasing(QUARTIC_OUT);
			tw_R.SetEasing(QUARTIC_OUT);
			tw_G.SetEasing(QUARTIC_OUT);
			tw_B.SetEasing(QUARTIC_OUT);
			easingType = "Quartic Out";
		}
		break;
		case 11:
		{
			twExample.SetEasing(QUARTIC_IN_OUT);
			tw_size.SetEasing(QUARTIC_IN_OUT);
			tw_alpha.SetEasing(QUARTIC_IN_OUT);
			tw_angle.SetEasing(QUARTIC_IN_OUT);
			tw_R.SetEasing(QUARTIC_IN_OUT);
			tw_G.SetEasing(QUARTIC_IN_OUT);
			tw_B.SetEasing(QUARTIC_IN_OUT);
			easingType = "Quartic In Out";
		}
		break;
		case 12:
		{
			twExample.SetEasing(QUINTIC_IN);
			tw_size.SetEasing(QUINTIC_IN);
			tw_alpha.SetEasing(QUINTIC_IN);
			tw_angle.SetEasing(QUINTIC_IN);
			tw_R.SetEasing(QUINTIC_IN);
			tw_G.SetEasing(QUINTIC_IN);
			tw_B.SetEasing(QUINTIC_IN);
			easingType = "Quintic In";
		}
		break;
		case 13:
		{
			twExample.SetEasing(QUINTIC_OUT);
			tw_size.SetEasing(QUINTIC_OUT);
			tw_alpha.SetEasing(QUINTIC_OUT);
			tw_angle.SetEasing(QUINTIC_OUT);
			tw_R.SetEasing(QUINTIC_OUT);
			tw_G.SetEasing(QUINTIC_OUT);
			tw_B.SetEasing(QUINTIC_OUT);
			easingType = "Quintic Out";
		}
		break;
		case 14:
		{
			twExample.SetEasing(QUINTIC_IN_OUT);
			tw_size.SetEasing(QUINTIC_IN_OUT);
			tw_alpha.SetEasing(QUINTIC_IN_OUT);
			tw_angle.SetEasing(QUINTIC_IN_OUT);
			tw_R.SetEasing(QUINTIC_IN_OUT);
			tw_G.SetEasing(QUINTIC_IN_OUT);
			tw_B.SetEasing(QUINTIC_IN_OUT);
			easingType = "Quintic In Out";
		}
		break;
		case 15:
		{
			twExample.SetEasing(SINUSOIDAL_IN);
			tw_size.SetEasing(SINUSOIDAL_IN);
			tw_alpha.SetEasing(SINUSOIDAL_IN);
			tw_angle.SetEasing(SINUSOIDAL_IN);
			tw_R.SetEasing(SINUSOIDAL_IN);
			tw_G.SetEasing(SINUSOIDAL_IN);
			tw_B.SetEasing(SINUSOIDAL_IN);
			easingType = "Sinusoidal In";
		}
		break;
		case 16:
		{
			twExample.SetEasing(SINUSOIDAL_OUT);
			tw_size.SetEasing(SINUSOIDAL_OUT);
			tw_alpha.SetEasing(SINUSOIDAL_OUT);
			tw_angle.SetEasing(SINUSOIDAL_OUT);
			tw_R.SetEasing(SINUSOIDAL_OUT);
			tw_G.SetEasing(SINUSOIDAL_OUT);
			tw_B.SetEasing(SINUSOIDAL_OUT);
			easingType = "Sinusoidal Out";
		}
		break;
		case 17:
		{
			twExample.SetEasing(SINUSOIDAL_IN_OUT);
			tw_size.SetEasing(SINUSOIDAL_IN_OUT);
			tw_alpha.SetEasing(SINUSOIDAL_IN_OUT);
			tw_angle.SetEasing(SINUSOIDAL_IN_OUT);
			tw_R.SetEasing(SINUSOIDAL_IN_OUT);
			tw_G.SetEasing(SINUSOIDAL_IN_OUT);
			tw_B.SetEasing(SINUSOIDAL_IN_OUT);
			easingType = "Sinusoidal In Out";
		}
		break;
		case 18:
		{
			twExample.SetEasing(EXPONENTIAL_IN);
			tw_size.SetEasing(EXPONENTIAL_IN);
			tw_alpha.SetEasing(EXPONENTIAL_IN);
			tw_angle.SetEasing(EXPONENTIAL_IN);
			tw_R.SetEasing(EXPONENTIAL_IN);
			tw_G.SetEasing(EXPONENTIAL_IN);
			tw_B.SetEasing(EXPONENTIAL_IN);
			easingType = "Exponential In";
		}
		break;
		case 19:
		{
			twExample.SetEasing(EXPONENTIAL_OUT);
			tw_size.SetEasing(EXPONENTIAL_OUT);
			tw_alpha.SetEasing(EXPONENTIAL_OUT);
			tw_angle.SetEasing(EXPONENTIAL_OUT);
			tw_R.SetEasing(EXPONENTIAL_OUT);
			tw_G.SetEasing(EXPONENTIAL_OUT);
			tw_B.SetEasing(EXPONENTIAL_OUT);
			easingType = "Exponential Out";
		}
		break;
		case 20:
		{
			twExample.SetEasing(EXPONENTIAL_IN_OUT);
			tw_size.SetEasing(EXPONENTIAL_IN_OUT);
			tw_alpha.SetEasing(EXPONENTIAL_IN_OUT);
			tw_angle.SetEasing(EXPONENTIAL_IN_OUT);
			tw_R.SetEasing(EXPONENTIAL_IN_OUT);
			tw_G.SetEasing(EXPONENTIAL_IN_OUT);
			tw_B.SetEasing(EXPONENTIAL_IN_OUT);
			easingType = "Exponential In Out";
		}
		break;
		case 21:
		{
			twExample.SetEasing(CIRCULAR_IN);
			tw_size.SetEasing(CIRCULAR_IN);
			tw_alpha.SetEasing(CIRCULAR_IN);
			tw_angle.SetEasing(CIRCULAR_IN);
			tw_R.SetEasing(CIRCULAR_IN);
			tw_G.SetEasing(CIRCULAR_IN);
			tw_B.SetEasing(CIRCULAR_IN);
			easingType = "Circular In";
		}
		break;
		case 22:
		{
			twExample.SetEasing(CIRCULAR_OUT);
			tw_size.SetEasing(CIRCULAR_OUT);
			tw_alpha.SetEasing(CIRCULAR_OUT);
			tw_angle.SetEasing(CIRCULAR_OUT);
			tw_R.SetEasing(CIRCULAR_OUT);
			tw_G.SetEasing(CIRCULAR_OUT);
			tw_B.SetEasing(CIRCULAR_OUT);
			easingType = "Circular Out";
		}
		break;
		case 23:
		{
			twExample.SetEasing(BOUNCE_IN);
			tw_size.SetEasing(BOUNCE_IN);
			tw_alpha.SetEasing(BOUNCE_IN);
			tw_angle.SetEasing(BOUNCE_IN);
			tw_R.SetEasing(BOUNCE_IN);
			tw_G.SetEasing(BOUNCE_IN);
			tw_B.SetEasing(BOUNCE_IN);
			easingType = "Bounce In";
		}
		break;
		case 24:
		{
			twExample.SetEasing(BOUNCE_OUT);
			tw_size.SetEasing(BOUNCE_OUT);
			tw_alpha.SetEasing(BOUNCE_OUT);
			tw_angle.SetEasing(BOUNCE_OUT);
			tw_R.SetEasing(BOUNCE_OUT);
			tw_G.SetEasing(BOUNCE_OUT);
			tw_B.SetEasing(BOUNCE_OUT);
			easingType = "Bounce Out";
		}
		break;
		case 25:
		{
			twExample.SetEasing(BOUNCE_IN_OUT);
			tw_size.SetEasing(BOUNCE_IN_OUT);
			tw_alpha.SetEasing(BOUNCE_IN_OUT);
			tw_angle.SetEasing(BOUNCE_IN_OUT);
			tw_R.SetEasing(BOUNCE_IN_OUT);
			tw_G.SetEasing(BOUNCE_IN_OUT);
			tw_B.SetEasing(BOUNCE_IN_OUT);
			easingType = "Bounce In Out";
		}
		break;
		case 26:
		{
			twExample.SetEasing(ELASTIC_IN);
			tw_size.SetEasing(ELASTIC_IN);
			tw_alpha.SetEasing(ELASTIC_IN);
			tw_angle.SetEasing(ELASTIC_IN);
			tw_R.SetEasing(ELASTIC_IN);
			tw_G.SetEasing(ELASTIC_IN);
			tw_B.SetEasing(ELASTIC_IN);
			easingType = "Elastic In";
		}
		break;
		case 27:
		{
			twExample.SetEasing(ELASTIC_OUT);
			tw_size.SetEasing(ELASTIC_OUT);
			tw_alpha.SetEasing(ELASTIC_OUT);
			tw_angle.SetEasing(ELASTIC_OUT);
			tw_R.SetEasing(ELASTIC_OUT);
			tw_G.SetEasing(ELASTIC_OUT);
			tw_B.SetEasing(ELASTIC_OUT);
			easingType = "Elastic Out";
		}
		break;
		case 28:
		{
			twExample.SetEasing(ELASTIC_IN_OUT);
			tw_size.SetEasing(ELASTIC_IN_OUT);
			tw_alpha.SetEasing(ELASTIC_IN_OUT);
			tw_angle.SetEasing(ELASTIC_IN_OUT);
			tw_R.SetEasing(ELASTIC_IN_OUT);
			tw_G.SetEasing(ELASTIC_IN_OUT);
			tw_B.SetEasing(ELASTIC_IN_OUT);
			easingType = "Elastic In Out";
		}
		break;
		case 29:
		{
			twExample.SetEasing(BACK_IN);
			tw_size.SetEasing(BACK_IN);
			tw_alpha.SetEasing(BACK_IN);
			tw_angle.SetEasing(BACK_IN);
			tw_R.SetEasing(BACK_IN);
			tw_G.SetEasing(BACK_IN);
			tw_B.SetEasing(BACK_IN);
			easingType = "Back In";
		}
		break;
		case 30:
		{
			twExample.SetEasing(BACK_OUT);
			tw_size.SetEasing(BACK_OUT);
			tw_alpha.SetEasing(BACK_OUT);
			tw_angle.SetEasing(BACK_OUT);
			tw_R.SetEasing(BACK_OUT);
			tw_G.SetEasing(BACK_OUT);
			tw_B.SetEasing(BACK_OUT);
			easingType = "Back Out";
		}
		break;
		case 31:
		{
			twExample.SetEasing(BACK_IN_OUT);
			tw_size.SetEasing(BACK_IN_OUT);
			tw_alpha.SetEasing(BACK_IN_OUT);
			tw_angle.SetEasing(BACK_IN_OUT);
			tw_R.SetEasing(BACK_IN_OUT);
			tw_G.SetEasing(BACK_IN_OUT);
			tw_B.SetEasing(BACK_IN_OUT);
			easingType = "Back In Out";
		}
		break;

		default:
			twExample.SetEasing(DEF);
			tw_size.SetEasing(DEF);
			tw_alpha.SetEasing(DEF);
			tw_angle.SetEasing(DEF);
			tw_R.SetEasing(DEF);
			tw_G.SetEasing(DEF);
			tw_B.SetEasing(DEF);
			easingType = "DEFAULT";
			break;
		}

		tw_size.Step(1, false);
		tw_alpha.Step(1, false);
		tw_angle.Step(1, false);
		tw_R.Step(1, false);
		tw_G.Step(1, false);
		tw_B.Step(1, false);

		SDL_Rect square = { 310,0,300,25 };

		SDL_Rect r_size = square;
		r_size.y = 50;
		app->render->DrawRectangle(r_size, 128, 128, 128, 255);
		app->fonts->DrawText(20, r_size.y + 5, font3, "[Z] Size:");

		SDL_Rect r_rotating = square;
		r_rotating.y = 100;
		app->render->DrawRectangle(r_rotating, 128, 128, 128, 255);
		app->fonts->DrawText(20, r_rotating.y + 5, font3, "[X] Rotation:");

		SDL_Rect r_alpha = square;
		r_alpha.y = 150;
		app->render->DrawRectangle(r_alpha, 128, 128, 128, 255);
		app->fonts->DrawText(20, r_alpha.y + 5, font3, "[C] Opacity:");


		SDL_Rect r_r = square;
		r_r.y = 200;
		app->render->DrawRectangle(r_r, 128, 128, 128, 255);
		app->fonts->DrawText(20, r_r.y + 5, font3, "[V] Channel Red:");


		SDL_Rect r_g = square;
		r_g.y = 250;
		app->render->DrawRectangle(r_g, 128, 128, 128, 255);
		app->fonts->DrawText(20, r_g.y + 5, font3, "[B] Channel Green:");


		SDL_Rect r_b = square;
		r_b.y = 300;
		app->render->DrawRectangle(r_b, 128, 128, 128, 255);
		app->fonts->DrawText(20, r_b.y + 5, font3, "[N] Channel Blue:");




		float grow;
		float rot ;
		float a   ;
		float r   ;
		float g   ;
		float b   ;

		if (activeGrow) grow = tw_size.GetPoint();
		else grow = 1;

		if (activeRotation) rot = tw_angle.GetPoint();
		else rot = 0;

		if (activeAlpha) a = tw_alpha.GetPoint();
		else a = 1;

		if (activeR) r = tw_R.GetPoint();
		else r = 1;

		if (activeG) g = tw_G.GetPoint();
		else g = 1;

		if (activeB) b = tw_B.GetPoint();
		else b = 1;

		/*
		 = tw_size.GetPoint();
		 = tw_size.GetPoint();
		 = tw_size.GetPoint();
		 = tw_size.GetPoint();
		 = tw_size.GetPoint();
		 = tw_size.GetPoint();		
		*/
		SDL_SetTextureColorMod(trollface, r * 255, g * 255, b * 255);
		app->render->DrawTextureExt(trollface, 1280 / 2 + 300, 720 / 2, 0.5f + grow * 0.5f, 0.5f + grow * 0.5f, a * 255, NULL, 1, rot * 360,388/2,388/2);
		
		


		SDL_Rect r_size2 = r_size;
		r_size2.w = grow * r_size.w;
		app->render->DrawRectangle(r_size2, 250, 100, 255, 255);

		SDL_Rect r_rotating2 = r_rotating;
		r_rotating2.w = rot * r_rotating.w;
		app->render->DrawRectangle(r_rotating2, 170, 100, 255, 255);

		SDL_Rect r_alpha2 = r_alpha;
		r_alpha2.w = a * r_alpha.w;
		app->render->DrawRectangle(r_alpha2, 170, 255, 107, 255);

		SDL_Rect r_r2 = r_r;
		r_r2.w = r * r_r.w;
		app->render->DrawRectangle(r_r2, 255, 0, 0, 255);

		SDL_Rect r_g2 = r_g;
		r_g2.w = g * r_g.w;
		app->render->DrawRectangle(r_g2, 0, 255, 0, 255);

		SDL_Rect r_b2 = r_b;
		r_b2.w = b * r_b.w;
		app->render->DrawRectangle(r_b2, 0, 0, 255, 255);


		LOG("size %f", grow);
		LOG("size %i", trollfaceTweeningType);

		app->fonts->DrawText(20, 540, font1, "Easing Mode:");
		app->fonts->DrawText(20, 580, font1, easingType);

		char tweeningT[16];
		sprintf_s(tweeningT, "%i", trollfacetweeningTime);

		app->fonts->DrawText(20, 640, font1, "Tweening Time:");
		app->fonts->DrawText(20, 680, font1, tweeningT);

	}break;
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
