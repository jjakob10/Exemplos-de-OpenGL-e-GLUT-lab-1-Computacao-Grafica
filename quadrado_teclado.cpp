#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#define TAMANHO_JANELA 500
#define INC 0.00001

float gX = 0.3;
float gY = 0.3;
int keyStatus[256];

void idle(void)
{

   if (keyStatus[(int)'w'])
      gY += INC;
   if (keyStatus[(int)'a'])
      gX -= INC;
   if (keyStatus[(int)'s'])
      gY -= INC;
   if (keyStatus[(int)'d'])
      gX += INC;

   glutPostRedisplay();
}

void keyUp(unsigned char key, int x, int y)
{
   keyStatus[(int)key] = 0;
   // glutPostRedisplay();
}

void keyPress(unsigned char key, int x, int y)
{
   keyStatus[(int)key] = 1;
   // glutPostRedisplay();
}

void display(void)
{
   /* Limpar todos os pixels  */
   glClear(GL_COLOR_BUFFER_BIT);

   /* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
   glColor3f(1.0, 1.0, 1.0);
   /* Desenhar um polígono branco (retângulo) */
   glBegin(GL_POLYGON);
   glVertex3f(gX, gY, 0.0);
   glVertex3f(gX + 0.2, gY, 0.0);
   glVertex3f(gX + 0.2, gY + 0.2, 0.0);
   glVertex3f(gX, gY + 0.2, 0.0);
   glEnd();

   /* Desenhar no frame buffer! */
   glutSwapBuffers(); // Funcao apropriada para janela double buffer
}

void init(void)
{
   /* selecionar cor de fundo (preto) */
   glClearColor(0.0, 0.0, 0.0, 0.0);

   /* inicializar sistema de visualizacao */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

   /* limpa keyStatus*/
   for (int i = 0; i < 256; i++)
      keyStatus[i] = 0;
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(TAMANHO_JANELA, TAMANHO_JANELA);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("hello world");
   init();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyPress);
   glutKeyboardUpFunc(keyUp);
   glutIdleFunc(idle);
   glutMainLoop();

   return 0;
}
