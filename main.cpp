#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

///Nama     : Robert Setyawan
///Materi   : Algoritma Bresenham

using namespace std;

//identifier fungsi
void init();
void display(void);
void lingkaran(void);

///ukuran window
int lebar = 500;
int tinggi = 500;

// judul window
char *judul = "Algoritma Menggambar Lingkaran";

int xc,yc,r;

int main(int argc, char **argv)
{
    cout <<"Masukkan nilai jari-jari : ";
    cin >>r;
    cout <<"Masukkan nilai x , y pusat : ";
    cin >>xc;
    cin >>yc;
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	glutInitWindowSize(lebar , tinggi);

	glutCreateWindow(judul);

	init(); // jalankan fungsi init
	glutDisplayFunc(display); // set fungsi display
	glutMainLoop(); // set loop pemrosesan GLUT
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //set warna background
	glColor3f(0.0, 0.0, 0.0); //set warna titik
	glPointSize(5.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	lingkaran();
	glutSwapBuffers(); //swap buffer
}

void lingkaran(void) {
	//hitung p awal dan set nilai awal untuk x dan y
	int p = 1-r; // p awal
	int x = 0;//set titik awal x
	int y = r;//set titik awal y

	glBegin(GL_POINTS);

	//perulangan untuk menggambar titik
	while (x <= y) {
		x++; //tambah nilai x
		if (p < 0) {
			p = p + 2 * x + 1;
		}
		else if(p >= 0) {
			y--; //kurangi nilai y
			p = p + 2 * (x - y) + 1;
		}

		// translasi terhadap titik pusat dan cerminkan
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc - y, yc - x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc - x, yc + y);
	}

	glEnd();
	glFlush();
}

