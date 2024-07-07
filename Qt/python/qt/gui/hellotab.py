from PyQt5 import QtCore, QtGui, QtWidgets

from gui.hellobox import HelloBox
from gui.gl_widget import MyGLWidget


class HelloTab(QtWidgets.QVBoxLayout):
    def __init__(self, parent=None):
        super(HelloTab, self).__init__(parent)

        self.hello_box = HelloBox()
        self.gl_widget = MyGLWidget()

        self.addWidget(self.hello_box)
        self.addWidget(self.gl_widget)

        self._setup_ui()

    def _setup_ui(self):
        self.retranslateUi()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
