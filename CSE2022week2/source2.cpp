#include <GLFW/glfw3.h>
#include "math.h"
#include <stdbool.h>

const int width = 640;
const int height = 480;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
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

	if (f > 0.0) return false;
	else return true;
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
		drawPixel(x0 + x, y0 + y, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 + y, y0 + x, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 - y, y0 + x, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 - x, y0 + y, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 - x, y0 - y, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 - y, y0 - x, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 + y, y0 - x, 1.0f, 0.0f, 0.0f);
		drawPixel(x0 + x, y0 - y, 1.0f, 0.0f, 0.0f);

		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

void drawCicleChangeColor(const int& i0, const int& j0, const int& r, GLFWwindow* window)
{
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	drawcircle(i0, j0, r);
	if (isInsideCircle(xpos, ypos, i0, j0, r) == true)
	{
		drawcircle2(i0, j0, r);
	}
}

void draw() {
	//thick line inside circle
	int i_center = 70, j_center = 280;
	const int thickness = 3;

	for (int j = j_center - thickness; j < j_center + thickness; j++)
		for (int i = i_center - thickness; i < i_center + thickness; i++) {
			for (int i = 60; i < thickness + 60; i++) {
				drawLine(i, j, 20 + i, 60 + j, 0.0f, 0.0f, 0.0f);
			}
		}
	//thick circle inside circle
	int i_center2 = 190, j_center2 = 300;

	for (int j = j_center2 - thickness; j < j_center2 + thickness; j++)
		for (int i = i_center2 - thickness; i < i_center2 + thickness; i++) {
			for (int i = 190; i < thickness + 190; i++) {
				drawcircle(i, j, 25);
			}
		}
	//sqaure inside circle
	drawLine(290, 270, 350, 270, 0.0f, 0.0f, 0.0f);
	drawLine2(290, 270, 290, 330, 0.0f, 0.0f, 0.0f);
	drawLine(290, 330, 350, 330, 0.0f, 0.0f, 0.0f);
	drawLine2(350, 270, 350, 330, 0.0f, 0.0f, 0.0f);
	//'X' inside circle
	drawLine(430, 280, 470, 320, 0.0f, 0.0f, 0.0f);
	drawLine(430, 320, 470, 280, 0.0f, 0.0f, 0.0f);
	//ก้ inside circle
	drawLine2(580, 280, 580, 320, 0.0f, 0.0f, 0.0f);
	drawLine(560, 300, 580, 280, 0.0f, 0.0f, 0.0f);
	drawLine(580, 280, 600, 300, 0.0f, 0.0f, 0.0f);
	//กๆ inside circle
	drawLine(50, 100, 90, 100, 0.0f, 0.0f, 0.0f);
	drawLine(80, 110, 90, 100, 0.0f, 0.0f, 0.0f);
	drawLine(80, 90, 90, 100, 0.0f, 0.0f, 0.0f);
	//'A' inside circle
	drawLine(180, 100, 200, 100, 0.0f, 0.0f, 0.0f);
	drawLine(170, 70, 190, 120, 0.0f, 0.0f, 0.0f);
	drawLine(190, 120, 210, 70, 0.0f, 0.0f, 0.0f);
	//| inside circle
	drawLine2(320, 70, 320, 130, 0.0f, 0.0f, 0.0f);
	//ก็ inside circle
	drawLine(430, 100, 470, 100, 0.0f, 0.0f, 0.0f);
	drawLine(430, 100, 440, 120, 0.0f, 0.0f, 0.0f);
	drawLine(430, 100, 440, 80, 0.0f, 0.0f, 0.0f);
	//ก่ inside circle
	drawLine2(580, 70, 580, 130, 0.0f, 0.0f, 0.0f);
	drawLine(560, 110, 580, 130, 0.0f, 0.0f, 0.0f);
	drawLine(580, 130, 600, 110, 0.0f, 0.0f, 0.0f);

	drawcircle(70, 300, 50);
	drawcircle(190, 300, 50);
	drawcircle(320, 300, 50);
	drawcircle(450, 300, 50);
	drawcircle(580, 300, 50);

	drawcircle(70, 100, 50);
	drawcircle(190, 100, 50);
	drawcircle(320, 100, 50);
	drawcircle(450, 100, 50);
	drawcircle(580, 100, 50);
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

		//white backboard
		for (int j = 0; j < height; j++)
			for (int i = 0; i < width; i++)
			{
				pixels[(i + width*j) * 3 + 0] = 1.0f;
				pixels[(i + width*j) * 3 + 1] = 1.0f;
				pixels[(i + width*j) * 3 + 2] = 1.0f;
			}

		draw();
		
		drawCicleChangeColor(70, 300, 50, window);
		drawCicleChangeColor(190, 300, 50, window);
		drawCicleChangeColor(320, 300, 50, window);
		drawCicleChangeColor(450, 300, 50, window);
		drawCicleChangeColor(580, 300, 50, window);
		
		drawCicleChangeColor(70, 100, 50, window);
		drawCicleChangeColor(190, 100, 50, window);
		drawCicleChangeColor(320, 100, 50, window);
		drawCicleChangeColor(450, 100, 50, window);
		drawCicleChangeColor(580, 100, 50, window);

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		/*std::this_thread::sleep_for(std::chrono::milliseconds(100));*/
	}

	glfwTerminate();
	delete[] pixels; // or you may reuse pixels array 

	return 0;
}
