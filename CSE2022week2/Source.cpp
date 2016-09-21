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

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	float theta = 2 * 3.1415926 / (float)num_segments;
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0 
	float y = 0;

	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex 

								   //apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}

void draw() {
	int i_center = 100, j_center = 400 ,i2_center =650, j2_center = 450;
	const int thickness = 3, thickness2 = 49;
	//thick line
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
	//drawcicle
	DrawCircle(300.0, 300.0, 50.0, 10);
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