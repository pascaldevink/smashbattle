#ifndef _DOUBLEDAMAGEPOWERUP_H
#define _DOUBLEDAMAGEPOWERUP_H

class CommandGeneratePowerup;

class DoubleDamagePowerUp : public GameplayObject {
public:
	DoubleDamagePowerUp(SDL_Surface * surface, SDL_Rect * clip, SDL_Rect * position, int ammo);
	~DoubleDamagePowerUp();

	virtual void move(Level * level);
	virtual void process();

	virtual void hit_player(Player * player);
	virtual void hit_npc(NPC * npc);

	virtual void draw(SDL_Surface * screen, int frames_processed = 0);
	
	virtual void copyTo(CommandGeneratePowerup &powerup);

	SDL_Surface * surface;
	SDL_Rect * clip;
	int ammo;
};

#endif
