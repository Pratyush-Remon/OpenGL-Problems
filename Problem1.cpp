#include <glew.h>
#include <glut.h>
#include <iostream>
#include <ogldev_math_3d.h>
/*This code creates a window and renders different colors*/


GLclampf randomizer(GLclampf c) {				//This function helps in not really randomize but change the value passed
	c += 1.0f / 256.0f;
	if (c >= 1) {
		c = 0.0f;
	}
	return c;
}


void RenderSceneCB() {
	static GLfloat Red = 0.2f, Green = 0.3f, Blue = 0.4f, Alpha = 1.0f;
	Red = randomizer(Red);
	Green = randomizer(Green);
	Blue = randomizer(Blue);
	Alpha = randomizer(Alpha);

	printf("%f\n%f\n%f\n%f\n", Red, Green, Blue, Alpha);

	glClearColor(Red, Green, Blue, Alpha); // this function tell glclear the RGBA values
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();  // to swap the front and back buffers
	glutPostRedisplay();// it creates a flag so that RenderScene keeps updating
}




int main(int argc, char* argv[]) {
	glutInit(&argc, argv);  // initiating glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 

	int height = 1980;
	int width = 1080;

	glutInitWindowSize(height, width);

	int X = 100;
	int Y = 200;

	glutInitWindowPosition(X, Y);

	int win = glutCreateWindow("The real window");
	printf("Window id = %i", win);

	glutDisplayFunc(RenderSceneCB);
	glutMainLoop();
	return 0;


}

