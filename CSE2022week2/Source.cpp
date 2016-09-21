#include <GLFW/glfw3.h>
#include <math.h>

const int width = 640*2;
const int height = 480*2;

float *pixels = new float [width*height*3];
//float *pixels = (float*)malloc(sizeof(float)*width *height *3); //C언어 동적할당

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

//void drawcircle(const float& c_x, const float& c_y, const float &r, int num) {
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < num; i++)
//	{
//		float theta = 2.0f * 3.1415926f * float(i) / float(num);//get the current angle
//
//		float x = r * cosf(theta);//calculate the x component
//		float y = r * sinf(theta);//calculate the y component
//
//		glVertex2f(x + c_x, y + c_y);//output vertex
//
//	}
//	glEnd();
//}


void draw() {
	int i_center = 100, j_center = 400 ,i2_center =650, j2_center = 450;
	const int thickness = 3, thickness2 = 49;
	/*const int time = 50;
	int i1 = 600, i2 = 650, i3 = 700, j1 = 100, j2 = 150, j3 = 200;*/
	
	for (int j = j_center - thickness; j < j_center + thickness; j++)
			for (int i = i_center - thickness; i < i_center + thickness; i++) {
				for (int i = 100; i < 200; i++) {
					
					drawPixel(i, j, 0.0f, 0.0f, 0.0f);
					
			}
	}
	
	//square
	drawLine(400, 400, 500, 400, 0.0f, 0.0f, 0.0f);
	drawLine2(400, 400, 400, 500, 0.0f, 0.0f, 0.0f);
	drawLine(400, 500, 500, 500, 0.0f, 0.0f, 0.0f);
	drawLine2(500, 400, 500, 500, 0.0f, 0.0f, 0.0f);
	//square (filled with color)
	drawLine(600, 400, 700, 400, 0.0f, 0.0f, 0.0f);
	drawLine2(600, 400, 600, 500, 0.0f, 0.0f, 0.0f);
	drawLine(600, 500, 700, 500, 0.0f, 0.0f, 0.0f);
	drawLine2(700, 400, 700, 500, 0.0f, 0.0f, 0.0f);
	for (int j = j2_center - thickness2; j < j2_center + thickness2; j++)
		for (int i = i2_center - thickness2; i < i2_center + thickness2; i++) {
			drawPixel(i, j, 1.0f, 1.0f, 0.0f);
			}
	//triangle
	drawLine(100, 100, 200, 100, 0.0f, 0.0f, 0.0f);
	drawLine(100, 100, 150, 200, 0.0f, 0.0f, 0.0f);
	drawLine(150, 200, 200, 100, 0.0f, 0.0f, 0.0f);
	//pentagon
	drawLine(400, 100, 450, 100, 0.0f, 0.0f, 0.0f);
	drawLine(370, 150, 400, 100, 0.0f, 0.0f, 0.0f);
	drawLine(370, 150, 430, 200, 0.0f, 0.0f, 0.0f);
	drawLine(430, 200, 490, 150, 0.0f, 0.0f, 0.0f);
	drawLine(450, 100, 490, 150, 0.0f, 0.0f, 0.0f);
	//circle
	/*for (int i = 0; i < time; i++) {
		drawLine(i2, j1, (i2 + 1), (j1 + 1), 1.0f, 0.0f, 0.0f);
		i2 += 1, j1 += 1;
	}*/
	/*drawLine(650, 100, 660, 110, 1.0f, 0.0f, 0.0f);
	drawLine(660, 110, 670, 115, 1.0f, 0.0f, 0.0f);
	drawLine(670, 115, 685, 130, 1.0f, 0.0f, 0.0f);
	drawLine(685, 130, 690, 140, 1.0f, 0.0f, 0.0f);
	drawLine(690, 140, 700, 150, 1.0f, 0.0f, 0.0f);*/
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