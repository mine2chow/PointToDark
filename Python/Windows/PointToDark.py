#coding=utf-8

from PyQt5.QtWidgets import QWidget, QLabel, QVBoxLayout
from PyQt5.QtCore import Qt, QEvent

class AREACFG:
    # x position
    x = 1577
    # y position
    y = 703
    # width
    width = 1
    # height
    height = 1

class QUnFrameWindow(QWidget):
    """
    无边框窗口类
    """
    def __init__(self):
        super(QUnFrameWindow, self).__init__(None, Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.WindowDoesNotAcceptFocus | Qt.BypassWindowManagerHint | Qt.Tool) # 设置为顶级窗口，无边框
        self.initLayout() # 设置框架布局
        self.setFixedSize(AREACFG.width, AREACFG.height)             # 固定窗体大小 
        self.setMouseTracking(True) # 设置widget鼠标跟踪


        p = self.palette()
        p.setColor(self.backgroundRole(), Qt.black)
        self.setPalette(p)

        self.move(AREACFG.x, AREACFG.y)
        self.resize(AREACFG.width, AREACFG.height)

    def showEvent(self, event):
        # Windows下面有一定概率无法置顶，增加此重载函数确保置顶正常
        if event.type() == QEvent.Show:
            self.activateWindow()
            self.setWindowFlags(self.windowFlags() | Qt.WindowStaysOnTopHint)
            #self.setTopMost()

    def initLayout(self):
        # 设置框架布局
        self._MainLayout = QVBoxLayout()
        self._MainLayout.setSpacing(0)
        self._MainLayout.addWidget(QLabel(), Qt.AlignLeft) # 顶一个QLabel在竖放框架第一行，以免正常内容挤占到标题范围里
        self._MainLayout.addStretch()
        self.setLayout(self._MainLayout)


if __name__ == "__main__":
    from PyQt5.QtWidgets import QApplication
    import sys
    app = QApplication(sys.argv)
    window = QUnFrameWindow()
    window.show()
    sys.exit(app.exec_())