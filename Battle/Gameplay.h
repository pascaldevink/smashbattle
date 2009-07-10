#ifndef _GAMEPLAY_H
#define _GAMEPLAY_H

#include <vector>

#include "Level.h"
#include "Player.h"
#include "GameplayObject.h"

class Gameplay {
public:
	Gameplay();
	~Gameplay();

	static int frame;

	static Gameplay * instance;

	void run();

	void set_level(Level * level);
	void add_player(Player * player);

	void add_object(GameplayObject * obj);
	void bounce_up_players_and_npcs(SDL_Rect * rect);
protected:
	virtual void initialize();
	virtual void deinitialize();

	void reset_game();
	
	virtual void draw_pause_screen();
	virtual void draw_score();
	virtual void draw_game_ended();
	virtual void draw_countdown();

	bool is_intersecting(SDL_Rect * one, SDL_Rect * two);

	virtual void on_game_reset() = 0;

	virtual void on_pre_processing() = 0;
	virtual void on_post_processing() = 0;

	void process_player_collission();
	void process_npc_collission();

	void handle_pause_input(SDL_Event * event);
	
	bool game_running;

	bool paused;

	bool countdown;
	int countdown_sec_left;
	Timer * countdown_timer;

	bool ended;
	Timer * end_timer;

	SDL_Surface * screen;
	Level * level;

	// Do players collide with each other?
	bool players_collide;
	// Do NPC's collide with each other?
	bool npcs_collide;
	// Do players collide with NPC's?
	bool players_npcs_collide;

	std::vector<Player*> * players;
	//std::vector<NPC*> * npcs;
	
	std::vector<GameplayObject*> * objects;

};

#endif
