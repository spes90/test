#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "math.h"
#include <stdbool.h>

const int width = 1280;
const int height = 960;
float *pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float&blue) {
	pixels[(i + width*j) * 3 + 0] = red;
	pixels[(i + width*j) * 3 + 1] = green;
	pixels[(i + width*j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawLine2(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int j = j0; j <= j1; j++)
	{
		const int i = (i1 - i0)*(j - j0) / (j1 - j0) + i0;

		drawPixel(i, j, red, green, blue);
	}
}

bool isInsideCircle(double& x, double& y, const int i, const int j, const int r)
{
	y = height - y;
	const double f = (x - i)*(x - i) + (y - j)*(y - j) - r*r;

	if (f > 0.0)
		return false;
	else
		return true;
}

void drawcircle(int x0, int y0, int radius)
{
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		drawPixel(x0 + x, y0 + y, 0.0f, 0.0f, 0.0f);
		drawPixel(x0 + y, y0 + x, 0.0f, 0.0f, 0.0f);
		drawPixel(x0 - y, y0 + x, 0.0f, 0.0f, 0.0f);
		drawPixel(x0 - x, y0 + y, 0.0f, 0.0f, 0.0f);
		drawPixel(x0 - x, y0 - y, 0.0f, 0.0f, 0.0f);
		drawPixel(x0 - y, y0 - x, 0.0f, 0.0f, 0.0f);
		drawPixel(x0 + y, y0 - x, 0.0f, 0.0f, 0.0f);
		drawPixel(x0 + x, y0 - y, 0.0f, 0.0f, 0.0f);

		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

void drawcircle2(int x0, int y0, int radius)
{
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		drawPixel(x0 + x, y0 + y, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 + y, y0 + x, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 - y, y0 + x, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 - x, y0 + y, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 - x, y0 - y, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 - y, y0 - x, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 + y, y0 - x, 0.0f, 0.0f, 1.0f);
		drawPixel(x0 + x, y0 - y, 0.0f, 0.0f, 1.0f);

		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

void changeCircleColor(const int& i0, const int& j0, const int& r, GLFWwindow* window)
{
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	drawcircle(i0, j0, r);
	if (isInsideCircle(xpos, ypos, i0, j0, r) == true)
			drawcircle2(i0, j0, r);
}

void draw() {
	//thick line inside circle
	int i_center = 0, j_center = 550;
	const int thickness = 3;
		
	for (int j = j_center - thickness; j < j_center + thickness; j++)
		for (int i = i_center - thickness; i < i_center + thickness; i++) {
			for (int i = 90; i < thickness+90; i++) {
				drawLine(i, j, 50 +i, 70 +j, 0.0f, 0.0f, 0.0f);
			}
		}
	//thick circle inside circle
	int i_center2 = 330, j_center2 = 600;
	
	for (int j = j_center2 - thickness; j < j_center2 + thickness; j++)
		for (int i = i_center2 - thickness; i < i_center2 + thickness; i++) {
			for (int i = 330; i < thickness + 330; i++) {
				drawcircle(i, j, 25);
			}
		}
	//sqaure inside circle
	drawLine(500, 570, 560, 570, 0.0f, 0.0f, 0.0f);
	drawLine2(500, 570, 500, 630, 0.0f, 0.0f, 0.0f);
	drawLine(500, 630, 560, 630, 0.0f, 0.0f, 0.0f);
	drawLine2(560, 570, 560, 630, 0.0f, 0.0f, 0.0f);
	//'X' inside circle
	drawLine(690, 560, 770, 650, 0.0f, 0.0f, 0.0f);
	drawLine(690, 650, 770, 560, 0.0f, 0.0f, 0.0f);
	//↓ inside circle
	drawLine2(930, 560, 930, 640, 0.0f, 0.0f, 0.0f);
	drawLine(900, 580, 930, 560, 0.0f, 0.0f, 0.0f);
	drawLine(930, 560, 960, 580, 0.0f, 0.0f, 0.0f);
	//→ inside circle
	drawLine(90, 300, 170, 300, 0.0f, 0.0f, 0.0f);
	drawLine(150, 330, 170, 300, 0.0f, 0.0f, 0.0f);
	drawLine(150, 270, 170, 300, 0.0f, 0.0f, 0.0f);
	//'A' inside circle
	drawLine(310, 300, 350, 300, 0.0f, 0.0f, 0.0f);
	drawLine(290, 270, 330, 330, 0.0f, 0.0f, 0.0f);
	drawLine(330, 330, 370, 270, 0.0f, 0.0f, 0.0f);
	//| inside circle
	drawLine2(530, 270, 530, 330, 0.0f, 0.0f, 0.0f);
	//← inside circle
	drawLine(690, 300, 770, 300, 0.0f, 0.0f, 0.0f);
	drawLine(690, 300, 720, 320, 0.0f, 0.0f, 0.0f);
	drawLine(690, 300, 720, 280, 0.0f, 0.0f, 0.0f);
	//↑ inside circle
	drawLine2(930, 270, 930, 330, 0.0f, 0.0f, 0.0f);
	drawLine(910, 310, 930, 330, 0.0f, 0.0f, 0.0f);
	drawLine(930, 330, 950, 310, 0.0f, 0.0f, 0.0f);
		
	drawcircle(330, 600, 75);
	drawcircle(530, 600, 75);
	drawcircle(730, 600, 75);
	drawcircle(930, 600, 75);

	drawcircle(130, 300, 75);
	drawcircle(330, 300, 75);
	drawcircle(530, 300, 75);
	drawcircle(730, 300, 75);
	drawcircle(930, 300, 75);	
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// white background
		for (int j = 0; j < height; j++)
			for (int i = 0; i < width; i++)
			{
				pixels[(i + width*j) * 3 + 0] = 1.0f;
				pixels[(i + width*j) * 3 + 1] = 1.0f;
				pixels[(i + width*j) * 3 + 2] = 1.0f;
			}
		// draw
		draw();
		changeCircleColor(130, 600, 75, window);

		// draw한것을 출력
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
				
	}

	glfwTerminate();
	delete[] pixels;

	return 0;
}