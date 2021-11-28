#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);


int main()
{
	//glfw��ʼ��
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glfw��������
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		printf("��������ʧ��");
		//��ֹ
		glfwTerminate();
		return -1;
	}
	//���õ�ǰOpenGL������
	glfwMakeContextCurrent(window);

	//���ûص��������ڴ�С�����󽫵��øûص�����
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//���ûص�����������������ʱ�����øûص�����
	glfwSetKeyCallback(window, key_callback);

	// glad��ʼ��
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("����ʧ��");
		return -1;
	}

	// ʹ��ѭ���ﵽѭ����ȾЧ��
	while (!glfwWindowShouldClose(window))
	{
		//����¼�
		glfwPollEvents();

		//��Ⱦָ��
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//��������
		glfwSwapBuffers(window);
	}

	//��ֹ��Ⱦ �رղ�����glfw������Դ
	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}