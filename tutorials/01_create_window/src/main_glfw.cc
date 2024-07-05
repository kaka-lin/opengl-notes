#include <iostream>

// Include GLEW. Always include it before gl.h and glfw3.h,
// since it's a bit magic.
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void userInit();
void render();
void run(GLFWwindow* window);
void framebuffer_size_callback(
    GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main(int argc, char* argv[]) {
  // Initialise GLFW
  if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

  // Get the version of GLFW
  int major, minor, revision;
  glfwGetVersion(&major, &minor, &revision);
  std::cout << "GLFW version: " << major << "." << minor << "." << revision << std::endl;

  // Check GLFW version and set appropriate OpenGL version and profile
  if (major >= 3 && minor >= 3) {
    // We want OpenGL 3.3 or higher
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // only 3.2+
#ifdef __APPLE__
    // Fix compilation on OS X
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // only 3.0+
#endif
  } else {
    // Fallback for older versions, for example, 3.2.1
    // FIXME: This is not working on my computer
    //        docker container: ubuntu:18.04, macOS: 14.3
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // only 3.2+
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE); //only 3.0+
  }

  // Open a window and create its OpenGL context
  GLFWwindow* window;
  window = glfwCreateWindow(640, 480, "Hello OpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    // const char* description;
    // int code = glfwGetError(&description);
    // if (code != GLFW_NO_ERROR) {
    //     std::cerr << "GLFW Error: " << description << std::endl;
    // }
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window);
  // Ensure we can capture the escape key being pressed below
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  /* Initialize GLEW */
  // glewInit() 必須在 opengl context 之後，
  // 即必須在 `glfwMakeContextCurrent(window)` 之後
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cout << "Failed to initialize GLEW" << std::endl;
    return -1;
  }

  userInit();
  // call run (display) function
  run(window);
  glfwTerminate();

	return 0;
}

void userInit() {
  // when call glClear()，清除 color buffer 後
  // 整個 color buffer 都會被填充為 glClearColor() 裡所設置的顏色
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void run(GLFWwindow* window) {
  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window)) {
    // preprecess input
    processInput(window);

    // Render here
    render();

    // Swap front and back buffers
    glfwSwapBuffers(window);
    // Poll for and process events (監聽滑鼠和鍵盤事件)
    glfwPollEvents();
  }
}

void render() {
  // call glClear() 來清空 buffer
  // 他可以清空:
  //   1. color: GL_COLOR_BUFFER_BIT
  //   2. depth: GL_DEPTH_BUFFER_BIT
  //   3. 模板:  GL_STENCIL_BUFFER_BIT
  glClear(GL_COLOR_BUFFER_BIT);
}

// glfw: whenever the window size changed
// this callback function executes
void framebuffer_size_callback(
    GLFWwindow* window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width and
  // height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}

// process all input: query GLFW whether relevant keys are pressed/released
// this frame and react accordingly
void processInput(GLFWwindow *window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}
