#include <iostream>

#ifdef __APPLE__
#include <OpenGL/gl.h>  // Header File For The OpenGL32 Library
#include <OpenGL/glu.h> // Header File For The GLu32 Library
#include <GLUT/glut.h>  // Header File For The GLut Library
#else
#include <GL/glut.h>
#endif

void keyboard(unsigned char key, int x, int y);
void userInit();
void display();

int main(int argc, char* argv[]) {
  // init the glut
	glutInit(&argc, argv);
  // setting display mode
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  // set the window position
  glutInitWindowPosition(100, 100);
  // setting the window size
	glutInitWindowSize(640, 480);
  // create the window
	glutCreateWindow("Hello OpenGL");

  // 检查 OpenGL 版本
  const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
  const GLubyte* version = glGetString(GL_VERSION);   // version as a string
  std::cout << "Renderer: " << renderer << std::endl;
  std::cout << "OpenGL version supported: " << version << std::endl;

  // set the viewport
  glViewport(0, 0, 640, 480);

  // 初始化 OpenGL 設定
	userInit();

  // 設置 callback function
	glutDisplayFunc(display); // display function
  glutKeyboardFunc(keyboard);

	// Enter the GLUT event loop
  // 進入 GLUT 主循環: 是一個無限循環
  glutMainLoop();

	return 0;
}

// 處理鍵盤輸入
void keyboard(unsigned char key, int x, int y) {
  if (key == 27) // 按下ESC鍵退出
    exit(0);
}

// like processing setting
void userInit() {
  // 設定清除顏色為黑色
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//like processing draw
void display() {
  // 更改清除顏色
  glClearColor(0.2, 0.3, 0.3, 1.0);

  // 清除顏色緩衝區，使用設置的清除顏色
  glClear(GL_COLOR_BUFFER_BIT);

  // 將畫面顯示到屏幕上
  glFlush(); // GLUT_SINGLE
}
