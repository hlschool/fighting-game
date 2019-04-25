/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/
//
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Apply the image
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

Greetings.And welcome.Welcome to Papa's house. Today is an exciting day in the history of Papa John's.Come on in, we'll talk about it. This morning, we launched our papajohns.com worldwide website. We've been working 18 months for this day.The site is easier, it's simpler, and it's more engaging.And I've got a special guest that's gonna walk us through this.I think you'll like him. Come on in. I got my best friend, my helper, my son Bo. "Bo's in the house!" Bo, I am so excited. Lot of hard work, by a lot of great people. We're launching a new refined, Papa John dot com website throughout the world. And you know what's most exciting? I get to do it with you! "You mean you get to watch me do it ? " Hey. I'm high pizza, low tech. "I'm high tech, high pizza." Alright, let's go. "What kind of pizza do you want dad?" Let's do a zesty Jalapeño and meats. Uh and let's go to the pizza builder.Those Jalapeños, they got a kick, you know what I'm saying? "Pretty cool, now I'm making a pizza." Heh heh, you're making the pizza? This is fantastic Bo, but you know I've never ordered anything on the internet? "Where have you been ? " Thanks. "Always here for you dad." Eh heh heh heh heh heh... This looks like fun. "Yeah it's easy, fun. Even you could probably do it." Eh heh heh heh heh... Thanks buddy. How about a Papa's Favorite.My favorite for 26 years now.Pepperoni, sausage, and six cheese. "How's that look?" It looks fantastic. "Alright how bout some coke?" I'll have a couple sodie pops. Two of the world's favorite.Coca - cola and Papa John's. "Some cheese sticks?" I love our cheese sticks. At papajohns.com you always get great value- for your money. "Oh really dad, you save some money?" Yeah we save some money. "That means you can raise my allowance!" You're always working on me.Man this is quick!I mean real quick!Two pies, order of cheese sticks, couple sodie pops. "Alright there? Ready to check out?" Let it happen, captain. "Done." Man I gotta tell you.That was fast. "I'd say so." That was real fast!We're making history! Click of the mouse, and papa's in the house.Hey!Matt!How you doin ? 'Good' You remember Bo ? 'Mmhmm' Matt's one of a 100,000 team members that make Papa John's great.We're real proud of him, he does a terrific job. And you've been with us two years ? 'Yep' Two years ? I paid for these online already. 'Yep' And I gave you a tip 'Mmhmm, big tip' I got these Bo. "Naah. I'll be taking those." You got em ? "Yes." Appreciate ya!. 'Thank You.' Thanks for comin' by, and Matt just made history. He's the first delivery driver to deliver Papa John's worldwide at papajohns.com On the internet site today, and we're real proud of him.So tell the team, thanks for the pizzas, great job, and have a great day. 'You too' Alright man 'Thanks!' Thank you!Appreciate ya!Where'd Bo run off with those pizzas?