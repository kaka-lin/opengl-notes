#include <iostream>
#include <string>

#ifdef __APPLE__
#include <OpenGL/gl.h>  // Header File For The OpenGL32 Library
#include <OpenGL/glu.h> // Header File For The GLu32 Library
#include <GLUT/glut.h>  // Header File For The GLut Library
#define glGenVertexArrays glGenVertexArraysAPPLE
#define glBindVertexArray glBindVertexArrayAPPLE
#define glDeleteVertexArrays glDeleteVertexArraysAPPLE
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

void keyboard(unsigned char key, int x, int y);
void userInit();
void display();

// Vertex Buffer Object (VBO)
// OpenGL 中以 GL_ARRAY_BUFFER 表示
GLuint vbo;
// Vertex Array Object (VAO)
GLuint vao;

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Hello OpenGL");

  // 检查 OpenGL 版本
  const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
  const GLubyte* version = glGetString(GL_VERSION);   // version as a string
  std::cout << "Renderer: " << renderer << std::endl;
  std::cout << "OpenGL version supported: " << version << std::endl;

  // set the viewport
  glViewport(0, 0, 640, 480);

  // glewExperimental = GL_TRUE; // 確保 GLEW 使用現代方法來檢測和獲取功能
  // if (glewInit() != GLEW_OK) {
  //   std::cout << "Failed to initialize GLEW" << std::endl;
  //   return -1;
  // }

  userInit();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);

	// Enter the GLUT event loop
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
	glClearColor(0.0, 0.0, 0.0, 0.0);

  // Create Vertex data
  // OpenGL 只會處理 3D 座標在值在 [−1.0,1.0] 的座標
  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
  };

  // Create Vertex Array Object (VAO)
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // Create Vertex Buffer Object (VBO) and Copy vertex data
  glGenBuffers(1, &vbo); // number, array to object id
  glBindBuffer(GL_ARRAY_BUFFER, vbo); // 綁定
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //傳輸資料

  // 設定頂點屬性
  // 由於 OpenGL 沒有規定傳入頂點資料的格式，這意味著我們可以自己決定，但也必須要我們手動指定給 OpenGL。
  // 根據我們上面訂出的頂點陣列 vertices[] ，有底下幾種屬性是必須告訴 OpenGL 的:
  // 1. 開始位置是 0 (location=0)
  // 2. 每個頂點有 3 個 float 資料，分別是 x, y, z
  // 3. 頂點資料是儲存在 float 大小是 sizeof(float)
  // 4. 每個頂點之間沒有空隙或是其他的資料，是緊密排列(Tightly Packed)
  //
  // `glVertexAttribPointer()` 會從 `GL_ARRAY_BUFFER`中
  // 按照參數給定的方式去讀取資料，然後將頂點資料的資訊告訴 Vertex Shader
  // 讓它知道該怎麼解析這些頂點資料。
  // 其中第一個參數 0 就是對應 vertex shader 中的 location=0
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0); // 是否啟動 VAO; 啟動 location=0

  // 解除綁定
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

// like processing draw
void display() {
  // 更改清除顏色
  glClearColor(0.2, 0.3, 0.3, 1.0);
  // 清除顏色緩衝區，使用設置的清除顏色
  glClear(GL_COLOR_BUFFER_BIT);

  // Starting draw the triangle !
  glBindVertexArray(vao);
  // from vertex 0; read 3 vertices => 1 triangle
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(0); // 解除綁定

  // glutSwapBuffers swaps the buffers of the current window if double buffered.
  // display rendering results
  glutSwapBuffers(); // for GLUT_DOUBLE
}
