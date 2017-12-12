#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center
	App->camera->Position.y = 1;
	App->camera->Position.x = 1;
	App->camera->LookAt({ 0, -2, -2 });

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference
	Plane plane(0, 1, 0, 0);
	plane.SetPos(0, -1, 0);
	plane.axis = true;
	plane.Render();
	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe
	Sphere sphereDef;
	sphereDef.SetPos(0, -1, 0);
	sphereDef.radius = 0.5f;
	sphereDef.Render();

	Cube cubeDef;
	cubeDef.SetPos(0, -1, 0);
	cubeDef.size = {3, 1, 1};
	cubeDef.wire = true;
	cubeDef.SetRotation(30, { 1, 1, 1 });
	cubeDef.Render();
	
	Cylinder cylinderDef;
	cylinderDef.SetPos(4, 0, 0);
	cylinderDef.radius = 0.5f;
	cylinderDef.wire = true;
	cylinderDef.Render();	

	return UPDATE_CONTINUE;
}

