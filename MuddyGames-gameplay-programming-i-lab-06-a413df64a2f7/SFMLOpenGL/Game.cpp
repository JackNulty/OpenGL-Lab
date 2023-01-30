#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x /window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES); {
		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(1.0, -1.0, -5.0);
	}
	glEnd();
	glLineWidth(6);
	glBegin(GL_LINES); {
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f ,-5.0f);
		glVertex3f(1.0f, 1.0f ,-5.0f);
	}
	glEnd();
	glBegin(GL_LINE_STRIP); {
		glVertex3f(-1.0f, 1.0f, -5.0f);
		glVertex3f(1.0f, 1.0f, -5.0f);
		glVertex3f(1.0f, 2.0f, -5.0f);
	}
	glEnd();
	glBegin(GL_LINE_LOOP); {
		glVertex3f(-1.1f, 1.1f, -5.0f);
		glVertex3f(1.1f, 1.1f, -5.0f);
		glVertex3f(1.1f, 2.1f, -5.0f);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN); { // the tumor
		glVertex3f(0.0, 1.0, -5.0);
		glVertex3f(-1.0, -1.0, -5.0);
		glVertex3f(1.0, -1.0, -5.0);
		
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glBegin(GL_QUADS); {
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -10.0f);
		glVertex3f(-1.0f, 1.0f, -10.0f);
		glVertex3f(1.0f, -1.0f, -10.0f);
		glVertex3f(-1.0f, -1.0f, -10.0f);
	}
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

