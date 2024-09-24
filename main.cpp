#include <windows.h>

#include <GL/glut.h>

#include <math.h>

GLfloat cPos = 0.0f;  // Initial Y position of the car
GLfloat cSp = -0.02f;
GLfloat position = 0.0f;//crow
GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;//sun
GLfloat speed = 0.1f;
GLfloat speed1 = 0.04f;
GLfloat speed2 = 0.06f;
GLfloat scaleFactor=1.0f;



# define PI 3.14159265358979323846

// Function to draw a circle

void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {

    int i;

    int triangleAmount = 20; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); // Center of circle

    for (i = 0; i <= triangleAmount; i++) {

        glVertex2f(

            x + (radius * cos(i * twicePi / triangleAmount)),

            y + (radius * sin(i * twicePi / triangleAmount))

        );

    }

    glEnd();

}

// Function to draw a cloud

void drawCloud(GLfloat x, GLfloat y, GLfloat radius) {

    glColor3f(1.0f, 1.0f, 1.0f); // White color for the cloud

    // Draw multiple circles to create a cloud shape

    drawCircle(x, y, radius);

    drawCircle(x - radius * 0.6f, y + radius * 0.5f, radius * 0.7f);

    drawCircle(x + radius * 0.6f, y + radius * 0.5f, radius * 0.7f);

    drawCircle(x - radius * 0.9f, y - radius * 0.5f, radius * 0.5f);

    drawCircle(x + radius * 0.9f, y - radius * 0.5f, radius * 0.5f);

}







void drawCar() {
    glPushMatrix(); // Save the current state of transformations


 glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0f,cPos, 0.0f);
   // Uniform scaling based on the position

    glScalef(scaleFactor, scaleFactor, scaleFactor);  // Uniform scaling based on the position

    // Move the car vertically along the Y-axis
glColor3f(0.1f, 0.1f, 0.1f); // Black wheels
    drawCircle(-0.08f, -0.1f, 0.01f); // Left wheel
    drawCircle(-0.02f, -0.1f, 0.01f);  // Right wheel
    glColor3f(0.0f, 0.0f, 1.0f); // Blue car
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f, -0.1f); // Bottom-left
    glVertex2f(-0.05f, -0.0f);  // Top-left
    glVertex2f(0.02f, -0.0f);   // Top-right
    glVertex2f(0.0f, -0.1f);  // Bottom-right
    glEnd();
    // Car roof
    glColor3f(0.9f, 0.9f, 0.9f); // Darker blue roof
    glBegin(GL_POLYGON);
    glVertex2f(-0.08f, -0.07f); // Bottom-left
    glVertex2f(-0.06f, -0.04f);  // Top-left
    glVertex2f(0.01f, -0.04f);   // Top-right
    glVertex2f(-0.0f, -0.07f);  // Bottom-right
    glEnd();
 glBegin(GL_POLYGON);
   glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, -0.08f); // Bottom-left
    glVertex2f(0.0f, -0.06f);  // Top-left
    glVertex2f(0.02f, -0.06f);   // Top-right
    glVertex2f(0.02f, -0.08f);  // Bottom-right
    glEnd();
     glBegin(GL_POLYGON);
   glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.075f, -0.08f); // Bottom-left
    glVertex2f(-0.075f, -0.06f);  // Top-left
    glVertex2f(-0.095f, -0.06f);   // Top-right
    glVertex2f(-0.095f, -0.08f);  // Bottom-right
    glEnd();
    // Car body
    // Car wheels


    glPopMatrix(); // Restore the previous state of transformations
}







void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Background is white

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Sky

    glColor3f(0.53f, 0.81f, 0.98f); // Light blue

    glBegin(GL_POLYGON);

    glVertex2f(1.0f, 1.0f);

    glVertex2f(1.0f, 0.0f);

    glVertex2f(-1.0f, 0.0f);

    glVertex2f(-1.0f, 1.0f);

    glEnd();
     // Sun
glPushMatrix(); // Save the current state of transformations
   glTranslatef(0.0f,position2, 0.0f);
    glColor3f(1.0f, 0.84f, 0.0f); // Yellow

    drawCircle(0.8f, 0.8f, 0.1f);
glPopMatrix();
    // Grass Field

     glColor3f(0.0f, 0.6f, 0.0f); // Green color

    glBegin(GL_POLYGON);

    glVertex2f(1.0f, 0.0f);

    glVertex2f(1.0f, -1.0f);

    glVertex2f(-1.0f, -1.0f);

    glVertex2f(-1.0f, 0.0f);

    glEnd();
    // Draw grass blades

    for (float x = -1.0f; x < 1.0f; x += 0.05f) {

    // Draw grass blade

    glColor3f(0.3f, 0.3f, 0.0f); // Green color for grass

    glBegin(GL_TRIANGLES);

    glVertex2f(x, 0.0f);         // Bottom point of the grass

    glVertex2f(x + 0.02f, 0.2f); // Top point of the grass blade

    glVertex2f(x + 0.02f, 0.0f); // Bottom right of the grass blade

    glEnd();

    // Draw cloud-like leaf at the top of the grass blade

    float centerX = x + 0.05f;

    float centerY = 0.2f;

    float radius = 0.07f; // Radius of the cloud-like leaf

    glColor3f(0.0f, 0.3f, 0.0f); // Different green color for leaf

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(centerX, centerY); // Center of the leaf

    // Approximate a circle for the cloud leaf using 20 vertices

    for (int i = 0; i <= 20; ++i) {

        float angle = 2.0f * 3.1415926f * float(i) / 20.0f; // Calculate the angle

        float dx = radius * cosf(angle); // X-coordinate of the vertex

        float dy = radius * sinf(angle); // Y-coordinate of the vertex

        glVertex2f(centerX + dx, centerY + dy); // Position of each vertex around the center

    }

    glEnd();

}

      for (float y = -1.0f; y < 0.0f; y += 0.02f) {

        glColor3f(0.0f, 0.3f, 0.0f); // Green color for grass

        glBegin(GL_TRIANGLES);

        glVertex2f(-1.0f,y);         // Bottom point of the grass

        glVertex2f(0.1f,y + 0.02f); // Top point of the grass blade

        glVertex2f(0.0f,y + 0.04f); // Bottom right of the grass blade

        glEnd();

    }

for (float y = -1.0f; y < 0.0f; y += 0.02f) {

        glColor3f(0.0f, 0.3f, 0.0f); // Green color for grass

        glBegin(GL_TRIANGLES);

        glVertex2f(1.0f,y);         // Bottom point of the grass

        glVertex2f(0.1f,y + 0.02f); // Top point of the grass blade

        glVertex2f(0.0f,y + 0.04f); // Bottom right of the grass blade

        glEnd();

    }

for (float x = -1.0f; x < -0.3f; x += 0.05f) {

    // Draw grass blade

    glColor3f(0.3f, 0.3f, 0.0f); // Green color for grass

    glBegin(GL_TRIANGLES);

    glVertex2f(x, -0.2f);         // Bottom point of the grass

    glVertex2f(x + 0.02f, 0.0f); // Top point of the grass blade

    glVertex2f(x + 0.02f, -0.2f); // Bottom right of the grass blade

    glEnd();

    // Draw cloud-like leaf at the top of the grass blade

    float centerX = x + 0.05f;

    float centerY = 0.0f;

    float radius = 0.07f; // Radius of the cloud-like leaf

    glColor3f(0.0f, 0.3f, 0.0f); // Different green color for leaf

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(centerX, centerY); // Center of the leaf

    // Approximate a circle for the cloud leaf using 20 vertices

    for (int i = 0; i <= 20; ++i) {

        float angle = 2.0f * 3.1415926f * float(i) / 20.0f; // Calculate the angle

        float dx = radius * cosf(angle); // X-coordinate of the vertex

        float dy = radius * sinf(angle); // Y-coordinate of the vertex

        glVertex2f(centerX + dx, centerY + dy); // Position of each vertex around the center

    }
     glEnd();

}

for (float x = -1.0f; x < -0.8f; x += 0.05f) {

    // Draw grass blade

    glColor3f(0.3f, 0.3f, 0.0f); // Green color for grass

    glBegin(GL_TRIANGLES);

    glVertex2f(x, -0.5f);         // Bottom point of the grass

    glVertex2f(x + 0.02f, -0.3f); // Top point of the grass blade

    glVertex2f(x + 0.02f, -0.5f); // Bottom right of the grass blade

    glEnd();

    // Draw cloud-like leaf at the top of the grass blade

    float centerX = x + 0.05f;

    float centerY = -0.3f;

    float radius = 0.07f; // Radius of the cloud-like leaf

    glColor3f(0.0f, 0.3f, 0.0f); // Different green color for leaf

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(centerX, centerY); // Center of the leaf

    // Approximate a circle for the cloud leaf using 20 vertices

    for (int i = 0; i <= 20; ++i) {

        float angle = 2.0f * 3.1415926f * float(i) / 20.0f; // Calculate the angle

        float dx = radius * cosf(angle); // X-coordinate of the vertex

        float dy = radius * sinf(angle); // Y-coordinate of the vertex

        glVertex2f(centerX + dx, centerY + dy); // Position of each vertex around the center

    }

    glEnd();

}


// Draw House

    // House base (walls)

    glColor3f(0.8f, 0.52f, 0.25f); // Brown color for walls

    glBegin(GL_POLYGON);

    glVertex2f(0.4f, 0.0f);  // Bottom left corner

    glVertex2f(0.4f, -0.5f); // Top left corner

    glVertex2f(0.7f, -0.5f); // Top right corner

    glVertex2f(0.7f, 0.0f);  // Bottom right corner

    glEnd();

    // Roof

    glColor3f(0.5f, 0.0f, 0.0f); // Dark red roof

    glBegin(GL_TRIANGLES);

    glVertex2f(0.35f, 0.0f);  // Bottom left corner of the roof

    glVertex2f(0.75f, 0.0f);  // Bottom right corner of the roof

    glVertex2f(0.55f, 0.2f);  // Top of the roof

    glEnd();

    // Door

    glColor3f(0.4f, 0.2f, 0.1f); // Dark brown door

    glBegin(GL_POLYGON);

    glVertex2f(0.5f, -0.3f);  // Top left corner of the door

    glVertex2f(0.5f, -0.5f);  // Bottom left corner of the door

    glVertex2f(0.6f, -0.5f);  // Bottom right corner of the door

    glVertex2f(0.6f, -0.3f);  // Top right corner of the door

    glEnd();

    // Windows (two small rectangles)

    glColor3f(0.7f, 0.9f, 1.0f); // Light blue windows

    // Left window

    glBegin(GL_POLYGON);

    glVertex2f(0.45f, -0.15f);   // Top left of the window

    glVertex2f(0.45f, -0.25f);   // Bottom left of the window

    glVertex2f(0.5f, -0.25f);    // Bottom right of the window

    glVertex2f(0.5f, -0.15f);    // Top right of the window

    glEnd();


// Right window

    glBegin(GL_POLYGON);

    glVertex2f(0.6f, -0.15f);    // Top left of the window

    glVertex2f(0.6f, -0.25f);    // Bottom left of the window

    glVertex2f(0.65f, -0.25f);   // Bottom right of the window

    glVertex2f(0.65f, -0.15f);   // Top right of the window

    glEnd();

    // Road (brownish color)

    glColor3f(0.76f, 0.60f, 0.42f);

    glBegin(GL_POLYGON);

    glVertex2f(-1.0f, -0.5f);

    glVertex2f(0.0f, 0.05f);

    glVertex2f(0.6f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();
     // Draw car
    drawCar();





    // Slimmer Palm trunk

    glColor3f(0.54f, 0.27f, 0.07f); // Brown color for the trunk

    glBegin(GL_POLYGON);

    glVertex2f(0.32f, -0.2f);  // Bottom left of the trunk

    glVertex2f(0.35f, -0.2f);  // Bottom right of the trunk

    glVertex2f(0.35f, 0.2f);   // Top right of the trunk

    glVertex2f(0.32f, 0.2f);   // Top left of the trunk

    glEnd();

    // First set of palm leaves (largest, lowest)

    glColor3f(0.0f, 0.5f, 0.0f); // Green color for leaves

    glBegin(GL_TRIANGLES);

    glVertex2f(0.17f, 0.2f);     // Bottom left of the leaves (extended width)

    glVertex2f(0.50f, 0.2f);     // Bottom right of the leaves (extended width)

    glVertex2f(0.35f, 0.35f);    // Top of the first set of leaves

    glEnd();

    // Second set of palm leaves (medium size, middle)

    glColor3f(0.0f, 0.5f, 0.0f); // Green color for leaves

    glBegin(GL_TRIANGLES);

    glVertex2f(0.20f, 0.3f);     // Bottom left of the leaves

    glVertex2f(0.47f, 0.3f);     // Bottom right of the leaves

    glVertex2f(0.35f, 0.45f);    // Top of the second set of leaves

    glEnd();

    // Slimmer Palm trunk

    glColor3f(0.54f, 0.27f, 0.07f); // Brown color for the trunk

    glBegin(GL_POLYGON);

    glVertex2f(0.77f, -0.2f);  // Bottom left of the trunk

    glVertex2f(0.80f, -0.2f);  // Bottom right of the trunk

    glVertex2f(0.80f, 0.2f);   // Top right of the trunk

    glVertex2f(0.77f, 0.2f);   // Top left of the trunk

    glEnd();

    // First set of palm leaves (largest, lowest)

    glColor3f(0.0f, 0.5f, 0.0f); // Green color for leaves

    glBegin(GL_TRIANGLES);

    glVertex2f(0.59f, 0.2f);     // Bottom left of the leaves (extended width)

    glVertex2f(0.95f, 0.2f);     // Bottom right of the leaves (extended width)

    glVertex2f(0.77f, 0.35f);    // Top of the first set of leaves

    glEnd();

    // Second set of palm leaves (medium size, middle)

    glColor3f(0.0f, 0.5f, 0.0f); // Green color for leaves

    glBegin(GL_TRIANGLES);

    glVertex2f(0.62f, 0.3f);     // Bottom left of the leaves

    glVertex2f(0.92f, 0.3f);     // Bottom right of the leaves

    glVertex2f(0.77f, 0.45f);    // Top of the second set of leaves

    glEnd();

    // Slimmer Palm trunk

    glColor3f(0.54f, 0.27f, 0.07f); // Brown color for the trunk

    glBegin(GL_POLYGON);

    glVertex2f(-0.63f, 0.2f);  // Bottom left of the trunk

    glVertex2f(-0.67f, 0.2f);  // Bottom right of the trunk

    glVertex2f(-0.67f, -0.1f);   // Top right of the trunk

    glVertex2f(-0.63f,-0.1f);   // Top left of the trunk

    glEnd();

    // First set of palm leaves (largest, lowest)

    glColor3f(0.0f, 0.5f, 0.0f); // Green color for leaves

    glBegin(GL_TRIANGLES);

    glVertex2f(-0.50f, 0.2f);     // Bottom left of the leaves (extended width)

    glVertex2f(-0.80f,0.2f);     // Bottom right of the leaves (extended width)

    glVertex2f(-0.65f, 0.35f);    // Top of the first set of leaves

    glEnd();
// Second set of palm leaves (medium size, middle)

    glColor3f(0.0f, 0.5f, 0.0f); // Green color for leaves

    glBegin(GL_TRIANGLES);

    glVertex2f(-0.53f,0.3f);     // Bottom left of the leaves

    glVertex2f(-0.77f,0.3f);     // Bottom right of the leaves

    glVertex2f(-0.65f,0.45f);    // Top of the second set of leaves

    glEnd();

    // Tree trunk

    glColor3f(0.54f, 0.27f, 0.07f); // Brown trunk

    glBegin(GL_POLYGON);

    glVertex2f(-0.85f,0.2f);  // Bottom left of the trunk

    glVertex2f(-0.89f, 0.2f);  // Top left of the trunk

    glVertex2f(-0.89f,- 0.1f);   // Top right of the trunk

    glVertex2f(-0.85f,- 0.1f);   // Bottom right of the trunk

    glEnd();

    // Tree leaves (simple triangle)

    glColor3f(0.0f, 0.5f, 0.0f);

    glBegin(GL_TRIANGLES);

    glVertex2f(-0.8f,0.2f);      // Bottom left corner of leaves

    glVertex2f(-0.95f,0.2f);     // Bottom right corner of leaves

    glVertex2f(-0.87f,0.4f);    // Top of the leaves

    glEnd();



    // Cloud
  glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
    drawCloud(0.5f, 0.75f, 0.1f);

    drawCloud(0.2f, 0.85f, 0.08f);

    drawCloud(0.3f, 0.75f, 0.12f);

    drawCloud(-0.1f, 0.8f, 0.09f);

    drawCloud(-0.4f, 0.6f, 0.11f);
              glPopMatrix();
   // .................................... Crow......................................./
      glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
 glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.67f , 0.67f);
    glVertex2f(-0.64f , 0.7f);
    glVertex2f(-0.67f , 0.68f);
    glVertex2f(-0.7f , 0.7f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.57f , 0.87f);
    glVertex2f(-0.54f , 0.9f);
    glVertex2f(-0.57f , 0.88f);
    glVertex2f(-0.6f, 0.9f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.47f , 0.77f);
    glVertex2f(-0.44f , 0.8f);
    glVertex2f(-0.47f , 0.78f);
    glVertex2f(-0.5f , 0.8f);
    glEnd();


  glPopMatrix();


  glFlush();

}
void update(int value)
{
    if(position >1.0)
        position = -1.0f;
    position += speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}

void update1(int value)
{
    if(-1.0f>cPos)
        cPos = 0.0f;
    cPos += cSp;
    scaleFactor = 8.0f - ((cPos + 1.0f) / 1.5f) * (8.0f - 1.0f / 25.0f);
    glutPostRedisplay();
    glutTimerFunc(150, update1, 0);
}
void update2(int value)
{
    if(position1 >1.0)
        position1 = -1.0f;
    position1 += speed1;
	glutPostRedisplay();
	glutTimerFunc(100, update2, 0);
}
void update3(int value)
{
    if(position2 >1.0)
        position2 = -0.5f;
    position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(100, update3, 0);
}
void sound()
{


    PlaySound("horn.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}
//crow//
void handleMouse(int button, int state, int x, int y)
{///mouse
	if (button == GLUT_LEFT_BUTTON)
	{
		speed = 0.00f;
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
	    speed = 0.02f;
	}
	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{///keypress
    switch (key)
    {
        case 'g':
            cSp = -0.1f;
            break;
        case 's':
           cSp = 0.0f;
            break;
        default:
            break;
    }
}
//sun//
void SpecialInput(int key, int x, int y)
{///specialinput
    switch (key) {
        case GLUT_KEY_UP:
            speed2 = 0.05f;
            break;
        case GLUT_KEY_DOWN:
            speed2 = -0.05f;
            break;
        case GLUT_KEY_LEFT:
            speed2 = 0.0f;
            break;
        case GLUT_KEY_RIGHT:
            break;
    }
    glutPostRedisplay();
}




int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitWindowSize(640, 480); // Set the window's initial width & height

    glutInitWindowPosition(100, 100); // Set the window's initial position

    glutCreateWindow("Nature Scene with Palm Trees, House, and Grass"); // Create a window with the given title

    glutDisplayFunc(display); // Register display callback handler for window re-paint
     glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(SpecialInput);
    glutMouseFunc(handleMouse);
      glutTimerFunc(100, update, 0);
      glutTimerFunc(100, update1, 0);
      glutTimerFunc(100, update2, 0);
      glutTimerFunc(100, update3, 0);
      sound();
    glutMainLoop(); // Enter the event-processing loop

    return 0;

}
