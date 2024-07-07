import sys

from PyQt5.QtWidgets import QOpenGLWidget
from OpenGL.GL import glClear, glClearColor, GL_COLOR_BUFFER_BIT


class MyGLWidget(QOpenGLWidget):
    def __init__(self, parent=None):
        super(MyGLWidget, self).__init__(parent)

    def initializeGL(self):
        #  Sets up the OpenGL resources and state.
        #  Gets called once before the first time resizeGL() or paintGL() is called.
        glClearColor(0.2, 0.3, 0.3, 1.0)

    def paintGL(self):
        # Renders the OpenGL scene. Gets called whenever the widget needs to be updated.
        glClear(GL_COLOR_BUFFER_BIT)

    def resizeGL(self, w, h):
        # Sets up the OpenGL viewport, projection, etc.
        pass
