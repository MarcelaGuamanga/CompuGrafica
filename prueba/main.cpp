#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

bool ejesActivos=false, tortuga=false, sphereTortuga=false, primitivas=false;

void dibujoEjes() {

	glBegin(GL_LINES);

	//Para X
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);

	//Para Y
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	//Para Z
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();

}

void dibujoPrimitivas() {

    //Triangulo 1 para estrella
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, -0.2);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.1, 0.1);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.1, 0.1);
    glEnd();
    //Triangulo 2 para estrella
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.2, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.1, -0.1, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.1, -0.1, 0.0);
    glEnd();

    //puntos de la estrella brillando
    glBegin(GL_POINTS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, 0.15);
    glVertex2f(0.05, -0.05);
    glVertex2f(-0.05, 0.05);
    glVertex2f(-0.05, -0.05);
    glVertex2f(0.0, -0.15);
    glVertex2f(0.05, 0.05);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.08, 0.08);
    glVertex2f(0.08, -0.08);
    glVertex2f(-0.08, 0.08);
    glVertex2f(-0.08, -0.08);
    glVertex2f(0.02, 0.02);
    glVertex2f(0.02, -0.02);
    glVertex2f(-0.02, 0.02);
    glVertex2f(-0.02, -0.02);
    glEnd();
 
    //Lineas para octagono
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.15, 0.3);
    glVertex2f(-0.22, 0.15);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.22, 0.15);
    glVertex2f(0.22, -0.15);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.15, -0.3);
    glVertex2f(-0.22, -0.15);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.22, 0.15);
    glVertex2f(-0.22, -0.15);
    glEnd();
   
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.15, 0.3);
    glVertex2f(0.22, 0.15);
    glEnd();
 
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.15, -0.3);
    glVertex2f(0.22, -0.15);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.15, 0.3);
    glVertex2f(0.15, 0.3);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.15, -0.3);
    glVertex2f(0.15, -0.3);
    glEnd();
}

void drawTurtle() {
    GLdouble x[] = { 0.0, 1.5, 2.5, 2.5, 1.5, 1.5, 4.5, 6.0, 8.0, 9.0, 9.0, 5.0, 6.0, 6.0, 5.0, 8.0, 8.0, 6.0, 4.0, 2.5, 0.0};
    GLdouble z[] = { 11.0, 11.0, 9.0, 7.0, 6.0, 4.0, 4.0, 6.0, 6.0, 4.0, 2.0, 0.0, -1.0, -4.0, -5.0, -7.0, -9.5, -10.5, -10.5, -7.5, -7.5};
    GLint i;
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 21; i++) {
        glVertex3f(x[i]*0.1 , 0.0, -.1*z[i]);
    }
    for (i = 20; i >= 0; i--) {
        glVertex3f(-.1 *x[i], 0.0, -.1*z[i]);
    }
    glEnd();

}

void drawSphereTurtle() {

    GLdouble x[] = { 0.0, 4.0, -8.0, 0.0, 8.0,-4.0 };
    GLdouble z[] = { -6.0, 2.0, 0.0, 8.0, 0.0,-4.0 };
    GLdouble r[] = { 5.0, 3.0, 1.7, 1.7, 2.0, 2.0 };
    GLint i;
    glColor3f(0.0, 1.0, 1.0);
    for (i = 0; i < 6; i++) {
        glutWireSphere(r[i] * 0.1, 10.0, 10.0);
        glTranslatef(x[i] * 0.1, 0.0, z[i] * 0.1);
    }

}

void reshape(int width, int height)
{
    int menor = (width < height) ? width : height;
    glViewport(0, 0, menor, menor);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 128.0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y) {
    
    switch (key) {
    case 'h':
        printf("help\n\n");
        printf("c - Toggle culling\n");
        printf("q - Quit\n");
        printf("a - Axes\n");
        printf("u - Up\n");
        printf("d - Down\n");
        printf("r - Right\n");
        printf("l - Left\n");
        printf("t - turtle\n");
        printf("s - Sphereturtle\n");
        printf("p - toroide+primitivas\n\n");
        break;
    case 'c':
        if (glIsEnabled(GL_CULL_FACE))
            glDisable(GL_CULL_FACE);
        else
            glEnable(GL_CULL_FACE)
            ;
        break;
    case '1':
        glRotatef(1.0, 1.0, 0.0, 0.0);
        break;
    case '2':
        glRotatef(1.0, 0.0, 1.0, 0.0);
        break;
    case 'a':
        ejesActivos = (ejesActivos) ? false : true;
        break;
    case 'u':
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0.0, 3.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 'd':
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0.0, -3.0, -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 'r':
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(3.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(-3.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 't':
        tortuga = true;
        primitivas = false;
        sphereTortuga = false;
        break;
    case 's':
        tortuga = false;
        primitivas = false;
        sphereTortuga = true;
        break;
    case 'p':
        tortuga = false;
        primitivas = true;
        sphereTortuga = false;
        break;
    case 'q':
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}


void display(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

    if (ejesActivos) {
        dibujoEjes();
    }
    if (tortuga) {
        drawTurtle();
    }
    if (sphereTortuga) {
        drawSphereTurtle();
    }
    if (primitivas) {
        glutWireTorus(0.25, 0.75, 28, 28); 
        glColor3f(0.0, 0.0, 1.0);
        glutWireCube(.60);
        dibujoPrimitivas();
    }
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE); 
    glutInitWindowSize(512, 512);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("tecnunLogo");
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
