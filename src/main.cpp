//
// Hello OpenGL World
//

#if defined (_DEBUG)
// コンソールを開いて実行(printfが使える)
#pragma comment(linker,"/SUBSYSTEM:CONSOLE")
#else
// コンソールを開かずにに実行
#pragma comment(linker, "/entry:mainCRTStartup")
#pragma comment(linker,"/SUBSYSTEM:WINDOWS")
#endif

// Windows: DLL形式のライブラリを使う
#define GLFW_DLL


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


int main(void)
{
  std::cout << "Hello World.\n";
  
  GLFWwindow* window;
  
  /* Initialize the library */
  if (!glfwInit())
    return -1;
  
  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }
  
  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  // Init OpenGL extensions
  if (!gladLoadGL())
  {
	  glfwTerminate();
	  return -1;
  }
  printf("OpenGL Version %d.%d loaded", GLVersion.major, GLVersion.minor);

  glfwSwapInterval(1);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window))
  {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    
    /* Swap front and back buffers */
    glfwSwapBuffers(window);
    
    /* Poll for and process events */
    glfwPollEvents();
  }
  
  glfwTerminate();
  return 0;
}
