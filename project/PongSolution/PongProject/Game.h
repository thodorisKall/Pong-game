#pragma once

#include <vector>
#include "Score.h"
#include "Ball.h"
#include "graphics.h"
#include "Player.h"
#include "Image.h"
#include "MainMenu.h"
#include "GameOver.h"

// state = 0 : main menu
// state = 1 : game playing
// state = 2 : game over, player 1 wins
// state = 3 : game over, player 2 wins

using namespace std;

struct Game {
	int window_width = 1024;
	int window_height = 650;
	float canvas_width = 100.0f;
	float canvas_height = 100.0f;

	Ball ball;
	Score score;
	MainMenu menu;
	GameOver gameOver;
	Player p1 = Player(1);
	Player p2 = Player(2);
	Image background_0 = Image("assets/background.png", canvas_width / 2, canvas_height / 2, canvas_width, canvas_height);
	Image background_1 = Image("assets/st2.png", canvas_width / 2, canvas_height / 2, canvas_width, canvas_height);
	Image background_2 = Image("assets/st3.png", canvas_width / 2, canvas_height / 2, canvas_width, canvas_height);
	Image background_3 = Image("assets/st4.png", canvas_width / 2, canvas_height / 2, canvas_width, canvas_height);
	Image background_4 = Image("assets/st5.png", canvas_width / 2, canvas_height / 2, canvas_width, canvas_height);
	Image background_5 = Image("assets/background.png", canvas_width / 2, canvas_height / 2, canvas_width, canvas_height);
	
	vector<ColorfulGameItem*> drawables;

	int state = 0;

	void init() {

		string openWav = "assets/start.wav";
		graphics::playMusic(openWav, 1.0f, true);

		graphics::Brush br;

		br.fill_color[0] = 0.1f; 
		br.fill_color[1] = 0.1f;
		br.fill_color[2] = 0.0f;

		br.texture = "assets/background.png";

		graphics::setWindowBackground(br);
		graphics::setFont("assets/retroFont.ttf");
		
		drawables.push_back(&ball);
		drawables.push_back(&score);
		drawables.push_back(&p1);
		drawables.push_back(&p2);

		//for (int i = 0; i < drawables.size(); i++) {
			//drawables[i]->start();
		//}
	}


	void startGame() {
		for (int i = 0; i < drawables.size(); i++) {
			drawables[i]->start();
		}		
	}

	void draw() {
		int level = score.getLevel();
		switch (level) {
		case 0:
			background_0.draw();
			break;
		case 1:
			background_1.draw();
			break;
		case 2:
			background_2.draw();
			break;
		case 3:
			background_3.draw();
			break;
		case 4:
			background_4.draw();
			break;
		case 5:
			background_5.draw();
			break;
		}

		for (int i = 0; i < drawables.size(); i++) {
			drawables[i]->draw();
		}
		
		switch (state) {
		case 0:
		{
			// draw main menu
			menu.draw();				
			break;
		}		
		case 2:
		case 3:
		{
			gameOver.state = state;
			gameOver.draw();			
		}		
		}				
	}

	void move() {
		switch (state) {
		case 0:
		{
			if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
				startGame();

				graphics::stopMusic();
				string wav = "assets/game.wav";
				graphics::playMusic(wav, 1.0f, true);

				state = 1;
			}
			break;
		}
		case 1: // game playing
		{
			for (int i = 0; i < drawables.size(); i++) {
				drawables[i]->move();
			}

			if (ball.status == "left") {
				score.scoreForPlayer2++;
			}
			else if (ball.status == "right") {
				score.scoreForPlayer1++;
			}

			if (score.scoreForPlayer1 == 10) {
				state = 2;

				graphics::stopMusic();
				string endWav = "assets/winner.wav";
				graphics::playMusic(endWav, 1.0f, true);
			}
			else if (score.scoreForPlayer2 == 10) {
				state = 3;

				graphics::stopMusic();
				string endWav = "assets/winner.wav";
				graphics::playMusic(endWav, 1.0f, true);
			}
			break;
		}
		case 2:
		{
			if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
				state = 0;
			}
			break;
		}
		case 3:
		{
			if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
				state = 0;
			}
			break;
		}
		}
	}
};