#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#define TAMANHO_JANELA 500
#define RAIO 30

int n = 10;
float size = 1.0;

const float max_dir = ((float)RAIO / TAMANHO_JANELA) * ((float)RAIO / TAMANHO_JANELA);

// Pontos de controle da Spline
GLfloat ctrlpoints[4][3] = {
    {0.0, 0.0, 0.0}, {0.25, 1, 0.0}, {0.75, 0.0, 0.0}, {1.0, 1.0, 0.0}};

int current_drag = -1;

float dist(float x1, float y1, float x2, float y2)
{
   return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void mouse(int button, int state, int x, int y)
{
   float x_rel = x / (float)TAMANHO_JANELA;
   float y_rel = 1.0 - (y / (float)TAMANHO_JANELA);
   if (!state)
   {
      for (int i = 0; i < 4; i++)
      {
         float min_dir = 2, dir;
         if ((dir = dist(ctrlpoints[i][0], ctrlpoints[i][1], x_rel, y_rel)) < max_dir && dir < min_dir)
         {
            current_drag = i;
            min_dir = dir;
         }
         // printf("dir %f max_dir %f min_dir %f\n ", dir, max_dir, min_dir);
      }
   }
   else
      current_drag = -1;

   // printf("current drag: %d\n", current_drag);
}

void move(int x, int y)
{
   float x_rel = x / (float)TAMANHO_JANELA;
   float y_rel = 1.0 - (y / (float)TAMANHO_JANELA);

   if (current_drag != -1)
   {
      if (x_rel >= 0 && x_rel <= 1)
         ctrlpoints[current_drag][0] = x_rel;
      if (y_rel >= 0 && y_rel <= 1)
         ctrlpoints[current_drag][1] = y_rel;
   }
}

void keyPress(unsigned char key, int x, int y)
{
   if (key == '+')
   {
      if (n < 40)
         n++;
   }

   else if (key == '-')
      if (n > 2)
         n--;
   // printf("%c -> n: %d", key, n);
   // glutPostRedisplay();
}

void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_MAP1_VERTEX_3);

   // Definicao do polinomio com os pontos de controle
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);

   // Muda para a matriz de projecao (aulas futuras)
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   // Define a area/volume de visualizacao. Os objetos desenhados devem estar dentro desta area
   glOrtho(0, size, 0, size, 0, size);
}

void idle(void)
{
   glutPostRedisplay();
}

void display(void)
{
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
   int i;

   glClear(GL_COLOR_BUFFER_BIT);

   /* Desenha a curva aproximada por n+1 pontos. */
   // int n = 30;
   glColor3f(1.0, 1.0, 1.0);
   glBegin(GL_LINE_STRIP);
   for (i = 0; i <= n; i++)
   {
      // Avaliacao do polinomio, retorna um vertice (equivalente a um glVertex3fv)
      glEvalCoord1f((GLfloat)i / (GLfloat)n);
   }
   glEnd();

   /* Desenha os pontos de controle. */
   glPointSize(5.0);
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_POINTS);
   for (i = 0; i < 4; i++)
      glVertex3fv(&ctrlpoints[i][0]);
   glEnd();

   glutSwapBuffers();
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(TAMANHO_JANELA, TAMANHO_JANELA);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutDisplayFunc(display);
   // glutReshapeFunc(reshape);
   glutMouseFunc(mouse);
   glutMotionFunc(move);
   glutIdleFunc(idle);
   glutKeyboardFunc(keyPress);
   glutMainLoop();
   return 0;
}
