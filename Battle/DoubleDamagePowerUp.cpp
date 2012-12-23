#include "SDL/SDL.h"

#include "GameplayObject.h"
#include "DoubleDamagePowerUp.h"
#include "commands/CommandGeneratePowerup.h"

DoubleDamagePowerUp::DoubleDamagePowerUp(SDL_Surface * surface, SDL_Rect * clip, SDL_Rect * position, int ammo) {
	clip->x = 48;
	clip->y = 0;
	this->surface = surface;
	this->clip = clip;
	this->position = position;
	this->ammo = ammo;
	is_powerup = true;
}

DoubleDamagePowerUp::~DoubleDamagePowerUp() {
	delete clip;
	delete position;
}

void DoubleDamagePowerUp::hit_player(Player * p) {
	Main::audio->play(SND_ITEM, p->position->x);

	p->doubledamagebullets += ammo;

	if(p->doubledamagebullets > 99)
		p->doubledamagebullets = 99;

	done = true;
}

void DoubleDamagePowerUp::hit_npc(NPC * npc) {}

void DoubleDamagePowerUp::draw(SDL_Surface * screen, int frames_processed) {
	SDL_BlitSurface(surface, clip, screen, position);
}

void DoubleDamagePowerUp::move(Level * level) {
	if(!level->is_on_bottom(position)) {
		done = true;
	}
}

void DoubleDamagePowerUp::process() {}

void DoubleDamagePowerUp::copyTo(CommandGeneratePowerup &powerup)
{
	GameplayObject::copyTo(powerup);

	powerup.data.type = CommandGeneratePowerup::PowerUps::TypeDoubleDamage;
	powerup.data.param = this->ammo;
}