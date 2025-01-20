#include"thehead.h"

MasterXHWND mxhwnd;
MasterXHWND *MasterXHWND::wnd_instance = 0;

Intro intro;
Start start;
GameUniverse game; 
SoundHandler sound; 
int current_y = 0, id_screen = 0, id_about = 0;
score user_score;
inline void init();
long event(unsigned int, unsigned int msg, unsigned int wparam , unsigned int lparam);

int main() {
	mxhwnd.setfullflag(false);
	if(mxhwnd.CreateMasterX("SuperMasterKong",1024,768,COLOR_DEFAULT,event, 0, 0, 0)) {
		init();
		return (mxhwnd.InitLoop(render));
	}

	return (0);
}

inline void init() {
#ifdef WIN2K_XP_2003
	mxhwnd.InitTimer(1,50);
#else
	mxhwnd.InitTimer(1,1); 
#endif
	mxhwnd.SetScreen(ID_INTRO);
	intro.load();
	start.load();
	game.load();
	sound.load();
	mxhwnd.HideCursor();
}


long event(unsigned int, unsigned int msg, unsigned int wparam , unsigned int lparam) {
	
	switch(msg) {
	case 1: {
			if(wparam == SDLK_ESCAPE)
				mxhwnd.Kill();

			switch(mxhwnd.GetScreen()) {
			case ID_START:
				start.keypress(wparam);
				start.onchar(wparam);
				break;
			case ID_GAME:
				game.keypress(wparam);
				break;
			}
			
		}
		break;
	break;
	default:
	break;
	//	return DefWindowProc(hwnd,msg,wparam,lparam);
	}
	return (0);
}


void render(int screen) {
	mxhwnd.SetTimeFlag(); 
	switch(screen) {
	case ID_INTRO:
		intro.update();
		break;
	case ID_START:
		start.update();
		break;
	case ID_GAME:
		game.update();
		break;
	}
	SDL_Delay(1000/30);
}

inline void this_callback() {
	start.release_particle();
}

inline void newgame() {
	game.newgame();
}

inline void scores_releaseinput() {
	start.releaseinput();
}

inline void releasebullet() {
	game.release_bullet();
}

inline void grandma_died() {
	game.grandmadied();
}

inline void about_setcredits() {
	start.setcredits();
}
inline void about_clearcredits() {
	start.clearcredits();
	start.grannyreset();
}

const inline bool livescheat() {
	return (game.lives_cheat);
}

MasterGraphic *getstartbmp() {
	return ((MasterGraphic*)&start.start);
}